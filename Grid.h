#ifndef GRID_H
#define GRID_H

#include <QList>
#include "GridItem.h"

class Grid
{
public:
    Grid();
    void placeGridItem(int x,int y,int cols,int rows, bool r);
    QList<GridItem *> getSquares() const;

private:
    QList<GridItem*> squares;
};


#endif // GRID_H
