#include "window.h"

Window::Window()
{

    setPen(QColor(255,255,0,255),5);
    setWindowHeight(1.5);
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

