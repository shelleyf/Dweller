#ifndef JSONFILEREADER_H
#define JSONFILEREADER_H
#include <QJsonObject>
#include <QJsonArray>
#include <QPoint>
#include <QColor>
#include <QFile>
#include <QJsonDocument>

#include "lib/draw/device.h"
#include "lib/draw/door.h"
#include "lib/draw/wall.h"
#include "lib/draw/floor.h"
#include "lib/draw/window.h"
#include "lib/data/globalcanvasdata.h"


class JsonFileReader
{
public:
    JsonFileReader();
    ~JsonFileReader();

    void setup(GlobalCanvasData *mainCanvas);
    bool read(const std::string &fileDir);

private:
    Device *readDevice(const QJsonObject &device);
    Door *readDoor(const QJsonObject &door);
    Wall *readWall(const QJsonObject &wall);
    Floor *readFloor(const QJsonObject &floor);
    Window *readWindow(const QJsonObject &window);

    GlobalCanvasData *m_GlobalCanvasData;
    QJsonDocument *m_Doc;
};

#endif // JSONFILEREADER_H
