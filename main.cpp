#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
/*    QTranslator translator;
    translator.load("translate");
    translator.load("qt_" + QLocale::system().name(),
        QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&translator);
*/
    MainWindow w;
    w.show();

    return a.exec();
}
