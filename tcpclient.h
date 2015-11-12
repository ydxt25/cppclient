#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include <boost/asio.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <iostream>
using namespace boost::asio;
class TcpClient
{
public:
    TcpClient(io_service ios_,std::string &host,int port);
    void startRead();
    void handle_connect(boost::system::error_code ec);
    void handle_read(const boost::system::error_code &ec);
    void handle_write(const boost::system::error_code &ec);
    void timeout(boost::system::error_code ec);
private:
    io_service &_ios;
    ip::tcp::socket _sock;
    ip::tcp::endpoint _ep;
    char buf[1024];
    boost::asio::deadline_timer _timer;

};

#endif // TCPCLIENT_H
