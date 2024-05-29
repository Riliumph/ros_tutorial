// STL
#include <sstream>
#include <string>
// ROS
#include "ros/ros.h"
#include "service_comm/AddTwoInts.h"
// original
#include "service.hpp"

using namespace std::literals::string_literals;

bool
add(service_comm::AddTwoInts::Request& req,
    service_comm::AddTwoInts::Response& res)
{
  res.sum = req.a + req.b;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}

int
main(int argc, char** argv)
{
  std::stringstream ss;
  ss << service_name << "_server";
  auto node_name = ss.str();
  ros::init(argc, argv, node_name.c_str());
  ros::NodeHandle n;

  auto service = n.advertiseService(service_name, add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}
