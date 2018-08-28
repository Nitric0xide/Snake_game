#include <QBrush>
#include "SnakeBody.h"


SnakeBody::SnakeBody(){
    setRect(0,0,30,30);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);
    this->setZValue(2);
}
