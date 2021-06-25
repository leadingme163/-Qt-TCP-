#ifndef SQLITE_H
#define SQLITE_H
#include <QSqlDatabase> // 注册驱动，创建数据库
#include <QSqlQuery> // 执行sql语句
#include <QMessageBox>
#include <QDebug>
#include <QSqlTableModel>

class sqlite: public QSqlDatabase
{
public:
    sqlite();
    void connection();
    void insert_one(QString ip, quint16 port, QString text);

private:
    QSqlDatabase db;
};

#endif // SQLITE_H
