#pragma execution_character_set("utf-8")
#include "GPSWorld.h"
#include "HDataManager\HDataManager.h"
#include "IconHelper\IconHelper.h"
#include "XYIntelligentMonitor\XYIntelligentMonitor.h"
#include "XYAlarmManagement\XYAlarmManagement.h"
#include "XYBaseManagement\XYBaseManagement.h"
#include "XYEngineerManagement\XYEngineerManagement.h"
#include "XYReportCenter\XYReportCenter.h"
#include <QMouseEvent>
#include <QDesktopWidget>
#include <QMenu>
#include <QAction>

#define ACTION_ICON_HisTrack	    ":/GPSWorld/Resources/image/track.png"
#define ACTION_ICON_CurveDiagram    ":/GPSWorld/Resources/image/curve.png"
#define ACTION_ICON_VideoMonitor    ":/GPSWorld/Resources/image/video.png"
#define ACTION_ICON_GoverRegulation ":/GPSWorld/Resources/image/govn.png"
#define ACTION_ICON_AlarmSetting    ":/GPSWorld/Resources/image/alarmsetting.png"
#define ACTION_ICON_AlarmMonitor    ":/GPSWorld/Resources/image/alarmmonitor.png"
#define ACTION_ICON_AlarmSuper      ":/GPSWorld/Resources/image/Alarmsuper.png"
#define ACTION_ICON_AlarmStatistics ":/GPSWorld/Resources/image/alarmstatistics.png"
#define ACTION_ICON_BaseReport      ":/GPSWorld/Resources/image/report.png"
#define ACTION_ICON_UsrReport       ":/GPSWorld/Resources/image/report.png"


GPSWorld::GPSWorld(QWidget *parent)
	: QWidget(parent),
mousePressed(false),
location(this->geometry()),
max(false),
m_pWatchMenu(nullptr),
m_pWarnMenu(nullptr),
m_pRepMenu(nullptr)
{
	ui.setupUi(this);
	initStyle();

	ui.stackedWidget->addWidget(XYIntelligentMonitor::instance().ActiveIntelligentMonitor());
	ui.stackedWidget->addWidget(XYIntelligentMonitor::instance().ActiveHisTrack());
	ui.stackedWidget->addWidget(XYIntelligentMonitor::instance().ActiveCurveDiagram());
	ui.stackedWidget->addWidget(XYIntelligentMonitor::instance().ActiveVideoMonitor());
	ui.stackedWidget->addWidget(XYIntelligentMonitor::instance().ActiveGoverRegulation());
	ui.stackedWidget->addWidget(XYAlarmManagement::instance().ActiveAlarmManagement());
	ui.stackedWidget->addWidget(XYBaseManagement::instance().ActiveBaseManagement());
	ui.stackedWidget->addWidget(XYEngineerManagement::instance().ActiveEngineerManagement());
	ui.stackedWidget->addWidget(XYReportCenter::instance().ActiveBaseReport());
	ui.stackedWidget->addWidget(XYReportCenter::instance().ActiveUsrReport());

	m_pCentralWidget = XYIntelligentMonitor::instance().ActiveIntelligentMonitor();
	ui.stackedWidget->setCurrentWidget(m_pCentralWidget);
}

GPSWorld::~GPSWorld()
{
	ui.stackedWidget->removeWidget(XYReportCenter::instance().ActiveUsrReport());
	ui.stackedWidget->removeWidget(XYReportCenter::instance().ActiveBaseReport());
	ui.stackedWidget->removeWidget(XYEngineerManagement::instance().ActiveEngineerManagement());
	ui.stackedWidget->removeWidget(XYBaseManagement::instance().ActiveBaseManagement());
	ui.stackedWidget->removeWidget(XYAlarmManagement::instance().ActiveAlarmManagement());
	ui.stackedWidget->removeWidget(XYIntelligentMonitor::instance().ActiveGoverRegulation());
	ui.stackedWidget->removeWidget(XYIntelligentMonitor::instance().ActiveVideoMonitor());
	ui.stackedWidget->removeWidget(XYIntelligentMonitor::instance().ActiveCurveDiagram());
	ui.stackedWidget->removeWidget(XYIntelligentMonitor::instance().ActiveHisTrack());
	ui.stackedWidget->removeWidget(XYIntelligentMonitor::instance().ActiveIntelligentMonitor());

	m_pCentralWidget = XYIntelligentMonitor::instance().ActiveIntelligentMonitor(); if (NULL != m_pCentralWidget) delete m_pCentralWidget;
	m_pCentralWidget = XYIntelligentMonitor::instance().ActiveHisTrack();           if (NULL != m_pCentralWidget) delete m_pCentralWidget;
	m_pCentralWidget = XYIntelligentMonitor::instance().ActiveCurveDiagram();       if (NULL != m_pCentralWidget) delete m_pCentralWidget;
	m_pCentralWidget = XYIntelligentMonitor::instance().ActiveVideoMonitor();       if (NULL != m_pCentralWidget) delete m_pCentralWidget;
	m_pCentralWidget = XYIntelligentMonitor::instance().ActiveGoverRegulation();    if (NULL != m_pCentralWidget) delete m_pCentralWidget;
	m_pCentralWidget = XYAlarmManagement::instance().ActiveAlarmManagement();       if (NULL != m_pCentralWidget) delete m_pCentralWidget;
	m_pCentralWidget = XYBaseManagement::instance().ActiveBaseManagement();         if (NULL != m_pCentralWidget) delete m_pCentralWidget;
	m_pCentralWidget = XYEngineerManagement::instance().ActiveEngineerManagement(); if (NULL != m_pCentralWidget) delete m_pCentralWidget;
	m_pCentralWidget = XYReportCenter::instance().ActiveBaseReport();               if (NULL != m_pCentralWidget) delete m_pCentralWidget;
	m_pCentralWidget = XYReportCenter::instance().ActiveUsrReport();                if (NULL != m_pCentralWidget) delete m_pCentralWidget;
	m_pCentralWidget = NULL;
}

