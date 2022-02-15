#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QKeyEvent>

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class keyboard
{
public:
    Direction dir;
    keyboard();
    void setKeys(QKeyEvent *event, Direction dir);
};

#endif // KEYBOARD_H
