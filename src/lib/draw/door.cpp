#include "door.h"

Door::Door()
{
    setPen(QColor(0,255,0),5);
    setDoorHeight(2);
    setDoorLeakage(0.2);
}

void Door::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setPen(m_pen);
    painter->drawLine(*(m_Line));
}

QRectF Door::boundingRect() const{
    QPoint p1 = m_Line->p1() - QPoint(1,1);
    QPoint p2 = m_Line->p2() + QPoint(1,1);
    QRectF *res = new QRectF(p1,p2);
    return *res;
}

QRect Door::getBoundary(){

}
void Door::setSelected(bool val){

}

bool Door::isSelected(){

}
bool Door::contains(int x, int y){

}

QPen Door::getPen(){
    return m_pen;
}

void Door::setPen(QColor color, int width){
    m_pen.setColor(color);
    m_pen.setWidth(width);
}

float Door::getDoorHeight(){
    return m_DoorHeight;
}

void Door::setDoorHeight(float height){
    m_DoorHeight = height;
}

void Door::setDoorLeakage(float leakage){
    m_DoorLeakage = leakage;
}

float Door::getDoorLeakage(){
    return m_DoorLeakage;
}

QPoint Door::getStartPoint(){
    return m_DoorStart;
}

void Door::setStartPoint(QPoint point){
    m_DoorStart = point;
}

QPoint Door::getEndPoint(){
    return m_DoorEnd;
}

void Door::setEndPoint(QPoint point){
    m_DoorEnd = point;
    QPoint p1 = m_DoorStart - QPoint(1,1);
    QPoint p2 = m_DoorEnd + QPoint(1,1);
    QRectF *res = new QRectF(p1,p2);
    m_Rect = res;
}
