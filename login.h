#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_button_clicked();

private:
    Ui::login *ui;
    login *logwin;
    QSqlDatabase db;
    QMessageBox* mes;
};

#endif // LOGIN_H
