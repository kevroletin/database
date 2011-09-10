#ifndef TABLECONFIGURATOR_H
#define TABLECONFIGURATOR_H

#include <QObject>
#include <QtGui>
#include <QtSql>
#include "cards/cars.h"
#include "dbactionstoolbar.h"

class TableConfigurator : public QObject
{
    Q_OBJECT
public:
    TableConfigurator(DbActionsToolbar* dbActTb, QObject *parent = 0);
    virtual QString GetTitle() = 0;
    virtual QString GetTableName() = 0;
    QTableView* GetView() { return view; }
    QSqlRelationalTableModel* GetModel() { return model; }

protected:
    virtual void CreateCard() = 0;
    virtual void CreateModel() = 0;
    virtual void CreateView();
    void Initialize();

    QDialog* card;
    QTableView *view;
    DbActionsToolbar* dbActTb;
    QSqlRelationalTableModel* model;

public slots:
    void AddRow();
    void DeleteRow();
    void FirstRow();
    void LastRow();
    void NextRow();
    void OpenCard();
    void PrevRow();
    void Revert();
    void Submit();
};

class CarsTable : public TableConfigurator
{
public:
    CarsTable(DbActionsToolbar* dbActTb, QObject* parent = 0);
    virtual QString GetTitle() { return "Cars"; }
    virtual QString GetTableName() { return "cars"; }

protected:
    virtual void CreateCard();
    virtual void CreateModel();
};

class CustomersTable : public TableConfigurator
{
public:
    CustomersTable(DbActionsToolbar* dbActTb, QObject* parent = 0);
    virtual QString GetTitle() { return "Customers"; }
    virtual QString GetTableName() { return "customers"; }

protected:
    virtual void CreateCard();
    virtual void CreateModel();
};

#endif // TABLECONFIGURATOR_H
