#include "floor.h"

Floor::Floor()
{
    setPen(QColor(0,255,255),1);
}

void Floor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

}

QRectF Floor::boundingRect() const{

}

QRect Floor::getBoundary(){

}

bool Floor::contains(int x, int y){

}

void Floor::setSelected(bool val){

}

bool Floor::isSelected(){

}

QPen Floor::getPen(){
    return m_pen;
}

void Floor::setPen(QColor color, int width){
    m_pen.setColor(color);
    m_pen.setWidth(width);
}

void Floor::addPoint(QPoint point, int index){
    if(floorPoint.isEmpty()){
        floorPoint.append(point);
    }
    else{
        floorPoint.insert(index,point);
    }
}

void Floor::deletePoint(int index){
    floorPoint.remove(index);
}
