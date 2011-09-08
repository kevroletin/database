#include "dbactionstoolbar.h"

DbActionsToolbar::DbActionsToolbar(QWidget *parent) :
    QToolBar(parent)
{
    addRowAct = new QAction(tr("Add row"), this);   
    deleteRowAct = new QAction(tr("Delete row"), this);
    firstRowAct = new QAction(tr("First row"), this);
    lastRowAct = new QAction(tr("Last row"), this);
    nextRowAct = new QAction(tr("Next row"), this);
    openCardAct = new QAction(tr("Open card"), this);
    prevRowAct = new QAction(tr("Prev row"), this);
    revertAct = new QAction(tr("Revert"), this);
    submitAct = new QAction(tr("Submit"), this);

    addAction(addRowAct);
    addAction(deleteRowAct);
    addAction(firstRowAct);
    addAction(lastRowAct);
    addAction(nextRowAct);
    addAction(openCardAct);
    addAction(prevRowAct);
    addAction(revertAct);
    addAction(submitAct);
}
