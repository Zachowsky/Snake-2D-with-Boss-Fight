#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setoptions.h"
#include "ui_setoptions.h"
#include "game.h"
#include "boards.h"
#include <QDialog>
#include <QPushButton>
#include <QMediaPlayer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

game::game(const game&) : QDialog(){};

void MainWindow::on_pushButton_clicked()
{
    hide();
    game *g = new game();
    g->setModal(true);
    g->exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    SetOptions setoptions;
    setoptions.setModal(true);
    setoptions.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    boards board;
    board.setModal(true);
    board.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
}