void GPSWorld::initStyle()
{
	//设置窗体标题栏隐藏
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

	IconHelper::Instance()->SetIcon(ui.btnMenu_Close, QChar(0xf00d), 10);
	IconHelper::Instance()->SetIcon(ui.btnMenu_Max, QChar(0xf096), 10);
	IconHelper::Instance()->SetIcon(ui.btnMenu_Min, QChar(0xf068), 10);
	IconHelper::Instance()->SetIcon(ui.btnMenu, QChar(0xf0c9), 10);
	IconHelper::Instance()->SetIcon(ui.terminalCommand, QChar(0xf06c), 10);
	IconHelper::Instance()->SetIcon(ui.terminalSetting, QChar(0xf0c1), 10);
	IconHelper::Instance()->SetIcon(ui.Warnning, QChar(0xf0a2), 13);
	IconHelper::Instance()->SetIcon(ui.OnlineNotice, QChar(0xf0a2), 13);

	//安装事件监听器
	ui.lab_title->installEventFilter(this);
	ui.widget_watchTool->installEventFilter(this); 
	ui.widget_warnTool->installEventFilter(this);
	ui.widget_proTool->installEventFilter(this);
	ui.widget_baseTool->installEventFilter(this);
	ui.widget_repTool->installEventFilter(this);
}

void GPSWorld::on_btnMenu_Close_clicked()
{
	qApp->exit();
}

void GPSWorld::on_btnMenu_Max_clicked()
{
	if (max) {
		this->setGeometry(location);
		IconHelper::Instance()->SetIcon(ui.btnMenu_Max, QChar(0xf096), 10);
		ui.btnMenu_Max->setToolTip("最大化");
	}
	else {
		location = this->geometry();
		this->setGeometry(qApp->desktop()->availableGeometry());
		IconHelper::Instance()->SetIcon(ui.btnMenu_Max, QChar(0xf079), 10);
		ui.btnMenu_Max->setToolTip("还原");
	}
	max = !max;
}

void GPSWorld::on_btnMenu_Min_clicked()
{
	this->showMinimized();
}

void GPSWorld::on_watchButton_clicked()
{
	m_pCentralWidget = XYIntelligentMonitor::instance().ActiveIntelligentMonitor();
	ui.stackedWidget->setCurrentWidget(m_pCentralWidget);
}
void GPSWorld::on_warningButton_clicked()
{
	m_pCentralWidget = XYAlarmManagement::instance().ActiveAlarmManagement();
	ui.stackedWidget->setCurrentWidget(m_pCentralWidget);
}
void GPSWorld::on_baseButton_clicked()
{
	m_pCentralWidget = XYBaseManagement::instance().ActiveBaseManagement();
	ui.stackedWidget->setCurrentWidget(m_pCentralWidget);
}
void GPSWorld::on_proButton_clicked()
{
	m_pCentralWidget = XYEngineerManagement::instance().ActiveEngineerManagement();
	ui.stackedWidget->setCurrentWidget(m_pCentralWidget);
}
void GPSWorld::on_reportButton_clicked()
{
	m_pCentralWidget = XYReportCenter::instance().ActiveBaseReport();
	ui.stackedWidget->setCurrentWidget(m_pCentralWidget);
}

