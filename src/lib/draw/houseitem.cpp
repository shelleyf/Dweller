#include "houseitem.h"

HouseItem::HouseItem()
{
    QPen *temp = new QPen();
    m_pen = *temp;
}

HouseItem::~HouseItem(){

}
QRect HouseItem::getBoundary(){

}
void HouseItem::setSelected(bool val){

}

bool HouseItem::isSelected(){

}

bool HouseItem::contains(int x, int y){

}

QPen HouseItem::getPen(){

}

void HouseItem::setPen(QColor color, int width){

}
