#include "cardconfigurator.h"
#include <QtSql>
#include <QtGui>

CardConfigurator::CardConfigurator(QSqlRelationalTableModel* _model_, QObject *parent) :
    QObject(parent),
    model(_model_)
{
    mapper = new QDataWidgetMapper;
    mapper->setModel(model);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
}

QVBoxLayout* CardConfigurator::CreatePotoControls(int colIndex)
{
    UpdatableLabel* photoLabel = new UpdatableLabel;
    mapper->addMapping(photoLabel, colIndex, "pictureByteArr");
    QPushButton* photoButton = new QPushButton("Load");
    connect(photoButton, SIGNAL(clicked()), photoLabel, SLOT(LoadPicture()));
    QVBoxLayout* pl = new QVBoxLayout;
    pl->addWidget(photoLabel);
    pl->addWidget(photoButton);
    return pl;
}
