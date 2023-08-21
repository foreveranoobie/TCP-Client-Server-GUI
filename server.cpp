#include "server.h"
#include "./ui_server.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setTcpServer(new TcpServer());
    connect(server, &TcpServer::messageReceived, this, &MainWindow::addMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete server;
}

void MainWindow::setTcpServer(TcpServer *server){
    this->server = server;
}

void MainWindow::addMessage(QString msg)
{
    ui->messagesList->addItem(msg);
}
