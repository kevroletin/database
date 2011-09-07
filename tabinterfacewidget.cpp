#include "tabinterfacewidget.h"

TabInterfaceWidget::TabInterfaceWidget(QWidget *parent) :
    QTabWidget(parent)
{
    ConnfigureTabs();
}

TabInterfaceWidget::~TabInterfaceWidget()
{
    peopleTable->GetModel()->submitAll();
}

void TabInterfaceWidget::ConnfigureTabs()
{
    peopleTable = new PeopleTable;
    addTab(peopleTable->CreateView(), peopleTable->GetTitle());
    peopleTable->GetModel()->insertRow(3);
}
