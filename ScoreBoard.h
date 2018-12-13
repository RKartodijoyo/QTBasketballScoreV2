#pragma once
#include <QWidget>
#include <QTime>
#include <QTimer>
#include<chrono>

namespace score {

    namespace cr = std::chrono;

    class Team
    {
    private:
        int m_score = 0;
        int m_foul = 0;
        QString m_name;
    public:
        Team() { }
        Team(int score, int foul) : m_score(score), m_foul(foul) { }
        ~Team() { }
        bool add_score(int add) { m_score = std::max(m_score + add, 0); return add != 0; }
        bool add_foul(int add) { m_foul = std::max(m_foul + add, 0); return add != 0; }
        int score() const { return m_score; }
        void score(int _score) { m_score = _score; }
        int foul() const { return m_foul; }
        void foul(int _foul) { m_foul = _foul; }

        void name(const QString& str) { m_name = str; }
        const QString& name() const { return m_name; }
    };

    class Board
        : public QObject
    {
        Q_OBJECT

    public:
        Board();
        ~Board() { }


        int home_score() const { return m_home.score(); }
        int home_foul() const { return m_home.foul(); }
        int away_score() const { return m_away.score(); }
        int away_foul() const { return m_away.foul(); }

        void home_name(const QString& str);
        const QString& home_name() const;

        void away_name(const QString& str);
        const QString& away_name() const;

        void update_home(Team* add);
        void update_away(Team* add);
        void reset_score();
        void reset_foul();

        void start_timer();
        void pause_timer();
        void reset_timer();

        void dec_round();
        void inc_round();
        int round() const;

        void set_timer_for(cr::milliseconds ms);
        void add_timer_time(cr::milliseconds ms);
        QString get_time() const;

        int twenty_four() const;
        void reset_twenty_four();
void reset_fourteen();
        void play_tet_sound() const;

        enum class changed
        {
            home_score,
            home_foul,
            home_name,
            away_score,
            away_foul,
            away_name,
            round,
            timer,
            twenty_four,
        };
    signals:
        void on_changed(changed change);

    private slots:
        void internal_on_second_tick();
        void on_timeout();

    private:
        Team m_home;
        Team m_away;
        int m_round = 1;

        QTime m_time;
        
        cr::seconds m_seconds;
        QTimer m_timer_second;
        int m_24 = 24;
    };
}
