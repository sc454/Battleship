#include "Grid.h"
#include "mainwindow.h"

extern MainWindow* w;

Grid::Grid()
{

}

QList<GridItem *> Grid::getSquares() const
{
    return squares;
}

void Grid::placeGridItem(int x,int y,int cols,int rows, bool r)
{
    int X_SHIFT = 35;
    for (int i = 0, n = cols; i < n; i++){
        int new_x = x+X_SHIFT*i;
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::gray);
        for(int j = 0; j < rows; j++)
        {
            GridItem* gridItem = new GridItem();
            gridItem->setPos(new_x,y+35*j);
            gridItem->setIsPlaced(true);
            if(r){
                gridItem->setIsRadar(true);
            }else{
                gridItem->setBrush(brush);
                gridItem->setOpacity(.6);
            }
            gridItem->setCoords(j,i);
            squares.append(gridItem);
            w->scene->addItem(gridItem);
        }
    }
}
