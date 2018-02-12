#ifndef JSONFILEWRITER_H
#define JSONFILEWRITER_H
#include <QJsonObject>
#include <QJsonArray>
#include <QPoint>
#include <QColor>
#include "lib/draw/device.h"
#include "lib/draw/door.h"
#include "lib/draw/wall.h"
#include "lib/draw/floor.h"
#include "lib/draw/window.h"
#include "lib/data/globalcanvasdata.h"

class JsonFileWriter
{
public:
    JsonFileWriter();
    ~JsonFileWriter();


    void setup(GlobalCanvasData *mainCanvas);
    bool write(const std::string &fileDir);

private:
    QJsonObject writeDevice(HouseItem *device);
    QJsonObject writeDoor(HouseItem *door);
    QJsonObject writeWall(HouseItem *wall);
    QJsonObject writeFloor(HouseItem *floor);
    QJsonObject writeWindow(HouseItem *window);

    GlobalCanvasData *m_Data;
    QJsonDocument *m_Doc;
};

#endif // JSONFILEWRITER_H
