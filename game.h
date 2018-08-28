#pragma once
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>

#include "SnakeHead.h"
#include "Boarder.h"
#include "Food.h"


class Game: public QGraphicsView{

    Q_OBJECT

public:
    QGraphicsScene* scene;
    QGraphicsView* view;
    QTimer* animationTimer;
    QTimer* timer;

    SnakeHead* snakeHead;
    Food* food;
    bool newfood = false;
    Boarder* boarder_right;
    Boarder* boarder_left;
    Boarder* boarder_botton;
    Boarder* boarder_top;

public:
    Game(QWidget* parent = nullptr);

public:
    void start();

private slots:
    void checkheadpos();
};
