#ifndef DRAWWALLTOOL_H
#define DRAWWALLTOOL_H
#include "lib/draw/wall.h"
#include "tool.h"

class DrawWallTool : public Tool
{
public:
    DrawWallTool();

protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent *event) override;
    void mouseRelease(QMouseEvent *event) override;

private:
    Wall m_Wall;
    bool m_ClickPressed;
    QPoint m_startPosition;
};

#endif // DRAWWALLTOOL_H
