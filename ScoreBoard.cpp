#include "ScoreBoard.h"
#include <QSound>

namespace score {

    Board::Board()
    {
      m_timer_second.setInterval(std::chrono::seconds(1));

        connect(&m_timer_second, &QTimer::timeout,
            this, &Board::internal_on_second_tick);
    }

    void Board::home_name(const QString & str)
    {
        m_home.name(str);
        emit on_changed(changed::home_name);
    }

    const QString & Board::home_name() const
    {
        return m_home.name();
    }

    void Board::away_name(const QString & str)
    {
        m_away.name(str);
        emit on_changed(changed::away_name);
    }

    const QString & Board::away_name() const
    {
        return m_away.name();
    }

    void Board::update_home(Team * addition)
    {
        if (m_home.add_score(addition->score()))
            emit on_changed(changed::home_score);

        if (m_home.add_foul(addition->foul()))
            emit on_changed(changed::home_foul);
    }

    void Board::update_away(Team * addition)
    {
        if (m_away.add_score(addition->score()))
            emit on_changed(changed::away_score);

        if (m_away.add_foul(addition->foul()))
            emit on_changed(changed::away_foul);
    }

    void Board::reset_score()
    {
        m_home.score(0);
        emit on_changed(changed::home_score);

        m_away.score(0);
        emit on_changed(changed::away_score);
    }

    void Board::reset_foul()
    {
        m_home.foul(0);
        emit on_changed(changed::home_foul);

        m_away.foul(0);
        emit on_changed(changed::away_foul);
    }

    void Board::start_timer()
    {
        if (m_timer_second.isActive())
            return;

        if (m_time.isValid())
        {
            m_timer_second.start();
            emit  on_changed(changed::twenty_four);
        }
    }

    void Board::pause_timer()
    {
        if (m_timer_second.isActive())
        {
            m_timer_second.stop();
        }
    }

    void Board::reset_timer()
    {
        pause_timer();
        m_time.setHMS(-1, 0, 0, 0);
        emit  on_changed(changed::timer);
        reset_twenty_four();
    }

    void Board::dec_round()
    {
        m_round = std::max(m_round - 1, 1);
        emit on_changed(changed::round);
    }

    void Board::inc_round()
    {
        m_round = std::min(m_round + 1, 4);
        emit on_changed(changed::round);
    }

    int Board::round() const { return m_round; }

    void Board::set_timer_for(cr::milliseconds ms)
    {
        m_time.setHMS(0, 0, 0, 0);

        m_time = m_time.addMSecs(ms.count());
        m_seconds =  cr::duration_cast<cr::seconds>(ms);

        emit  on_changed(changed::timer);
    }

    void Board::add_timer_time(cr::milliseconds ms)
    {
        cr::milliseconds rem(0);

        if (m_timer_second.isActive() || m_time.isValid())
            rem = m_seconds;

        rem += ms;
        set_timer_for(rem);
    }

    QString Board::get_time() const
    {
        return m_time.isValid()
            ? m_time.toString("mm:ss")
            : "00:00";
    }

    int Board::twenty_four() const
    {
        return m_24;
    }
    void Board::reset_fourteen()
    {
        m_24 = 14;
        emit on_changed(changed::twenty_four);

    }
    void Board::reset_twenty_four()
    {
        m_24 = 24;
        emit on_changed(changed::twenty_four);

    }

    void Board::play_tet_sound() const
    {
        QSound::play(":/tet.wav");
    }

    void Board::on_timeout()
    {
        reset_timer();
        play_tet_sound();
    }

    void Board::internal_on_second_tick()
    {
        if (m_seconds == cr::seconds(0))
            return on_timeout();

        m_time = m_time.addSecs(-1);
        --m_seconds;

        --m_24;
        emit on_changed(changed::timer);
        emit on_changed(changed::twenty_four);

        if (m_24 == 0)
        {
            // TODO: do something
            // TEEET!!
            pause_timer();
            reset_twenty_four();
            play_tet_sound();
        }
    }
}
