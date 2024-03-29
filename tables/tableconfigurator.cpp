#include "tableconfigurator.h"
#include <QtGui>
#include <QtSql>
#include "applicationsettings.h"

TableConfigurator::TableConfigurator(DbActionsToolbar* _dbActTb_, QObject* parent) :
    QObject(parent),
    dbActTb(_dbActTb_)
{
}

void TableConfigurator::CreateView()
{
    view = new CustomizedTableView;
    view->setModel(model);
    CustomizeView();
}

void TableConfigurator::CustomizeView()
{
    view->setSelectionMode(QAbstractItemView::SingleSelection);

    view->setItemDelegate(new PictureDelegate(GetSettings().colomnsToDraw, view));

    for (int i = 0; i < GetSettings().colonmSizes.size(); ++i) {
        view->setColumnWidth(i, GetSettings().colonmSizes[i]);
    }
    if (GetSettings().rowsHeight) {
        view->verticalHeader()->setDefaultSectionSize(GetSettings().rowsHeight);
    }
}

CustomTableModel* TableConfigurator::CreateNewModel()
{
    return new CustomTableModel(GetSettings());
}

void TableConfigurator::CreateModel()
{
    TableSettings& s = GetSettings();
    model = CreateNewModel();
    model->setTable(s.name);

    foreach (int col, GetSettings().relations.keys()) {
        model->setRelation(col, QSqlRelation(s.relations[col].first, /* table name */
                                             "id",
                                             s.relations[col].second /* field to show */));
        int i = model->relationModel(col)->fieldIndex(s.relations[col].second);
        model->relationModel(col)->setSort(i, Qt::AscendingOrder);
        model->relationModel(col)->sort(i, Qt::AscendingOrder);
    }

    for (int i = 0; i < s.colomnAliases.size(); ++i) {
        model->setHeaderData(i, Qt::Horizontal, s.colomnAliases[i]);
    }
}

void TableConfigurator::Initialize()
{
    CreateModel();
    model->setSort(0, Qt::AscendingOrder);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    CreateView();
    CreateDialog();
}

void TableConfigurator::CreateDialog()
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

void TableConfigurator::OpenDialog()
{
    card->SetCurrentIndex(view->currentIndex().row());
    dialog->show();
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

void TableConfigurator::Refresh()
{
    model->select();
    for (int i = 0; i < model->columnCount(); ++i) {
        if (model->relationModel(i)) {
            model->relationModel(i)->select();
        }
    }
    CustomizeView();
}

void TableConfigurator::Revert()
{
// HACK: since where is no simple api to save editable data in table
    view->setDisabled( true );
    view->setDisabled( false );
    model->revertAll();
}

void TableConfigurator::Submit()
{
// HACK: since where is no simple api to save editable data in table
    view->setDisabled( true );
    view->setDisabled( false );

    if (!model->submitAll()) {
        // :TODO: show only usefull messages for users
        // :TODO: save errors in logs
        QMessageBox::critical(0, qApp->tr("Cannot perform commit"),
                              model->lastError().text(), QMessageBox::Cancel);
    }
}
