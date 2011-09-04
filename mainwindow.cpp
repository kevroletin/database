#include "mainwindow.h"

void MainWindow::showAboutDialog()
{
    AboutDialog aDialog;

    aDialog.exec();
}


bool MainWindow::ConfigureDatabase()
{
    // :TODO: read database configuration from file
    // :TODO: read password from user interface or save encripted
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setUserName("postgres");
    db.setDatabaseName("postgres");
    db.setHostName("localhost");

    return true;
}

void MainWindow::CreateMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));

    exitAct = new QAction(tr("E&xit"), this);
    fileMenu->addAction(exitAct);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    helpMenu = menuBar()->addMenu(tr("&Help"));

    aboutAct = new QAction(tr("About"), this);
    helpMenu->addAction(aboutAct);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(showAboutDialog()));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    tabInterface = new TabInterfaceWidget;
    setCentralWidget(tabInterface);
    CreateMenus();
    if (!ConfigureDatabase()) {
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
