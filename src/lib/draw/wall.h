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
    ~Wall();

    QPen getPen() override;
    void setPen(QColor color,int width) override;

    void draw(QPainter *painter) override;

    QRect getBoundary() override;
    bool contains(int x, int y) override;

    QPoint getStartPoint();
    void setStartPoint(QPoint value);

    QPoint getEndPoint();
    void setEndPoint(QPoint value);

protected:
    QColor m_WallColor;
    QPoint m_WallStart;
    QPoint m_WallEnd;
    int m_WallThickness;
    QLine m_Line;

};

#endif // WALL_H
