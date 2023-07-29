#ifndef MAPPIN_H
#define MAPPIN_H
#include <QGeoView/QGVDrawItem.h>
#include <QGeoView/QGVImage.h>
#include "property.h"

class MapPin : public QGVImage
{
    Property* pinnedProperty;

public:
    enum pinType {RED, GREEN, BLUE};

    MapPin(QGV::GeoPos pos, MapPin::pinType type);

    void changeType(MapPin::pinType type);

    Property* getPinnedProperty();
};

#endif // MAPPIN_H
