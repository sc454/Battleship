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
    ~MainWindow();
    QGraphicsScene* scene;

private:
    Ui::MainWindow *ui;
    Grid* grid1;

public slots:
    void startGame();
    void quitGame();

};

#endif // MAINWINDOW_H
