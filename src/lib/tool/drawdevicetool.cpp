#include "drawdevicetool.h"

DrawDeviceTool::DrawDeviceTool(DwellerCanvas *canvas)
{
    m_canvas = canvas;
}

void DrawDeviceTool::mousePress(QMouseEvent *event){
    m_ClickPressed = true;
    m_StartPosition = event->pos();

    m_Device = new Device();
    m_Device->setDevicePositionTL(event->pos());

}

void DrawDeviceTool::mouseMove(QMouseEvent *event){
    if(m_ClickPressed){
        m_Device->setDevicePositionBR(event->pos());
        m_EndPosition = event->pos();
    }
}

void DrawDeviceTool::mouseRelease(QMouseEvent *event){
    m_ClickPressed = false;
    m_Device->setWidth(qAbs(m_Device->getDevicePositionBR().x()-m_Device->getDevicePositionTL().x()));
    m_Device->setHeight(qAbs(m_Device->getDevicePositionBR().y()-m_Device->getDevicePositionTL().y()));
    m_Device->m_Rect = new QRectF(m_Device->getDevicePositionTL(),m_Device->getDevicePositionBR());
    m_canvas->scene->addRect(*(m_Device->m_Rect),m_Device->getPen(),m_Device->getBrush());
}
