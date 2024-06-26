#include "client.h"
// STL
#include <sstream>
// ROS
#include "service_comm/AddTwoInts.h"
// original
#include "server.h"

namespace add_two_ints {
client::client()
{
  n = std::make_shared<ros::NodeHandle>();
  cli = n->serviceClient<service_comm::AddTwoInts>(service_name);
}

client::~client() {}

int
client::send(service_comm::AddTwoInts msg)
{
  if (cli.call(msg)) {
    ROS_INFO("Sum: %ld", (long int)msg.response.sum);
  } else {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }
  return 0;
}
}
