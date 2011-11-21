#include "tableconfigurator.h"
#include "cards/cardconfigurator.h"

CompaniesTable::CompaniesTable(DbActionsToolbar* dbActTb, QObject*) :
    TableConfigurator(dbActTb)
{
    Initialize();
}

void CompaniesTable::CreateCard()
{
    card = new CompaniesCard(model);
}
