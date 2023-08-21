#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include "qtcpsocket.h"
#include <QObject>

class TcpClient : public QObject
{
    Q_OBJECT

private:
    QTcpSocket *socket;

public:
    explicit TcpClient(QObject *parent = nullptr);
    ~TcpClient();
    bool connect(QString &ip, int port, int timeout = 5000);
    bool disconnect();
    bool send(QString &msg);
    bool isOpen();

signals:

};

#endif // TCPCLIENT_H
