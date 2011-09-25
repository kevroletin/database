#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

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

    TabInterfaceWidget* tabInterface;
};

#endif // MAINWINDOW_H
