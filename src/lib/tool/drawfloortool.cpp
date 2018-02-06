#include "drawfloortool.h"

DrawFloorTool::DrawFloorTool(DwellerCanvas *canvas):m_IsDrawing(false)
{
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
            m_Floor->appendPoint(m_TempPosition);
            m_Floor->update();
        }else{
            qDebug("no function define");
        }
    }else{
        if(event->button() == Qt::LeftButton){
            qDebug("floor tool 3");
            m_Floor = new Floor();
            m_IsDrawing = true;
            m_StartPosition = event->pos() - m_MapTranslate;
            m_Floor->appendPoint(m_StartPosition);
            m_Floor->m_Polygon = new QPolygonF(m_Floor->m_Point);
            m_canvas->scene->addItem(m_Floor);
        }
    }
    //qDebug()<<m_Floor->m_Point;
    qDebug()<<m_Floor->m_Polygon->boundingRect().topLeft();
    qDebug()<<m_Floor->m_Polygon->boundingRect().bottomRight();

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
}
