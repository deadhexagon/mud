#ifndef CONNECTION_HPP
#define CONNECTION_HPP

namespace Mud
{
    namespace Server
    {
        class Connection
        {
            public:
                typedef boost::asio::ip::tcp::socket SocketType;

                explicit Connection(boost::asio::io_service &io_service)
                    : m_socket(io_service) {}

                void Start(void)
                {
                    std::cout << "Connection started" << std::endl;
                }

                SocketType &Socket() { return m_socket; };

            private:
                SocketType m_socket;
        };
    }
}

#endif
