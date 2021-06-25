#include "sqlite.h"

sqlite::sqlite()
{
//    db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("tcp.db");
}

void sqlite::connection(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("tcp.db");
    if(db.open()){ //打开数据库
        // QMessageBox::information(this,"连接提示","连接成功");
        qDebug() << "sqlite连接成功";
     }else{
        // QMessageBox::warning(this,"连接提示","连接失败");
        qDebug() << "sqlite连接失败";
    }
    QSqlQuery query;
    QString sql = QString("create table information(ip varchar(16) not null, port integer not null, text);");
    query.exec(sql);
};

void sqlite::insert_one(QString ip, quint16 port, QString text){
    QSqlQuery query;
    QString sql = QString("insert into information values('%1', %2, '%3');").arg(ip).arg(port).arg(text);
/*    qDebug() << sql;*/
    if(query.exec(sql)){
        qDebug() << "插入成功";
    }else{
        qDebug() << "插入失败";
    }
}
