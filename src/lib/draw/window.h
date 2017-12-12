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

    float getWindowHeight();
    void setWindowHeight(float height);

    float getWindowLeakage();
    void setWindowLeakage(float leakage);

protected:
    QColor m_WindowColor;
    QPoint m_WindowTL;
    QPoint m_WindowTR;
    QPoint m_WindowBL;
    QPoint m_WindowBR;

    float m_WindowHeight;
    float m_WindowLeakage;

    QLine m_Line;

};

#endif // WINDOW_H
