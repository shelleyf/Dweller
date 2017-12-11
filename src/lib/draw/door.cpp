#include "door.h"

Door::Door()
{
    setPen(new QColor(0,255,0),5);
}

QPen Door::getPen(){
    return m_pen;
}

void Door::setPen(QColor color, int width){
    m_pen.setColor(color);
    m_pen.setWidth(width);
}

int Door::getDoorHeight(){

}

void Door::setDoorHeight(int height){

}

float Door::getDoorLeakage(){

}
