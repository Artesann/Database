#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->adr-> setText("ARTESANLT");
    ui->bd-> setText("touragent2");

    mes = new QMessageBox();
}

login::~login()
{
    delete ui;
}

void login::on_button_clicked()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL Server};SERVER="+ui->adr->text()+";DATABASE="+ui->bd->text()+";Trusted_Connection=yes;");

    if (db.open())
        mes->setText("Подключение успешно");
    else
        mes->setText("Не удалось подключиться");

    mes->show();
}
