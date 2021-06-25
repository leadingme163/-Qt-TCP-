#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QTcpSocket *s, QWidget *parent):
    QWidget(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
    // 将传送来的QTcpSocket对象用socket接受
    socket = s;
}

Chat::~Chat()
{
    delete ui;
}

void Chat::on_clearButton_clicked()
{
    ui->lineEdit->clear();
}

void Chat::on_sendButton_clicked()
{
    // 将获取的文本转QByteArray
    QByteArray ba;
    ba.append(ui->lineEdit->text());
    // 写入socket
    socket->write(ba);
}
