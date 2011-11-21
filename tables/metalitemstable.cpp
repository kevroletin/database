#include "tableconfigurator.h"
#include "cards/cardconfigurator.h"

MetalItemsTable::MetalItemsTable(DbActionsToolbar* dbActTb, QObject*) :
    TableConfigurator(dbActTb)
{
    Initialize();
}

void MetalItemsTable::CreateCard()
{
    card = new MetalItemsCard(model);
}
