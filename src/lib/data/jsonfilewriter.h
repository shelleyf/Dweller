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

    void setup(GlobalCanvasData *mainCanvas);
    bool write(const std::string &fileDir);

private:
    Device *writeDevice(const QJsonObject &device);
    Door *writeDoor(const QJsonObject &door);
    Wall *writeWall(const QJsonObject &wall);
    Floor *writeFloor(const QJsonObject &floor);
    Window *writeWindow(const QJsonObject &window);

    GlobalCanvasData m_Data;
};

#endif // JSONFILEWRITER_H
