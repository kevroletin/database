#include "cardconfigurator.h"
#include <QtCore>
#include <QtGui>
#include <QtSql>

CarsCard::CarsCard(QSqlRelationalTableModel* _model_, QObject* parent) :
    CardConfigurator(_model_, parent)
{
    CreateLayout();
}
