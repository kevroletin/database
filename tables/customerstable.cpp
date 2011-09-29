#include "tableconfigurator.h"
#include "cards/cardconfigurator.h"

CustomersTable::CustomersTable(DbActionsToolbar* dbActTb, QObject*) :
    TableConfigurator(dbActTb)
{
    Initialize();
}

void CustomersTable::CreateCard()
{
    card = new CustomersCard(model);
}

