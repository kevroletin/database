#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include "tabinterfacewidget.h"
#include "Dialogs/aboutdialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void showAboutDialog();

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QMenu *fileMenu;
    QMenu *helpMenu;
    QAction *exitAct;
    QAction *aboutAct;

private:
    bool ConfigureDatabase();
    void CreateMenus();

    TabInterfaceWidget* tabInterface;
};

#endif // MAINWINDOW_H
