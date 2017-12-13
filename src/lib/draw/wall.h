#ifndef WALL_H
#define WALL_H
#include <QColor>
#include <QLine>
#include <Qpen>

#include "houseitem.h"
class Wall : public HouseItem
{
public:
    Wall();

    QPen getPen() override;
    void setPen(QColor color,int width) override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

    void setSelected(bool val) override;
    bool isSelected() override;

    QRect getBoundary() override;
    bool contains(int x, int y) override;

    QPoint getStartPoint();
    void setStartPoint(QPoint value);

    QPoint getEndPoint();
    void setEndPoint(QPoint value);

    QLine *m_Line;
protected:
    QColor m_WallColor;
    QPoint m_WallStart;
    QPoint m_WallEnd;
    int m_WallThickness;


};

#endif // WALL_H
