#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    socket = new QTcpSocket; // 初始化scoket对象
}

Widget::~Widget()
{
    delete ui;
}

void Widget::connectSlot(){
    QMessageBox::information(this,"连接提示","连接服务器成功");
    // 隐藏提示界面
    this->close();
    Chat *c = new Chat(socket); // 堆空间创建
    c->show();
}

void Widget::disconnectSlot(){
    QMessageBox::warning(this,"连接提示","连接异常，网络断开");
}

void Widget::on_cancelButton_clicked()
{
    this->close();
}

void Widget::on_connectButton_clicked()
{
    // 获取ip和port
    QString ip = ui->ipLineEdit->text();
    QString port = ui->portLineEdit->text();\

//    qDebug() << ip << port;


    //连接服务器
    socket->connectToHost(QHostAddress(ip),port.toShort());

    // 连接服务器成功，socket对象会发出信号
    connect(socket,SIGNAL(connected()),this,SLOT(connectSlot()));

    // 连接断开，socket发出信号
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnectSlot()));
}
