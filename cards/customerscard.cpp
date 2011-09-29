#include "cardconfigurator.h"
#include <QtCore>
#include <QtGui>
#include <QtSql>

CustomersCard::CustomersCard(QSqlRelationalTableModel* _model_, QObject* parent) :
    CardConfigurator(_model_, parent)
{
    CreateLayout();
}

