#include "searchframe.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QHeaderView>

SearchFrame::SearchFrame()
{

    // L1 LAYOUT (search panel)
    this->searchFrameLayout = new QVBoxLayout(this);

    // ======= Search section =======
    // L2 LAYOUT (search bar)
    this->searchSectionLayout = new QHBoxLayout();
    this->searchLabel = new QLabel("Search");
    this->searchBox = new QLineEdit();
    this->searchButton = new QPushButton("Search");

    this->searchSectionLayout->addWidget(this->searchLabel);
    this->searchSectionLayout->addWidget(this->searchBox);
    this->searchSectionLayout->addWidget(this->searchButton);

    this->searchFrameLayout->addLayout(searchSectionLayout);

    // ======= Property type section =======
    this->propertyTypeLayout = new QHBoxLayout();

    this->propertyTypeLabel = new QLabel("Property Type");
    this->propertySelection = new QButtonGroup();
    this->residentialButton = new QRadioButton("Residential");
    this->nonResidentialButton = new QRadioButton("Non-Residential");
    this->bothButton = new QRadioButton("Both");

    this->propertySelection->addButton(this->residentialButton);
    this->propertySelection->addButton(this->nonResidentialButton);
    this->propertySelection->addButton(this->bothButton);

    this->propertyTypeLayout->addWidget(this->residentialButton);
    this->propertyTypeLayout->addWidget(this->nonResidentialButton);
    this->propertyTypeLayout->addWidget(this->bothButton);
    this->propertyTypeLayout->addStretch();
    this->searchFrameLayout->addWidget(this->propertyTypeLabel);
    this->searchFrameLayout->addLayout(this->propertyTypeLayout);

    // ======= Advanced section: Algorithm choice =======
    // L2 LAYOUT (algorithm button group)
    this->algorithmLayout = new QHBoxLayout();
    this->advancedSelection = new QButtonGroup();
    this->advancedLabel = new QLabel("Advanced");
    this->quickSortButton = new QRadioButton("Quick Sort");
    this->mergeSortButton = new QRadioButton("Merge Sort");

    this->advancedSelection->addButton(this->quickSortButton);
    this->advancedSelection->addButton(this->mergeSortButton);

    this->algorithmLayout->addWidget(this->quickSortButton);
    this->algorithmLayout->addWidget(this->mergeSortButton);
    this->algorithmLayout->addStretch();
    this->searchFrameLayout->addWidget(this->advancedLabel);
    this->searchFrameLayout->addLayout(this->algorithmLayout);

    // ======= Table section: Property results =======
    this->propertyTable = new QTableWidget();
    QStringList headerTitles = {"Market Value", "City", "Zip Code", "Year Built", "Address", "Property Type"};
    for (int i = 0; i < headerTitles.size(); i++)
        this->propertyTable->insertColumn(i);

    this->propertyTable->verticalHeader()->hide();
    this->propertyTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->propertyTable->setHorizontalHeaderLabels(headerTitles);
    this->searchFrameLayout->addWidget(propertyTable);
}

SearchFrame::~SearchFrame()
{
    // Search section
    delete searchLabel;
    delete searchBox;
    delete searchButton;

    // Property type section
    delete propertyTypeLabel;
    delete residentialButton;
    delete nonResidentialButton;
    delete bothButton;
    delete propertySelection;

    // Advanced section
    delete advancedLabel;
    delete quickSortButton;
    delete mergeSortButton;
    delete advancedSelection;

    // All layouts
    delete propertyTypeLayout;
    delete algorithmLayout;
    delete searchSectionLayout;
    delete searchFrameLayout;

    delete propertyTable;
}
