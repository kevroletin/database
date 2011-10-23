#include "tableconfigurator.h"
#include "cards/cardconfigurator.h"


PassportsModel::PassportsModel(TableSettings& _tableSet_, QObject * parent, QSqlDatabase db) :
    CustomTableModel(_tableSet_, parent, db)
{
}

QVariant PassportsModel::data(const QModelIndex &item, int role) const
{
    if ((role == Qt::DisplayRole || role == Qt::EditRole)  && item.column() == 6) {
        QVariant value = CustomTableModel::data(item, role);
        return value.toBool() ? tr("man") : tr("woman");
    }
    return CustomTableModel::data(item, role);
}

bool PassportsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if ((role == Qt::DisplayRole || role == Qt::EditRole)  && index.column() == 6) {
        // TODO:
        return CustomTableModel::setData(index, !QRegExp("^(W|w).*$").exactMatch(value.toString()), role);
    }
}

PassportsTable::PassportsTable(DbActionsToolbar* dbActTb, QObject*) :
    TableConfigurator(dbActTb)
{
    Initialize();
}

void PassportsTable::CreateCard()
{
    card = new PassportsCard(model);
}
