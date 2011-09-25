#include "mainwindow.h"

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
    db.setUserName("postgres");
    db.setDatabaseName("postgres");
    db.setHostName("localhost");

    db.open();

    return true;
}

void MainWindow::CreateToolbar()
{
    dbActTb = new DbActionsToolbar;
    addToolBar(dbActTb);
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
    ConnectDatabase();
    CreateActions();
    CreateToolbar();
    CreateMenus();

    tabInterface = new TabInterfaceWidget(dbActTb);
    connect(tabInterface, SIGNAL(currentChanged(int)), tabInterface, SLOT(ConnectDbActions(int)));
    setCentralWidget(tabInterface);
    if (!ConnectDatabase()) {
        // :TODO: show good error dscription for user and save error in logs
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
                              "some error occured", QMessageBox::Cancel);
    }

    // :TODO: read config from file
    setWindowTitle(tr("Metal base database"));
}

MainWindow::~MainWindow()
{
}
