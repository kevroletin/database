#ifndef CARDCONFIGURATOR_H
#define CARDCONFIGURATOR_H

#include <QObject>
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

protected:
    QLayout* layout;
    QDataWidgetMapper* mapper;
    QSqlRelationalTableModel* model;

    virtual void CreateLayout() = 0;
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

protected:
    virtual void CreateLayout();

private:

public slots:
    void Submit();
    void Revert();
};

#endif // CARDCONFIGURATOR_H
