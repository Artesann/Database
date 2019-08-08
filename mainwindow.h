#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <login.h>
#include <ui_login.h>
#include <add_client.h>
#include <ui_add_client.h>
#include <update_record.h>
#include <ui_update_record.h>
#include <graph.h>
#include <ui_graph.h>
#include <QSqlQuery>
#include <QDebug>
#include <QPrinter>
#include <QTextDocument>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_triggered();

    void on_add_record_clicked();

    void on_pirnt_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_toPDF_clicked();

    void on_graph_clicked();

private:
    Ui::MainWindow *ui;
    login *logwin;
    add_client *addwin;
    QSqlQueryModel* model;
    update_record* upwin;
    graph *graphwin;
};

#endif // MAINWINDOW_H
