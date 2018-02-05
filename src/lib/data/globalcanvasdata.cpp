#include "globalcanvasdata.h"

GlobalCanvasData::GlobalCanvasData()
{

}

void GlobalCanvasData::add(HouseItem *item){
    m_Data.append(item);
}

void GlobalCanvasData::remove(int index){
    m_Data.removeAt(index);
}

void GlobalCanvasData::clear(){
    m_Data.clear();
}

HouseItem * GlobalCanvasData::find(QString string){

}
