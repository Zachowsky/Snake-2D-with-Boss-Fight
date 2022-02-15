#ifndef GAME_H
#define GAME_H

#include "boards.h"
#include "ui_boards.h"
#include "keyboard.h"
#include <QWidget>
#include <QDialog>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QMediaPlaylist>


namespace Ui {
class game;
}

const int SIZE=40;
const int MARGIN=1;
const int AREA_ROW=13;
const int AREA_COL=20;

/*enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};
*/
class game : public QDialog
{
    Q_OBJECT

public:
    game(QDialog *parent = nullptr);
    ~game();
    virtual void paintEvent(QPaintEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    game(const game&);

public:
    void InitGame();
    void PauseResumeGame();
    void GameOver();
    void GenerateFood();
    bool IsGameOver();
private slots:
    void SnakeUpdate(Direction dir);

private:

    QTimer *gameTimer;
    bool isPause;
    QMediaPlayer *music = new QMediaPlayer();
    QMediaPlaylist *playlist = new QMediaPlaylist();

    QPoint foodPoint;
    QList<QPoint> snake;


    int score;
    int snakedie;
    int level;
    int SPEED;
    int random;

    Ui::game *ui;
};

#endif // GAME_H
