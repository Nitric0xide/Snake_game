#include <QBrush>

#include "Food.h"
#include "game.h"


extern Game* game;

Food::Food(){
    setRect(0,0,30,30);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);
    this->setZValue(1);
    game->newfood = false;
}


Food::~Food(){
    game->newfood = true;
}
