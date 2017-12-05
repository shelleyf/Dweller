#include "simulatewindow.h"

SimulateWindow::SimulateWindow()
{
    createItem();
    loadUI();

}

void SimulateWindow::on_startSimulate(){
    Sleep(100);
}

void SimulateWindow::createItem(){
    controllLabel = new QLabel;
    controllLabel->setText(tr("Simulator"));
    timeLabel = new QLabel;
    timeLabel->setText(tr("Timer"));
    showTime = new QLabel;
    showTime->setText(tr("00:00:00"));
    setPmLabel = new QLabel;
    setPmLabel->setText(tr("Set Pm"));
    environmentLabel = new QLabel;
    environmentLabel->setText(tr("Controll"));
    setXLabel = new QLabel;
    setXLabel->setText(tr("Camera X position"));
    setYLabel = new QLabel;
    setYLabel->setText(tr("Camera Y position"));
    setZLabel = new QLabel;
    setZLabel->setText(tr("Camera Z position"));
    funcLabel = new QLabel;
    funcLabel->setText(tr("Settings"));

    setPm = new QLineEdit;

    startButton = new QPushButton;
    startButton->setIcon(QIcon(":/res/simulator_start.png"));
    startButton->setStatusTip(tr("start"));
    connect(startButton, SIGNAL(triggered()), this, SLOT(on_startSimulate()));
    pauseButton = new QPushButton;
    pauseButton->setIcon(QIcon(":/res/simulator_pause.png"));
    pauseButton->setStatusTip(tr("pause"));
    stopButton = new QPushButton;
    stopButton->setIcon(QIcon(":/res/simulator_stop.png"));
    stopButton->setStatusTip(tr("stop"));

    modeBox = new QComboBox;
    modeBox->addItem(tr("heatExchange"));
    modeBox->addItem(tr("internalRecycle"));
    modeBox->addItem(tr("unidirectionalAirflow"));

    xslider = createSlider();
    yslider = createSlider();
    zslider = createSlider();

    cButtonGroup = new QHBoxLayout;
    cButtonGroup->addWidget(startButton);
    cButtonGroup->addWidget(pauseButton);
    cButtonGroup->addWidget(stopButton);

    int xpos = 0;
    int ypos = 0;
    funcBox[0] = new QCheckBox("show wind flow");
    funcBox[0]->setGeometry(xpos , ypos, 100, 30);
    funcBox[1] = new QCheckBox("trace");
    funcBox[1]->setGeometry(xpos+120 , ypos, 100, 30);
    funcBox[2] = new QCheckBox("structural line mode");
    funcBox[2]->setGeometry(xpos , ypos+40, 100, 30);
    funcBox[3] = new QCheckBox("function 4");
    funcBox[3]->setGeometry(xpos+120 , ypos+40, 100, 30);
    funcBox[4] = new QCheckBox("function 5");
    funcBox[4]->setGeometry(xpos , ypos+80, 100, 30);
    funcBox[5] = new QCheckBox("function 6");
    funcBox[5]->setGeometry(xpos+120 , ypos+80, 100, 30);

    funcLayout = new QVBoxLayout;
    funcLayout->addWidget(funcLabel);
    int i=0;
    for(i=0;i<3;i++){
        funcLayout->addWidget(funcBox[i]);
    }
}

void SimulateWindow::loadUI(){
    QWidget *widget = new QWidget;

    QQuickView *view = new QQuickView;
    view->setSource(QUrl("qrc:/simulator.qml"));
    view->show();
    QWidget *mWidget;
    mWidget = QWidget::createWindowContainer(view);

    container = new QHBoxLayout(widget);
    viewLayout = new QVBoxLayout;
    controllLayout = new QVBoxLayout;

    container->addLayout(viewLayout);
    container->addLayout(controllLayout);

    //viewLayout->addWidget(sWidget);
    viewLayout->addWidget(mWidget);


    controllLayout->addWidget(timeLabel);
    controllLayout->addWidget(showTime);
    controllLayout->addWidget(controllLabel);
    controllLayout->addLayout(cButtonGroup);
    controllLayout->addWidget(setPmLabel);
    controllLayout->addWidget(setPm);
    controllLayout->addWidget(environmentLabel);
    controllLayout->addWidget(modeBox);
    controllLayout->addWidget(setXLabel);
    controllLayout->addWidget(xslider);
    controllLayout->addWidget(setYLabel);
    controllLayout->addWidget(yslider);
    controllLayout->addWidget(setZLabel);
    controllLayout->addWidget(zslider);
    controllLayout->addWidget(funcLabel);
    controllLayout->addLayout(funcLayout);

    setLayout(container);
    setWindowTitle(tr("simulator"));
    widget->show();
}

QSlider * SimulateWindow::createSlider(){
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 360);
    slider->setSingleStep(1);
    slider->setPageStep(10);
    slider->setTickInterval(10);
    slider->setTickPosition(QSlider::TicksAbove);
    return slider;
}
