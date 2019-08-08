#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graph->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    logwin = new login();
    logwin->show();
}

void MainWindow::on_add_record_clicked()
{
    addwin = new add_client();
    addwin->show();
}

void MainWindow::on_pirnt_clicked()
{
    model = new QSqlQueryModel(); //только выводит, запрос прописывается ниже, выбираем столбцы сами
    model -> setQuery("SELECT * FROM clients");

    model -> setHeaderData(0, Qt::Horizontal, "id");
    model -> setHeaderData(1, Qt::Horizontal, "Телефон");
    model -> setHeaderData(2, Qt::Horizontal, "Имя");
    model -> setHeaderData(3, Qt::Horizontal, "Фамилия");
    model -> setHeaderData(4, Qt::Horizontal, "Отчество");
    model -> setHeaderData(5, Qt::Horizontal, "Паспорт");
    model -> setHeaderData(6, Qt::Horizontal, "День рождения");
    model -> setHeaderData(7, Qt::Horizontal, "Адрес");
    model -> setHeaderData(8, Qt::Horizontal, "Город");

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    upwin = new update_record(ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toInt());
    upwin->show();
}

void MainWindow::on_toPDF_clicked()
{
    QString str;

    str.append("<html><head></head><body><center>" + QString("Отчет"));
    str.append("<table border = 1><tr>");
    str.append("<td>" + QString("id") + "</td>");
    str.append("<td>" + QString("Имя") + "</td>");
    str.append("<td>" + QString("Фамилия") + "</td>");
    str.append("<td>" + QString("Отчество") + "</td>");
    str.append("<td>" + QString("Паспорт") + "</td>");
    str.append("<td>" + QString("День рождения") + "</td>");
    str.append("<td>" + QString("Адрес") + "</td>");
    str.append("<td>" + QString("Город") + "</td></tr>");

    QSqlQuery* query = new QSqlQuery();
    query -> exec("SELECT * FROM clients");

    while (query->next())
    {
        str.append("<tr><td>");
        str.append(query -> value(0).toString());
        str.append("</td><td>");
        str.append(query -> value(1).toString());
        str.append("</td><td>");
        str.append(query -> value(2).toString());
        str.append( "</td><td>");
        str.append(query -> value(3).toString());
        str.append("</td><td>");
        str.append(query -> value(4).toString());
        str.append("</td><td>");
        str.append(query -> value(5).toString());
        str.append("</td><td>");
        str.append(query -> value(6).toString());
        str.append("</td><td>");
        str.append(query -> value(7).toString());
        str.append("</td></tr>");
    }

    str.append("</table></center></body></html>");

    QPrinter printer;
    printer.setOrientation(QPrinter::Portrait);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);

    QString path = QFileDialog::getSaveFileName(NULL, "Сохранить в pdf", "Отчет", "PDF (*.pdf)");
    if (path.isEmpty()) return;

    printer.setOutputFileName(path);

    QTextDocument doc;
    doc.setHtml(str);
    doc.print(&printer);
}

void MainWindow::on_graph_clicked()
{
    graphwin = new graph();
    graphwin->show();
}
