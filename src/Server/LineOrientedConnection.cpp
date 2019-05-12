#include "LineOrientedConnection.hpp"

#include <iostream>

using namespace Mud::Server;

void LineOrientedConnection::ReadLine()
{
    async_read_until(
        m_socket,
        m_inputBuffer,
        '\n',
        [this](boost::system::error_code error, std::size_t)
        {
            if (error)
            {
                std::cout << "async_read_until encountered an error" << std::endl;
            }
            else
            {
                std::string line;
                std::getline(m_inputStream, line);
                //m_interface.HandleLine(line);
                std::cout << "Received line: " << line << std::endl;

                ReadLine();
            }
        }
    );
}
