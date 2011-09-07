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
    QAction* commitAct;
    QAction* deleteRowAct;
    QAction* nextRowAct;
    QAction* openCardAct;
    QAction* prewRowAct;
    QAction* rollBackAct;

signals:

public slots:

};

#endif // DBACTIONSTOOLBAR_H
