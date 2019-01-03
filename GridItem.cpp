#include "GridItem.h"
#include "mainwindow.h"

extern MainWindow* w;

GridItem::GridItem(QGraphicsItem *parent)
{
    QRect sqPoints = QRect(QPoint(0,0),QPoint(35,35));

    QRectF square(sqPoints);

    setRect(square);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBrush(brush);
    isPlaced = false;
    isRadar = false;
}

bool GridItem::getIsPlaced()
{
    return isPlaced;
}

bool GridItem::getIsRadar()
{
    return isRadar;
}

int GridItem::getXCoord()
{
    return xCoord;
}

int GridItem::getYCoord()
{
    return yCoord;
}

void GridItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void GridItem::setIsPlaced(bool b)
{
    this->isPlaced = b;
}

void GridItem::setIsRadar(bool b)
{
    this->isRadar = b;
}

void GridItem::setCoords(int x, int y)
{
    this->xCoord = x;
    this->yCoord = y;
}
