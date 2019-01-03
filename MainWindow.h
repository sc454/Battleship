#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "gameoptions.h"
#include "Grid.h"

namespace Ui {
class MainWindow;
}

class MainWindow: public QGraphicsView{
    Q_OBJECT

public:
    MainWindow(QWidget* parent=nullptr);
    void displayMainMenu();
    void drawShipHolder(int x,int y,int w,int h);
    ~MainWindow();
    QGraphicsScene* scene;

private:
    Ui::MainWindow *ui;
    Grid* playerGrid;
    Grid* shipHolderGrid; // Area to drag ships from

public slots:
    void startGame();
    void quitGame();

};

#endif // MAINWINDOW_H
