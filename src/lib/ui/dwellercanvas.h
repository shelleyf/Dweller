#ifndef DWELLERCANVAS_H
#define DWELLERCANVAS_H

#include <QGraphicsview>
#include <math.h>
#include <QKeyEvent>
#include <QPen>
#include <QDebug>

#include "lib/tool/tool.h"

#define CANVAS_RATIO 10

class DwellerCanvas : public QGraphicsView
{
    Q_OBJECT

public:
    DwellerCanvas(QGraphicsScene *scene);
//    void itemMoved();
//    // 平移速度
    void setTranslateSpeed(qreal speed);
    qreal translateSpeed() const;

//    // 缩放的增量
    void setZoomDelta(qreal delta);
    qreal zoomDelta() const;

    QGraphicsScene *scene;
    Tool *m_ActiveTool;

public slots:
    void translate(QPointF delta);

protected:
    void keyPressEvent(QKeyEvent *event) override;
//    void timerEvent(QTimerEvent *event) override;
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void wheelEvent(QWheelEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
//    bool event(QEvent *event) override;

    void scaleView(qreal scaleFactor);
private:
    int timerId;
    qreal m_translateSpeed;
    Qt::MouseButton m_translateButton;
    QPoint m_lastMousePos;
    bool m_bMouseTranslate;
    qreal m_scale;
    qreal m_zoomDelta;


    //Node *centerNode;
};

#endif // DWELLERCANVAS_H
