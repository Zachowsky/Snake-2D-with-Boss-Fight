#include "keyboard.h"
#include <QKeyEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameover.h"
#include "ui_gameover.h"

keyboard::keyboard()
{

}

void keyboard::setKeys(QKeyEvent *event, Direction dir){
    game *game = new class game();

    switch(event->key())
    {
    case Qt::Key_Up:
            dir=UP;
        break;
    case Qt::Key_Down:
            dir=DOWN;
        break;
    case Qt::Key_Left:
            dir=LEFT;
        break;
    case Qt::Key_Right:
            dir=RIGHT;
        break;
    case Qt::Key_P:
        game->PauseResumeGame();
        break;
    case Qt::Key_Escape:
        //game->PauseResumeGamegameTimer->stop();
        //game::close();
        MainWindow *mainwidow = new MainWindow();
        mainwidow->show();
    }
}
