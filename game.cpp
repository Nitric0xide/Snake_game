#include <QGraphicsLineItem>
#include "Game.h"


Game::Game(QWidget *parent): QGraphicsView(parent){
    QPainter painter(this);
    setFixedSize(QSize(660,660)) ;
    view = new QGraphicsView(this);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene(0,0,660,660,this);
    scene->setBackgroundBrush(QBrush(Qt::black));
    scene->setStickyFocus(true);

    view->setScene(scene);
    view->setFixedSize(660,660);
    view->setSceneRect(0,0,660,660);

    boarder_right = new Boarder(661, 0, 10, 660);
    scene->addItem(boarder_right);
    boarder_left = new Boarder(-11, 0, 10, 660);
    scene->addItem(boarder_left);
    boarder_botton = new Boarder(0, 661, 660, 10);
    scene->addItem(boarder_botton);
    boarder_top = new Boarder(0, -11, 660, 10);
    scene->addItem(boarder_top);



    timer = new QTimer(this);
    timer->start(200);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkheadpos()));
}


void Game::start(){
    animationTimer = new QTimer(this);
    connect(animationTimer,SIGNAL(timeout()),scene,SLOT(advance()));
    animationTimer->start(1000/5);

    snakeHead = new SnakeHead();
    snakeHead->setPos(30, 120);
    scene->addItem(snakeHead);
    snakeHead->setFocus();

    food = new Food();
    food->setPos(330,330);
    scene->addItem(food);
}


void Game::checkheadpos(){
    if(scene->items(snakeHead->pos()) == scene->items(food->pos())){
        delete food;
        snakeHead->elongate();
    }

    if(newfood == true){
        int x = 30 * (rand() % 21 + 1);
        int y = 30 * (rand() % 21 + 1);
        food = new Food();
        food->setPos(x, y);
        scene->addItem(food);
    }
}
