#ifndef CONNECTION_HPP
#define CONNECTION_HPP

namespace Mud
{
    namespace Server
    {
        class Connection
        {
            public:
                explicit Connection(boost::asio::io_service &io_service)
                    : m_socket(io_service) {}

            private:
                SocketType m_socket;
        }
    }
}

#endif
