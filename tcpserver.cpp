#include "tcpserver.h"

TcpServer::TcpServer(QObject* parent) : QObject(parent){
    server = new QTcpServer(this);

    connect(server, SIGNAL(newConnection()),
            this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::LocalHost, 9999))
    {
        qDebug() << "Server could not start";
    }
    else
    {
        qDebug() << "Server started!";
    }
}

TcpServer::~TcpServer(){
    delete server;
}

void TcpServer::newConnection()
{
    qDebug() << "New client has connected!";
    // need to grab the socket
    socket = server->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(cleanSocket()));
}

void TcpServer::readData(){
    QString msg = socket->readLine();
    qDebug() << "Received the client's message" << msg;
    emit messageReceived(msg);
}

void TcpServer::cleanSocket()
{
    qDebug() << "The client has disconnected";
    delete socket;
    socket = nullptr;
}
