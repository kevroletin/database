#include "tabinterfacewidget.h"

TabInterfaceWidget::TabInterfaceWidget(DbActionsToolbar* _dbActTb_, QWidget *parent) :
    QTabWidget(parent),
    dbActTb(_dbActTb_)
{
    RegisterTables();
    ConnfigureTabs();
    connect(this, SIGNAL(currentChanged(int)),
            this, SLOT(ConnectDbActions(int)));
    ConnectDbActions(0);

    // DEBUG:
    //carsTable->OpenCard();
}

TabInterfaceWidget::~TabInterfaceWidget()
{
}

void TabInterfaceWidget::ConnfigureTabs()
{
    for (int i = 0; i < tables.size(); ++i)
    {
        addTab(tables[i]->GetView(), tables[i]->GetTableAlias());
    }
}

void TabInterfaceWidget::ConnectDbActions(int table_index)
{
    static TableConfigurator* previousTable = NULL;
    TableConfigurator* currentTable = tables[table_index];

// TODO: create little function where:
    disconnect(dbActTb->addRowAct, 0, previousTable, 0);
    connect(dbActTb->addRowAct, SIGNAL(triggered()),
            currentTable, SLOT(AddRow()));

    disconnect(dbActTb->deleteRowAct, 0, previousTable, 0);
    connect(dbActTb->deleteRowAct, SIGNAL(triggered()),
            currentTable, SLOT(DeleteRow()));

    disconnect(dbActTb->prevRowAct, 0, previousTable, 0);
    connect(dbActTb->prevRowAct, SIGNAL(triggered()),
            currentTable, SLOT(PrevRow()));

    disconnect(dbActTb->firstRowAct, 0, previousTable, 0);
    connect(dbActTb->firstRowAct, SIGNAL(triggered()),
            currentTable, SLOT(FirstRow()));

    disconnect(dbActTb->nextRowAct, 0, previousTable, 0);
    connect(dbActTb->nextRowAct, SIGNAL(triggered()),
            currentTable, SLOT(NextRow()));

    disconnect(dbActTb->lastRowAct, 0, previousTable, 0);
    connect(dbActTb->lastRowAct, SIGNAL(triggered()),
            currentTable, SLOT(LastRow()));

    disconnect(dbActTb->openCardAct, 0, previousTable, 0);
    connect(dbActTb->openCardAct, SIGNAL(triggered()),
            currentTable, SLOT(OpenDialog()));

    disconnect(dbActTb->revertAct, 0, previousTable, 0);
    connect(dbActTb->revertAct, SIGNAL(triggered()),
            currentTable, SLOT(Revert()));

    disconnect(dbActTb->submitAct, 0, previousTable, 0);
    connect(dbActTb->submitAct, SIGNAL(triggered()),
            currentTable, SLOT(Submit()));

    previousTable = currentTable;
}

void TabInterfaceWidget::RegisterTables()
{
    carsTable = new CarsTable(dbActTb);
    customersTable = new CustomersTable(dbActTb);
    licensesTable = new LicensesTable(dbActTb);
    passportsTable = new PassportsTable(dbActTb);

    tables << carsTable << customersTable << licensesTable << passportsTable;
}
