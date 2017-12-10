#ifndef DRAWDEVICETOOL_H
#define DRAWDEVICETOOL_H

#include "lib/draw/device.h"
#include "tool.h"

class DrawDeviceTool : public Tool
{
public:
    DrawDeviceTool();

protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent *event) override;
    void mouseRelease(QMouseEvent *event) override;

private:
    Device m_Device;
    bool m_ClickPressed;
    QPoint m_startPosition;
};

#endif // DRAWDEVICETOOL_H
