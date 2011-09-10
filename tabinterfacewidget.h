#ifndef TABINTERFACEWIDGET_H
#define TABINTERFACEWIDGET_H

#include <QTabWidget>
#include "tableconfigurator.h"

class TabInterfaceWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit TabInterfaceWidget(DbActionsToolbar* _dbActTb_, QWidget *parent = 0);
    ~TabInterfaceWidget();

private:
    void ConnfigureTabs();
    void RegisterTables();

    DbActionsToolbar* dbActTb;
    CarsTable* peopleTable;
    CustomersTable* customersTable;
    QList<TableConfigurator*> tables;

public slots:
    void ConnectDbActions(int table_index);

};

#endif // TABINTERFACEWIDGET_H
