#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget * parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
{
    // TODO: utilize the menu(s) properly
    m_ui->setupUi(this);
this->setWindowTitle("Panel Admin");
    connect(&m_score, &score::Board::on_changed,
            this, &MainWindow::on_update);

    // TODO: find out auto deletion of closed dialog
    m_scoreDialog = new ScoreDialog(&m_score, this);
    m_scoreDialog->show();
}

MainWindow::~MainWindow() { delete m_ui; delete m_scoreDialog; }

void MainWindow::on_Home_plus_1_clicked()
{
    score::Team score{ 1, 0 };
    _update_home(&score);
}

void MainWindow::on_Home_plus_2_clicked()
{
    score::Team score{ 2, 0 };
    _update_home(&score);
}

void MainWindow::on_Home_plus_3_clicked()
{
    score::Team score{ 3, 0 };
    _update_home(&score);
}

void MainWindow::on_Home_min_1_clicked()
{
    score::Team score{ -1, 0 };
    _update_home(&score);
}

void MainWindow::on_Home_foul_inc_clicked()
{
    score::Team score{ 0, 1 };
    _update_home(&score);
}

void MainWindow::on_Home_foul_dec_clicked()
{
    score::Team score{ 0, -1 };
    _update_home(&score);
}

void MainWindow::on_Away_plus_1_clicked()
{
    score::Team score{ 1, 0 };
    _update_away(&score);
}

void MainWindow::on_Away_plus_2_clicked()
{
    score::Team score{ 2, 0 };
    _update_away(&score);
}

void MainWindow::on_Away_plus_3_clicked()
{
    score::Team score{ 3, 0 };
    _update_away(&score);
}

void MainWindow::on_Away_min_1_clicked()
{
    score::Team score{ -1, 0 };
    _update_away(&score);
}

void MainWindow::on_Away_foul_inc_clicked()
{
    score::Team score{ 0, 1 };
    _update_away(&score);
}

void MainWindow::on_Away_foul_dec_clicked()
{
    score::Team score{ 0, -1 };
    _update_away(&score);
}

void MainWindow::on_Timer_plus_1_minute_clicked()
{
    m_score.add_timer_time(score::cr::minutes(1));
}

void MainWindow::on_Timer_plus_1_second_clicked()
{
    m_score.add_timer_time(score::cr::seconds(1));
}

void MainWindow::on_Timer_set_15_minutes_clicked()
{
    m_score.set_timer_for(score::cr::minutes(15));
}

void MainWindow::on_Timer_set_10_minutes_clicked()
{
    m_score.set_timer_for(score::cr::minutes(10));
}

void MainWindow::on_Timer_set_5_minutes_clicked()
{
    m_score.set_timer_for(score::cr::minutes(5));
}

void MainWindow::on_Timer_set_3_minutes_clicked()
{
    m_score.set_timer_for(score::cr::minutes(3));
}

void MainWindow::on_Timer_set_1_minute_clicked()
{
    m_score.set_timer_for(score::cr::minutes(1));
}

void MainWindow::on_Round_inc_clicked()
{
    m_score.inc_round();
}

void MainWindow::on_Round_dec_clicked()
{
    m_score.dec_round();
}

void MainWindow::on_Timer_start_clicked()
{
    m_score.start_timer();
}

void MainWindow::on_Timer_reset_clicked()
{
    m_score.reset_timer();
}

void MainWindow::on_Timer_pause_clicked()
{
    m_score.pause_timer();
}

void MainWindow::on_Score_reset_clicked()
{
    m_score.reset_score();
}

void MainWindow::on_update(score::Board::changed changed)
{
    switch (changed)
    {
      case score::Board::changed::home_score:
          m_ui->Home_score->display(m_score.home_score());
          return;

    case score::Board::changed::home_foul:
        m_ui->Home_foul->display(m_score.home_foul());
        return;

    case score::Board::changed::away_score:
        m_ui->Away_score->display(m_score.away_score());
        return;

    case score::Board::changed::away_foul:
        m_ui->Away_foul->display(m_score.away_foul());
        return;

    case score::Board::changed::round:
        m_ui->Round->display(m_score.round());
        return;

    case score::Board::changed::timer:
        m_ui->Timer_display->setText(m_score.get_time());
        return;

    case score::Board::changed::twenty_four:
        m_ui->Twenty_four_display->setText(QString("%1").arg(m_score.twenty_four()));
        return;
    }
}

void MainWindow::_update_home(score::Team * addition)
{
    m_score.update_home(addition);
}

void MainWindow::_update_away(score::Team * addition)
{
    m_score.update_away(addition);
}

void MainWindow::on_Home_name_textChanged(const QString &name)
{
    m_score.home_name(name);
}

void MainWindow::on_Away_name_textChanged(const QString &name)
{
    m_score.away_name(name);
}

void MainWindow::on_Twenty_four_clicked()
{
    m_score.reset_twenty_four();
}

void MainWindow::on_Tet_button_clicked()
{
    m_score.play_tet_sound();
}

void MainWindow::on_fourteen_clicked()
{
        m_score.reset_fourteen();
}
void MainWindow::on_actionMusic_triggered(){
  
 musicDialog = new MusicDialog(this);

  musicDialog->show();}

void MainWindow::on_actionExit_triggered(){
  
  destroy();
}
