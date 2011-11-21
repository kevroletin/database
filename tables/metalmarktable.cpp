#include "tableconfigurator.h"
#include "cards/cardconfigurator.h"

MetalMarkTable::MetalMarkTable(DbActionsToolbar* dbActTb, QObject*) :
    TableConfigurator(dbActTb)
{
    Initialize();
}

void MetalMarkTable::CreateCard()
{
    card = new MetalMarkCard(model);
}
