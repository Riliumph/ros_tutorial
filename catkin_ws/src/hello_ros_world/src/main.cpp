// STL
#include <iostream>
// ROS
#include <ros/ros.h>
// original
#include "newbie.hpp"

int
main(int argc, char** argv)
{
  ros::init(argc, argv, "hello_ros_world_node");
  hello_ros_world::Newbie nb;
  nb.hello();
  return 0;
}
