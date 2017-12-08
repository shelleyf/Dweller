#ifndef TOOL_H
#define TOOL_H

#include <QMouseEvent>
#include <QKeyEvent>

class Tool
{
public:
    Tool();

    bool handleEvent(QEvent *event);

protected:
    virtual void mousePress(QMouseEvent* event) = 0;
    virtual void mouseMove(QMouseEvent* event) = 0;
    virtual void mouseRelease(QMouseEvent* event) = 0;
    virtual void keyPress(QKeyEvent* event) = 0;

};

#endif // TOOL_H
