#include "tabinterfacewidget.h"

TabInterfaceWidget::TabInterfaceWidget(DbActionsToolbar* _dbActTb_, QWidget *parent) :
    QTabWidget(parent),
    dbActTb(_dbActTb_)
{
    ConnfigureTabs();
}

TabInterfaceWidget::~TabInterfaceWidget()
{
//    peopleTable->GetModel()->submitAll();
}

void TabInterfaceWidget::ConnfigureTabs()
{
    peopleTable = new PeopleTable(dbActTb);
    addTab(peopleTable->CreateView(), peopleTable->GetTitle());
//    peopleTable->GetModel()->insertRow(3);
    connect(dbActTb->addRowAct, SIGNAL(triggered()),
            peopleTable, SLOT(AddRow()));
    connect(dbActTb->deleteRowAct, SIGNAL(triggered()),
            peopleTable, SLOT(DeleteRow()));
    connect(dbActTb->nextRowAct, SIGNAL(triggered()),
            peopleTable, SLOT(NextRow()));
    connect(dbActTb->prevRowAct, SIGNAL(triggered()),
            peopleTable, SLOT(PrevRow()));
    connect(dbActTb->firstRowAct, SIGNAL(triggered()),
            peopleTable, SLOT(FirstRow()));
    connect(dbActTb->lastRowAct, SIGNAL(triggered()),
            peopleTable, SLOT(LastRow()));
    connect(dbActTb->revertAct, SIGNAL(triggered()),
            peopleTable, SLOT(Revert()));
    connect(dbActTb->submitAct, SIGNAL(triggered()),
            peopleTable, SLOT(Submit()));


//    peopleTable->GetView()->setCurrentIndex();
}
