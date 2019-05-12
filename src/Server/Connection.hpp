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
                    : m_socket(io_service),
                      m_outputStream(&m_outputBuffer)
                {}

                void Start(void)
                {
                    m_outputStream << "Connection started" << std::endl;

                    async_write(
                        m_socket,
                        m_outputBuffer,
                        [this](boost::system::error_code error, std::size_t)
                        {
                            if (!error)
                            {
                                std::cout << "Write completed successfully" << std::endl;
                            }
                        }
                    );
                }

                SocketType &Socket() { return m_socket; };

            private:
                SocketType m_socket;
                boost::asio::streambuf m_outputBuffer;
                std::ostream m_outputStream;
        };
    }
}

#endif
