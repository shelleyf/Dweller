#ifndef DRAWFLOORTOOL_H
#define DRAWFLOORTOOL_H
#include "lib/draw/floor.h"
#include "tool.h"

class DrawFloorTool : public Tool
{
public:
    DrawFloorTool();

protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent *event) override;
    void mouseRelease(QMouseEvent *event) override;

private:
    Floor m_Floor;
    bool m_ClickPressed;
    QPoint m_startPosition;

};

#endif // DRAWFLOORTOOL_H
