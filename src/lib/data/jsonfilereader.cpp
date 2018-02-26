#include "jsonfilereader.h"

JsonFileReader::JsonFileReader()
{

}

JsonFileReader::~JsonFileReader(){


}

void JsonFileReader::setup(GlobalCanvasData *mainCanvas){
    m_GlobalCanvasData = mainCanvas;
}

bool JsonFileReader::read(const std::string &fileDir){
    QFile loadFile(QString::fromUtf8(fileDir.c_str()));
    if(!loadFile.open(QIODevice::ReadOnly)){
        return false;
    }

    QByteArray saveData = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    QJsonObject jsonObj = loadDoc.object();

    QJsonArray houseMap = jsonObj["HouseMap"].toArray();

    for(int i=0;i<houseMap.size();i++){
        QJsonObject obj = houseMap[i].toObject();

        if(obj["Type"].toString() == "Device"){
            m_GlobalCanvasData->add(readDevice(obj));
        }else if(obj["Type"].toString() == "Door"){
            m_GlobalCanvasData->add(readDoor(obj));
        }else if(obj["Type"].toString() == "Wall"){
            m_GlobalCanvasData->add(readWall(obj));
        }else if(obj["Type"].toString() == "Floor"){
            m_GlobalCanvasData->add(readFloor(obj));
        }else if(obj["Type"].toString() == "Window"){
            m_GlobalCanvasData->add(readWindow(obj));
        }else{
            qDebug("cant load unknow houseitem");
            throw std::runtime_error("error: unknow houseitem");
        }
    }

    return true;
}

Device* JsonFileReader::readDevice(const QJsonObject &device){
    Device *tmp = new Device();
    QJsonObject pos;

    tmp->m_DeviceName = device["Name"].toString();

    pos = device["PositionTL"].toObject();
    QPoint positionTL(pos["x"].toInt(),pos["y"].toInt());
    tmp->m_DevicePositionTL = positionTL;

    pos = device["PositionBR"].toObject();
    QPoint positionBR(pos["x"].toInt(),pos["y"].toInt());
    tmp->m_DevicePositionBR = positionBR;

    return tmp;
}

Door* JsonFileReader::readDoor(const QJsonObject &door){
    Door *tmp = new Door();
    QJsonObject pos;

    tmp->m_DoorName = door["Name"].toString();

    pos = door["PositionStart"].toObject();
    QPoint positionS(pos["x"].toInt(),pos["y"].toInt());
    tmp->m_DoorStart = positionS;

    pos = door["PositionEnd"].toObject();
    QPoint positionE(pos["x"].toInt(),pos["y"].toInt());
    tmp->m_DoorEnd = positionE;

    tmp->m_DoorLeakage = door["DoorLeakage"].toDouble();
    tmp->m_DoorHeight = door["DoorHeight"].toDouble();

    return tmp;
}

Wall* JsonFileReader::readWall(const QJsonObject &wall){
    Wall *tmp = new Wall();
    QJsonObject pos;

    tmp->m_WallName = wall["Name"].toString();

    pos = wall["PositionStart"].toObject();
    QPoint positionS(pos["x"].toInt(),pos["y"].toInt());
    tmp->m_WallStart = positionS;

    pos = wall["PositionEnd"].toObject();
    QPoint positionE(pos["x"].toInt(),pos["y"].toInt());
    tmp->m_WallEnd = positionE;

    tmp->m_WallThickness = wall["WallThickness"].toInt();

    return tmp;
}

Floor* JsonFileReader::readFloor(const QJsonObject &floor){
    Floor *tmp = new Floor();
    QJsonObject posArray;
    QJsonObject posTmp;

    tmp->m_FloorName = floor["Name"].toString();

    posArray = floor["PositionPoint"].toObject();
    for(int i=0;i<posArray.size();i++){
        posTmp = posArray["Point"+QString::number(i)].toObject();
        QPoint point(posTmp["x"].toInt(),posTmp["y"].toInt());
        tmp->m_Point.append(point);
    }

    return tmp;
}

Window* JsonFileReader::readWindow(const QJsonObject &window){
    Window *tmp = new Window();
    QJsonObject pos;

    tmp->m_WindowName = window["Name"].toString();

    pos = window["PositionStart"].toObject();
    QPoint positionS(pos["x"].toInt(),pos["y"].toInt());
    tmp->m_WindowStart = positionS;

    pos = window["PositionEnd"].toObject();
    QPoint positionE(pos["x"].toInt(),pos["y"].toInt());
    tmp->m_WindowEnd = positionE;

    tmp->m_WindowLeakage = window["WindowLeakage"].toDouble();
    tmp->m_WindowBottomHeight = window["WindowBottomHeight"].toDouble();
    tmp->m_WindowHeight = window["WindowHeight"].toDouble();

    return tmp;
}
