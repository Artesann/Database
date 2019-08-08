#include "update.h"
#include "ui_update.h"

struct client_data
{
    QString phone;
    QString fname;
    QString lname;
    QString dad_name;
    QString pasport;
    QString birthday;
    QString adr;
    QString city;
};

update::update(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::update)
{
    ui->setupUi(this);
}

update::~update()
{
    delete ui;
}
