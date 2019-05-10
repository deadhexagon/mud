#include <iostream>
#include "src/Server/Server.hpp"

using namespace Mud::Server;

namespace {
    const int SERVER_PORT = 4000;
}

int main(void)
{
    Server server(SERVER_PORT);
    server.Run();

    std::cout << "Program terminated normally." << std::endl;

    return 0;
}
