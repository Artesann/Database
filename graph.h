#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include <QSqlQuery>
#include <qcpdocumentobject.h>

namespace Ui {
class graph;
}

class graph : public QWidget
{
    Q_OBJECT

public:
    explicit graph(QWidget *parent = nullptr);
    ~graph();

private:
    Ui::graph *ui;
};

#endif // GRAPH_H
