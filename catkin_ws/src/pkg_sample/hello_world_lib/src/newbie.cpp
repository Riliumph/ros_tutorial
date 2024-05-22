#include "newbie.hpp"
// STL
#include <iostream>

namespace hello_ros_world_lib {
Newbie::Newbie() {}

Newbie::~Newbie()
{
  std::cout << "bye, ROS world" << std::endl;
}

void
Newbie::hello()
{
  std::cout << "hello, ROS world" << std::endl;
}
}
