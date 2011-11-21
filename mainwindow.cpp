#include "mainwindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <iostream>
#include <QString>

void MainWindow::showAboutDialog()
{
    AboutDialog aDialog;

    aDialog.exec();
}

bool MainWindow::ConnectDatabase()
{
    // :TODO: read database configuration from file
    // :TODO: read password from user interface or save encripted
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    // TODO: remove debug output:
    std::cerr << "\n*********************************\n";
    std::cerr << tr("username: ").toAscii().data() << userName.toAscii().data() << "\n"
              << tr("password: ").toAscii().data() << password.toAscii().data() << "\n"
              << tr("database name: ").toAscii().data() << databaseName.toAscii().data() << "\n"
              << tr("host: ").toAscii().data() << hostName.toAscii().data();
    std::cerr << "\n*********************************\n";

    db.setUserName(userName);
    db.setPassword(password);
    db.setDatabaseName(databaseName);
    db.setHostName(hostName);
/*
    db.setUserName("postgres");
    db.setDatabaseName("postgres");
    db.setHostName("localhost");
*/
    db.open();

    return true;
}

void MainWindow::CreateToolbar()
{
    dbActTb = new DbActionsToolbar;
    addToolBar(dbActTb);
}

void MainWindow::ReadSettings()
{
    QSettings& settings = globalSettings.iniSettings;
    settings.beginGroup("MainWindow");
        resize(settings.value("size", QSize(800, 600)).toSize());
        move(settings.value("pos", QPoint(200, 200)).toPoint());
    settings.endGroup();
    settings.beginGroup("Database");
        userName = settings.value("userName", "postgres").toString();
        password = settings.value("password", "").toString();
        hostName = settings.value("host", "localhost").toString();
        databaseName = settings.value("databaseName", "postgres").toString();
    settings.endGroup();
}

void MainWindow::WriteSettings()
{
    QSettings& settings = globalSettings.iniSettings;
    settings.beginGroup("MainWindow");
        settings.setValue("size", size());
        settings.setValue("pos", pos());
    settings.endGroup();
    settings.beginGroup("Database");
        settings.setValue("userName", userName);
        settings.setValue("password", password);
        settings.setValue("host", hostName);
        settings.setValue("databaseName", databaseName);
    settings.endGroup();
}

void MainWindow::CreateActions()
{
    exitAct = new QAction(tr("E&xit"), this);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    aboutAct = new QAction(tr("About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(showAboutDialog()));
}

void MainWindow::CreateMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ReadSettings();
    ConnectDatabase();
    CreateActions();
    CreateToolbar();
    CreateMenus();

    tabInterface = new TabInterfaceWidget(dbActTb);
    connect(tabInterface, SIGNAL(currentChanged(int)), tabInterface, SLOT(ConnectDbActions(int)));
    setCentralWidget(tabInterface);

    // :TODO: read config from file
    setWindowTitle(tr("Metal base database"));
}

MainWindow::~MainWindow()
{
    WriteSettings();
}
