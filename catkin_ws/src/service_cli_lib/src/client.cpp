#include "client.hpp"
// STL
#include <sstream>
// ROS
#include "service_comm/AddTwoInts.h"

const char* service_name = "add_two_ints";

namespace service_cli {
client::client(int argc, char** argv)
  : argc(argc)
  , argv(argv)
{
  std::stringstream ss;
  ss << service_name << "_client";
  auto node_name = ss.str();

  ros::init(argc, argv, node_name.c_str());
  n = std::make_shared<ros::NodeHandle>();
  cli = n->serviceClient<service_comm::AddTwoInts>(service_name);
}

client::~client() {}

int
client::send()
{
  service_comm::AddTwoInts srv;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  if (cli.call(srv)) {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  } else {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }
  return 0;
}
}
