#pragma once

#include <QDialog>
#include <QMap>
#include "ScoreBoard.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class fourthdialog;
}
QT_END_NAMESPACE

class MainWindow;
class ScoreDialog
    : public QDialog
{
    Q_OBJECT

public:
    explicit ScoreDialog(score::Board* score, QWidget *parent = 0);
    ~ScoreDialog();

private slots:
    void on_update(score::Board::changed changed);

private:
    Ui::fourthdialog* m_ui;
    void resizeEvent(QResizeEvent * event);
    float m_height = 0.0f;
    float m_witdh = 0.0f;
    QMap<QWidget*, int> m_font_size;
    score::Board* m_score;

};
