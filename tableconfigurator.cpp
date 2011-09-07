#include "tableconfigurator.h"

TableConfigurator::TableConfigurator(QObject* parent) :
    QObject(parent)
{
}

QTableView* TableConfigurator::CreateView()
{
    QTableView *view = new QTableView;
    view->setModel(model);
    view->setItemDelegate(new QSqlRelationalDelegate(view));
//    view->setWindowTitle(GetTitle());

    return view;
}

PeopleTable::PeopleTable(QObject*)
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

    model->select();
}
