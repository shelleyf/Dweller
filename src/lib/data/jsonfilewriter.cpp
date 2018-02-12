#include "jsonfilewriter.h"

JsonFileWriter::JsonFileWriter()
{

}

JsonFileWriter::~JsonFileWriter(){

}

void JsonFileWriter::setup(GlobalCanvasData *mainCanvas){
    QJsonObject json;
    QJsonObject tmp;
    QJsonArray groupArray;
    HouseItem *temp_Item;
    for(int i=0; i<(mainCanvas->m_Data.size());i++){
        temp_Item = mainCanvas->m_Data.at(i);
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
    m_Doc = new QJsonDocument(json);
}

bool JsonFileWriter::write(const std::string &fileDir){
//    QFile saveFile(QString::fromUtf8(fileDir.c_str()));
//    if (!saveFile.open(QIODevice::WriteOnly)) {
//        return false;
//    }
}

QJsonObject JsonFileWriter::writeDevice(HouseItem *device){

}

QJsonObject JsonFileWriter::writeDoor(HouseItem *door){

}

QJsonObject JsonFileWriter::writeWall(HouseItem *wall){

}

QJsonObject JsonFileWriter::writeFloor(HouseItem *floor){

}

QJsonObject JsonFileWriter::writeWindow(HouseItem *window){

}
