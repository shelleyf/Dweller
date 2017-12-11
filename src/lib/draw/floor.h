#ifndef FLOOR_H
#define FLOOR_H

#include "houseitem.h"
#include <QPen>
class Floor : public HouseItem
{
public:
    Floor();

    QPen getPen() override;
    void setPen(QColor color,int width) override;
    void draw(QPainter *painter) override;

    QRect getBoundary() override;
    bool contains(int x, int y) override;

    void addPoint(QPoint point,int index);
    void deletePoint(int index);


protected:
    QVector<QPoint> floorPoint;

private:

};

#endif // FLOOR_H
