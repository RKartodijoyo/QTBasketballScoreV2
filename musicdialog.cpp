#include "musicdialog.h"
#include "ui_musicdialog.h"
#include <QtGui/QFont>
#include <QtGui/QFontDatabase>
#include <QtGui/qevent.h>
#include<QSound>
#include<QDir>
#include <QCoreApplication>
MusicDialog::MusicDialog(QWidget *parent) :
    

  QDialog(parent),
  ui(new Ui::MusicDialog)
{
this->setWindowTitle("Panel Music");
  ui->setupUi(this);
  
  player = new QMediaPlayer(this);
  playlist = new QMediaPlaylist(this);
  player->setPlaylist(playlist);

}

MusicDialog::~MusicDialog()
{
  delete ui;
}


void MusicDialog::on_pushButton_indonesia_raya_clicked()
{
    player->stop();
  rizaldi=  QDir::currentPath()+"/music/indonesia_raya.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
  player->play();

}

void MusicDialog::on_pushButton_wait_2_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/music_waiting_2.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}

void MusicDialog::on_pushButton_stop_clicked()
{
player->stop();
  
}

void MusicDialog::on_pushButton_the_champion_clicked()
{

  player->stop();
rizaldi=  QDir::currentPath()+"/music/we_are_the_champion.mp3";

player->setMedia(QUrl::fromLocalFile(rizaldi));
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}

void MusicDialog::on_pushButton_free_throw_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/freethrow.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}

void MusicDialog::on_pushButton_semangat_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/semangat.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}

void MusicDialog::on_pushButton_seru_1_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/seru.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}

void MusicDialog::on_pushButton_seru_2_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/seru2.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}

void MusicDialog::on_pushButton_masuk_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/terompet.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();  
}

void MusicDialog::on_pushButton_tegang_1_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/tegang.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}

void MusicDialog::on_pushButton_tegang_2_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/tegang_2.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}


void MusicDialog::on_pushButton_gagal_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/freethrow_fail.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}

void MusicDialog::on_pushButton_timeout_1_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/timeout.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}

void MusicDialog::on_pushButton_timeout_2_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/timeout_2.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}

void MusicDialog::on_pushButton_tet_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/tet_panjang.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}

void MusicDialog::on_pushButton_wait_3_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/music_waiting_3.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}

void MusicDialog::on_pushButton_wait_1_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/music_waiting.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}

void MusicDialog::on_pushButton_timeout_3_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/timeout_3.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}

void MusicDialog::on_pushButton_terompet_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/terompet.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}
void MusicDialog::on_pushButton_l_menit_1_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/l_minute.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}
void MusicDialog::on_pushButton_l_menit2_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/l_minute_2.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}

void MusicDialog::on_pushButton_music_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/music_game.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
}

void MusicDialog::on_pushButton_music_2_clicked()
{
  player->stop();
rizaldi=  QDir::currentPath()+"/music/music_game_2.mp3";
player->setMedia(QUrl::fromLocalFile(rizaldi));
player->play();
    
}
