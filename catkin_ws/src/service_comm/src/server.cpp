#include "ros/ros.h"
#include "service_comm/AddTwoInts.h"

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
  const char* node_name = "add_two_ints_server";
  ros::init(argc, argv, node_name);
  ros::NodeHandle n;

  auto service = n.advertiseService("add_two_ints", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}
