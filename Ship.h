#ifndef SHIP_H
#define SHIP_H
#include <QString>
#include <QGraphicsItem>
#include "GridItem.h"

class Ship: public QGraphicsRectItem
{
public:
    Ship(QString n, int l,QGraphicsItem* parent=NULL);

    QList<GridItem*> getSpaces();
    QString getName();
    int getLength();
    bool getIsPlaced();
    bool getIsPickedUp();
    void setIsPlaced(bool b);
    void setIsPickedUp(bool b);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QString name;
    int length;
    bool isPlaced;
    bool isPickedUp;
    QList<GridItem*> spaces;
};

#endif // SHIP_H
