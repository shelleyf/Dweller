#ifndef GLOBALCANVASDATA_H
#define GLOBALCANVASDATA_H
#include <QQmlListProperty>
#include <QObject>
#include "lib/draw/houseitem.h"
class GlobalCanvasData : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QQmlListProperty<HouseItem> houseMap READ houseMap)
    Q_PROPERTY(QString testString READ testString)

public:
    GlobalCanvasData();

    QQmlListProperty<HouseItem> houseMap();
    QString testString(){
        return m_testString;
    }

    void add(HouseItem *item);
    void remove(int index);
    void clear();
    HouseItem * find(QString string);

    QList<HouseItem *> m_Data;
    QJsonObject m_Json;
private:
    QString m_testString;

};

#endif // GLOBALCANVASDATA_H
