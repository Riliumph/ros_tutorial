#include <service_cli_lib/client.hpp>
int
main(int argc, char** argv)
{
  auto cli = service_cli::client(argc, argv);
  cli.send();
  return 0;
}
