#ifndef TOOL_H
#define TOOL_H

#include <QMouseEvent>
#include <QKeyEvent>

class Tool
{
public:
    Tool();
    virtual ~Tool();

    bool handleEvent(QEvent *event);

protected:
    virtual void mousePress(QMouseEvent* event) {}
    virtual void mouseMove(QMouseEvent* event) {}
    virtual void mouseRelease(QMouseEvent* event) {}
    virtual void keyPress(QKeyEvent* event){}

};

#endif // TOOL_H
