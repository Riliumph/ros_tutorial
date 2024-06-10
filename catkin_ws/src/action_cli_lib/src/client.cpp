#include "client.hpp"
// STL
#include <random>
#include <sstream>
// ROS
#include "action_communication/DoDishesAction.h"

namespace action {
client::client(int argc, char** argv)
{
  std::stringstream ss;
  ss << "action_comm" << "_client";
  auto node_name = ss.str();
  ros::init(argc, argv, node_name.c_str());

  cli = std::make_shared<CLI>(destination, auto_ros_spin_enabled);

  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  random_num = engine();
}

client::~client() {}

int
client::send()
{
  ROS_INFO("waiting for %s server", destination);
  cli->waitForServer();
  ROS_INFO("sever connected");

  action_communication::DoDishesGoal goal;
  goal.dishwasher_id = random_num;
  cli->sendGoal(goal);
  cli->waitForResult();

  if (cli->getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
    ROS_INFO("Yay! The dishes are now clean");
  }
  ROS_INFO("Current State: %s\n", cli->getState().toString().c_str());
  return 0;
}
}
