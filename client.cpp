#include "client.h"
#include "./ui_client.h"
#include "qlineedit.h"
#include "qpushbutton.h"

Client::Client(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    client = new TcpClient();
}

Client::~Client()
{
    delete ui;
    delete client;
}

void Client::on_connectButton_clicked()
{
    QString ip = findChild<QLineEdit *>("ipInput")->text();
    int port = findChild<QLineEdit *>("portInput")->text().toInt();
    if (client->connect(ip, port)) {
        findChild<QLineEdit *>("messageInput")->setEnabled(true);
        findChild<QPushButton *>("sendButton")->setEnabled(true);
    } else {
        qDebug() << "Cannot connect to given host";
    }
}

void Client::on_sendButton_clicked()
{
    QLineEdit *input = findChild<QLineEdit *>("messageInput");
    if (client->isOpen()) {
        QString msg = input->text();
        client->send(msg);
    } else {
        input->setEnabled(false);
        findChild<QPushButton *>("sendButton")->setEnabled(false);
        client->disconnect();
    }
}

void Client::on_disconnectButton_clicked()
{
    findChild<QLineEdit *>("messageInput")->setEnabled(false);
    findChild<QPushButton *>("sendButton")->setEnabled(false);
    client->disconnect();
}
