#ifndef HOUSEITEM_H
#define HOUSEITEM_H
#include <QRect>
#include <QPainter>
#include <QGraphicsItem>
#include <QVector2D>
#include <QVector>
#include <Qpen>
#include <QColor>

class HouseItem : public QGraphicsItem
{
public:
    HouseItem();
    virtual ~HouseItem();

    virtual QRect getBoundary();
    virtual void setSelected(bool val);
    virtual bool isSelected();
    virtual bool contains(int x, int y);

    virtual void setPen(QColor color,int width);
    virtual QPen getPen();

    QPoint itemPos;
    QString noteText;

    QPen m_pen;

/*protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
*/
};

#endif // HOUSEITEM_H
