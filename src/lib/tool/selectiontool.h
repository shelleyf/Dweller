#ifndef SELECTIONTOOL_H
#define SELECTIONTOOL_H
#include "tool.h"
#include "lib/draw/window.h"
#include "lib/ui/dwellercanvas.h"
#include "lib/draw/houseitem.h"

class SelectionTool : public Tool
{
public:
    SelectionTool(DwellerCanvas *canvas);
    ~SelectionTool();

protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent *event) override;
    void mouseRelease(QMouseEvent *event) override;

private:
    HouseItem *selectedItem;
    bool m_isMousePressed;
    bool m_hasMoved;
    DwellerCanvas *m_canvas;
};

#endif // SELECTIONTOOL_H
