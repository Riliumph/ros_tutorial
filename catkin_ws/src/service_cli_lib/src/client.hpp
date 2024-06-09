// STL
#include <memory>
#include <string>
// ROS
#include "ros/ros.h"

namespace service_cli {
class client
{
public:
  client(int argc, char** argv);
  ~client();
  int send();

private:
  int argc;
  char** argv;
  std::shared_ptr<ros::NodeHandle> n;
  ros::ServiceClient cli;
};
}
