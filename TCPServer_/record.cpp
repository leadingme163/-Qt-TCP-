#include "record.h"
#include "ui_record.h"

record::record(QSqlTableModel *stm,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::record)
{
    ui->setupUi(this);
    ui->tableView->setModel(stm);
    ui->tableView->setModel(stm);
}

record::~record()
{
    delete ui;
}
