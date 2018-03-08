#include "drawdevicetool.h"

DrawDeviceTool::DrawDeviceTool(DwellerCanvas *canvas, GlobalCanvasData *data)
{
    m_GlobalCanvasData = data;
    m_canvas = canvas;
    m_EnableViewChange = false;
    m_ClickPressed = false;
    //m_Device->m_Rect = new QRectF(m_Device->getDevicePositionTL(),m_Device->getDevicePositionBR());
}

DrawDeviceTool::~DrawDeviceTool(){

}


void DrawDeviceTool::mousePress(QMouseEvent *event){
    m_ClickPressed = true;
    m_StartPosition = event->pos()-m_MapTranslate;

    m_Device = new Device();
    m_Device->setDevicePositionTL(m_StartPosition);
    m_Device->setDevicePositionBR(m_StartPosition);
    m_Device->m_Rect = new QRectF(m_Device->getDevicePositionTL(),m_Device->getDevicePositionBR());
    //m_Device->m_Rect->setTopLeft(m_Device->getDevicePositionTL());
    //m_Device->m_Rect->setBottomRight(m_Device->getDevicePositionBR());
    m_canvas->scene->addItem(m_Device);
    m_GlobalCanvasData->add(m_Device);
}

void DrawDeviceTool::mouseMove(QMouseEvent *event){
    if(m_ClickPressed){
        m_EndPosition = event->pos()-m_MapTranslate;
        qDebug()<<"device here1";
        m_Device->setDevicePositionBR(m_EndPosition);
        qDebug()<<"device here3";
        m_Device->m_Rect->setBottomRight(m_EndPosition);
        qDebug()<<"device here4";
        m_Device->update();
        qDebug()<<"device here5";
    }
    qDebug()<<"device here2";
}

void DrawDeviceTool::mouseRelease(QMouseEvent *event){
    m_ClickPressed = false;
//    m_Device->setWidth(qAbs(m_Device->getDevicePositionBR().x()-m_Device->getDevicePositionTL().x()));
//    m_Device->setHeight(qAbs(m_Device->getDevicePositionBR().y()-m_Device->getDevicePositionTL().y()));
//    m_Device->m_Rect = new QRectF(m_Device->getDevicePositionTL(),m_Device->getDevicePositionBR());
//    m_canvas->scene->addRect(*(m_Device->m_Rect),m_Device->getPen(),m_Device->getBrush());
//    m_canvas->scene->addItem(m_Device);
}
