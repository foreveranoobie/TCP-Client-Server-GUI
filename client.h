#ifndef CLIENT_H
#define CLIENT_H

#include "tcpclient.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Client;
}
QT_END_NAMESPACE

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void on_connectButton_clicked();

    void on_sendButton_clicked();

    void on_disconnectButton_clicked();

private:
    Ui::Client *ui;
    TcpClient *client;
};

#endif // CLIENT_H
