#ifndef MAPFRAME_H
#define MAPFRAME_H

#include <QFrame>
#include <QGeoView/QGVWidget.h>
#include <QGeoView/QGVMap.h>
#include <QGeoView/QGVLayerOSM.h>
#include <QGeoView/QGVImage.h>
#include "mappin.h"

class MapFrame : public QFrame
{
    QGVMap* map;

    QGVLayerOSM* osm;

    QGVLayer* pinLayer;

    QVector<MapPin*> pins;
public:
    QGVMap* getMap();

    MapFrame();

    ~MapFrame();
};

#endif // MAPFRAME_H
