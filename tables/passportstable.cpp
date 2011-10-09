#include "tableconfigurator.h"
#include "cards/cardconfigurator.h"

PassportsTable::PassportsTable(DbActionsToolbar* dbActTb, QObject*) :
    TableConfigurator(dbActTb)
{
    Initialize();
}

void PassportsTable::CreateCard()
{
    card = new PassportsCard(model);
}
