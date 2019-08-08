#ifndef UPDATE_RECORD_H
#define UPDATE_RECORD_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
namespace Ui {
class update_record;
}

class update_record : public QWidget
{
    Q_OBJECT

public:
    explicit update_record(int ind, QWidget *parent = nullptr);
    ~update_record();

private slots:
    void on_pushButton_clicked();

    void on_delete_2_clicked();

private:
    Ui::update_record *ui;
    QMessageBox* mes;
    int record_id;
};

#endif // UPDATE_RECORD_H
