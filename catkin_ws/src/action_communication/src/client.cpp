// STL
#include <iostream>
#include <random>
// ROS
#include <actionlib/client/simple_action_client.h>
// original
// #include <${your-package-name}/${action-filename}Action.h>
// 最初は未解決の参照エラーが出ている。
// catkin build時にgenaction.pyによってヘッダファイルが生成される。
#include <action_communication/DoDishesAction.h>

#define AUTO_ROS_SPIN_ENABLED 1

using Client =
  actionlib::SimpleActionClient<action_communication::DoDishesAction>;

template<typename T>
double
reciprocal(T number)
{
  return 1.0 / number;
}

uint32_t
get_dishwasher_id()
{
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  return engine();
}

int
main(int argc, char** argv)
{
  ros::init(argc, argv, "client_node");

#ifdef AUTO_ROS_SPIN_ENABLED
  std::cout << "AUTO ROS SPIN MODE" << std::endl;
  // クライアントがros::spin()を内部スレッドで実行して返信（Result）を待つかどうかのフラグ。
  bool auto_ros_spin_enabled = true;
#else
  std::cout << "MANUAL ROS SPIN MODE" << std::endl;
  bool auto_ros_spin_enabled = false;
#endif
  Client client("do_dishes", auto_ros_spin_enabled);

  // Actionサーバーに接続できるまで無限待機
  std::cout << "waiting for ROS Server..." << std::endl;
  client.waitForServer();
  std::cout << "Server connected" << std::endl;

  // Goalの送信
  action_communication::DoDishesGoal goal;
  goal.dishwasher_id = get_dishwasher_id();
  std::cout << "sending goal ..." << std::endl;
  client.sendGoal(goal);

  // Resultの受信
  const int hz = 10;
  ros::Duration result_timeout(1.0 / hz);
  std::cout << "waiting result response .." << std::endl;
#ifdef AUTO_ROS_SPIN_ENABLED
  client.waitForResult(result_timeout);
#else
  // waitForResultをより簡素化して実装する必要がある。
  ros::Rate rate(hz); // 10 Hz
  while (ros::ok()) {
    // Process incoming messages
    ros::spinOnce();
    // 前回のrate.sleep()から計測して一周期（1/hz）経過するまで待機
    rate.sleep();
  }
#endif

  if (client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
    printf("Yay! The dishes are now clean");
  }
  printf("Current State: %s\n", client.getState().toString().c_str());
  return 0;
}
