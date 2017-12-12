#include "wall.h"

Wall::Wall()
{

}

QPen Wall::getPen(){
    return m_pen;
}

void Wall::setPen(QColor color, int width){
    m_pen.setColor(color);
    m_pen.setWidth(width);
}

void Wall::draw(QPainter *painter){
    //painter->setPen(m_pen);
    //painter->drawLine(m_WallStart,m_WallEnd);
}

QRect Wall::getBoundary(){

}

bool Wall::contains(int x, int y){

}

QPoint Wall::getStartPoint(){
    return m_WallStart;
}

void Wall::setStartPoint(QPoint point){
    m_WallStart = point;
}

QPoint Wall::getEndPoint(){
    return m_WallEnd;
}

void Wall::setEndPoint(QPoint point){
    m_WallEnd = point;
}
