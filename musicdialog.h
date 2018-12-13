#ifndef MUSICDIALOG_H
#define MUSICDIALOG_H
#include <QDialog>
#include <QMap>
#include <QString>
#include <QUrl>
#include <QSound>
#include <QMediaPlayer> 
#include <QMediaPlaylist> 
#include<QDebug>
namespace Ui {
  class MusicDialog;
}

class MusicDialog : public QDialog
{
  Q_OBJECT
  
public:
  explicit MusicDialog(QWidget *parent = nullptr);
  ~MusicDialog();
void putar(QString k, int c) { 
QMediaPlayer bold;
bold.setMedia(QUrl::fromLocalFile("/home/rizaldi/Downloads/tet_panjang.mp3"));
bold.setVolume(50);
bold.play();
qDebug()<<k;
    if(c==0){
     // bold.stop();
     
     c=1;}else if(c==1){
       // bold.stop();
        c=0;
      }
  }
  
private slots:
  void on_pushButton_indonesia_raya_clicked();
  
  void on_pushButton_wait_2_clicked();
  
  void on_pushButton_stop_clicked();
  
  void on_pushButton_the_champion_clicked();
  
  void on_pushButton_free_throw_clicked();
  
  void on_pushButton_semangat_clicked();
  
  void on_pushButton_seru_1_clicked();
  
  void on_pushButton_seru_2_clicked();
  
  void on_pushButton_masuk_clicked();
  
  void on_pushButton_tegang_1_clicked();
  
  void on_pushButton_tegang_2_clicked();
  
  
  void on_pushButton_gagal_clicked();
  
  void on_pushButton_timeout_1_clicked();
  
  void on_pushButton_timeout_2_clicked();
  
  void on_pushButton_tet_clicked();
  
  void on_pushButton_wait_3_clicked();
  
  void on_pushButton_wait_1_clicked();
  
  void on_pushButton_timeout_3_clicked();
  
  void on_pushButton_l_menit_1_clicked();
  
  void on_pushButton_terompet_clicked();
  
  void on_pushButton_l_menit2_clicked();
  
  void on_pushButton_music_clicked();
  
  void on_pushButton_music_2_clicked();
  
private:
  Ui::MusicDialog *ui;
  int baru =0;
  QString mama;
  QMediaPlayer *player;
  QMediaPlaylist *playlist;
  QMediaPlayer::State playerState;
  QString rizaldi;
};

#endif // MUSICDIALOG_H
