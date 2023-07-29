#include <QNetworkInformation>
#include <QMessageBox>
#include <QGeoView/QGVWidget.h>
#include <QGeoView/QGVMap.h>
#include <QGeoView/QGVImage.h>
#include <QGeoView/QGVDrawItem.h>
#include "mapframe.h"
#include "mappin.h"

MapFrame::MapFrame()
{
    QGV::setNetworkManager(new QNetworkAccessManager());
    this->map = new QGVMap(this);
    // Set the camera to the center of Alchua Count with a scale factor that emcompasses it
    this->map->cameraTo(QGVCameraActions(map).moveTo(QGV::GeoPos(29.7536, -82.5712)).scaleBy(0.013));

    // Initialize two QGVLayer types to eparate the osm layer and pin layers
    this->osm = new QGVLayerOSM();
    this->pinLayer = new QGVLayer();
    // Add the OSM layer to the map layer
    this->map->addItem(this->osm);
}

QGVMap* MapFrame::getMap()
{
    return this->map;
}

MapFrame::~MapFrame()
{
    // Clear all pins created originally and clear its vector
    for (int i = 0; i < this->pins.size(); i++)
    {
        delete this->pins[i];
    }
    this->pins.clear();
    delete pinLayer;
    delete osm;
    delete map;
}
