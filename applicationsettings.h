#ifndef APPLICATIONSETTINGS_H
#define APPLICATIONSETTINGS_H

#include <QObject>
#include <QtCore>
#include <QSettings>

const int TablesCount = 9;
enum Tables {
    TABLE_CARS,
    TABLE_COMPANIES,
    TABLE_METAL_COSTS,
    TABLE_METAL_DEALS,
    TABLE_METAL_ITEMS,
    TABLE_METAL_MARKS,
    TABLE_CUSTOMERS,
    TABLE_LICENSES,
    TABLE_PASSPORTS
    /* Do not forgot to update TablesCount */
};

enum ControlTypes {
    CONTROL_COMBO_BOX,
    CONTROL_EDIT,
    CONTROL_NONE,
    CONTROL_PHOTO
};

typedef QPair<QString, QString> Relation;

struct TableSettings
{
      QString alias;
      QString name;
      QStringList colomnAliases;
      QVector<int> colonmSizes;
      QHash<int, Relation> relations;
      QVector<ControlTypes> ui_controls;
      QSet<int> colomnsToDraw;
      int rowsHeight;
      TableSettings() : rowsHeight(0) {}
};

class ApplicationSettings : public QObject
{
    Q_OBJECT
public:
    QSettings iniSettings;

    ApplicationSettings(QObject *parent = 0);
    TableSettings& Table(Tables table) { return tableSettings[table]; }

private:
    TableSettings tableSettings[TablesCount];
    inline Relation rl(QString table, QString name_field);
    void ConfigureCarsTable();
    void ConfigureCustomersTable();
    void ConfigureLicensesTable();
    void ConfigurePassportsTable();
    void ConfigureCompaniesTable();
    void ConfigureMetalCostTable();
    void ConfigureMetalDealTable();
    void ConfigureMetalItemsTable();
    void ConfigureMetalMarkTable();

signals:

public slots:

};

extern ApplicationSettings globalSettings;

#endif // APPLICATIONSETTINGS_H
