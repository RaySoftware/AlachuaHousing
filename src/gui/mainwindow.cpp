#include <QNetworkInformation>
#include <QMessageBox>
#include <QGeoView/QGVMap.h>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "searchframe.h"
#include "selectedpropertyframe.h"
#include <QWindow>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/icon.ico"));
    this->setWindowState(Qt::WindowMaximized);

    // Check if there is an internet connection, warn the user if there is none
    QNetworkInformation::loadDefaultBackend();
    QNetworkInformation* netInfo = QNetworkInformation::instance();

    if (netInfo->reachability() != QNetworkInformation::Reachability::Online)
    {
        QMessageBox msg = QMessageBox(this->parentWidget());
        QMessageBox::warning(this->parentWidget(),
                             "No internet connection",
                             "No internet connection detected. The Alachua County map will not load.",
                             QMessageBox::StandardButton::Ok);
    }
    // Create a widget container for all the frames required
    this->mainWidget = new QWidget(this);
    // Level 1 layout (main)
    this->mainLayout = new QHBoxLayout(this);
    this->setCentralWidget(mainWidget);

    // Level 2 layout (search and property selection frames)
    this->mapInfoLayout = new QVBoxLayout();

    // Create level 1-2 layout widgets/frames
    this->mapFrame = new MapFrame();
    this->mapFrame->setParent(this);
    this->searchFrame = new SearchFrame();
    this->selectedPropertyFrame = new SelectedPropertyFrame();

    // Map resides in the level 1 layout, other frames are level 2
    this->mainLayout->addWidget(mapFrame->getMap());
    this->mapInfoLayout->addWidget(searchFrame);
    this->mapInfoLayout->addWidget(selectedPropertyFrame);

    this->mainLayout->addLayout(mapInfoLayout);
    this->mainWidget->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->searchFrame;
    delete this->selectedPropertyFrame;
    delete this->mapFrame;
    delete this->mapInfoLayout;
    delete this->mainLayout;
    delete this->mainWidget;
}

