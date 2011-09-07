#include "dbactionstoolbar.h"

DbActionsToolbar::DbActionsToolbar(QWidget *parent) :
    QToolBar(parent)
{
    addRowAct = new QAction(tr("Add row"), this);
    commitAct = new QAction(tr("Commit"), this);
    deleteRowAct = new QAction(tr("Delete row"), this);
    nextRowAct = new QAction(tr("Next row"), this);
    openCardAct = new QAction(tr("Open card"), this);
    prewRowAct = new QAction(tr("Prev row"), this);
    rollBackAct = new QAction(tr("Roll back"), this);

    addAction(addRowAct);
    addAction(commitAct);
    addAction(deleteRowAct);
    addAction(nextRowAct);
    addAction(openCardAct);
    addAction(prewRowAct);
    addAction(rollBackAct);
}
