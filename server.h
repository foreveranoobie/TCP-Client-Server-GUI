#ifndef SERVER_H
#define SERVER_H

#include "TcpServer.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setTcpServer(TcpServer *server);

private slots:
    void addMessage(QString msg);

private:
    Ui::MainWindow *ui;
    TcpServer *server;
};
#endif // SERVER_H
