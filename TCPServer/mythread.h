#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class myThread :public QThread
{
    Q_OBJECT //信号与槽
public:
    explicit myThread(QTcpSocket *s);
    void run(); //虚函数(线性处理函数)

signals:
    void sendToWidget(QByteArray ba);

public slots:
    void clientInfoSlot();

private:
    QTcpSocket *socket;
};

#endif // MYTHREAD_H
