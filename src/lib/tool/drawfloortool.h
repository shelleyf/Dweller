#ifndef DRAWFLOORTOOL_H
#define DRAWFLOORTOOL_H
#include "lib/draw/floor.h"
#include "lib/ui/dwellercanvas.h"
#include "tool.h"

class DrawFloorTool : public Tool
{
public:
    DrawFloorTool(DwellerCanvas *canvas, GlobalCanvasData *data);
    ~DrawFloorTool();
protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent *event) override;
    void mouseRelease(QMouseEvent *event) override;

private:
    Floor *m_Floor;
    bool m_ClickPressed;
    bool m_IsDrawing;
    QPoint m_StartPosition;
    QPoint m_EndPosition;
    QPoint m_TempPosition;
    DwellerCanvas *m_canvas;
};

#endif // DRAWFLOORTOOL_H
