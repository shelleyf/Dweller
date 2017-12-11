#ifndef DEVICE_H
#define DEVICE_H
#include "houseitem.h"

class Device : public HouseItem
{
public:
    Device();

    QPen getPen() override;
    void setPen(QColor color,int width) override;
    void draw(QPainter *painter) override;

    QRect getBoundary() override;
    bool contains(int x, int y) override;

    QPoint getDevicePosition();
    void setDevicePosition (QPoint value);

    int getWidth() const;
    void setWidth(int value);

    int getHeight() const;
    void setHeight(int value);

    QString getDeviceName();
    void setDeviceName(QString &string);

protected:
    QPoint m_DevicePosition;
    int m_DeviceWidth;
    int m_DeviceHeight;

    QString m_DeviceName;
};

#endif // DEVICE_H
