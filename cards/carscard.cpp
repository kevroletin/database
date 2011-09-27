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

    QLineEdit* brandEdit = new QLineEdit;
    mapper->addMapping(brandEdit, model->fieldIndex("brand"));

    QLineEdit* serialNumberEdit = new QLineEdit;
    mapper->addMapping(serialNumberEdit, model->fieldIndex("serial_number"));
    QGroupBox* photoGroupBox = new QGroupBox(tr("Photo"));
    QVBoxLayout* photoLayout = new QVBoxLayout;
    photoLabel = new QLabel;
    photoPixmap = new QPixmap;
    photoPixmap->load("/home/behemoth/Work/MetalDatabase/img/image.png", "PNG");
    // FIXME: QSqlTableModel can't handle binary data correctly.
    // TODO: QSqlTableModel should be inhereted and fixed.
    // TODO: but now QSqlQuery should be used to send picture into database:
    // TODO:     QSqlQuery q;
    // TODO:     q.prepare("update cars set (photo) = (:data);");
    // TODO:     q.bindValue(":data", QVariant(buff.data()));
    // TODO:     q.exec();
    //
    //    photoPixmap->save(buffer, "PNG");
    //    photoPixmap.save(buff, "PNG");
    //    model->setData(model->index(0, 4),
    //                   QVariant(buffer->data()));

    // BUG: causes double free
    photoLabel->setPixmap(*photoPixmap);

    photoLayout->addWidget(photoLabel);
    photoGroupBox->setLayout(photoLayout);
    QPushButton* loadButton = new QPushButton("Load");
    connect(loadButton, SIGNAL(clicked()), this, SLOT(LoadPicture()));
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
    QBuffer buff;
    photoPixmap->save(&buff, "PNG");
    model->setData(model->index(mapper->currentIndex(), 4),
                   QVariant(buff.data()));
    mapper->submit();
}

void CarsCard::Revert()
{
    mapper->revert();
}

void CarsCard::LoadPicture()
{
    QString fileName = QFileDialog::getOpenFileName();
    photoPixmap->load(fileName, "PNG");
    photoLabel->setPixmap(*photoPixmap);
}
