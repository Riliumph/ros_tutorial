#ifndef INCLUDE_SERVICE_COMM_ADD_TWO_INTS_SERVICE_H
#define INCLUDE_SERVICE_COMM_ADD_TWO_INTS_SERVICE_H
// STL
#include <memory>
// ROS
#include <ros/ros.h>
// auto generated
#include "service_comm/AddTwoInts.h"

namespace add_two_ints {
static const char* service_name = "add_two_ints";

class service
{
public:
  static bool api(service_comm::AddTwoInts::Request& req,
                  service_comm::AddTwoInts::Response& res);

public:
  service();
  ~service();

private:
  std::shared_ptr<ros::NodeHandle> n;
  ros::ServiceServer server;
};
}
#endif // INCLUDE_SERVICE_COMM_ADD_TWO_INTS_SERVICE_H
