#ifndef LINE_ORIENTED_CONNECTION_HPP
#define LINE_ORIENTED_CONNECTION_HPP

#include <boost/asio.hpp>
#include "Connection.hpp"

namespace Mud
{
    namespace Server
    {
        class LineOrientedConnection : public Connection
        {
            public:
                LineOrientedConnection(boost::asio::io_service &io_service)
                    : Connection(io_service),
                      m_inputStream(&m_inputBuffer)
                {
                }

                void Start()
                {
                    ReadLine();
                }

            private:
                void ReadLine();

                boost::asio::streambuf m_inputBuffer;
                std::istream m_inputStream;
        };
    }
}

#endif
