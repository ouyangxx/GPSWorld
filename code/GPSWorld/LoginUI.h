#ifndef LOGINUI_H
#define LOGINUI_H

#include <QWidget>
#include "ui_LoginUI.h"
#include <QPoint>
#include <QMovie>

class LoginUI : public QWidget
{
	Q_OBJECT

public:
	LoginUI(QWidget *parent = 0);
	~LoginUI();

public slots:
	void doLogin();
	void onClientEngineStarted();
	void onLoginSuccess(bool isSuccess);

protected:
	virtual void mousePressEvent(QMouseEvent *);
	virtual void mouseReleaseEvent(QMouseEvent *);
	virtual void mouseMoveEvent(QMouseEvent *);

private:
	Ui::LoginUI ui;

	QPoint mousePoint;
	bool mousePressed;
	QMovie * m_Movie;

	QString m_usrName;
	QString m_pwd;
};

#endif // LOGINUI_H
