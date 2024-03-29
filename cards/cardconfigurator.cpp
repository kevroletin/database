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
    mapper->toFirst();
}

void CardConfigurator::CreateLayout()
{
    TableSettings& s = globalSettings.Table(GetTable());
    QGridLayout* l = new QGridLayout;
    layout = l;

    for (int i = 0; i < s.colomnAliases.size(); ++i) {
        QLabel* label = new QLabel(s.colomnAliases[i].toAscii());
        l->addWidget(label, i, 0);
    }

    for (int i = 0; i < s.ui_controls.size(); ++i) {
        switch (s.ui_controls[i]) {
        case CONTROL_COMBO_BOX: {
            l->addWidget(CreateComboBox(i, s.relations[i].second) /* field */,
                         i, 1);
        } break;
        case CONTROL_EDIT: {
            l->addWidget(CreateEdit(i), i, 1);
        } break;
        case CONTROL_NONE: {

        } break;
        case CONTROL_PHOTO: {
            l->addLayout(CreatePotoControls(i), i, 1);
        }
        }
    }

    return;
}


QComboBox* CardConfigurator::CreateComboBox(int colIndex, QString& fieldToShow)
{
    QComboBox* nameComboBox = new QComboBox;
    QSqlTableModel *relModel = model->relationModel(colIndex);
    nameComboBox->setEditable(true);

    nameComboBox->setModel(relModel);
    nameComboBox->setModelColumn(relModel->fieldIndex(fieldToShow));
    mapper->addMapping(nameComboBox, colIndex);
    return nameComboBox;
}


QLineEdit* CardConfigurator::CreateEdit(int colIndex)
{
    QLineEdit* edit = new QLineEdit;
    if (colIndex == 0) {
        edit->setText(model->data(model->index(mapper->currentIndex(), 0)).toString());
        edit->setReadOnly(1);
    } else {
        mapper->addMapping(edit, colIndex);
    }
    return edit;
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
