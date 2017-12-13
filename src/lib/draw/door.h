#ifndef DOOR_H
#define DOOR_H

#include "houseitem.h"

class Door : public HouseItem
{
public:
    Door();

    QPen getPen() override;
    void setPen(QColor color,int width) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

    QRect getBoundary() override;
    bool contains(int x, int y) override;
    void setSelected(bool val) override;
    bool isSelected() override;

    QPoint getStartPoint();
    void setStartPoint(QPoint value);

    QPoint getEndPoint();
    void setEndPoint(QPoint value);

    float getDoorHeight();
    void setDoorHeight(float height);

    float getDoorLeakage();
    void setDoorLeakage(float leakage);

    QLine *m_Line;
protected:
    QColor m_DoorColor;
    QPoint m_DoorStart;
    QPoint m_DoorEnd;
    float m_DoorHeight;
    float m_DoorLeakage;




};

#endif // DOOR_H
