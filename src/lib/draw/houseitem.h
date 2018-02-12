#ifndef HOUSEITEM_H
#define HOUSEITEM_H
#include <QRect>
#include <QPainter>
#include <QGraphicsItem>
#include <QVector2D>
#include <QVector>
#include <Qpen>
#include <QColor>
#include <QJsonObject>

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

    const int margin = 1;

    QPoint itemPos;
    QString noteText;

    QPen m_pen;
    QString m_Kind;

/*protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
*/
private:
    QString m_Name;
    int index;
};

#endif // HOUSEITEM_H
