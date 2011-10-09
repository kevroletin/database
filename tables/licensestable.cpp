#include "tableconfigurator.h"
#include "cards/cardconfigurator.h"

LicensesTable::LicensesTable(DbActionsToolbar* dbActTb, QObject*) :
    TableConfigurator(dbActTb)
{
    Initialize();
}

void LicensesTable::CreateCard()
{
    card = new LicensesCard(model);
}

