#include "drawwindowtool.h"

DrawWindowTool::DrawWindowTool(DwellerCanvas *canvas)
{
    m_canvas = canvas;
    m_EnableViewChange = false;
}

void DrawWindowTool::mousePress(QMouseEvent *event){
    m_ClickPressed = true;
    m_StartPosition = event->pos();

    m_Window = new Window();
    m_Window->setStartPoint(m_StartPosition);

    m_Window->setEndPoint(m_StartPosition);
    m_Window->m_Line = new QLine(m_StartPosition,m_EndPosition);
    m_canvas->scene->addItem(m_Window);
}

void DrawWindowTool::mouseMove(QMouseEvent *event){
    if(m_ClickPressed){
        m_Window->setEndPoint(event->pos());
        m_EndPosition = event->pos();
        m_Window->m_Line->setP2(m_EndPosition);
        m_Window->update();
    }
}

void DrawWindowTool::mouseRelease(QMouseEvent *event){
    m_ClickPressed = false;
    //m_Window->m_Line = new QLine(m_StartPosition,m_EndPosition);
    //m_canvas->scene->addLine(*(m_Window->m_Line),m_Window->getPen());
    //m_canvas->scene->addItem(m_Window);
}
