#include "tableconfigurator.h"
#include "cards/cardconfigurator.h"

CarsTable::CarsTable(DbActionsToolbar* dbActTb, QObject*) :
    TableConfigurator(dbActTb)
{
    Initialize();
}

void CarsTable::CreateDialog()
{
    // TODO: вынести в инициализацию объекта. Разобраться с виртуальными методами.
    CreateCard();

    dialog = new QDialog(view);
    dialog->setWindowTitle(GetTitle());
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QLayout* cardLayout = card->GetLayout();
    mainLayout->addLayout(cardLayout);


    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                     | QDialogButtonBox::Cancel);

    mainLayout->insertStretch(1, 10);

    mainLayout->addWidget(buttonBox);
    dialog->setLayout(mainLayout);

    connect(buttonBox, SIGNAL(accepted()), card, SLOT(Submit()));
    connect(buttonBox, SIGNAL(rejected()), card, SLOT(Revert()));

    //connect(buttonBox, SIGNAL(accepted()), card, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));
}

void CarsTable::CreateCard()
{
    card = new CarsCard(model);
}

void CarsTable::CreateModel()
{
    model = new QSqlRelationalTableModel;
    model->setTable(GetTableName());

    // TODO: move table metainformation in separate entity
    model->setRelation(1, QSqlRelation("customer_passports", "id", "name"));
/*
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("OWNER"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("BRAND"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SERIAL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PHOTO"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMBER PHOTO"));
    */
}

