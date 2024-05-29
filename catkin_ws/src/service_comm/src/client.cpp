// STL
#include <sstream>
#include <string>
// ROS
#include "ros/ros.h"
#include "service_comm/AddTwoInts.h"
// original
#include "service.hpp"

using namespace std::literals::string_literals;

int
main(int argc, char** argv)
{
  std::stringstream ss;
  ss << service_name << "_client";
  auto node_name = ss.str();
  ros::init(argc, argv, node_name.c_str());
  if (argc != 3) {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  ros::NodeHandle n;
  auto client = n.serviceClient<service_comm::AddTwoInts>(service_name);
  service_comm::AddTwoInts srv;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  if (client.call(srv)) {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  } else {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}
