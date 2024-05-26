// STL
#include <iostream>
// ROS
#include <actionlib/server/simple_action_server.h>
// original
#include <action_communication/DoDishesAction.h>

using Server =
  actionlib::SimpleActionServer<action_communication::DoDishesAction>;

void
execute(const action_communication::DoDishesGoalConstPtr& goal, Server* as)
{
  std::cout << "execute callback" << std::endl;
  std::cout << "do_dishes: Received goal with dishwasher_id = "
            << goal->dishwasher_id << std::endl;
  as->setSucceeded();
}

int
main(int argc, char** argv)
{
  ros::init(argc, argv, "do_dishes_server");
  ros::NodeHandle n;
  Server server(n, "do_dishes", boost::bind(&execute, _1, &server), false);
  std::cout << "Server start" << std::endl;
  server.start();
  std::cout << "infinite spin start" << std::endl;
  ros::spin();
  std::cout << "finalize server" << std::endl;
  return 0;
}
