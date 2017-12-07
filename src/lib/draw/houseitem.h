#ifndef HOUSEITEM_H
#define HOUSEITEM_H
#include <QRect>
#include <QPainter>
#include <QGraphicsItem>
#include <QVector2D>

class HouseItem : public QGraphicsItem
{
public:
    HouseItem();
    virtual void draw(QPainter *painter) = 0;
    virtual QRect getBoundary() = 0;
    virtual void setSelected(bool val) = 0;
    virtual bool isSelected() = 0;
    virtual bool contains(int x, int y) = 0;

    QVector2D itemPos;

    QString noteText;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // HOUSEITEM_H
