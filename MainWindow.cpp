#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "gameoptions.h"
#include <QGraphicsTextItem>
#include <stdlib.h>
#include <QDebug>
#include <QFont>

MainWindow::MainWindow(QWidget *parent){
    // set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1440,900);

    // set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1440,900);
    QImage bg("/Users/sravya.chelikani/Desktop/BattleshipGame/TitleImage.jpg");
    QBrush brush(bg);
    scene->setBackgroundBrush(bg);
    setScene(scene);

    currentShip = NULL;
    locked = false;
}

void MainWindow::displayMainMenu()
{
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Battleship"));
    QFont titleFont("comic sans", 70);
    titleFont.setBold(true);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos, tyPos);
    scene->addItem(titleText);

    GameOptions* startOption = new GameOptions(QString("Start Game"),200,50,15);
    int bxPos = this->width()/2 - startOption->boundingRect().width()/2;
    int byPos = 275;
    startOption->setPos(bxPos,byPos);
    connect(startOption,SIGNAL(clicked()),this,SLOT(startGame()));
    scene->addItem(startOption);

    GameOptions* quitOption = new GameOptions(QString("Quit"),200,50,15);
    int qxPos = this->width()/2 - quitOption->boundingRect().width()/2;
    int qyPos = 350;
    quitOption->setPos(qxPos,qyPos);
    connect(quitOption,SIGNAL(clicked()),this,SLOT(quitGame()));
    scene->addItem(quitOption);
}

void MainWindow::startGame()
{
    scene->clear();
    playerGrid = new Grid();
    playerGrid->placeGridItem(345,275,10,10,false);
    drawShipHolder(745,275,350,350);
    QGraphicsTextItem* header = new QGraphicsTextItem("Drag ships to your board below");
    QFont playerFont("comic sans", 15);
    header->setFont(playerFont);
    header->setPos(400,250);
    scene->addItem(header);
    doneSettingShips = new GameOptions(QString("Done Setting Ships"),200,50,15);
    int bxPos = this->width()/2 - doneSettingShips->boundingRect().width()/2;
    int byPos = 750;
    doneSettingShips->setPos(bxPos,byPos);
    connect(doneSettingShips,SIGNAL(clicked()),this,SLOT(showBattlefield()));
    scene->addItem(doneSettingShips);
    createShips();
    drawShips();
}

void MainWindow::createShips()
{
    Ship* Carrier = new Ship("Carrier",5);
    Ship* Battleship = new Ship("Battleship",4);
    Ship* Cruiser = new Ship("Cruiser",3);
    Ship* Submarine = new Ship("Submarine",3);
    Ship* Destroyer = new Ship("Destroyer",2);
    playerShips.append(Carrier);
    playerShips.append(Battleship);
    playerShips.append(Cruiser);
    playerShips.append(Submarine);
    playerShips.append(Destroyer);
}

void MainWindow::drawShips()
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);

    for(int i = 0; i < playerShips.size(); i++){
        Ship* ship = playerShips[i];
        ship->setPos(775+53.75*i,300);
        ship->setBrush(brush);
        scene->addItem(ship);
    }
}

void MainWindow::pickUpShip(Ship *ship)
{
    if(currentShip == NULL){
        qDebug() << QString("Picked up a ship");
        currentShip = ship;
        ogShipPos = ship->pos();
        return;
    }
}

bool MainWindow::getLocked()
{
    return locked;
}

void MainWindow::placeShip(int tx, int ty)
{
    if(currentShip){
        currentShip->setPos(QPointF(345+35*tx,275+35*ty));
        currentShip->setIsPlaced(true);
        currentShip->setIsPickedUp(false);
        currentShip = NULL;
    }
    qDebug() << QString("Placed a ship");
}

void MainWindow::showBattlefield()
{

}

void MainWindow::drawShipHolder(int x,int y,int w,int h)
{
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,w,h);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    panel->setBrush(brush);
    scene->addItem(panel);
    QGraphicsTextItem* header = new QGraphicsTextItem("Your ships. Click 'R' key to rotate them");
    QFont playerFont("comic sans", 15);
    header->setFont(playerFont);
    header->setPos(x+25,y-25);
    scene->addItem(header);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(currentShip){
        currentShip->setPos(event->pos());
    }

    QGraphicsView::mouseMoveEvent(event);
}

void MainWindow::mousePressEvent(QMouseEvent *event){

    if (event->button() == Qt::RightButton){
        if (currentShip){
            currentShip->setPos(ogShipPos);
            currentShip->setIsPickedUp(false);
            currentShip = NULL;
            return;
        }
    }

    QGraphicsView::mousePressEvent(event);
}


void MainWindow::quitGame()
{
    this->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
