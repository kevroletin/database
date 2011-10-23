#include "applicationsettings.h"

ApplicationSettings globalSettings;

ApplicationSettings::ApplicationSettings(QObject *parent) :
    QObject(parent)
{   
    ConfigureCarsTable();
    ConfigureCustomersTable();
    ConfigureLicensesTable();
    ConfigurePassportsTable();
}

Relation ApplicationSettings::rl(QString table, QString name_field)
{
    return Relation(table, name_field);
}

void ApplicationSettings::ConfigureCarsTable()
{
    TableSettings* t = &tableSettings[TABLE_CARS];

    t->name = "cars";
    t->alias = tr("Cars");
    t->colonmSizes << 40
                   << 300
                   << 100
                   << 100
                   << 50
                   << 50;
    t->colomnAliases << tr("Id")
                     << tr("Owner")
                     << tr("Brand")
                     << tr("Serial number")
                     << tr("Photo")
                     << tr("Number photo");
    t->relations[1] = rl("passports", "name");
    t->ui_controls << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_PHOTO
                   << CONTROL_PHOTO;
    t->colomnsToDraw << 4 << 5;
//    t->rowsHeight = 50;
}

void ApplicationSettings::ConfigureCustomersTable()
{
    TableSettings* t = &tableSettings[TABLE_CUSTOMERS];

    t->name = "customers";
    t->alias = tr("Customers");

    t->colonmSizes << 40
                   << 250
                   << 250;
    t->colomnAliases << tr("Id")
                     << tr("Owner")
                     << tr("License");
    t->relations[1] = rl("passports", "name");
    t->relations[2] = rl("licenses", "serial_number");
    t->ui_controls << CONTROL_EDIT
                   << CONTROL_COMBO_BOX
                   << CONTROL_COMBO_BOX;
}

void ApplicationSettings::ConfigureLicensesTable()
{
    TableSettings* t = &tableSettings[TABLE_LICENSES];

    t->name = "licenses";
    t->alias = tr("Licenses");
    t->colonmSizes << 40
                   << 300;
    t->colomnAliases << tr("Id")
                     << tr("Owner")
                     << tr("Serial number")
                     << tr("Photo");
    t->ui_controls << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_PHOTO;
    t->colomnsToDraw << 3;
}

void ApplicationSettings::ConfigurePassportsTable()
{
    TableSettings* t = &tableSettings[TABLE_PASSPORTS];

    t->name = "passports";
    t->colonmSizes << 40
                   << 300;
    t->alias = tr("Passports");

    t->colomnAliases << tr("Id")
                     << tr("Full name")
                     << tr("Serial number")
                     << tr("Issue date")
                     << tr("Birth date")
                     << tr("Birth place")
                     << tr("Gender")
                     << tr("Given by unit(name)")
                     << tr("Given by unit(code)")
                      << tr("Photo");
    t->ui_controls << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_PHOTO;
    t->colomnsToDraw << 9;
}
