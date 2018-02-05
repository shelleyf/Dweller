#ifndef DRAWFLOORTOOL_H
#define DRAWFLOORTOOL_H
#include "lib/draw/floor.h"
#include "lib/ui/dwellercanvas.h"
#include "tool.h"

class DrawFloorTool : public Tool
{
public:
    DrawFloorTool(DwellerCanvas *canvas);
    ~DrawFloorTool();
protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent *event) override;
    void mouseRelease(QMouseEvent *event) override;

private:
    Floor *m_Floor;
    bool m_ClickPressed;
    QPoint m_startPosition;
    DwellerCanvas *m_canvas;
};

#endif // DRAWFLOORTOOL_H
