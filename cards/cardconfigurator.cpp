#include "cardconfigurator.h"

CardConfigurator::CardConfigurator(QSqlRelationalTableModel* _model_, QObject *parent) :
    QObject(parent),
    model(_model_)
{
    mapper = new QDataWidgetMapper;
    mapper->setModel(model);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
}
