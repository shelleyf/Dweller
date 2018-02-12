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

private:
    QList<HouseItem *> m_Data;
    QJsonObject json;
};

#endif // GLOBALCANVASDATA_H
