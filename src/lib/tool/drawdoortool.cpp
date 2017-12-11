#include "drawdoortool.h"

DrawDoorTool::DrawDoorTool(DwellerCanvas *canvas)
{
    m_canvas = canvas;
}

void DrawDoorTool::mousePress(QMouseEvent *event){
    m_ClickPressed = true;
    m_StartPosition = event->pos();

    m_Door = new Door();
    m_Door.setStartPoint(m_StartPosition);
}

void DrawDoorTool::mouseMove(QMouseEvent *event){
    if(m_ClickPressed){
        m_Door.setEndPoint(event->pos());
        m_EndPosition = event->pos();
    }
}

void DrawDoorTool::mouseRelease(QMouseEvent *event){
    m_ClickPressed = false;
    m_Door.m_Line = new QLine(m_StartPosition,m_EndPosition);
    m_canvas->scene->addLine(m_Door.m_Line,m_Door.getPen());
}
