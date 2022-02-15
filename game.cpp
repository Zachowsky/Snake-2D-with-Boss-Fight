#include <QPainter>
#include <cstdlib>
#include <time.h>
#include <QTimer>
#include <QRect>
#include <QMessageBox>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QMediaPlayer>
#include "game.h"
#include "boards.h"
#include "ui_boards.h"
#include "setoptions.h"
#include "ui_setoptions.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameover.h"
#include "ui_gameover.h"
#include "keyboard.h"
#include <unistd.h>

using namespace std;

game::game(QDialog *parent)
        : QDialog(parent)
{
    resize(MARGIN*4+(AREA_COL+3)*SIZE,MARGIN*2+AREA_ROW*SIZE);
                 InitGame();
}
game::~game(){}

void game::InitGame()
{

    Direction dir = RIGHT;
    for(int j=4;j>=0;j--){
        snake.push_back(QPoint(j,0));
    }

    GenerateFood();
    srand (static_cast<unsigned int>(time(nullptr)));


    score = 0;
    level = 1;
    SPEED = 230;
    isPause=false;
    gameTimer=new QTimer(this);
    connect(gameTimer,SIGNAL(timeout()),this,SLOT(SnakeUpdate(dir)));
    gameTimer->start(SPEED);
}

void game::GenerateFood()
{
    foodPoint.setX(rand()%AREA_COL);
    foodPoint.setY(rand()%AREA_ROW);

    if(snake.contains(foodPoint)){
        GenerateFood();
    }
}

void game::paintEvent(QPaintEvent *event)
{
    Direction dir;
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::white);
    painter.setFont(QFont("Arial",14));
    painter.drawLine(0*SIZE,0*SIZE,0*SIZE,13*SIZE);
    painter.drawLine(20*SIZE,0*SIZE,20*SIZE,13*SIZE);
    painter.drawLine(0*SIZE,13*SIZE,20*SIZE,13*SIZE);
    boards* ui2 = new boards();

    //Wybór tła

    if(ui2->getUi()->radioButton->isChecked()){
        painter.drawImage(QRect(MARGIN,MARGIN,AREA_COL*SIZE,AREA_ROW*SIZE), QImage(":/rec/img/board1.jpg"));
    }
    else if(ui2->getUi()->radioButton_2->isChecked()){
        painter.drawImage(QRect(MARGIN,MARGIN,AREA_COL*SIZE,AREA_ROW*SIZE), QImage(":/rec/img/board2.jpg"));
   }
    else if(ui2->getUi()->radioButton_3->isChecked()){
        painter.drawImage(QRect(MARGIN,MARGIN,AREA_COL*SIZE,AREA_ROW*SIZE), QImage(":/rec/img/board3.jpg"));
   }
    else if(ui2->getUi()->radioButton_4->isChecked()){
        painter.drawImage(QRect(MARGIN,MARGIN,AREA_COL*SIZE,AREA_ROW*SIZE), QImage(":/rec/img/board4.jpg"));
    }
    else if(ui2->getUi()->radioButton_5->isChecked()){
       painter.drawImage(QRect(MARGIN,MARGIN,AREA_COL*SIZE,AREA_ROW*SIZE), QImage(":/rec/img/board5.jpg"));
   }

    //Rysowanie głowy węża.
    for(int j=0;j<snake.size();j++){
         if(snake[j].x()<20){
             if(dir==RIGHT){
                 painter.drawImage(QRect(MARGIN+snake.front().x()*SIZE,MARGIN+snake.front().y()*SIZE-2,SIZE,SIZE+5), QImage(":/rec/img/headRight.png"));
             }
             else if(dir==DOWN){
                 painter.drawImage(QRect(MARGIN+snake.front().x()*SIZE-2,MARGIN+snake.front().y()*SIZE,SIZE+5,SIZE), QImage(":/rec/img/headDown.png"));
             }
             else if(dir==UP){
                 painter.drawImage(QRect(MARGIN+snake.front().x()*SIZE-2,MARGIN+snake.front().y()*SIZE,SIZE+5,SIZE), QImage(":/rec/img/headUp.png"));
             }
             else if(dir==LEFT){
                 painter.drawImage(QRect(MARGIN+snake.front().x()*SIZE,MARGIN+snake.front().y()*SIZE-2,SIZE,SIZE+5), QImage(":/rec/img/headLeft.png"));
             }
        }
   }

    QPen pen(QColor(79,127,108), 5);
    painter.setPen(pen);
    painter.setBrush(QColor(99,160,135));

    //Rysowanie węża

    for(int i=1;i<snake.size();i++){
        if(snake[i].x()<20){
            painter.drawRect(MARGIN+snake[i].x()*SIZE,MARGIN+snake[i].y()*SIZE,SIZE,SIZE);
        }
    }

    painter.drawImage(QRect(MARGIN+foodPoint.x()*SIZE,MARGIN+foodPoint.y()*SIZE,SIZE,SIZE), QImage(":/rec/img/food.png"));

    SetOptions *ui3 = new SetOptions();

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial",14));
    painter.drawText(MARGIN*2+AREA_COL*SIZE,MARGIN+1*SIZE,"Level: "+QString::number(level));
    painter.drawText(MARGIN*3+AREA_COL*SIZE,MARGIN+2*SIZE,"Score: "+QString::number(score));

    delete ui2;
    delete ui3;
}