void GPSWorld::onAction_HisTrack()
{
	m_pCentralWidget = XYIntelligentMonitor::instance().ActiveHisTrack();
	ui.stackedWidget->setCurrentWidget(m_pCentralWidget);
}
void GPSWorld::onAction_CurveDiagram()
{
	m_pCentralWidget = XYIntelligentMonitor::instance().ActiveCurveDiagram();
	ui.stackedWidget->setCurrentWidget(m_pCentralWidget);
}
void GPSWorld::onAction_VideoMonitor()
{
	m_pCentralWidget = XYIntelligentMonitor::instance().ActiveVideoMonitor();
	ui.stackedWidget->setCurrentWidget(m_pCentralWidget);
}
void GPSWorld::onAction_GoverRegulation()
{
	m_pCentralWidget = XYIntelligentMonitor::instance().ActiveGoverRegulation();
	ui.stackedWidget->setCurrentWidget(m_pCentralWidget);
}
void GPSWorld::onAction_AlarmSetting()
{
	m_pCentralWidget = XYAlarmManagement::instance().ActiveAlarmSetting();
	ui.stackedWidget->setCurrentWidget(m_pCentralWidget);
}
void GPSWorld::onAction_AlarmMonitor()
{
	m_pCentralWidget = XYAlarmManagement::instance().ActiveAlarmMonitor();
	ui.stackedWidget->setCurrentWidget(m_pCentralWidget);
}
void GPSWorld::onAction_AlarmSuper()
{
	m_pCentralWidget = XYAlarmManagement::instance().ActiveAlarmSuper();
	ui.stackedWidget->setCurrentWidget(m_pCentralWidget);
}
void GPSWorld::onAction_AlarmStatistics()
{
	m_pCentralWidget = XYAlarmManagement::instance().ActiveAlarmStatistics();
	ui.stackedWidget->setCurrentWidget(m_pCentralWidget);
}
void GPSWorld::onAction_BaseReport()
{
	m_pCentralWidget = XYReportCenter::instance().ActiveBaseReport();
	ui.stackedWidget->setCurrentWidget(m_pCentralWidget);
}
void GPSWorld::onAction_UsrReport()
{
	m_pCentralWidget = XYReportCenter::instance().ActiveUsrReport();
	ui.stackedWidget->setCurrentWidget(m_pCentralWidget);
}

