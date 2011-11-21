#include "tableconfigurator.h"
#include "cards/cardconfigurator.h"

MetalDealTable::MetalDealTable(DbActionsToolbar* dbActTb, QObject*) :
    TableConfigurator(dbActTb)
{
    Initialize();
}

void MetalDealTable::CreateCard()
{
    card = new MetalDealCard(model);
}
