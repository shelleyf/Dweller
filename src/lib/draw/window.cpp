#include "window.h"

Window::Window()
{
    setPen(new QColor(255,255,0),5);
}

QPen Window::getPen(){
    return m_pen;
}

void Window::setPen(QColor color, int width){
    m_pen.setColor(color);
    m_pen.setWidth(width);
}
