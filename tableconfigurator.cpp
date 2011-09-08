#include "tableconfigurator.h"

TableConfigurator::TableConfigurator(DbActionsToolbar* _dbActTb_, QObject* parent) :
    QObject(parent),
    dbActTb(_dbActTb_)
{
}

QTableView* TableConfigurator::CreateView()
{
    view = new QTableView;
    view->setModel(model);
    view->setItemDelegate(new QSqlRelationalDelegate(view));
    view->setSelectionMode(QAbstractItemView::SingleSelection);

    return view;
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

PeopleTable::PeopleTable(DbActionsToolbar* dbActTb, QObject*) :
    TableConfigurator(dbActTb)
{
    model = new QSqlRelationalTableModel;
    model->setTable("employee");

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setRelation(2, QSqlRelation("city", "id", "name"));
    model->setRelation(3, QSqlRelation("country", "id", "name"));

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("City"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Country"));

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
}
