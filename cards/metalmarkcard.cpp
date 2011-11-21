#include "cardconfigurator.h"
#include <QtCore>
#include <QtGui>
#include <QtSql>

MetalMarkCard::MetalMarkCard(QSqlRelationalTableModel* _model_, QObject* parent) :
    CardConfigurator(_model_, parent)
{
    CreateLayout();
}
