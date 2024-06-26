// STL
#include <sstream>
#include <string>
// ROS
#include "ros/ros.h"
#include "service_comm/AddTwoInts.h"
// original
#include "add_two_ints.h"

int
main(int argc, char** argv)
{
  std::stringstream ss;
  ss << add_two_ints::service_name << "_server";
  auto node_name = ss.str();
  ros::init(argc, argv, node_name.c_str());

  // サーバー機能をクラス化すると最適化で削除されそう。
  // クラス化の意味が薄い可能性が高い。
  add_two_ints::service srv;

  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}
