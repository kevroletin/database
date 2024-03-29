#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
QT_END_NAMESPACE

#include "dialogs/aboutdialog.h"
#include "dbactionstoolbar.h"
#include "tabinterfacewidget.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void showAboutDialog();

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QMenu* fileMenu;
    QMenu* helpMenu;
    QAction* exitAct;
    QAction* aboutAct;

    DbActionsToolbar* dbActTb;

private:
    bool ConnectDatabase();
    void CreateActions();
    void CreateMenus();
    void CreateToolbar();
    void ReadSettings();
    void WriteSettings();

    TabInterfaceWidget* tabInterface;
    QString userName;
    QString password;
    QString databaseName;
    QString hostName;
};

#endif // MAINWINDOW_H
