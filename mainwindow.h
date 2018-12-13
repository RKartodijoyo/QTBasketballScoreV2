#pragma once

#include <qmainwindow.h>
#include <QWidget>
#include <QLCDNumber>
#include <QSound>
#include "ScoreDialog.h"
#include "ScoreBoard.h"
#include "musicdialog.h"

namespace Ui { class MainWindow; }


class MainWindow
    : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

private slots:

    void on_Home_plus_1_clicked();
    void on_Home_plus_2_clicked();
    void on_Home_plus_3_clicked();
    void on_Home_min_1_clicked();
    void on_Home_foul_inc_clicked();
    void on_Home_foul_dec_clicked();


    void on_Away_plus_1_clicked();
    void on_Away_plus_2_clicked();
    void on_Away_plus_3_clicked();
    void on_Away_min_1_clicked();
    void on_Away_foul_inc_clicked();
    void on_Away_foul_dec_clicked();

    void on_Timer_start_clicked();
    void on_Timer_reset_clicked();
    void on_Timer_pause_clicked();
    void on_Timer_plus_1_second_clicked();
    void on_Timer_plus_1_minute_clicked();
    void on_Timer_set_15_minutes_clicked();
    void on_Timer_set_10_minutes_clicked();
    void on_Timer_set_5_minutes_clicked();
    void on_Timer_set_3_minutes_clicked();
    void on_Timer_set_1_minute_clicked();

    void on_Round_inc_clicked();
    void on_Round_dec_clicked();

    void on_Score_reset_clicked();
    void on_Home_name_textChanged(const QString &arg1);

    void on_update(score::Board::changed changed);

    void on_Away_name_textChanged(const QString &arg1);

    void on_Twenty_four_clicked();

    void on_Tet_button_clicked();
    void on_actionMusic_triggered();
    
    void on_actionExit_triggered();
    void on_fourteen_clicked();
    
private:
    void _update_home(score::Team* addition);
    void _update_away(score::Team* addition);

    Ui::MainWindow* m_ui;
    score::Board m_score;
    ScoreDialog* m_scoreDialog;
    MusicDialog *musicDialog;
    

};
