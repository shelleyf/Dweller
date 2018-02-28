#include "globalcanvasdata.h"

GlobalCanvasData::GlobalCanvasData()
{
    m_testString = "Qml pass value";
}

//QQmlListProperty<HouseItem> GlobalCanvasData::houseMap(){
//    return QQmlListProperty<HouseItem>(this,0,&GlobalCanvasData::append_houseItem);
//}

//void GlobalCanvasData::append_houseItem(QQmlListProperty<HouseItem> *list, HouseItem *item){
//    GlobalCanvasData *data = qobject_cast<GlobalCanvasData *>(list->object);
//    if(item){
//        data->m_Data.append(item);
//    }
//}

void GlobalCanvasData::convertJson(){
    QJsonObject json;
    QJsonObject tmp;
    QJsonArray groupArray;
    HouseItem *temp_Item;
    for(int i=0; i<(m_Data.size());i++){
        temp_Item = m_Data.at(i);
        if(temp_Item->m_Kind == "Device"){
            tmp = writeDevice(temp_Item);
        }else if(temp_Item->m_Kind == "Door"){
            tmp = writeDoor(temp_Item);
        }else if(temp_Item->m_Kind == "Wall"){
            tmp = writeWall(temp_Item);
        }else if(temp_Item->m_Kind == "Floor"){
            tmp = writeFloor(temp_Item);
        }else if(temp_Item->m_Kind == "Window"){
            tmp = writeWindow(temp_Item);
        }else{
            qDebug("not a proper houseItem kind");
        }
        groupArray.append(tmp);
    }
    json["HouseMap"] = groupArray;
    m_testString = QString(QJsonDocument(json).toJson());
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

QJsonObject GlobalCanvasData::writeDevice(HouseItem *device){
    QJsonObject devObj;
    QJsonObject posTL;
    QJsonObject posBR;
    devObj["Type"] = "Device";
    devObj["Name"] = dynamic_cast<Device*>(device)->m_DeviceName;

    posTL["x"] = dynamic_cast<Device*>(device)->m_DevicePositionTL.x();
    posTL["y"] = dynamic_cast<Device*>(device)->m_DevicePositionTL.y();
    devObj["PositionTL"] = posTL;

    posBR["x"] = dynamic_cast<Device*>(device)->m_DevicePositionBR.x();
    posBR["y"] = dynamic_cast<Device*>(device)->m_DevicePositionBR.y();
    devObj["PositionBR"] = posBR;

    return devObj;
}

QJsonObject GlobalCanvasData::writeDoor(HouseItem *door){
    QJsonObject doorObj;
    QJsonObject posStart;
    QJsonObject posEnd;
    doorObj["Type"] = "Door";
    doorObj["Name"] = dynamic_cast<Door*>(door)->m_DoorName;

    posStart["x"] = dynamic_cast<Door*>(door)->m_DoorStart.x();
    posStart["y"] = dynamic_cast<Door*>(door)->m_DoorStart.y();
    doorObj["PositionStart"] = posStart;

    posEnd["x"] = dynamic_cast<Door*>(door)->m_DoorEnd.x();
    posEnd["y"] = dynamic_cast<Door*>(door)->m_DoorEnd.y();
    doorObj["PositionEnd"] = posEnd;

    doorObj["DoorHeight"] = dynamic_cast<Door*>(door)->m_DoorHeight;
    doorObj["DoorLeakage"] = dynamic_cast<Door*>(door)->m_DoorLeakage;

    return doorObj;
}

QJsonObject GlobalCanvasData::writeWall(HouseItem *wall){
    QJsonObject wallObj;
    QJsonObject posStart;
    QJsonObject posEnd;

    wallObj["Type"] = "Wall";
    wallObj["Name"] = dynamic_cast<Wall*>(wall)->m_WallName;

    posStart["x"] = dynamic_cast<Wall*>(wall)->m_WallStart.x();
    posStart["y"] = dynamic_cast<Wall*>(wall)->m_WallStart.y();
    wallObj["PositionStart"] = posStart;

    posEnd["x"] = dynamic_cast<Wall*>(wall)->m_WallEnd.x();
    posEnd["y"] = dynamic_cast<Wall*>(wall)->m_WallEnd.y();
    wallObj["PositionEnd"] = posEnd;

    wallObj["WallThickness"] = dynamic_cast<Wall*>(wall)->m_WallThickness;

    return wallObj;
}

QJsonObject GlobalCanvasData::writeFloor(HouseItem *floor){
    QJsonObject floorObj;
    QJsonObject posArray;
    QJsonObject posTmp;

    floorObj["Type"] = "Floor";
    floorObj["Name"] = dynamic_cast<Floor*>(floor)->m_FloorName;

    for(int i = 0; i<(dynamic_cast<Floor*>(floor)->m_Point.size());i++){
        posTmp["x"] = dynamic_cast<Floor*>(floor)->m_Point.at(i).x();
        posTmp["y"] = dynamic_cast<Floor*>(floor)->m_Point.at(i).y();
        posArray["Point" + QString::number(i)] = posTmp;
    }
    floorObj["PositionPoint"] = posArray;

    return floorObj;
}

QJsonObject GlobalCanvasData::writeWindow(HouseItem *window){
    QJsonObject windowObj;
    QJsonObject posStart;
    QJsonObject posEnd;

    windowObj["Type"] = "Window";
    windowObj["Name"] = dynamic_cast<Window*>(window)->m_WindowName;

    posStart["x"] = dynamic_cast<Window*>(window)->m_WindowStart.x();
    posStart["y"] = dynamic_cast<Window*>(window)->m_WindowStart.y();
    windowObj["PositionStart"] = posStart;

    posEnd["x"] = dynamic_cast<Window*>(window)->m_WindowEnd.x();
    posEnd["y"] = dynamic_cast<Window*>(window)->m_WindowEnd.y();
    windowObj["PositionEnd"] = posEnd;

    windowObj["WindowLeakage"] = dynamic_cast<Window*>(window)->m_WindowLeakage;
    windowObj["WindowHeight"] = dynamic_cast<Window*>(window)->m_WindowHeight;
    windowObj["WindowBottomHeight"] = dynamic_cast<Window*>(window)->m_WindowBottomHeight;

    return windowObj;
}
