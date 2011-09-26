#include "tableconfigurator.h"

CustomersTable::CustomersTable(DbActionsToolbar* dbActTb, QObject*) :
    TableConfigurator(dbActTb)
{
    Initialize();
}

void CustomersTable::CreateDialog()
{
}

void CustomersTable::CreateModel()
{
    model = new QSqlRelationalTableModel;
    model->setTable(GetTableName());

    model->setRelation(1, QSqlRelation("customer_passports", "id", "name"));
}

