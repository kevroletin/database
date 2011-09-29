#ifndef TABLECONFIGURATOR_H
#define TABLECONFIGURATOR_H

#include <QObject>

QT_BEGIN_NAMESPACE
class QDialog;
class QSqlRelationalTableModel;
class QTableView;
QT_END_NAMESPACE

#include "cards/cardconfigurator.h"
#include "dbactionstoolbar.h"
#include "picturedelegate.h"
#include "applicationsettings.h"

class TableConfigurator : public QObject
{
    Q_OBJECT
public:
    TableConfigurator(DbActionsToolbar* dbActTb, QObject *parent = 0);
    virtual QString GetTableAlias() { return GetSettings().alias; }
    virtual QString GetTableName() { return GetSettings().name; }
    virtual Tables GetTable() = 0;
    virtual TableSettings& GetSettings() { return globalSettings.Table(GetTable()); }
    QTableView* GetView() { return view; }
    QSqlRelationalTableModel* GetModel() { return model; }

protected:
    virtual void CreateDialog();
    virtual void CreateCard() = 0;
    virtual void CreateModel();
    virtual void CreateView();
    void Initialize();

    CardConfigurator* card;
    QDialog* dialog;
    QTableView *view;
    DbActionsToolbar* dbActTb;
    QSqlRelationalTableModel* model;

public slots:
    void AddRow();
    void DeleteRow();
    void FirstRow();
    void LastRow();
    void NextRow();
    void OpenDialog();
    void PrevRow();
    void Revert();
    void Submit();
};

class CarsTable : public TableConfigurator
{
public:
    CarsTable(DbActionsToolbar* dbActTb, QObject* parent = 0);
    virtual Tables GetTable() { return TABLE_CARS; }

protected:
    virtual void CreateCard();
};

class CustomersTable : public TableConfigurator
{
public:
    CustomersTable(DbActionsToolbar* dbActTb, QObject* parent = 0);
    virtual Tables GetTable() { return TABLE_CUSTOMERS; }

protected:
    virtual void CreateCard();
};

#endif // TABLECONFIGURATOR_H
