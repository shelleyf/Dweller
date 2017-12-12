#include "door.h"

Door::Door()
{
    setPen(QColor(0,255,0),5);
    setDoorHeight(2);
    setDoorLeakage(0.2);
}

void Door::draw(QPainter *painter){

}

QRect Door::getBoundary(){

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
