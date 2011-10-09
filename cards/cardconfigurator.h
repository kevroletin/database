#ifndef CARDCONFIGURATOR_H
#define CARDCONFIGURATOR_H

#include <QObject>
#include "applicationsettings.h"
#include "updatablelabel.h"

QT_BEGIN_NAMESPACE
class QDataWidgetMapper;
class QLayout;
class QSqlRelationalTableModel;
class QVBoxLayout;
QT_END_NAMESPACE

class CardConfigurator : public QObject
{
    Q_OBJECT
public:
    explicit CardConfigurator(QSqlRelationalTableModel* model, QObject *parent = 0);

    virtual void SetCurrentIndex(int row) { mapper->setCurrentIndex(row); }
    QLayout* GetLayout() { return layout; }
    virtual Tables GetTable() = 0;

protected:
    QLayout* layout;
    QDataWidgetMapper* mapper;
    QSqlRelationalTableModel* model;

    virtual void CreateLayout();
    QComboBox* CreateComboBox(int colIndex, QString& fieldToShow);
    QLineEdit* CreateEdit(int colIndex);
    QVBoxLayout* CreatePotoControls(int colIndex);

signals:

public slots:
    void Submit() { mapper->submit(); }
    void Revert() { mapper->submit(); }
};

class CarsCard : public CardConfigurator
{
    Q_OBJECT
public:
    CarsCard(QSqlRelationalTableModel* model, QObject *parent = 0);
    virtual Tables GetTable() { return TABLE_CARS; }
};

class CustomersCard : public CardConfigurator
{
    Q_OBJECT
public:
    CustomersCard(QSqlRelationalTableModel* model, QObject *parent = 0);
    virtual Tables GetTable() { return TABLE_CUSTOMERS; }
};

class LicensesCard : public CardConfigurator
{
    Q_OBJECT
public:
    LicensesCard(QSqlRelationalTableModel* model, QObject *parent = 0);
    virtual Tables GetTable() { return TABLE_LICENSES; }
};

class PassportsCard : public CardConfigurator
{
    Q_OBJECT
public:
    PassportsCard(QSqlRelationalTableModel* model, QObject *parent = 0);
    virtual Tables GetTable() { return TABLE_PASSPORTS; }
};


#endif // CARDCONFIGURATOR_H
