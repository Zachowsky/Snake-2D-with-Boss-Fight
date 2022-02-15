#include "boards.h"
#include "ui_boards.h"
#include "game.h"
#include "setoptions.h"
#include "ui_setoptions.h"
#include <QSettings>
#include <QMediaPlayer>

boards::boards(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::boards)
{
    ui->setupUi(this);
    LoadSettings();
}

boards::~boards()
{
    delete ui;
}

void boards::LoadSettings()
{
    QSettings setting("Snake","Plansze");
    setting.beginGroup("Opcje");
    ui->radioButton->setChecked(setting.value("plansza1",false).toBool());
    ui->radioButton_2->setChecked(setting.value("plansza2",false).toBool());
    ui->radioButton_3->setChecked(setting.value("plansza3",false).toBool());
    ui->radioButton_4->setChecked(setting.value("plansza4",false).toBool());
    ui->radioButton_5->setChecked(setting.value("plansza5",false).toBool());
    setting.endGroup();
}

void boards::SaveSettings()
{
    QSettings setting("Snake","Plansze");
    setting.beginGroup("Opcje");
    setting.setValue("plansza1", ui->radioButton->isChecked());
    setting.setValue("plansza2", ui->radioButton_2->isChecked());
    setting.setValue("plansza3", ui->radioButton_3->isChecked());
    setting.setValue("plansza4", ui->radioButton_4->isChecked());
    setting.setValue("plansza5", ui->radioButton_5->isChecked());
    setting.endGroup();
}


void boards::on_pushButton_2_clicked()
{
    hide();
}

void boards::on_pushButton_clicked()
{
    SaveSettings();
    hide();
}