void game::keyPressEvent(QKeyEvent *event)
{
    Direction dir = RIGHT;
    keyboard *key = new keyboard();
    key->setKeys(event, dir);

//    switch(event->key())
//    {
//    case Qt::Key_Up:
//            dir=UP;
//        break;
//    case Qt::Key_Down:
//            dir=DOWN;
//        break;
//    case Qt::Key_Left:
//            dir=LEFT;
//        break;
//    case Qt::Key_Right:
//            dir=RIGHT;
//        break;
//    case Qt::Key_P:
//        PauseResumeGame();
//        break;
//    case Qt::Key_Escape:
//        gameTimer->stop();
//        game::close();
//        MainWindow *mainwidow = new MainWindow();
//        mainwidow->show();
//    }
}

bool game::IsGameOver(){

    int x=snake.front().x();
    int y=snake.front().y();

    if(x<0||x>AREA_COL-1||y<0||y>AREA_ROW-1)
        return true;
    for(int i=3;i<snake.size();i++)
        if(snake[i]==snake.front())
            return true;
    return false;
}

void game::SnakeUpdate(Direction dir){

         SetOptions *ui3 = new SetOptions();

         if(ui3->getUi()->checkBox_2->isChecked()==false){

            switch(dir)
            {
            case UP:
                snake.push_front(QPoint(snake.front().x(),snake.front().y()-1));
                break;
            case DOWN:
                snake.push_front(QPoint(snake.front().x(),snake.front().y()+1));
                break;
            case LEFT:
                snake.push_front(QPoint(snake.front().x()-1,snake.front().y()));
                break;
            case RIGHT:
                snake.push_front(QPoint(snake.front().x()+1,snake.front().y()));
                break;
            }
         }

         else
         {
            switch(dir)
            {
                case UP:
                    snake.push_front(QPoint(snake.front().x(),snake.front().y()-1));
                    if(snake.front().y() < 0){
                        snake.front().setY(12);
                    }
                    break;
                case DOWN:
                    snake.push_front(QPoint(snake.front().x(),snake.front().y()+1));
                    if(snake.front().y() > 12 ){
                        snake.front().setY(0);
                    }
                    break;
                case LEFT:
                    snake.push_front(QPoint(snake.front().x()-1,snake.front().y()));
                    if(snake.front().x() < 0 ){
                        snake.front().setX(19);
                    }
                    break;
                case RIGHT:
                    snake.push_front(QPoint(snake.front().x()+1,snake.front().y()));
                    if(snake.front().x() > 19 ){
                        snake.front().setX(0);
                    }
                    break;
                }
        }

    if(snake.front().x() == foodPoint.x() && snake.front().y() == foodPoint.y()){
        score+=1;
        GenerateFood();

        if(score%5 == 0 && score != 0 && SPEED>30){
            level+=1;
            SPEED -=5;
            gameTimer->start(SPEED);
        }
    }
    else{
        snake.pop_back();
    }

    if(IsGameOver()){
        GameOver();
    }
    update();
    delete ui3;
}

void game::GameOver()
{
    gameTimer->stop();
    gameover *ui5 = new gameover();
    ui5->getUi()->label_2->setNum(score);
    ui5->exec();
    game::close();

}

void game::PauseResumeGame()
{
    if(!isPause)
    {
        isPause=!isPause;
        gameTimer->stop();
        music->pause();
    }
    else
    {
        isPause=!isPause;
        gameTimer->start(SPEED);
        music->play();
    }
}


