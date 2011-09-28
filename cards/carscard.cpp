#include "cardconfigurator.h"
#include <QtCore>
#include <QtGui>

CarsCard::CarsCard(QSqlRelationalTableModel* _model_, QObject* parent) :
    CardConfigurator(_model_, parent)
{
    CreateLayout();
}

void CarsCard::CreateLayout()
{
    QGridLayout* l = new QGridLayout;
    layout = l;
    // TODO: move table metainformation in separate entity
    QStringList names;
    names << "Id" << "Name" << "Brand" << "Serial number" << "Photo" << "Number photo";
    for (int i = 0; i < names.size(); ++i) {
        l->addWidget(new QLabel(tr(names[i].toAscii())), i, 0);
    }

    QLineEdit* idEdit = new QLineEdit;
    mapper->addMapping(idEdit, model->fieldIndex("id"));
    l->addWidget(idEdit, 0, 1);

    QComboBox* nameComboBox = new QComboBox;
    QSqlTableModel *relModel = model->relationModel(1);

    nameComboBox->setModel(relModel);
    nameComboBox->setModelColumn(relModel->fieldIndex("name"));
    mapper->addMapping(nameComboBox, 1);
    l->addWidget(nameComboBox, 1, 1);

    QLineEdit* brandEdit = new QLineEdit;
    mapper->addMapping(brandEdit, model->fieldIndex("brand"));
    l->addWidget(brandEdit, 2, 1);

    QLineEdit* serialNumberEdit = new QLineEdit;
    mapper->addMapping(serialNumberEdit, model->fieldIndex("serial_number"));
    l->addWidget(serialNumberEdit, 3, 1);

    l->addLayout(CreatePotoControls(4), 4, 1);

    l->addLayout(CreatePotoControls(5), 5, 1);

    //mapper->toFirst();
    mapper->setCurrentIndex(1);
}

void CarsCard::Submit()
{    
    mapper->submit();
}

void CarsCard::Revert()
{
    mapper->revert();
}
