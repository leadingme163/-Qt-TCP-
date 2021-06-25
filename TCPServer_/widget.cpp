#include "widget.h"
#include "ui_widget.h"
#include "record.h"
#include "client.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    client *c = new client();
    c->show();

    server = new QTcpServer;
    server->listen(QHostAddress::AnyIPv4,PORT);

    // 客户端发起连接,server发出信号
    connect(server,SIGNAL(newConnection()),this,SLOT(newClientHandler()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::newClientHandler()
{
    // 建立TCP连接
    socket = server->nextPendingConnection();
//    socket->peerAddress();
//    socket->peerPort();

    ui->ipLineEdit->setText(socket->peerAddress().toString());
    ui->portLineEdit->setText(QString::number(socket->peerPort()));

    // 服务器收到客户端发送的信息，sokect发出readyread信号
    //connect(socket,&QTcpSocket::readyRead,this,&Widget::clientInfoSlot);

    // 启动线程,传参sokect
    myThread *t = new myThread(socket);
    // 开始线程
    t->start();

    connect(t,SIGNAL(sendToWidget(QByteArray)),this,SLOT(threadSlot(QByteArray)));
}


void Widget::threadSlot(QByteArray ba)
{
    sqlite s;
    s.connection();
    QString ip = socket->peerAddress().toString();
    quint16 port = socket->peerPort();
    s.insert_one(ip,port,QString(ba));
    ui->mainLineEdit->setText(QString(ba));
}

//void Widget::clientInfoSlot()
//{
//    // 获取信号的发出者，socket
//    QTcpSocket *s =  (QTcpSocket *)sender();
//    QString text = QString(s->readAll());
//    ui->mainLineEdit->setText(text);
//}

void Widget::on_displayButton_clicked()
{
    this->close();
    sqlite s;
    s.connection();
    stm = new QSqlTableModel; //初始化对象
    stm->setTable("information");
    stm->select(); // 显示数据
    record *c = new record(stm);
    c->show();
}
