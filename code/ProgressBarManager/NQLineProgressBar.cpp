#pragma execution_character_set("utf-8")
#include "NQLineProgressBar.h"

NQLineProgressBar::NQLineProgressBar(QWidget *parent) :
    QWidget(parent),
    m_TipInfo("正在加载数据"),
    m_CurrentValue(0),
    m_MaxValue(100),
    m_MinValue(0),
    m_UpdateInterval(500)
{
    m_TipLabel = new QLabel(this);
    m_ProgressBar = new QProgressBar(this);
    m_Timer = new QTimer();
    connect(m_Timer, SIGNAL(timeout()), this, SLOT(onUpdateProgressValue()));

    setupUI();
    m_TipLabel->setText(m_TipInfo);
}

NQLineProgressBar::~NQLineProgressBar()
{
    if (NULL != m_Timer) {
        delete m_Timer;
        m_Timer = NULL;
    }
    if (NULL != m_ProgressBar) {
        delete m_ProgressBar;
        m_ProgressBar = NULL;
    }
    if (NULL != m_TipLabel) {
        delete m_TipLabel;
        m_TipLabel = NULL;
    }
}


void NQLineProgressBar::setupUI()
{
    this->setFixedSize(260, 85);
    m_TipLabel->setGeometry(10, 15, 240, 20);
    m_ProgressBar->setGeometry(10, 50, 240, 20);

    this->setStyleSheet("background-color: transparent;");
    m_TipLabel->setStyleSheet("color: black; background-color: transparent;");

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
}

void NQLineProgressBar::startLoading()
{
    m_Timer->start(m_UpdateInterval);
    m_ProgressBar->setValue(0);
}

void NQLineProgressBar::stopLoading()
{
    m_Timer->stop();
}

void NQLineProgressBar::setTipInfo(QString &text)
{
    m_TipInfo = text;
    m_TipLabel->setText(m_TipInfo);
}

void NQLineProgressBar::setBarRange(int minValue, int maxValue)
{
    m_MinValue = minValue;
    m_MaxValue = maxValue;
    m_ProgressBar->setRange(m_MinValue, m_MaxValue);
}

void NQLineProgressBar::setBarMinValue(int minValue)
{
    m_MinValue = minValue;
    m_ProgressBar->setMinimum(m_MinValue);
}

void NQLineProgressBar::setBarMaxValue(int maxValue)
{
    m_MaxValue = maxValue;
    m_ProgressBar->setMaximum(maxValue);
}

void NQLineProgressBar::setBarCurrentValue(int value)
{
    m_CurrentValue = value;
    m_ProgressBar->setValue(m_CurrentValue);
}

void NQLineProgressBar::onUpdateProgressValue()
{
    emit sig_UpdateCurrentValue();
}
