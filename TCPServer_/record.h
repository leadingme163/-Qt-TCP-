#ifndef RECORD_H
#define RECORD_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class record;
}

class record : public QWidget
{
    Q_OBJECT

public:
    explicit record(QSqlTableModel *stm, QWidget *parent = 0);
    ~record();

private slots:


private:
    Ui::record *ui;
};

#endif // RECORD_H
