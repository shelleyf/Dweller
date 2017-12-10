#ifndef DRAWDOORTOOL_H
#define DRAWDOORTOOL_H
#include "lib/draw/door.h"
#include "tool.h"

class DrawDoorTool : public Tool
{
public:
    DrawDoorTool();
protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent *event) override;
    void mouseRelease(QMouseEvent *event) override;

private:
    Door m_Door;
    bool m_ClickPressed;
    QPoint m_startPosition;
};

#endif // DRAWDOORTOOL_H
