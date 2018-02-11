#include "drawfloortool.h"

DrawFloorTool::DrawFloorTool(DwellerCanvas *canvas, GlobalCanvasData *data):m_IsDrawing(false)
{
    m_GlobalCanvasData = data;
    m_canvas = canvas;
    m_EnableViewChange = false;
}

DrawFloorTool::~DrawFloorTool(){

}

void DrawFloorTool::mousePress(QMouseEvent *event){    
    if(m_IsDrawing){
        if(event->button() == Qt::RightButton){
            qDebug("floor tool 1");
            m_IsDrawing = false;
        }else if(event->button() == Qt::LeftButton){
            qDebug("floor tool 2");
            m_TempPosition = event->pos() - m_MapTranslate;
            if(m_TempPosition.x()<=m_Floor->regionTL.x()){
                m_Floor->regionTL.setX(m_TempPosition.x());
            }
            if(m_TempPosition.y()>=m_Floor->regionTL.y()){
                m_Floor->regionTL.setY(m_TempPosition.y());
            }
            if(m_TempPosition.x()>=m_Floor->regionBR.x()){
                m_Floor->regionBR.setX(m_TempPosition.x());
            }
            if(m_TempPosition.y()<=m_Floor->regionBR.y()){
                m_Floor->regionBR.setY(m_TempPosition.y());
            }
            m_Floor->appendPoint(m_TempPosition);
            m_Floor->m_Polygon->append(m_TempPosition);

        }else{
            qDebug("no function define");
        }
    }else{
        if(event->button() == Qt::LeftButton){
            qDebug("floor tool 3");
            m_Floor = new Floor();
            m_IsDrawing = true;
            m_StartPosition = event->pos() - m_MapTranslate;
            m_Floor->regionTL=m_StartPosition;
            m_Floor->regionBR=m_StartPosition;
            m_Floor->appendPoint(m_StartPosition);
            m_Floor->m_Polygon = new QPolygonF(m_Floor->m_Point);
            m_canvas->scene->addItem(m_Floor);
            m_GlobalCanvasData->add(m_Floor);
        }
    }
    //qDebug()<<m_Floor->m_Point;
    //qDebug()<<*(m_Floor->m_Polygon);
    //qDebug()<<m_Floor->regionTL;
    //qDebug()<<m_Floor->regionBR;
    //qDebug()<<m_Floor->boundingRect().topLeft();
    //qDebug()<<m_Floor->boundingRect().bottomRight();
    //qDebug()<<m_Floor->isVisible();
    m_Floor->update();
    m_Floor->scene()->update();


}

void DrawFloorTool::mouseMove(QMouseEvent *event){
    if(m_IsDrawing){
        m_TempPosition = event->pos() - m_MapTranslate;
        //m_Floor->appendPoint(m_TempPosition);
        //m_Floor->update();
    }

}

void DrawFloorTool::mouseRelease(QMouseEvent *event){
    m_ClickPressed = false;
    //m_Floor->update();
}
