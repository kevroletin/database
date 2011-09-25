#ifndef CARS_H
#define CARS_H

#include <QLayout>
#include <QDialog>
#include <QtGui>
#include <QtSql>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QTextEdit;
class QLineEdit;
QT_END_NAMESPACE

class CarsCardLayout : public QGridLayout
{
    Q_OBJECT
public:
    explicit CarsCardLayout(QSqlRelationalTableModel* model, QWidget *parent = 0);

private:
    QSqlRelationalTableModel* model;


signals:

public slots:

};

#endif // CARS_H
