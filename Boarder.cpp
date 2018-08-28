#include <QPen>
#include "Boarder.h"


Boarder::Boarder(int x, int y, int width, int height){
    setRect(x, y, width, height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
    this->setZValue(4);
}
