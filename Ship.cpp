#include "Ship.h"

Ship::Ship(QString n, int l,QGraphicsItem* parent)
{
    name = n;
    length = l;

    QRect sqPoints = QRect(QPoint(0,0),QPoint(35,35*l));
    QRectF square(sqPoints);
    setRect(square);

    isPlaced = false;
    isPickedUp = false;
}

QList<GridItem *> Ship::getSpaces()
{
    return spaces;
}

QString Ship::getName()
{
    return name;
}

int Ship::getLength()
{
    return length;
}

bool Ship::getIsPlaced()
{
    return isPlaced;
}

bool Ship::getIsPickedUp()
{
    return isPickedUp;
}

void Ship::setIsPlaced(bool b)
{
    this->isPlaced = b;
}

void Ship::setIsPickedUp(bool b)
{
    this->isPickedUp = b;
}

void Ship::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}
