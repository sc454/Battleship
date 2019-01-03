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
}

void MainWindow::drawShipHolder(int x,int y,int w,int h)
{
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,w,h);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    panel->setBrush(brush);
    scene->addItem(panel);
}

void MainWindow::quitGame()
{
    this->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
