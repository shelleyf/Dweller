#ifndef GLOBALCANVASDATA_H
#define GLOBALCANVASDATA_H
#include <QQmlListProperty>
#include <QObject>
#include <QJsonDocument>
#include <QJsonArray>

#include "lib/draw/houseitem.h"
#include "lib/draw/device.h"
#include "lib/draw/door.h"
#include "lib/draw/wall.h"
#include "lib/draw/floor.h"
#include "lib/draw/window.h"

class GlobalCanvasData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString testString READ testString)

public:
    GlobalCanvasData();

    QString testString(){
        return m_testString;
    }

    void add(HouseItem *item);
    void remove(int index);
    void clear();
    HouseItem * find(QString string);

    void convertJson();
    QJsonObject writeDevice(HouseItem *device);
    QJsonObject writeDoor(HouseItem *door);
    QJsonObject writeWall(HouseItem *wall);
    QJsonObject writeFloor(HouseItem *floor);
    QJsonObject writeWindow(HouseItem *window);

    QList<HouseItem *> m_Data;
    QJsonObject m_Json;

private:
    QString m_testString;

};

#endif // GLOBALCANVASDATA_H
