#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include<QTcpSocket> //网络有关库
#include<chat.h>
#include<QMessageBox>
#include<QDebug>
#include<QHostAddress>

namespace Ui {
class client;
}

class client : public QWidget
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = 0);
    ~client();

private slots:
    void on_cancelButton_clicked();
    void on_connectButton_clicked();
    void connectSlot();
    void disconnectSlot();

private:
    Ui::client *ui;
    // 声明网络对象
    QTcpSocket *socket;
};

#endif // CLIENT_H
