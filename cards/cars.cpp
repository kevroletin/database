#include "cars.h"
#include <QtCore>
#include <QtGui>

CarsCardLayout::CarsCardLayout(QSqlRelationalTableModel* _model_, QWidget *parent) :
    QGridLayout(parent),
    model(_model_)
{
    QDataWidgetMapper* mapper = new QDataWidgetMapper;
    mapper->setModel(model);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));

    // TODO: move table metainformation in separate entity
    QStringList names;
    names << "Id" << "Name" << "Brand" << "Serial number";
    for (int i = 0; i < names.size(); ++i) {
        addWidget(new QLabel(tr(names[i].toAscii())), i, 0);
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
    QLabel* photoLabel = new QLabel;
    QPixmap* photoPixmap = new QPixmap;
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
    photoLabel->setPixmap(*photoPixmap);
    photoLayout->addWidget(photoLabel);
    photoGroupBox->setLayout(photoLayout);

    QGroupBox* numberPhotoGroupBox = new QGroupBox(tr("Number photo"));

    addWidget(idEdit, 0, 1);
    addWidget(nameComboBox, 1, 1);
    addWidget(brandEdit, 2, 1);
    addWidget(serialNumberEdit, 3, 1);
    addWidget(photoGroupBox, 4, 0, 1, 2);
    addWidget(photoGroupBox, 4, 0, 1, 2);

    mapper->toFirst();
}
