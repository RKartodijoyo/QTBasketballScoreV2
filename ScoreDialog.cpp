#include "ScoreDialog.h"
#include "ui_ScoreDialog.h"
#include <QtGui/QFont>
#include <QtGui/QFontDatabase>
#include <QtGui/qevent.h>
#include <QString>

ScoreDialog::ScoreDialog(score::Board* score, QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::fourthdialog)
    
    , m_score(score)
{
    m_ui->setupUi(this);
    this->setWindowTitle("Panel Score");
    m_witdh = this->rect().width();
    m_height = this->rect().height();

    connect(m_score, &score::Board::on_changed,
        this, &ScoreDialog::on_update);

    for (auto& child : this->children())
    {
        if (QWidget* tmp = qobject_cast<QWidget*>(child))
            m_font_size[tmp] = tmp->font().pointSize();
    }

    on_update(score::Board::changed::home_score);
    on_update(score::Board::changed::away_score);
}

ScoreDialog::~ScoreDialog()
{
    delete m_ui;
}

void ScoreDialog::resizeEvent(QResizeEvent * event)
{
    auto height_ratio = event->size().height() / m_height;
    auto width_ratio = event->size().width() / m_witdh;
    auto font_ratio = std::min(height_ratio, width_ratio);

    if (font_ratio <= 0) return;

    auto resize_font = [](QWidget *obj, int fontSize, float ratio)
    {
        if (fontSize <= 0) return;

        fontSize *= ratio;

#if 0
        const QString fontFormat("font: %1pt");
        QRegExp font("font:\\s+[0-9]+pt");
        QRegExp fontsize("[0-9]+");

        if (font.indexIn(obj->styleSheet()) != -1)
        {
            auto fontText = font.capturedTexts().at(0);
            if (fontsize.indexIn(fontText) != -1)
            {
                auto stylesheet = obj->styleSheet();
                stylesheet.replace(font, fontFormat.arg(fontSize));
                obj->setStyleSheet(stylesheet);
            }
        }
        else
        {
#endif // 0

            auto font = obj->font();
            font.setPointSize(fontSize);
            obj->setFont(font);
#if 0
        }
#endif // 0

    };

    for (auto& child : this->children())
        if (QWidget* widget = qobject_cast<QWidget*>(child))
            resize_font(widget, m_font_size[widget], font_ratio);

}

void ScoreDialog::on_update(score::Board::changed changed)
{
    QString score("%1");
    switch (changed)
    {
    case score::Board::changed::home_score:
        m_ui->Home_score->setText(score.arg(m_score->home_score(), 3, 10, QChar(' ')));
        break;

    case score::Board::changed::home_foul:
        m_ui->Home_foul->setText(score.arg(m_score->home_foul()));
        break;

    case score::Board::changed::away_score:
        m_ui->Away_score->setText(score.arg(m_score->away_score(), 3, 10, QChar(' ')));
        break;

    case score::Board::changed::away_foul:
        m_ui->Away_foul->setText(score.arg(m_score->away_foul()));
        break;

    case score::Board::changed::round:
        m_ui->Rounds->setText(score.arg(m_score->round()));
        break;

    case score::Board::changed::timer:
        m_ui->Timer_display->setText(m_score->get_time());
        break;

    case score::Board::changed::home_name:
        m_ui->Home_name->setText(m_score->home_name());
        break;

    case score::Board::changed::away_name:
        m_ui->Away_name->setText(m_score->away_name());
        break;

    case score::Board::changed::twenty_four:
        m_ui->Twenty_four->setText(score.arg(m_score->twenty_four()));
    default:
        break;
    }
}

