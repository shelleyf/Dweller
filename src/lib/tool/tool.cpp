#include "tool.h"

Tool::Tool()
{

}

Tool::~Tool()
{

}



bool Tool::handleEvent(QEvent *event){
    if (event->type() == QEvent::KeyPress) {
        qDebug("handleEvent keyPress");
        QKeyEvent *ke = reinterpret_cast<QKeyEvent *>(event);
        keyPress(ke);
        return true;
    } else if (event->type() == QEvent::MouseButtonPress) {
        qDebug("handleEvent mouseButtonPress");
        QMouseEvent *me = reinterpret_cast<QMouseEvent *>(event);
        mousePress(me);
    } else if (event->type() == QEvent::MouseMove) {
        qDebug("handleEvent MouseMove");
        QMouseEvent *me = reinterpret_cast<QMouseEvent *>(event);
        mouseMove(me);
    } else if (event->type() == QEvent::MouseButtonRelease) {
        qDebug("handleEvent MouseButton");
        QMouseEvent *me = reinterpret_cast<QMouseEvent *>(event);
        mouseRelease(me);
    }

    return true;
}
