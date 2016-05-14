#pragma execution_character_set("utf-8")
#include "ProgressBarManager\ProgressBarManager.h"
#include "NQLineProgressBar.h"
#include "NQRoundProgressBar.h"

ProgressBarManager::ProgressBarManager(QObject *parent) :
QObject(parent),
m_Type(None)
{
	m_LineBar = NULL;
	m_RoundBar = NULL;
}

void ProgressBarManager::startProgressBar(QWidget *parent, int type, QString &tipInfo)
{
	stopProgressBar();

	m_Type = type;
	switch (m_Type)
	{
	case ProgressBarType::LineBar:
		m_LineBar = new NQLineProgressBar(parent);
		m_LineBar->setTipInfo(tipInfo);
		m_LineBar->startLoading();
		m_LineBar->show();
		break;
	case RoundBar:
		m_RoundBar = new NQRoundProgressBar(parent);
		m_RoundBar->setTipInfo(tipInfo);
		m_RoundBar->startLoading();
		m_RoundBar->show();
		break;
	case None:
		break;
	}
}

void ProgressBarManager::stopProgressBar()
{
	switch (m_Type)
	{
	case LineBar:
		m_LineBar->stopLoading();
		delete m_LineBar;
		m_LineBar = NULL;
		m_Type = None;
		break;
	case RoundBar:
		m_RoundBar->stopLoading();
		delete m_RoundBar;
		m_RoundBar = NULL;
		m_Type = None;
		break;
	case None:
		break;
	}
}

