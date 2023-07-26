#include "selectedpropertyframe.h"

SelectedPropertyFrame::SelectedPropertyFrame()
{
    // L1 LAYOUT (property info panel)
    this->selectedPropertyLayout = new QVBoxLayout(this);

    QVector<QString> tempLabels = {
            "Selected Property",
            "Market Value: n/a",
            "City: n/a",
            "Zip Code: n/a",
            "Year Built: n/a",
            "Address: n/a",
            "Property Type: n/a"
    };

    // Load icon images from Qt's resources
    QVector<QPixmap> iconLabelPixmaps = {
            QPixmap(":/images/redpin.png"),
            QPixmap(":/images/money.png"),
            QPixmap(":/images/building.png"),
            QPixmap(":/images/gps.png"),
            QPixmap(":/images/clock.png"),
            QPixmap(":/images/house.png"),
            QPixmap(":/images/hammer.png"),
    };

    // Load L2 LAYOUT (property info pannel attributes)
    // There are 7 attributes including the panel header
    for (int i = 0; i < 7; i++)
    {
        propertyAttributeLayouts.emplaceBack(new QHBoxLayout());
        propertyAttributeLabels.emplaceBack(new QLabel(tempLabels[i]));
        propertyAttributeIconLabels.emplaceBack(new QLabel());

        propertyAttributeIconLabels[i]->setPixmap(QPixmap(iconLabelPixmaps[i]));
        propertyAttributeIconLabels[i]->setPixmap(propertyAttributeIconLabels[i]->pixmap().scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));

        // Add the header of the property info panel special formatting
        if (i == 0)
        {
            propertyAttributeLayouts[i]->addStretch();
            propertyAttributeIconLabels[i]->setPixmap(propertyAttributeIconLabels[i]->pixmap().scaled(24, 32, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

        }
        // Add the icon and the property attribute label on the current row
        propertyAttributeLayouts[i]->addWidget(propertyAttributeIconLabels[i]);
        propertyAttributeLayouts[i]->addWidget(propertyAttributeLabels[i]);
        propertyAttributeLayouts[i]->addStretch();
        selectedPropertyLayout->addLayout(propertyAttributeLayouts[i]);
    }

    propertyAttributeLayouts[0]->setAlignment(Qt::AlignCenter);
}
SelectedPropertyFrame::~SelectedPropertyFrame()
{
    for (int i = 0; i < 7; i++)
    {

        delete this->propertyAttributeIconLabels[i];
        delete this->propertyAttributeLabels[i];
        delete this->propertyAttributeLayouts[i];
    }
    this->propertyAttributeIconLabels.clear();
    this->propertyAttributeLabels.clear();
    this->propertyAttributeLayouts.clear();

    delete this->selectedPropertyLayout;
}
