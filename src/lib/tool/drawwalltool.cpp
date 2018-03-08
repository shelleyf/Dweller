#include "drawwalltool.h"

DrawWallTool::DrawWallTool(DwellerCanvas *canvas, GlobalCanvasData *data)
{
    //qDebug()<<"construct0";
    m_GlobalCanvasData = data;
    m_canvas = canvas;
    m_EnableViewChange = false;
    m_ClickPressed = false;
    //m_Wall->m_Line = new QLine(m_StartPosition,m_EndPosition);
    //qDebug()<<"construct1";
}

DrawWallTool::~DrawWallTool(){

}

void DrawWallTool::mousePress(QMouseEvent *event){
    qDebug("wall tool mousePress");
    qDebug()<<event->pos();
    qDebug()<<m_MapTranslate;

    m_ClickPressed = true;
    //m_StartPosition = event->pos();
    m_StartPosition = event->pos() - m_MapTranslate;

    m_Wall = new Wall();
    m_Wall->setStartPoint(m_StartPosition);

    m_Wall->setEndPoint(m_StartPosition);
    m_Wall->m_Line = new QLine(m_StartPosition,m_EndPosition);
    //m_Wall->m_Line->setP1();
    //m_Wall->m_Line->setP2();
    m_canvas->scene->addItem(m_Wall);
    m_GlobalCanvasData->add(m_Wall);
}

void DrawWallTool::mouseMove(QMouseEvent *event){
    //qDebug()<<"mousemove"<<event->pos();
    if(m_ClickPressed){
         qDebug()<<"wall here1";
        m_Wall->setEndPoint(event->pos() - m_MapTranslate);
        //m_EndPosition = event->pos();
        m_EndPosition = event->pos()-m_MapTranslate;

        m_Wall->m_Line->setP2(m_EndPosition);
        m_Wall->update();
    }
     qDebug()<<"wall here2";
}

void DrawWallTool::mouseRelease(QMouseEvent *event){
    m_ClickPressed = false;
    //m_Wall->m_Line = new QLine(m_StartPosition,m_EndPosition);
    //m_canvas->scene->addLine(*(m_Wall->m_Line),m_Wall->getPen());
    //m_canvas->scene->addItem(m_Wall);
}
