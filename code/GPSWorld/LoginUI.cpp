#pragma execution_character_set("utf-8")
#include "LoginUI.h"
#include "GPSWorld.h"
#include "HDataManager\HDataManager.h"
#include <QMouseEvent>
#include <QDateTime>
#include <QMessageBox>

#define LODING_GIF     ":/Login/Resources/login/logining.gif"
#define LOGIN_NORMAL   ":/Login/Resources/login/button_login_normal.png"

LoginUI::LoginUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_Movie = new QMovie(LODING_GIF);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
	connect(ui.btn_close, SIGNAL(clicked(bool)), this, SLOT(close()));
	connect(ui.btn_min, SIGNAL(clicked(bool)), this, SLOT(showMinimized()));
	connect(ui.btn_login, &QPushButton::clicked, this, &LoginUI::doLogin);

	connect(HDataManager::instance().m_pClientEngine, &HClientEngine::sig_engineStarted, this, &LoginUI::onClientEngineStarted);
	connect(&HDataManager::instance(), &HDataManager::sig_loginSuccess, this, &LoginUI::onLoginSuccess);
	connect(ui.lineEdit_pwd, &QLineEdit::returnPressed, this, &LoginUI::doLogin);
}

LoginUI::~LoginUI()
{

}

void LoginUI::mouseMoveEvent(QMouseEvent *e)
{
	if (mousePressed && (e->buttons() && Qt::LeftButton)) {
		this->move(e->globalPos() - mousePoint);
		e->accept();
	}
}

void LoginUI::mousePressEvent(QMouseEvent *e)
{
	if (e->button() == Qt::LeftButton) {
		mousePressed = true;
		mousePoint = e->globalPos() - this->pos();
		e->accept();
	}
}

void LoginUI::mouseReleaseEvent(QMouseEvent *)
{
	mousePressed = false;
}

void LoginUI::doLogin()
{
	m_Movie->stop();
	m_Movie->start();
	ui.btn_login->setIcon(QIcon(m_Movie->currentPixmap()));
	ui.btn_login->setEnabled(false);

	m_usrName = ui.comb_usrName->currentText();
	m_pwd = ui.lineEdit_pwd->text();

	HDataManager::instance().startClientEngine();
}

void LoginUI::onClientEngineStarted()
{
	HDataManager::instance().m_pClientEngine->login(m_usrName, m_pwd);
}


void LoginUI::onLoginSuccess(bool isSuccess)
{
	if (isSuccess) {
		GPSWorld * pGPSWorld = new GPSWorld;
		this->close();
		pGPSWorld->show();
	}
	else {
		m_Movie->stop();
		ui.btn_login->setIcon(QIcon(LOGIN_NORMAL));
		ui.btn_login->setEnabled(true);
		HDataManager::instance().m_pClientEngine->stopEngine();
		QMessageBox::information(this, "ÌáÊ¾", "µÇÂ¼Ê§°Ü");
	}
}