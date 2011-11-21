#include "tableconfigurator.h"
#include "cards/cardconfigurator.h"

MetalCostTable::MetalCostTable(DbActionsToolbar* dbActTb, QObject*) :
    TableConfigurator(dbActTb)
{
    Initialize();
}

void MetalCostTable::CreateCard()
{
    card = new MetalCostCard(model);
}
