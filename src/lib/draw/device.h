#ifndef DEVICE_H
#define DEVICE_H
#include <QBrush>
#include "houseitem.h"

class Device : public HouseItem
{
public:
    Device();

    QPen getPen() override;
    void setPen(QColor color,int width) override;
    void draw(QPainter *painter) override;
    void setSelected(bool val) override;
    bool isSelected() override;

    QRect getBoundary() override;
    bool contains(int x, int y) override;

    QBrush getBrush();
    void setBrush();

    QPoint getDevicePositionTL();
    void setDevicePositionTL(QPoint value);

    QPoint getDevicePositionBR();
    void setDevicePositionBR(QPoint value);

    int getWidth();
    void setWidth(int value);

    int getHeight();
    void setHeight(int value);

    QString getDeviceName();
    void setDeviceName(QString string);

protected:
    QPoint m_DevicePositionTL;
    QPoint m_DevicePositionBR;
    int m_DeviceWidth;
    int m_DeviceHeight;

    QString m_DeviceName;

    QRectF m_Rect;
    QBrush m_Brush;

};

#endif // DEVICE_H
