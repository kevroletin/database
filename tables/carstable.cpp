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
    dialog->setWindowTitle(GetTableAlias());
    QVBoxLayout *mainLayout = new QVBoxLayout;

    QLayout* cardLayout = card->GetLayout();
    mainLayout->addLayout(cardLayout);


    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Save
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

