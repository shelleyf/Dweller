#ifndef DRAWDOORTOOL_H
#define DRAWDOORTOOL_H
#include "lib/draw/door.h"
#include "lib/ui/dwellercanvas.h"
#include "tool.h"

class DrawDoorTool : public Tool
{
public:
    DrawDoorTool(DwellerCanvas *canvas, GlobalCanvasData *data);
    ~DrawDoorTool();
protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent *event) override;
    void mouseRelease(QMouseEvent *event) override;

private:
    Door *m_Door;
    bool m_ClickPressed;
    QPoint m_StartPosition;
    QPoint m_EndPosition;
    DwellerCanvas *m_canvas;
};

#endif // DRAWDOORTOOL_H
