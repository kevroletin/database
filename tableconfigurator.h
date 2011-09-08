#ifndef TABLECONFIGURATOR_H
#define TABLECONFIGURATOR_H

#include <QObject>
#include <QtGui>
#include <QtSql>
#include "dbactionstoolbar.h"

class TableConfigurator : public QObject
{
    Q_OBJECT
public:
    TableConfigurator(DbActionsToolbar* dbActTb, QObject *parent = 0);
    QTableView* CreateView();
    QString GetTitle() { return ""; }
    virtual QString GetTableName() { return ""; }
    QTableView* GetView() { return view; }
    QSqlRelationalTableModel* GetModel() { return model; }

protected:
    QDataWidgetMapper* mapper;
    QTableView *view;
    DbActionsToolbar* dbActTb;
    QSqlRelationalTableModel* model;

public slots:
    void AddRow();
    void DeleteRow();
    void FirstRow();
    void LastRow();
    void NextRow();
    void PrevRow();
    void Revert();
    void Submit();
};

class PeopleTable : public TableConfigurator
{
public:
    PeopleTable(DbActionsToolbar* dbActTb, QObject *parent = 0);
    QString GetTitle() { return "Employee"; }
    virtual QString GetTableName() { return "employee"; }
};

#endif // TABLECONFIGURATOR_H
