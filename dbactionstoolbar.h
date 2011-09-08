#ifndef DBACTIONSTOOLBAR_H
#define DBACTIONSTOOLBAR_H

#include <QToolBar>
#include <QAction>

class DbActionsToolbar : public QToolBar
{
    Q_OBJECT
public:
    explicit DbActionsToolbar(QWidget *parent = 0);

    QAction* addRowAct;
    QAction* deleteRowAct;
    QAction* firstRowAct;
    QAction* lastRowAct;
    QAction* nextRowAct;
    QAction* openCardAct;
    QAction* prevRowAct;
    QAction* revertAct;
    QAction* submitAct;

signals:

public slots:

};

#endif // DBACTIONSTOOLBAR_H
