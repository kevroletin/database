#ifndef DBACTIONSTOOLBAR_H
#define DBACTIONSTOOLBAR_H

#include <QToolBar>

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

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
    QAction* refreshAct;
    QAction* submitAct;

signals:

public slots:

};

#endif // DBACTIONSTOOLBAR_H
