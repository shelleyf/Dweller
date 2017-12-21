#ifndef JSONFILEREADER_H
#define JSONFILEREADER_H
#include <QJsonObject>
#include <QJsonArray>
#include <QPoint>
#include <QColor>

#include "lib/draw/device.h"
#include "lib/draw/door.h"
#include "lib/draw/wall.h"
#include "lib/draw/floor.h"
#include "lib/draw/window.h"


class JsonFileReader
{
public:
    JsonFileReader();

    void setup();
    bool read();

private:
    Device *readDevice(const QJsonObject &device);
    Door *readDoor(const QJsonObject &door);
    Wall *readWall(const QJsonObject &wall);
    Floor *readFloor(const QJsonObject &floor);


};

#endif // JSONFILEREADER_H
