#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpSocket> //网络有关库
#include<chat.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_cancelButton_clicked();
    void on_connectButton_clicked();
    void connectSlot();
    void disconnectSlot();

private:
    Ui::Widget *ui;
    // 声明网络对象
    QTcpSocket *socket;
};

#endif // WIDGET_H
