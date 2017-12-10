#ifndef FLOOR_H
#define FLOOR_H

#include "houseitem.h"

class Floor : public HouseItem
{
public:
    Floor();

    void draw(QPainter *painter) override;

    QRect getBoundary() override;
    bool contains(int x, int y) override;

    void addPoint(QPoint point,int index);
    void deletePoint(int index);


protected:
    QVector<QPoint> floorPoint;
};

#endif // FLOOR_H
