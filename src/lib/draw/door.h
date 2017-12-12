#ifndef DOOR_H
#define DOOR_H

#include "houseitem.h"

class Door : public HouseItem
{
public:
    Door();

    QPen getPen() override;
    void setPen(QColor color,int width) override;
    void draw(QPainter *painter) override;

    QRect getBoundary() override;
    bool contains(int x, int y) override;

    QPoint getStartPoint();
    void setStartPoint(QPoint value);

    QPoint getEndPoint();
    void setEndPoint(QPoint value);

    float getDoorHeight();
    void setDoorHeight(float height);

    float getDoorLeakage();
    void setDoorLeakage(float leakage);


protected:
    QColor m_DoorColor;
    QPoint m_Doorstart;
    QPoint m_DoorEnd;
    float m_DoorHeight;
    float m_DoorLeakage;

    QLine m_Line;


};

#endif // DOOR_H
