#include "mappin.h"

MapPin::MapPin(QGV::GeoPos pos, MapPin::pinType type)
{
    // Check which pin type is intended, load the correct pin image
    switch (type)
    {
    case (MapPin::pinType::RED):
        this->loadImage(QImage(":/images/redpin.png"));
        break;
    case (MapPin::pinType::GREEN):
        this->loadImage(QImage(":/images/greenpin.png"));
        break;
    case (MapPin::pinType::BLUE):
        this->loadImage(QImage(":/images/blue.png"));
        break;
    default:
        this->loadImage(QImage(":/images/blue.png"));
        break;
    }

    // Set proper transformation and flags
    this->setGeometry(pos, QSize(24, 32), QPoint(16, 32));
    this->setFlags(QGV::ItemFlag::Transformed);
    this->setFlags(QGV::ItemFlag::Clickable);
    this->setFlags(QGV::ItemFlag::IgnoreScale);
    this->setSelectable(true);
}

void MapPin::changeType(MapPin::pinType type)
{
    // Reload the image of MapPin to the intended image
    switch (type)
    {
    case (MapPin::pinType::RED):
        this->loadImage(QImage(":/images/redpin.png"));
        break;
    case (MapPin::pinType::GREEN):
        this->loadImage(QImage(":/images/greenpin.png"));
        break;
    case (MapPin::pinType::BLUE):
        this->loadImage(QImage(":/images/blue.png"));
        break;
    default:
        this->loadImage(QImage(":/images/blue.png"));
        break;
    }
}

Property *MapPin::getPinnedProperty()
{
    return this->pinnedProperty;
}
