#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "gameoptions.h"
#include "Grid.h"
#include "ship.h"

namespace Ui {
class MainWindow;
}

class MainWindow: public QGraphicsView{
    Q_OBJECT

public:
    MainWindow(QWidget* parent=nullptr);
    void displayMainMenu();
    void drawShipHolder(int x,int y,int w,int h);
    void createShips();
    void drawShips();
    void pickUpShip(Ship* ship);
    bool getLocked();
    void placeShip(int x,int y);
    ~MainWindow();
    QGraphicsScene* scene;

    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);

private:
    Ui::MainWindow *ui;
    Grid* playerGrid;
    Grid* shipHolderGrid; // Area to drag ships from
    GameOptions* doneSettingShips;
    QList<Ship* > playerShips;
    Ship* currentShip;
    QPointF ogShipPos;
    bool locked;

public slots:
    void startGame();
    void quitGame();
    void showBattlefield();

};

#endif // MAINWINDOW_H
