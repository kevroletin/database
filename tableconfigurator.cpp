#include "tableconfigurator.h"

TableConfigurator::TableConfigurator(DbActionsToolbar* _dbActTb_, QObject* parent) :
    QObject(parent),
    dbActTb(_dbActTb_)
{
}

void TableConfigurator::CreateView()
{
    view = new QTableView;
    view->setModel(model);
    view->setItemDelegate(new QSqlRelationalDelegate(view));
    view->setSelectionMode(QAbstractItemView::SingleSelection);
}

void TableConfigurator::Initialize()
{
    CreateModel();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    CreateView();
    CreateCard();
}

void TableConfigurator::AddRow()
{
    int index = view->currentIndex().row();
    if (index < 0) index = 0;
    model->insertRow(index, view->rootIndex());
}

void TableConfigurator::DeleteRow()
{
    model->removeRow(view->currentIndex().row(), view->rootIndex());
}

void TableConfigurator::FirstRow()
{
    view->setCurrentIndex(model->index(0, 0, QModelIndex()));
}

void TableConfigurator::LastRow()
{
    view->setCurrentIndex(model->index(model->rowCount(view->rootIndex()) - 1, 0, QModelIndex()));
}

void TableConfigurator::NextRow()
{
    view->setCurrentIndex(model->index(view->currentIndex().row() + 1, 0, QModelIndex()));
    if (view->currentIndex().row() < 0 ) FirstRow();
}

void TableConfigurator::OpenCard()
{
    card->show();
}

void TableConfigurator::PrevRow()
{
    int index = view->currentIndex().row() - 1;
    if (index < 0) {
        LastRow();
    } else {
        view->setCurrentIndex(model->index(index, 0, QModelIndex()));
    }
}

void TableConfigurator::Revert()
{
    model->revertAll();
}

void TableConfigurator::Submit()
{
// :HACK: since where is no simple api to save editable data in table
    view->setDisabled( true );
    view->setDisabled( false );

    if (!model->submitAll()) {
        // :TODO: show only usefull messages for users
        // :TODO: save errors in logs
        QMessageBox::critical(0, qApp->tr("Cannot perform commit"),
                              model->lastError().text(), QMessageBox::Cancel);
    }
}

CarsTable::CarsTable(DbActionsToolbar* dbActTb, QObject*) :
    TableConfigurator(dbActTb)
{
    Initialize();
}

void CarsTable::CreateCard()
{
    card = new QDialog(view);
    card->setWindowTitle(GetTitle());
    CarsCardLayout* cardLayout = new CarsCardLayout;

    QPushButton* okButton = new QPushButton("OK");
    QPushButton* cancelButton = new QPushButton("Cancel");

    QGridLayout *buttonLayout = new QGridLayout;
    buttonLayout->setColumnStretch(2, 2);
    buttonLayout->addWidget(okButton, 0, 0);
    buttonLayout->addWidget(cancelButton, 0, 1);

//    cardLayout->addLayout(buttonLayout, 2, 1, Qt::AlignRight);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(cardLayout);
    mainLayout->addLayout(buttonLayout);
    card->setLayout(mainLayout);

    connect(okButton, SIGNAL(clicked()),
            card, SLOT(accept()));

    connect(cancelButton, SIGNAL(clicked()),
            card, SLOT(reject()));
}

void CarsTable::CreateModel()
{
    model = new QSqlRelationalTableModel;
    model->setTable(GetTableName());

    model->setRelation(1, QSqlRelation("customer_passports", "id", "name"));

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("OWNER"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("BRAND"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SERIAL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PHOTO"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMBER PHOTO"));
}

CustomersTable::CustomersTable(DbActionsToolbar* dbActTb, QObject*) :
    TableConfigurator(dbActTb)
{
    Initialize();
}

void CustomersTable::CreateCard()
{
}

void CustomersTable::CreateModel()
{
    model = new QSqlRelationalTableModel;
    model->setTable(GetTableName());

    model->setRelation(1, QSqlRelation("customer_passports", "id", "name"));
}
