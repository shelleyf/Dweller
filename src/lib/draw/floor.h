#ifndef FLOOR_H
#define FLOOR_H

#include "houseitem.h"
#include <QPen>
#include <QPolygonF>
#include <QPointF>

class Floor : public HouseItem
{
public:
    Floor();
    ~Floor();

    QPen getPen() override;
    void setPen(QColor color,int width) override;
    QBrush getBrush();
    void setBrush();


    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    QRect getBoundary() override;
    bool contains(int x, int y) override;
    void setSelected(bool val) override;
    bool isSelected() override;

    void appendPoint(QPoint point);
    void addPoint(QPoint point,int index);
    void deletePoint(int index);

    QPolygonF *m_Polygon;
    QVector<QPointF> m_Point;

    QPointF regionTL;
    QPointF regionBR;
private:
    QBrush m_Brush;
    QRectF *regionRect;
};

#endif // FLOOR_H
