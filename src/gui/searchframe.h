#ifndef SEARCHFRAME_H
#define SEARCHFRAME_H

#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QTableWidget>

class SearchFrame : public QFrame
{
    QVBoxLayout* searchFrameLayout;

    QHBoxLayout* searchSectionLayout, *propertyTypeLayout, *algorithmLayout;

    QLabel* searchLabel, *propertyTypeLabel, *advancedLabel;

    QLineEdit* searchBox;

    QPushButton* searchButton;

    QButtonGroup* propertySelection, *advancedSelection;

    QRadioButton* residentialButton, *nonResidentialButton, *bothButton, *quickSortButton,
        *mergeSortButton;

    QTableWidget* propertyTable;
public:
    SearchFrame();
    ~SearchFrame();
};

#endif // SEARCHFRAME_H
