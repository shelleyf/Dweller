#ifndef WINDOW_H
#define WINDOW_H

#include "houseitem.h"
class Window : public HouseItem
{
public:
    Window();

    QPen getPen() override;
    void setPen(QColor color,int width) override;
    void draw(QPainter *painter) override;

    QRect getBoundary() override;
    bool contains(int x, int y) override;

    QPoint getWindowPosition(int position);
    void setWindowPosition(QPoint point,int position);

    int getDoorHeight();
    void setDoorHeight(int height);

    float getDoorLeakage();
    void setDoorLeakage(float leakage);

protected:
    QColor m_WindowColor;
    QPoint m_WindowTL;
    QPoint m_WindowTR;
    QPoint m_WindowBL;
    QPoint m_WindowBR;

    int m_WindowThickness;
    int m_WindowHeight;
    float m_WindowLeakage;

};

#endif // WINDOW_H
