#include <action_cli_lib/client.hpp>
int
main(int argc, char** argv)
{
  auto cli = action::client(argc, argv);
  cli.send();
  return 0;
}
