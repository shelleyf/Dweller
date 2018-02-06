#include "floor.h"

Floor::Floor()
{
    setPen(QColor(0,255,255),5);
    QPixmap brushPix;
    brushPix.load(":/res/texture/wood-2.jpg");
    m_Brush.setTexture(brushPix);
}

Floor::~Floor(){

}

void Floor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setPen(m_pen);
    painter->setBrush(m_Brush);
    painter->drawPoints(*m_Polygon);
    painter->drawPolygon(*(m_Polygon));
}

QPainterPath Floor::shape() const{
    QPainterPath path;
    path.addPolygon(*(m_Polygon));
    return path;
}

QRectF Floor::boundingRect() const{
    regionRect = new QRectF(regionTL,regionBR);
    return regionRect->adjusted(-margin,-margin,margin,margin);
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

void Floor::appendPoint(QPoint point){
    m_Point.append(point);
    //boundingRect();
}

void Floor::addPoint(QPoint point, int index){
    if(m_Point.isEmpty()){
        m_Point.append(point);
    }
    else{
        m_Point.insert(index,point);
    }
}
QBrush Floor::getBrush(){
    return m_Brush;
}

void Floor::setBrush(){

}

void Floor::deletePoint(int index){
    m_Point.remove(index);
}
