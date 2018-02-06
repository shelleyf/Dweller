#ifndef WINDOW_H
#define WINDOW_H

#include "houseitem.h"
class Window : public HouseItem
{
public:
    Window();
    ~Window();

    QPen getPen() override;
    void setPen(QColor color,int width) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

    QRect getBoundary() override;
    bool contains(int x, int y) override;
    void setSelected(bool val) override;
    bool isSelected() override;

    QPoint getWindowPosition(int position);
    void setWindowPosition(QPoint point,int position);

    float getWindowHeight();
    void setWindowHeight(float height);

    float getWindowLeakage();
    void setWindowLeakage(float leakage);

    QPoint getStartPoint();
    void setStartPoint(QPoint value);

    QPoint getEndPoint();
    void setEndPoint(QPoint value);

    QLine *m_Line;
    QRectF *m_Rect;
protected:
    QColor m_WindowColor;
    QPoint m_WindowTL;
    QPoint m_WindowTR;
    QPoint m_WindowBL;
    QPoint m_WindowBR;

    float m_WindowHeight;
    float m_WindowLeakage;

    QPoint m_WindowStart;
    QPoint m_WindowEnd;



};

#endif // WINDOW_H
