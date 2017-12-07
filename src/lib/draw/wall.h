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




};

#endif // WALL_H
