#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGeoView/QGVMap.h>
#include "searchframe.h"
#include "selectedpropertyframe.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);

    // Create a widget container for all the frames required
    mainWidget = new QWidget(this);
    // Level 1 layout (main)
    mainLayout = new QHBoxLayout(this);
    this->setCentralWidget(mainWidget);

    // Level 2 layout (search and property selection frames)
    mapInfoLayout = new QVBoxLayout();

    // Create level 1-2 layout widgets/frames
    map = new QGVMap();
    searchFrame = new SearchFrame();
    selectedPropertyFrame = new SelectedPropertyFrame();

    // Map resides in the level 1 layout, other frames are level 2
    mainLayout->addWidget(map);
    mapInfoLayout->addWidget(searchFrame);
    mapInfoLayout->addWidget(selectedPropertyFrame);

    mainLayout->addLayout(mapInfoLayout);
    mainWidget->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->searchFrame;
    delete this->selectedPropertyFrame;
    delete this->map;
    delete this->mapInfoLayout;
    delete this->mainLayout;
    delete this->mainWidget;

}

