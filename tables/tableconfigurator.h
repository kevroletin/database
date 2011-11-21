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

class CustomizedTableView : public QTableView
{
    Q_OBJECT
protected:
};

class CustomTableModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    CustomTableModel(TableSettings& _tableSet_, QObject * parent = 0, QSqlDatabase db = QSqlDatabase()):
        QSqlRelationalTableModel(parent, db),
        tableSet(_tableSet_)  { }

protected:
    Qt::ItemFlags flags (const QModelIndex& index) const
    {
        return Qt::ItemIsSelectable |
               Qt::ItemIsEnabled;
        // TODO: remove
        if (index.column() == 0) {
            return Qt::ItemIsSelectable |
                   Qt::ItemIsEnabled;
        }
        else if (tableSet.colomnsToDraw.contains(index.column())) {
            return Qt::ItemIsSelectable |
                   Qt::ItemIsEnabled;
        }
        return QSqlRelationalTableModel::flags(index);
    }

    TableSettings& tableSet;
};

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
    virtual CustomTableModel* CreateNewModel();
    virtual void CreateModel();
    virtual void CreateView();
    virtual void CustomizeView();
    void Initialize();

    CardConfigurator* card;
    QDialog* dialog;
    CustomizedTableView *view;
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
    void Refresh();
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

class LicensesTable : public TableConfigurator
{
public:
    LicensesTable(DbActionsToolbar* dbActTb, QObject* parent = 0);
    virtual Tables GetTable() { return TABLE_LICENSES; }

protected:
    virtual void CreateCard();
};


class PassportsModel : public CustomTableModel
{
    Q_OBJECT
public:
    PassportsModel(TableSettings& _tableSet_, QObject * parent = 0, QSqlDatabase db = QSqlDatabase());
    virtual QVariant data(const QModelIndex &item, int role) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role);
};

class PassportsTable : public TableConfigurator
{
public:
    PassportsTable(DbActionsToolbar* dbActTb, QObject* parent = 0);
    virtual Tables GetTable() { return TABLE_PASSPORTS; }

protected:
    virtual void CreateCard();
    virtual CustomTableModel* CreateNewModel() { return new PassportsModel(GetSettings()); }
};

class CompaniesTable : public TableConfigurator
{
public:
    CompaniesTable(DbActionsToolbar* dbActTb, QObject* parent = 0);
    virtual Tables GetTable() { return TABLE_COMPANIES; }

protected:
    virtual void CreateCard();
};

class MetalCostTable : public TableConfigurator
{
public:
    MetalCostTable(DbActionsToolbar* dbActTb, QObject* parent = 0);
    virtual Tables GetTable() { return TABLE_METAL_COSTS; }

protected:
    virtual void CreateCard();
};

class MetalDealTable : public TableConfigurator
{
public:
    MetalDealTable(DbActionsToolbar* dbActTb, QObject* parent = 0);
    virtual Tables GetTable() { return TABLE_METAL_DEALS; }

protected:
    virtual void CreateCard();
};

class MetalItemsTable : public TableConfigurator
{
public:
    MetalItemsTable(DbActionsToolbar* dbActTb, QObject* parent = 0);
    virtual Tables GetTable() { return TABLE_METAL_ITEMS; }

protected:
    virtual void CreateCard();
};

class MetalMarkTable : public TableConfigurator
{
public:
    MetalMarkTable(DbActionsToolbar* dbActTb, QObject* parent = 0);
    virtual Tables GetTable() { return TABLE_METAL_MARKS; }

protected:
    virtual void CreateCard();
};

#endif // TABLECONFIGURATOR_H
