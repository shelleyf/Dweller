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
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

    QRect getBoundary() override;
    bool contains(int x, int y) override;
    void setSelected(bool val) override;
    bool isSelected() override;

    void addPoint(QPoint point,int index);
    void deletePoint(int index);


protected:
    QVector<QPoint> floorPoint;

private:

};

#endif // FLOOR_H
