#ifndef DOOR_H
#define DOOR_H

#include "houseitem.h"

class Door : public HouseItem
{
public:
    Door();

    void setDoorColor(QColor &val);
    void setDoorThickness(int &val);
    void draw(QPainter *painter) override;

    QRect getBoundary() override;
    bool contains(int x, int y) override;

    QPoint getStartPoint();
    void setStartPoint(QPoint value);

    QPoint getEndPoint();
    void setEndPoint(QPoint value);

    int getDoorHeight();
    void setDoorHeight(int height);

    float getDoorLeakage();
    void setDoorLeakage(float leakage);

protected:
    QColor m_DoorColor;
    QPoint m_Doorstart;
    QPoint m_DoorEnd;
    int m_DoorThickness;
    int m_DoorHeight;
    float m_DoorLeakage;

};

#endif // DOOR_H
