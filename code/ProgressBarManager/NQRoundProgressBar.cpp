#pragma execution_character_set("utf-8")
#include "NQRoundProgressBar.h"

#define LODING_ICON     ":/ProgressBarManager/Resources/image/loading.gif"

NQRoundProgressBar::NQRoundProgressBar(QWidget *parent)
    : QWidget(parent),
	  m_TipInfo("正在加载"),
      m_Index(0)
{
	setupUi(this);
	//setWindowIcon(QIcon(":/EBIM.ico"));
	setAttribute(Qt::WA_TranslucentBackground, true);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    m_Movie = new QMovie(LODING_ICON);
    m_Timer = new QTimer();
    connect(m_Timer, SIGNAL(timeout()), this, SLOT(onUpdateTipInfo()));

    m_TipLabel->setText(m_TipInfo);
    m_PixLabel->setMovie(m_Movie);
}

NQRoundProgressBar::~NQRoundProgressBar()
{
    if (NULL != m_Timer) {
        delete m_Timer;
        m_Timer = NULL;
    }
    if (NULL != m_Movie) {
        delete m_Movie;
        m_Movie = NULL;
    }
}

void NQRoundProgressBar::setTipInfo(QString &text)
{
	m_TipInfo = text;
	m_TipLabel->setText(m_TipInfo);
}

void NQRoundProgressBar::startLoading()
{
    m_Movie->start();
    m_Timer->start(500);
}

void NQRoundProgressBar::stopLoading()
{
    m_Index = 0;
    m_Timer->stop();
    m_Movie->stop();
}

void NQRoundProgressBar::onUpdateTipInfo()
{
    m_Index++;
    QString signal;

    if(m_Index % 6 == 1)
    {
        signal = QString(".");
    }
    else if(m_Index % 6 == 2)
    {
        signal = QString("..");
    }
	else if (m_Index % 6 == 3)
	{
		signal = QString("...");
	}
	else if (m_Index % 6 == 4)
	{
		signal = QString("....");
	}
	else if (m_Index % 6 == 5)
	{
		signal = QString(".....");
	}
    else
    {
        signal = QString("......");
    }

    QString newTipInfo = m_TipInfo + signal;
    m_TipLabel->setText(newTipInfo);
}

