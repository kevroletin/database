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

    DbActionsToolbar* dbActTb;
    CarsTable* peopleTable;

signals:

public slots:

};

#endif // TABINTERFACEWIDGET_H
