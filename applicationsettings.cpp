#include "applicationsettings.h"

ApplicationSettings globalSettings;

ApplicationSettings::ApplicationSettings(QObject *parent) :
    QObject(parent),
    iniSettings("settings.ini", QSettings::IniFormat)
{   
    ConfigureCarsTable();
    ConfigureCustomersTable();
    ConfigureLicensesTable();
    ConfigurePassportsTable();
    ConfigureCompaniesTable();
    ConfigureMetalCostTable();
    ConfigureMetalDealTable();
    ConfigureMetalItemsTable();
    ConfigureMetalMarkTable();
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
    t->relations[1] = rl("customer_passports", "name");
    t->ui_controls << CONTROL_EDIT
                   << CONTROL_COMBO_BOX
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
                   << 100
                   << 250;
    t->colomnAliases << tr("Id")
                     << tr("Owner")
                     << tr("License")
                     << tr("Company");

    t->relations[1] = rl("customer_passports", "name");
    t->relations[2] = rl("licenses", "serial_number");
    t->relations[3] = rl("companies", "name");
    t->ui_controls << CONTROL_EDIT
                   << CONTROL_COMBO_BOX
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

void ApplicationSettings::ConfigureCompaniesTable()
{
    TableSettings* t = &tableSettings[TABLE_COMPANIES];

    t->name = "companies";
    t->alias = tr("Companies");
    t->colonmSizes << 40;
    t->colomnAliases << tr("Id")
                     << tr("Name")
                     << tr("INN")
                     << tr("KPP")
                     << tr("Legal adress")
                     << tr("Actual adress")
                     << tr("Settlement account")
                     << tr("Bank")
                     << tr("Correspondent account")
                     << tr("Phone")
                     << tr("BIK");
    t->ui_controls << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT;
}
void ApplicationSettings::ConfigureMetalCostTable()
{
    TableSettings* t = &tableSettings[TABLE_METAL_COSTS];

    t->name = "metal_costs";
    t->alias = tr("Metal cost");
    t->colonmSizes << 40
                   << 100
                   << 100;
    t->colomnAliases << tr("Id")
                     << tr("Value")
                     << tr("Data");
    t->ui_controls << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_EDIT;
}
void ApplicationSettings::ConfigureMetalDealTable()
{
    TableSettings* t = &tableSettings[TABLE_METAL_DEALS];

    t->name = "metal_deals";
    t->alias = tr("Metal deal");
    t->colonmSizes << 40
                   << 100
                   << 100;
    t->colomnAliases << tr("Id")
                     << tr("Customer")
                     << tr("Timestamp")
                     << tr("Money");
    t->relations[1] = rl("customer_passports", "name");
    t->ui_controls << CONTROL_EDIT
                   << CONTROL_COMBO_BOX
                   << CONTROL_EDIT
                   << CONTROL_EDIT;
}
void ApplicationSettings::ConfigureMetalItemsTable()
{
    TableSettings* t = &tableSettings[TABLE_METAL_ITEMS];

    t->name = "metal_items";
    t->alias = tr("Metal items");
    t->colonmSizes << 40
                   << 100
                   << 100
                   << 100
                   << 100;
    t->colomnAliases << tr("Id")
                     << tr("Deal id")
                     << tr("Coast")
                     << tr("Mark")
                     << tr("Weight")
                     << tr("Radioctivity");
    t->relations[1] = rl("metal_deals", "id");
    t->relations[2] = rl("metal_costs", "value");
    t->relations[3] = rl("metal_marks", "name");
    t->ui_controls << CONTROL_EDIT
                   << CONTROL_COMBO_BOX
                   << CONTROL_COMBO_BOX
                   << CONTROL_COMBO_BOX
                   << CONTROL_EDIT
                   << CONTROL_EDIT;
//    t->rowsHeight = 50;
}
void ApplicationSettings::ConfigureMetalMarkTable()
{
    TableSettings* t = &tableSettings[TABLE_METAL_MARKS];

    t->name = "metal_marks";
    t->alias = tr("Metal_mark");
    t->colonmSizes << 40
                   << 200
                   << 200
                   << 50;
    t->colomnAliases << tr("Id")
                     << tr("Name")
                     << tr("Cost")
                     << tr("Color");
    t->relations[2] = rl("metal_costs", "value");
    t->ui_controls << CONTROL_EDIT
                   << CONTROL_EDIT
                   << CONTROL_COMBO_BOX
                   << CONTROL_EDIT;
}
