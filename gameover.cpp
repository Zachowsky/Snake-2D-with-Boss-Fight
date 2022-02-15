#include "gameover.h"
#include "ui_gameover.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"


gameover::gameover(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameover)
{
    ui->setupUi(this);
}


gameover::~gameover()
{
    delete ui;
}

void gameover::on_pushButton_clicked()
{
    hide();
    MainWindow *mainwidow = new MainWindow();
    mainwidow->show();

}
void gameover::on_pushButton_2_clicked()
{
    exit(0);
}

