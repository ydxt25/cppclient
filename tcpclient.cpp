#include "tcpclient.h"
#include <boost/bind.hpp>
#include <boost/date_time.hpp>
TcpClient::TcpClient(io_service ios_,std::string &host,int port):_ios(ios_),
    _sock(ios_),_ep(ip::address::from_string(host),port),_timer(ios_)
{
}


void TcpClient::startRead()
{

    _sock.async_connect(_ep,boost::bind(&TcpClient::handle_connect,this,_1));

}

void TcpClient::handle_connect(boost::system::error_code ec)
{
    if(!ec)
    {

    }
    else
    {
        _timer.async_wait(boost::bind(&TcpClient::timeout,this,_1));
        _timer.expires_from_now(boost::posix_time::seconds(5));
    }
}


void TcpClient::timeout(boost::system::error_code ec)
{

}

void TcpClient::handle_read(const boost::system::error_code &ec)
{


}

void TcpClient::handle_write(const boost::system::error_code &ec)
{

}
