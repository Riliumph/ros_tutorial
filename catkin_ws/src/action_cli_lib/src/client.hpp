// STL
#include <memory>
#include <string>
// ROS
#include <action_communication/DoDishesAction.h>
#include <actionlib/client/simple_action_client.h>
#include <ros/ros.h>

namespace action {
class client
{
  using CLI =
    actionlib::SimpleActionClient<action_communication::DoDishesAction>;

public:
  client(int argc, char** argv);
  ~client();
  int send();

private:
  const char* destination = "do_dishes";
  const bool auto_ros_spin_enabled = true;
  std::shared_ptr<CLI> cli;
  uint32_t random_num;
};
}
