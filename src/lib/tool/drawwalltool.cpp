#include "drawwalltool.h"

DrawWallTool::DrawWallTool(DwellerCanvas *canvas)
{
    m_canvas = canvas;
}

void DrawWallTool::mousePress(QMouseEvent *event){
    m_ClickPressed = true;
    m_StartPosition = event->pos();

    m_Wall = new Wall();
    m_Wall->setStartPoint(m_StartPosition);
}

void DrawWallTool::mouseMove(QMouseEvent *event){
    if(m_ClickPressed){
        m_Wall->setEndPoint(event->pos());
        m_EndPosition = event->pos();
    }
}

void DrawWallTool::mouseRelease(QMouseEvent *event){
    m_ClickPressed = false;
    m_Wall->m_Line = new QLine(m_StartPosition,m_EndPosition);
    m_canvas->scene->addLine(*(m_Wall->m_Line),m_Wall->getPen());
}
