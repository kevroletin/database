#include "tableconfigurator.h"
#include "cards/cardconfigurator.h"

CarsTable::CarsTable(DbActionsToolbar* dbActTb, QObject*) :
    TableConfigurator(dbActTb)
{
    Initialize();
}

void CarsTable::CreateCard()
{
    card = new CarsCard(model);
}

