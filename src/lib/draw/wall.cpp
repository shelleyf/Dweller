#include "wall.h"

Wall::Wall()
{
    setPen(QColor(255,0,0),2);
}

QPen Wall::getPen(){
    return m_pen;
}

void Wall::setPen(QColor color, int width){
    m_pen.setColor(color);
    m_pen.setWidth(width);
}

void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setPen(m_pen);
    painter->drawLine(*(m_Line));
}

QRectF Wall::boundingRect() const{
    QPoint p1 = m_Line->p1() - QPoint(1,1);
    QPoint p2 = m_Line->p2() + QPoint(1,1);
    QRectF *res = new QRectF(p1,p2);
    return *res;
}

QRect Wall::getBoundary(){

}
void Wall::setSelected(bool val){

}

bool Wall::isSelected(){

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
