#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <boost/asio.hpp>

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
                      m_outputStream1(&m_outputBuffer1),
                      m_outputStream2(&m_outputBuffer2),
                      m_outputBuffer(&m_outputBuffer1),
                      m_bufferBeingWritten(&m_outputBuffer2),
                      m_outputStream(&m_outputStream1),
                      m_streamBeingWritten(&m_outputStream2),
                      m_writing(false),
                      m_moreToWrite(false)
                {}

                template <class T>
                void Write(const T &message)
                {
                    *m_outputStream << message;
                    WriteToSocket();
                }

                template <class T>
                std::ostream &operator << (const T &message)
                {
                    Write(message);
                    m_moreToWrite = true;
                    return *m_outputStream;
                }

                std::ostream &ostream()
                {
                    WriteToSocket();
                    m_moreToWrite = true;
                    return *m_outputStream;
                }

                void Start(void)
                {
                    Write("Connection started\n");
                }

                SocketType &Socket() { return m_socket; };

            protected:
                SocketType m_socket;

            private:
                void WriteToSocket();

                boost::asio::streambuf m_outputBuffer1, m_outputBuffer2;
                std::ostream m_outputStream1, m_outputStream2;
                boost::asio::streambuf *m_outputBuffer, *m_bufferBeingWritten;
                std::ostream *m_outputStream, *m_streamBeingWritten;

                bool m_writing, m_moreToWrite;
        };
    }
}

#endif