bool GPSWorld::eventFilter(QObject *obj, QEvent *event)
{
	//标题栏事件
	if (obj == ui.lab_title) {
		if (event->type() == QEvent::MouseButtonDblClick) {
			this->on_btnMenu_Max_clicked();
			return true;
		}
		if (event->type() == QEvent::MouseMove) {
			QMouseEvent *e = static_cast<QMouseEvent *>(event);
			if (mousePressed && (e->buttons() && Qt::LeftButton) && !max) {
				this->move(e->globalPos() - mousePoint);
				return true;
			}
			if (mousePressed && (e->buttons() && Qt::LeftButton) && max) {
				on_btnMenu_Max_clicked();
				return true;
			}
		}
		if (event->type() == QEvent::MouseButtonPress) {
			QMouseEvent *e = static_cast<QMouseEvent *>(event);
			if (e->button() == Qt::LeftButton) {
				mousePressed = true;
				mousePoint = e->globalPos() - this->pos();
				return true;
			}
		}
		if (event->type() == QEvent::MouseButtonRelease) {
			mousePressed = false;
			return true;
		}
	}
	
	//导航选择弹出菜单
	if (obj == ui.widget_watchTool) {
		if (event->type() == QEvent::HoverMove) {
			if (m_pWatchMenu) {
				delete m_pWatchMenu;
				m_pWatchMenu = NULL;
			}
			m_pWatchMenu = new QMenu(this);
			m_pWatchMenu->setStyleSheet("QMenu{border:0px solid;}QMenu::item{background-color:#1b89CA;color:#FFFFFF;font-size:12px;height:30px;width:100px;padding-left:20px;}QMenu::item:selected{background-color:#187eb9;}");
			QAction *pActionHisTrack = new QAction(QIcon(ACTION_ICON_HisTrack), "历史轨迹", m_pWatchMenu);
			QAction *pActionCurveDiagram = new QAction(QIcon(ACTION_ICON_CurveDiagram), "曲线图", m_pWatchMenu);
			QAction *pActionVideoMonitor = new QAction(QIcon(ACTION_ICON_VideoMonitor), "视频监控", m_pWatchMenu);
			QAction *pActionGoverRegulation = new QAction(QIcon(ACTION_ICON_GoverRegulation), "政府监管", m_pWatchMenu);
			connect(pActionHisTrack, &QAction::triggered, this, &GPSWorld::onAction_HisTrack);
			connect(pActionCurveDiagram, &QAction::triggered, this, &GPSWorld::onAction_CurveDiagram);
			connect(pActionVideoMonitor, &QAction::triggered, this, &GPSWorld::onAction_VideoMonitor);
			connect(pActionGoverRegulation, &QAction::triggered, this, &GPSWorld::onAction_GoverRegulation);
			m_pWatchMenu->addAction(pActionHisTrack);
			m_pWatchMenu->addAction(pActionCurveDiagram);
			m_pWatchMenu->addAction(pActionVideoMonitor);
			m_pWatchMenu->addAction(pActionGoverRegulation);
			QPoint point = this->pos() + ui.widget_tool->pos() + ui.widget_toolBtn->pos() + ui.widget_watchTool->pos();
			m_pWatchMenu->exec(QPoint(point.x(), point.y() + ui.widget_watchTool->height()));
			return true;
		}
	}
	if (obj == ui.widget_warnTool) {
		if (event->type() == QEvent::HoverMove) {
			if (m_pWarnMenu) {
				delete m_pWarnMenu;
				m_pWarnMenu = NULL;
			}
			m_pWarnMenu = new QMenu(this);
			m_pWarnMenu->setStyleSheet("QMenu{border:0px solid;}QMenu::item{background-color:#1b89CA;color:#FFFFFF;font-size:12px;height:30px;width:100px;padding-left:20px;}QMenu::item:selected{background-color:#187eb9;}");
			QAction *pActionAlarmSetting = new QAction(QIcon(ACTION_ICON_AlarmSetting), "报警设置", m_pWarnMenu);
			QAction *pActionAlarmMonitor = new QAction(QIcon(ACTION_ICON_AlarmMonitor), "报警监控", m_pWarnMenu);
			QAction *pActionAlarmSuper = new QAction(QIcon(ACTION_ICON_AlarmSuper), "报警督办", m_pWarnMenu);
			QAction *pActionAlarmStatistics = new QAction(QIcon(ACTION_ICON_AlarmStatistics), "报警统计", m_pWarnMenu);
			connect(pActionAlarmSetting, &QAction::triggered, this, &GPSWorld::onAction_AlarmSetting);
			connect(pActionAlarmMonitor, &QAction::triggered, this, &GPSWorld::onAction_AlarmMonitor);
			connect(pActionAlarmSuper, &QAction::triggered, this, &GPSWorld::onAction_AlarmSuper);
			connect(pActionAlarmStatistics, &QAction::triggered, this, &GPSWorld::onAction_AlarmStatistics);
			m_pWarnMenu->addAction(pActionAlarmSetting);
			m_pWarnMenu->addAction(pActionAlarmMonitor);
			m_pWarnMenu->addAction(pActionAlarmSuper);
			m_pWarnMenu->addAction(pActionAlarmStatistics);
			QPoint point = this->pos() + ui.widget_tool->pos() + ui.widget_toolBtn->pos() + ui.widget_warnTool->pos();
			m_pWarnMenu->exec(QPoint(point.x(), point.y() + ui.widget_warnTool->height()));
			return true;
		}
	}
	if (obj == ui.widget_repTool) {
		if (event->type() == QEvent::HoverMove) {
			if (m_pRepMenu) {
				delete m_pRepMenu;
				m_pRepMenu = NULL;
			}
			m_pRepMenu = new QMenu(this);
			m_pRepMenu->setStyleSheet("QMenu{border:0px solid;}QMenu::item{background-color:#1b89CA;color:#FFFFFF;font-size:12px;height:30px;width:100px;padding-left:20px;}QMenu::item:selected{background-color:#187eb9;}");
			QAction *pActionBaseReport = new QAction(QIcon(ACTION_ICON_BaseReport), "基础报表", m_pRepMenu);
			QAction *pActionUsrReport = new QAction(QIcon(ACTION_ICON_UsrReport), "用户报表", m_pRepMenu);
			connect(pActionBaseReport, &QAction::triggered, this, &GPSWorld::onAction_BaseReport);
			connect(pActionUsrReport, &QAction::triggered, this, &GPSWorld::onAction_UsrReport);
			m_pRepMenu->addAction(pActionBaseReport);
			m_pRepMenu->addAction(pActionUsrReport);
			QPoint point = this->pos() + ui.widget_tool->pos() + ui.widget_toolBtn->pos() + ui.widget_repTool->pos();
			m_pRepMenu->exec(QPoint(point.x(), point.y() + ui.widget_repTool->height()));
			return true;
		}
	}

	return QObject::eventFilter(obj, event);
}