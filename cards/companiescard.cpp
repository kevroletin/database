#include "cardconfigurator.h"
#include <QtCore>
#include <QtGui>
#include <QtSql>

CompaniesCard::CompaniesCard(QSqlRelationalTableModel* _model_, QObject* parent) :
    CardConfigurator(_model_, parent)
{
    CreateLayout();
}
