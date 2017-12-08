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
    void setStartPoint(const QPoint &value);

    QPoint getEndPoint();
    void setEndPoint(const QPoint &value);

protected:
    QColor m_wallColor;
    QPoint m_wallstart;
    QPoint m_wallEnd;
    int m_wallThickness;




};

#endif // WALL_H
