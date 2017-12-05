#ifndef SIMULATEWINDOW_H
#define SIMULATEWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QPushButton>
#include <QDesktopWidget>
#include <QApplication>
#include <QMessageBox>
#include <QComboBox>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QCheckBox>

#include "lib\ui\simulatewidget.h"

class SimulateWindow : public QMainWindow
{
    Q_OBJECT

public:
    SimulateWindow();

private slots:
    void on_startSimulate();

private:
    void createItem();
    QSlider * createSlider();
    void loadUI();

    //UI layout
    QHBoxLayout *container;
    QVBoxLayout *viewLayout;
    QVBoxLayout *controllLayout;

    //view
    SimulateWidget *sWidget;

    //simulate controll
    QLabel *showTime;
    QLabel *timeLabel;
    QLabel *setPmLabel;
    QLineEdit *setPm;
    QHBoxLayout *cButtonGroup;
    QLabel *controllLabel;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;

    //environment setting
    QHBoxLayout *envLayout;

    QLabel *environmentLabel;
    QComboBox *modeBox;
    QLabel *setXLabel;
    QSlider *xslider;
    QLabel *setYLabel;
    QSlider *yslider;
    QLabel *setZLabel;
    QSlider *zslider;

    //function setting
    QVBoxLayout *funcLayout;
    QLabel *funcLabel;
    QCheckBox *funcBox[6];
};

#endif // SIMULATEWINDOW_H
