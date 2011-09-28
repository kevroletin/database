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
    names << "Id" << "Name" << "Brand" << "Serial number";
    for (int i = 0; i < names.size(); ++i) {
        l->addWidget(new QLabel(tr(names[i].toAscii())), i, 0);
    }

    QLineEdit* idEdit = new QLineEdit;
    mapper->addMapping(idEdit, model->fieldIndex("id"));

    QComboBox* nameComboBox = new QComboBox;
    QSqlTableModel *relModel = model->relationModel(1);

    nameComboBox->setModel(relModel);
    nameComboBox->setModelColumn(relModel->fieldIndex("name"));
    mapper->addMapping(nameComboBox, 1, "currentIndex");

    QLineEdit* brandEdit = new QLineEdit;
    mapper->addMapping(brandEdit, model->fieldIndex("brand"));

    QLineEdit* serialNumberEdit = new QLineEdit;
    mapper->addMapping(serialNumberEdit, model->fieldIndex("serial_number"));
    QGroupBox* photoGroupBox = new QGroupBox(tr("Photo"));
    QVBoxLayout* photoLayout = new QVBoxLayout;
    photoLabel = new UpdatableLabel;
    mapper->addMapping(photoLabel, 4, "pictureByteArr");


    photoLayout->addWidget(photoLabel);
    photoGroupBox->setLayout(photoLayout);
    QPushButton* loadButton = new QPushButton("Load");
    connect(loadButton, SIGNAL(clicked()), photoLabel, SLOT(LoadPicture()));
    photoLayout->addWidget(loadButton);

    QGroupBox* numberPhotoGroupBox = new QGroupBox(tr("Number photo"));

    l->addWidget(idEdit, 0, 1);
    l->addWidget(nameComboBox, 1, 1);
    l->addWidget(brandEdit, 2, 1);
    l->addWidget(serialNumberEdit, 3, 1);
    l->addWidget(photoGroupBox, 4, 0, 1, 2);
    l->addWidget(photoGroupBox, 4, 0, 1, 2);

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
