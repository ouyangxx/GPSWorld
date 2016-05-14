#ifndef NQLOADINGDIALOG_H
#define NQLOADINGDIALOG_H

#include <QWidget>
#include <QLabel>
#include <QMovie>
#include <QTimer>
#include <QString>
#include "ui_NQRoundProgressBarUI.h"

class NQRoundProgressBar : public QWidget, public Ui_NQRoundProgressBarUI
{
    Q_OBJECT

public:
	NQRoundProgressBar(QWidget *parent = 0);
    ~NQRoundProgressBar();

	void setTipInfo(QString &text);
    void startLoading();
    void stopLoading();

public slots:
    void onUpdateTipInfo();

private:
    QMovie * m_Movie;
    QTimer * m_Timer;

    QString m_TipInfo;
    int m_Index;
};

#endif // NQLOADINGDIALOG_H
