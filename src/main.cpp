#include "mainwindow.h"
#include "simulatewindow.h"
#include <QApplication>

void setStyleSheet(const QString &style){
    QFile qss(style);
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //qmlRegisterType<HouseItem>("HouseItem",1,0,"HouseItem");

    setStyleSheet(":style.qss");

    MainWindow w;
    w.show();
    return a.exec();
}

