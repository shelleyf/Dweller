#include "tool.h"

Tool::Tool()
{
    m_EnableViewChange = false;
    m_MapTranslate.setX(0);
    m_MapTranslate.setY(0);
}

Tool::~Tool()
{

}



bool Tool::handleEvent(QEvent *event){
    if (event->type() == QEvent::KeyPress) {
        //qDebug("handleEvent keyPress");
        QKeyEvent *ke = reinterpret_cast<QKeyEvent *>(event);
        qDebug()<<"event here1";
        keyPress(ke);
        return true;
    } else if (event->type() == QEvent::MouseButtonPress) {
        //qDebug("handleEvent mouseButtonPress");
        QMouseEvent *me = reinterpret_cast<QMouseEvent *>(event);
        mousePress(me);
    } else if (event->type() == QEvent::MouseMove) {
        //qDebug("handleEvent MouseMove");
        //qDebug()<<"event here1";
        QMouseEvent *me = reinterpret_cast<QMouseEvent *>(event);
        //qDebug()<<"event here2";
        mouseMove(me);
    } else if (event->type() == QEvent::MouseButtonRelease) {
        //qDebug("handleEvent MouseButton");
        QMouseEvent *me = reinterpret_cast<QMouseEvent *>(event);
        mouseRelease(me);
    }

    return true;
}
