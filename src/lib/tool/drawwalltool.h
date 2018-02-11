#ifndef DRAWWALLTOOL_H
#define DRAWWALLTOOL_H
#include "lib/ui/dwellercanvas.h"
#include "lib/draw/wall.h"
#include "tool.h"

class DrawWallTool : public Tool
{
public:
    DrawWallTool(DwellerCanvas *canvas, GlobalCanvasData *data);
    ~DrawWallTool();
protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent *event) override;
    void mouseRelease(QMouseEvent *event) override;

private:
    Wall *m_Wall;
    bool m_ClickPressed;
    QPoint m_StartPosition;
    QPoint m_EndPosition;
    DwellerCanvas *m_canvas;
};

#endif // DRAWWALLTOOL_H
