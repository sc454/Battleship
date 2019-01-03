#ifndef GRIDITEM_H
#define GRIDITEM_H
#include <QGraphicsItem>

class GridItem: public QGraphicsRectItem{
public:
    // constructors
    GridItem(QGraphicsItem* parent=NULL);
    bool getIsPlaced();
    bool getIsRadar();
    int getXCoord();
    int getYCoord();

    //event
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    void setIsPlaced(bool b);
    void setIsRadar(bool b);
    void setCoords(int x, int y);

private:
    bool isPlaced;
    bool isRadar;
    int xCoord;
    int yCoord;
};

#endif // GRIDITEM_H
