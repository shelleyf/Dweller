#ifndef SELECTIONTOOL_H
#define SELECTIONTOOL_H
#include "tool.h"
#include "lib/draw/window.h"
#include "lib/ui/dwellercanvas.h"

class SelectionTool : public Tool
{
public:
    SelectionTool(DwellerCanvas *canvas);

protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent *event) override;
    void mouseRelease(QMouseEvent *event) override;

private:
    DwellerCanvas *m_canvas;
};

#endif // SELECTIONTOOL_H
