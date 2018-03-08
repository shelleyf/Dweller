#include "drawwindowtool.h"

DrawWindowTool::DrawWindowTool(DwellerCanvas *canvas, GlobalCanvasData *data)
{
    m_GlobalCanvasData = data;
    m_canvas = canvas;
    m_EnableViewChange = false;
    m_ClickPressed = false;
}

DrawWindowTool::~DrawWindowTool(){

}

void DrawWindowTool::mousePress(QMouseEvent *event){
    m_ClickPressed = true;
    m_StartPosition = event->pos() - m_MapTranslate;

    m_Window = new Window();
    m_Window->setStartPoint(m_StartPosition);

    m_Window->setEndPoint(m_StartPosition);
    m_Window->m_Line = new QLine(m_StartPosition,m_EndPosition);
    m_canvas->scene->addItem(m_Window);
    m_GlobalCanvasData->add(m_Window);
}

void DrawWindowTool::mouseMove(QMouseEvent *event){
    if(m_ClickPressed){
        qDebug()<<"window here1";
        m_Window->setEndPoint(event->pos() - m_MapTranslate);
        m_EndPosition = event->pos() - m_MapTranslate;
        m_Window->m_Line->setP2(m_EndPosition);
        m_Window->update();
    }
    qDebug()<<"window here2";
}

void DrawWindowTool::mouseRelease(QMouseEvent *event){
    m_ClickPressed = false;
    //m_Window->m_Line = new QLine(m_StartPosition,m_EndPosition);
    //m_canvas->scene->addLine(*(m_Window->m_Line),m_Window->getPen());
    //m_canvas->scene->addItem(m_Window);
}
