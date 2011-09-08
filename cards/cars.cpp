#include "cars.h"

CarsCardLayout::CarsCardLayout(QWidget *parent) :
    QGridLayout(parent)
{
    nameLabel = new QLabel("Name");
    nameText = new QLineEdit;

    setColumnStretch(1, 2);
    addWidget(nameLabel, 0, 0);
    addWidget(nameText, 0, 1);
}
