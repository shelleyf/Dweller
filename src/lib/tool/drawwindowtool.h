#ifndef DRAWWINDOWTOOL_H
#define DRAWWINDOWTOOL_H
#include "lib/draw/window.h"
#include "tool.h"

class DrawWindowTool : public Tool
{
public:
    DrawWindowTool();
protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent *event) override;
    void mouseRelease(QMouseEvent *event) override;

private:
    Window m_Window;
    bool m_ClickPressed;
    QPoint m_startPosition;
};

#endif // DRAWWINDOWTOOL_H
