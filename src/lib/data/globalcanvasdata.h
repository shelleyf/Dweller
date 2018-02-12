#ifndef GLOBALCANVASDATA_H
#define GLOBALCANVASDATA_H

#include "lib/draw/houseitem.h"
class GlobalCanvasData
{
public:
    GlobalCanvasData();
    void add(HouseItem *item);
    void remove(int index);
    void clear();
    HouseItem * find(QString string);

    QList<HouseItem *> m_Data;
    QJsonObject m_Json;
};

#endif // GLOBALCANVASDATA_H
