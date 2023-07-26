#ifndef SELECTEDPROPERTYFRAME_H
#define SELECTEDPROPERTYFRAME_H

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>

class SelectedPropertyFrame : public QFrame
{
    QVBoxLayout* selectedPropertyLayout;

    QVector<QHBoxLayout*> propertyAttributeLayouts;

    QVector<QLabel*> propertyAttributeLabels;

    QVector<QLabel*> propertyAttributeIconLabels;
public:
    SelectedPropertyFrame();
    ~SelectedPropertyFrame();
};

#endif // SELECTEDPROPERTYFRAME_H
