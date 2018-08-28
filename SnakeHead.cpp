#include <QBrush>
#include <QDebug>

#include "SnakeHead.h"
#include "SnakeBody.h"
#include "Boarder.h"
#include "Game.h"


extern Game* game;

SnakeHead::SnakeHead(){
    setRect(0,0,30,30);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

    setFlag(QGraphicsItem::ItemIsFocusable,true);

    body = new SnakeBody;
    body->setPos(30, 90);
    game->scene->addItem(body);
    snakeBodies.prepend(body);
    this->setZValue(3);

    currentpos = new QTimer;
    currentpos->start(100);

}


void SnakeHead::keyPressEvent(QKeyEvent *event){    
    switch(event->key()){
    case Qt::Key_Up: move = up; break;
    case Qt::Key_Down: move = down; break;
    case Qt::Key_Left: move = left; break;
    case Qt::Key_Right: move = right; break;
    default: break;
    }

}


void SnakeHead::elongate(){
    body = new SnakeBody();
    snakeBodies.prepend(body);
    body->setPos(-200,-200);
    game->scene->addItem(body);
}


void SnakeHead::moveBodies(){
    for (size_t i = 0, n = snakeBodies.size()-1; i < n; ++i){
        snakeBodies[i]->setPos(snakeBodies[i+1]->pos());
    }
    snakeBodies.last()->setPos(prevPos);
}


void SnakeHead::advance(int phase){
    prevPos = pos();
    switch(move)  {
    case down: moveBy(0, 15); moveBodies(); break;
    case up: moveBy(0, -15); moveBodies(); break;
    case right:moveBy(15, 0); moveBodies(); break;
    case left: moveBy(-15, 0); moveBodies(); break;
    default: break;
    }
    QList<QGraphicsItem *> list = collidingItems();
    foreach(QGraphicsItem * i , list){
        Boarder* wall = dynamic_cast<Boarder *>(i);
        if(i == wall){
            game->animationTimer->stop();
            qDebug() << "you lose";
        }
    }
}
