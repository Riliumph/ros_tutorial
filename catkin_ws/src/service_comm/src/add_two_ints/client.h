#ifndef INCLUDE_SERVICE_COMM_ADD_TWO_INTS_CLIENT_H
#define INCLUDE_SERVICE_COMM_ADD_TWO_INTS_CLIENT_H
// STL
#include <memory>
#include <string>
// ROS
#include "ros/ros.h"
// auto generated
#include "service_comm/AddTwoInts.h"

namespace add_two_ints {
class client
{
public:
  client();
  ~client();
  int send(service_comm::AddTwoInts msg);

private:
  std::shared_ptr<ros::NodeHandle> n;
  ros::ServiceClient cli;
};
}
#endif // INCLUDE_SERVICE_COMM_ADD_TWO_INTS_CLIENT_H
