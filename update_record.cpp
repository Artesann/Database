#include "update_record.h"
#include "ui_update_record.h"
#include <QSqlQuery>
#include <QDebug>

update_record::update_record(int ind, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::update_record)
{
    ui->setupUi(this);
    mes = new QMessageBox();
    record_id = ind;

    QSqlQuery* query = new QSqlQuery();
    query -> prepare("SELECT * FROM clients WHERE id = :id");
    query -> bindValue(":id", ind);

    if (query-> exec())
    {
        query -> next();
        ui -> id ->setText(query->value(0).toString());
        ui -> phone ->setText(query->value(1).toString());
        ui -> fname ->setText(query->value(2).toString());
        ui -> lname ->setText(query->value(3).toString());
        ui -> dad_name ->setText(query->value(4).toString());
        ui -> pasport ->setText(query->value(5).toString());
        ui -> birthday -> setDate(QDate(query->value(6).toDate()));
        ui -> adr ->setText(query->value(7).toString());
        ui ->city ->setText(query->value(8).toString());
    }

}

update_record::~update_record()
{
    delete ui;
}

void update_record::on_pushButton_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query -> prepare("UPDATE clients SET phone = :phone,"
                     " fname = :fname, lname = :lname,"
                     " dad_name = :dad_name, pasport = :pasport,"
                     " birhtday = :birthday, adr = :adr, city = :city WHERE id = :id");
    query -> bindValue(":id", ui->id -> text());
    query -> bindValue(":phone", ui->phone -> text());
    query -> bindValue(":fname", ui->fname -> text());
    query -> bindValue(":lname", ui->lname -> text());
    query -> bindValue(":dad_name", ui->dad_name -> text());
    query -> bindValue(":adr", ui->adr -> text());
    query -> bindValue(":city", ui->city -> text());
    query -> bindValue(":pasport", ui->pasport -> text());
    query -> bindValue(":birthday", ui->birthday -> text());

    if (query->exec())
        mes->setText("Выполнено");
    else
        mes->setText("Не выполнено");
}

void update_record::on_delete_2_clicked()
{
    QSqlQuery* query = new QSqlQuery();
    query -> prepare("DELETE FROM clients WHERE id=?");
    query -> bindValue(0, ui->id->text());
}
