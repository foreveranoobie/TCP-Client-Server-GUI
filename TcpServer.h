#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include "qlistwidget.h"
#include "qobject.h"
#include "qtmetamacros.h"

class TcpServer : public QObject {
    Q_OBJECT

Q_SIGNALS:
    void messageReceived(QString msg);

private:
    QTcpServer *server;
    QTcpSocket *socket;

public slots:
    void newConnection();

    void readData();

    void cleanSocket();

public:
    TcpServer(QObject* parent = nullptr);

    ~TcpServer();
};
#endif // TCPSERVER_H
