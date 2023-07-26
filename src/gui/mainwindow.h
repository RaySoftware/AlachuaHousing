#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGeoView/QGVMap.h>
#include "searchframe.h"
#include "selectedpropertyframe.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QGVMap* map;

    QWidget* mainWidget;

    QHBoxLayout* mainLayout;

    QVBoxLayout* mapInfoLayout;

    SearchFrame* searchFrame;

    SelectedPropertyFrame* selectedPropertyFrame;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
