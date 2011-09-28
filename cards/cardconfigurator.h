#ifndef CARDCONFIGURATOR_H
#define CARDCONFIGURATOR_H

#include <QObject>
#include <QtSql>
#include <QtGui>
#include "updatablelabel.h"

class CardConfigurator : public QObject
{
    Q_OBJECT
public:
    explicit CardConfigurator(QSqlRelationalTableModel* model, QObject *parent = 0);

    virtual void SetCurrentIndex(int row) { mapper->setCurrentIndex(row); }
    QLayout* GetLayout() { return layout; }

protected:
    QLayout* layout;
    QDataWidgetMapper* mapper;
    QSqlRelationalTableModel* model;

    virtual void CreateLayout() = 0;

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

protected:
    virtual void CreateLayout();

private:
    QPixmap* photoPixmap;
    UpdatableLabel* photoLabel;

public slots:
    void Submit();
    void Revert();
};

#endif // CARDCONFIGURATOR_H
