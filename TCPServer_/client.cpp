#include "client.h"
#include "ui_client.h"

client::client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::client)
{
    socket = new QTcpSocket; // 初始化scoket对象
    ui->setupUi(this);
}

client::~client()
{
    delete ui;
}


void client::connectSlot(){
    QMessageBox::information(this,"Tip","Success");
    // 隐藏提示界面
    this->close();
    chat *c = new chat(socket); // 堆空间创建
    c->show();
}

void client::disconnectSlot(){
    QMessageBox::warning(this,"Tip","Disconnect");
}

void client::on_cancelButton_clicked()
{
    this->close();
}

void client::on_connectButton_clicked()
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
