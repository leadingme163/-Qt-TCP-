#include "mythread.h"

myThread::myThread(QTcpSocket *s)
{
    // 传参来的socket赋值给private中的socket
    socket = s;
}


void myThread::run()
{
    connect(socket,SIGNAL(readyRead()),this,SLOT(clientInfoSlot()));
}

void myThread::clientInfoSlot()
{
    // 不能在其他类里面操作界面
    // qDebug() << socket->readAll(); // 可通过自定义信号实现操作ui
    QByteArray ba;
    ba.append(socket->readAll());
    emit sendToWidget(ba); //emit: 发送自定义信号
}
