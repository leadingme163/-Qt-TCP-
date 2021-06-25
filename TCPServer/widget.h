#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <mythread.h>
#include <sqlite.h>
#include <QSqlTableModel>

#define PORT 8000

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
    void newClientHandler();
    // void clientInfoSlot();
    void threadSlot(QByteArray ba);

    void on_displayButton_clicked();

private:
    Ui::Widget *ui;
    QTcpServer *server;
    QTcpSocket *socket;
    QSqlTableModel *stm;
};

#endif // WIDGET_H
