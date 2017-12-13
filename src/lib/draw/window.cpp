#include "window.h"

Window::Window()
{

    setPen(QColor(255,255,0,255),5);
    setWindowHeight(1.5);
}

void Window::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

}

QRectF Window::boundingRect() const{

}

QPen Window::getPen(){
    return m_pen;
}

void Window::setPen(QColor color, int width){
    m_pen.setColor(color);
    m_pen.setWidth(width);
}

QRect Window::getBoundary(){

}

bool Window::contains(int x, int y){

}

void Window::setSelected(bool val){

}

bool Window::isSelected(){

}

float Window::getWindowHeight(){
    return m_WindowHeight;
}

void Window::setWindowHeight(float height){
    m_WindowHeight = height;
}

void Window::setWindowLeakage(float leakage){
    m_WindowLeakage = leakage;
}

float Window::getWindowLeakage(){
    return m_WindowLeakage;
}


QPoint Window::getWindowPosition(int position){
    switch(position){
        case 1:
            return m_WindowTL;
        case 2:
            return m_WindowTR;
        case 3:
            return m_WindowBL;
        case 4:
            return m_WindowBR;
    }
}

void Window::setWindowPosition(QPoint point,int position){
    switch(position){
        case 1:
            m_WindowTL = point;
        case 2:
            m_WindowTR = point;
        case 3:
            m_WindowBL = point;
        case 4:
            m_WindowBR = point;
    }
}

QPoint Window::getStartPoint(){
    return m_WindowStart;
}

void Window::setStartPoint(QPoint point){
    m_WindowStart = point;
}

QPoint Window::getEndPoint(){
    return m_WindowEnd;
}

void Window::setEndPoint(QPoint point){
    m_WindowEnd = point;
}

