#pragma once
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QPointF>
#include <QTimer>
#include <QList>

#include "SnakeBody.h"


class SnakeHead: public QGraphicsRectItem{

private:
    enum Move_to {up, down, left, right} move;
    QTimer* currentpos;
    QList<SnakeBody*> snakeBodies;
    QPointF prevPos;
    QGraphicsScene* scene;
    SnakeBody* body;

public:
    SnakeHead();

public:
    void keyPressEvent(QKeyEvent* event);
    void elongate();
    void moveBodies();
    void advance(int phase);
};
