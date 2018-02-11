#ifndef TOOL_H
#define TOOL_H

#include <QMouseEvent>
#include <QKeyEvent>

#include "lib/data/globalcanvasdata.h"

class Tool
{
public:
    Tool();
    ~Tool();

    bool handleEvent(QEvent *event);

    bool m_EnableViewChange;
    QPoint m_MapTranslate;
    GlobalCanvasData *m_GlobalCanvasData;

protected:
    virtual void mousePress(QMouseEvent* event) {}
    virtual void mouseMove(QMouseEvent* event) {}
    virtual void mouseRelease(QMouseEvent* event) {}
    virtual void keyPress(QKeyEvent* event){}

};

#endif // TOOL_H
