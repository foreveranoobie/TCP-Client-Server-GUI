#include "tcpclient.h"

TcpClient::TcpClient(QObject *parent)
    : QObject{parent}
{
    socket = new QTcpSocket(this);
}

TcpClient::~TcpClient(){
    if(socket->isOpen()){
        socket->close();
    }
    delete socket;
}

bool TcpClient::connect(QString &ip, int port, int timeout){
    socket->connectToHost(ip, port);
    return socket->waitForConnected(timeout);
}

bool TcpClient::disconnect(){
    socket->close();
    return !isOpen();
}

bool TcpClient::send(QString &msg){
    socket->write(msg.toUtf8());
    socket->flush();
    return socket->waitForBytesWritten(1000);
}

bool TcpClient::isOpen(){
    return socket->isOpen();
}
