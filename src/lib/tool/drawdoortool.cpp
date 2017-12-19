#include "drawdoortool.h"

DrawDoorTool::DrawDoorTool(DwellerCanvas *canvas)
{
    m_canvas = canvas;
    m_EnableViewChange = false;
}

void DrawDoorTool::mousePress(QMouseEvent *event){
    qDebug("wall tool mousePress");
    m_ClickPressed = true;
    m_StartPosition = event->pos() - m_MapTranslate;

    m_Door = new Door();
    m_Door->setStartPoint(m_StartPosition);

    m_Door->setEndPoint(m_StartPosition);
    m_Door->m_Line = new QLine(m_StartPosition,m_EndPosition);
    m_canvas->scene->addItem(m_Door);
}

void DrawDoorTool::mouseMove(QMouseEvent *event){
    if(m_ClickPressed){
        m_Door->setEndPoint(event->pos() - m_MapTranslate);
        m_EndPosition = event->pos() - m_MapTranslate;
        m_Door->m_Line->setP2(m_EndPosition);
        m_Door->update();
    }
}

void DrawDoorTool::mouseRelease(QMouseEvent *event){
    m_ClickPressed = false;
    //m_Door->m_Line = new QLine(m_StartPosition,m_EndPosition);
    //m_canvas->scene->addLine(*(m_Door->m_Line),m_Door->getPen());
    //m_canvas->scene->addItem(m_Door);
}
