#include "drawdoortool.h"

DrawDoorTool::DrawDoorTool(DwellerCanvas *canvas, GlobalCanvasData *data)
{
    m_GlobalCanvasData = data;
    m_canvas = canvas;
    m_EnableViewChange = false;
    m_ClickPressed = false;
    //m_Line = new QLine(m_StartPosition,m_EndPosition);
}

DrawDoorTool::~DrawDoorTool(){

}

void DrawDoorTool::mousePress(QMouseEvent *event){
    qDebug("wall tool mousePress");
    m_ClickPressed = true;
    m_StartPosition = event->pos() - m_MapTranslate;

    m_Door = new Door();
    m_Door->setStartPoint(m_StartPosition);

    m_Door->setEndPoint(m_StartPosition);
    m_Door->m_Line = new QLine(m_StartPosition,m_EndPosition);
    //m_Door->m_Line->setP1(m_StartPosition);
    //m_Door->m_Line->setP2(m_EndPosition);
    m_canvas->scene->addItem(m_Door);
    m_GlobalCanvasData->add(m_Door);
}

void DrawDoorTool::mouseMove(QMouseEvent *event){
    if(m_ClickPressed){
        qDebug()<<"door here1";
        m_Door->setEndPoint(event->pos() - m_MapTranslate);
        qDebug()<<"door here3";
        m_EndPosition = event->pos() - m_MapTranslate;
        qDebug()<<"door here4"<<m_EndPosition;
        m_Door->m_Line->setP2(m_EndPosition);
        qDebug()<<"door here5";
        m_Door->update();
    }
    qDebug()<<"door here2";
}

void DrawDoorTool::mouseRelease(QMouseEvent *event){
    m_ClickPressed = false;
    //m_Door->m_Line = new QLine(m_StartPosition,m_EndPosition);
    //m_canvas->scene->addLine(*(m_Door->m_Line),m_Door->getPen());
    //m_canvas->scene->addItem(m_Door);
}
