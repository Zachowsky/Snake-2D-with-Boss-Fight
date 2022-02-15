#include "setoptions.h"
#include "ui_setoptions.h"
#include <QSettings>
#include <QCheckBox>
#include <QMediaPlayer>
#include <QtCore>
#include <QDebug>
#include <game.h>

SetOptions::SetOptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetOptions)
{
    ui->setupUi(this);
    LoadSettings();
}

SetOptions::~SetOptions()
{
    delete ui;
}

void SetOptions::LoadSettings()
{
    QSettings setting("Snake","Tryby");
    setting.beginGroup("Opcje");
    ui->checkBox->setChecked(setting.value("przeszkody",false).toBool());
    ui->checkBox_2->setChecked(setting.value("przechodzenie",false).toBool());
    ui->checkBox_3->setChecked(setting.value("owoce",false).toBool());
    ui->checkBox_4->setChecked(setting.value("sound",false).toBool());
    setting.endGroup();
}

void SetOptions::SaveSettings()
{
    QSettings setting("Snake","Tryby");
    setting.beginGroup("Opcje");
    setting.setValue("przeszkody", ui->checkBox->isChecked());
    setting.setValue("przechodzenie", ui->checkBox_2->isChecked());
    setting.setValue("owoce", ui->checkBox_3->isChecked());
    setting.setValue("sound", ui->checkBox_4->isChecked());
    setting.endGroup();
}

void SetOptions::on_pushButton_clicked()
{
    SaveSettings();
    hide();
}

void SetOptions::on_pushButton_2_clicked()
{
    hide();
}


