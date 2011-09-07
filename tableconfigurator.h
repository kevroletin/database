#ifndef TABLECONFIGURATOR_H
#define TABLECONFIGURATOR_H

#include <QObject>
#include <QtGui>
#include <QtSql>

class TableConfigurator : public QObject
{
    Q_OBJECT
public:
    TableConfigurator(QObject *parent = 0);
    QTableView* CreateView();
    QString GetTitle() { return ""; }
    QSqlRelationalTableModel* GetModel() { return model; }

protected:

    QSqlRelationalTableModel* model;
};

class PeopleTable : public TableConfigurator
{
public:
    PeopleTable(QObject *parent = 0);
    QString GetTitle() { return "Employee"; }
};

#endif // TABLECONFIGURATOR_H
