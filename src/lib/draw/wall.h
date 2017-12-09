#ifndef WALL_H
#define WALL_H
#include <QColor>

#include "houseitem.h"
class Wall : public HouseItem
{
public:
    Wall();
    ~Wall();

    void setWallColor(QColor &val);
    void setWallThickness(int &val);
    void draw(QPainter *painter) override;

    QRect getBoundary() override;
    bool contains(int x, int y) override;

    QPoint getStartPoint();
    void setStartPoint(QPoint value);

    QPoint getEndPoint();
    void setEndPoint(QPoint value);

protected:
    QColor m_WallColor;
    QPoint m_Wallstart;
    QPoint m_WallEnd;
    int m_WallThickness;





};

#endif // WALL_H
