#ifndef NQLINEPROGRESSBAR_H
#define NQLINEPROGRESSBAR_H

#include <QWidget>
#include <QLabel>
#include <QProgressBar>
#include <QTimer>

class NQLineProgressBar : public QWidget
{
    Q_OBJECT
public:
    explicit NQLineProgressBar(QWidget *parent = 0);
    ~NQLineProgressBar();

    void setupUI();
    void startLoading();
    void stopLoading();

    void setTipInfo(QString &text);
    void setBarRange(int minValue, int maxValue);
    void setBarMinValue(int minValue);
    void setBarMaxValue(int maxValue);
    void setBarCurrentValue(int value);

signals:
    void sig_UpdateCurrentValue();

public slots:
    void onUpdateProgressValue();

private:
    QLabel * m_TipLabel;
    QProgressBar * m_ProgressBar;
    QTimer * m_Timer;

    QString m_TipInfo;
    int m_CurrentValue;
    int m_MaxValue;
    int m_MinValue;
    int m_UpdateInterval;
};

#endif // NQLINEPROGRESSBAR_H
