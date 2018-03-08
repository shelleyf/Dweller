#include "selectiontool.h"

SelectionTool::SelectionTool(DwellerCanvas *canvas, GlobalCanvasData *data)
{
    m_GlobalCanvasData = data;
    m_canvas = canvas;
    m_EnableViewChange = true;
    m_ClickPressed = false;
}

SelectionTool::~SelectionTool()
{

}

void SelectionTool::mousePress(QMouseEvent *event){

}

void SelectionTool::mouseMove(QMouseEvent *event){

}

void SelectionTool::mouseRelease(QMouseEvent *event){

}
