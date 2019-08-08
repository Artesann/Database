#include "add_client.h"
#include "ui_add_client.h"

add_client::add_client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_client)
{
    ui->setupUi(this);


}

add_client::~add_client()
{
    delete ui;
}

void add_client::on_toolButton_clicked()
{
    image = QFileDialog::getOpenFileName(0, "Добавить изображение", "/", "*.jpg");
    ui -> label_8 -> setScaledContents(true);
    ui -> label_8 -> setPixmap(QPixmap(image));
}

void add_client::on_pushButton_clicked()
{
    QSqlQuery* query = new QSqlQuery(); //
    query -> prepare("INSERT INTO clients VALUES (:phone, :fname, :lname, :dad_name, :pasport, :birthday, :adr, :city)"); //
    query -> bindValue(":phone", ui->phone -> text());
    query -> bindValue(":fname", ui->fname -> text());
    query -> bindValue(":lname", ui->lname -> text());
    query -> bindValue(":dad_name", ui->dad_name -> text());
    query -> bindValue(":adr", ui->adr -> text());
    query -> bindValue(":city", ui->city -> text());
    query -> bindValue(":pasport", ui->pasport -> text());
    query -> bindValue(":birthday", ui->birthday -> text());
    query -> bindValue(":picadr", image);

    QMessageBox* mess = new QMessageBox();

    if (!query -> exec())
        mess -> setText("Error in insert");
    else
        mess -> setText("Add saccess");

    mess -> show();
}
