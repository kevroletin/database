#ifndef APPLICATIONSETTINGS_H
#define APPLICATIONSETTINGS_H

#include <QObject>
#include <QtCore>

const int TablesCount = 2;
enum Tables {
    TABLE_CARS,
    TABLE_CUSTOMERS
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
    explicit ApplicationSettings(QObject *parent = 0);
    TableSettings& Table(Tables table) { return tableSettings[table]; }

private:
    TableSettings tableSettings[TablesCount];
    inline Relation rl(QString table, QString name_field);
    void ConfigureCarsTable();
    void ConfigureCustomersTable();

signals:

public slots:

};

extern ApplicationSettings globalSettings;

#endif // APPLICATIONSETTINGS_H
