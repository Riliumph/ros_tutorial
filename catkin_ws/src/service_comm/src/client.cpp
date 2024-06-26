// STL
#include <sstream>
#include <string>
// ROS
#include "ros/ros.h"
#include "service_comm/AddTwoInts.h"
// original
#include "add_two_ints.h"

using namespace std::literals::string_literals;

int
main(int argc, char** argv)
{
  std::stringstream ss;
  ss << add_two_ints::service_name << "_client";
  auto node_name = ss.str();
  ros::init(argc, argv, node_name.c_str());
  if (argc != 3) {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  add_two_ints::client cli;
  service_comm::AddTwoInts msg;
  msg.request.a = atoll(argv[1]);
  msg.request.b = atoll(argv[2]);
  cli.send(msg);

  return 0;
}
