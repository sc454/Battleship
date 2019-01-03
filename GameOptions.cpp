#include "GameOptions.h"
#include <QBrush>
#include <QFont>

GameOptions::GameOptions(QString name,int tx,int ty,int f, QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setRect(0,0,tx,ty);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    QColor color = Qt::darkCyan;
    color.setAlphaF(0.5);
    brush.setColor(color);
    setBrush(brush);

    text = new QGraphicsTextItem(name,this);
    QFont textFont("comic sans", f);
    text->setFont(textFont);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    setAcceptHoverEvents(true);
}

void GameOptions::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void GameOptions::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void GameOptions::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    QColor color = Qt::darkCyan;
    color.setAlphaF(0.5);
    brush.setColor(color);
    setBrush(brush);
}
