#ifndef GAMEOPTIONS_H
#define GAMEOPTIONS_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class GameOptions: public QObject, public QGraphicsRectItem{
    Q_OBJECT

public:
    GameOptions(QString name, int tx, int ty, int f, QGraphicsItem* parent=NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();

private:
    QGraphicsTextItem* text;
};


#endif // GAMEOPTIONS_H
