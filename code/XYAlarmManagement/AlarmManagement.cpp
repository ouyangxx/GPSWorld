#pragma execution_character_set("utf-8")
#include "AlarmManagement.h"

AlarmManagement::AlarmManagement(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);

	m_pCurrentTabList = new QList<QWidget *>;
	m_pBaseAlarmSetting = new BaseAlarmSetting;
	m_pAreaAlarmSetting = new AreaAlarmSetting;
	m_pOfflineAlarmSetting = new OfflineAlarmSetting;
	m_pSpeedAlarmSetting = new SpeedAlarmSetting;
	m_pKeypointAlarmSetting = new KeypointAlarmSetting;
	m_pAlarmRuleSetting = new AlarmRuleSetting;
	m_pAlarmMonitor = new AlarmMonitor;
	m_pAlarmSuper = new AlarmSuper;
	m_pAlarmStatistics = new AlarmStatistics;
	ui.treeWidget->expandAll();

	m_pCurrentTabList->clear();
	m_pCurrentTabList->append(m_pBaseAlarmSetting);
	ui.tabWidget->addTab(m_pBaseAlarmSetting, QString("基础报警设置"));
	ui.tabWidget->setCurrentWidget(m_pBaseAlarmSetting);
	ui.tabWidget->setTabsClosable(true);
	connect(ui.tabWidget, &QTabWidget::tabCloseRequested, this, &AlarmManagement::onTabClosed);
	connect(ui.tabWidget, &QTabWidget::currentChanged, this, &AlarmManagement::onTabCurrentChanged);

	connect(ui.treeWidget, &QTreeWidget::itemClicked, this, &AlarmManagement::onTreeItemClicked);
}

AlarmManagement::~AlarmManagement()
{
	if (NULL != m_pAlarmStatistics) {
		delete m_pAlarmStatistics;
		m_pAlarmStatistics = NULL;
	}
	if (NULL != m_pAlarmSuper) {
		delete m_pAlarmSuper;
		m_pAlarmSuper = NULL;
	}
	if (NULL != m_pAlarmMonitor) {
		delete m_pAlarmMonitor;
		m_pAlarmMonitor = NULL;
	}
	if (NULL != m_pAlarmRuleSetting) {
		delete m_pAlarmRuleSetting;
		m_pAlarmRuleSetting = NULL;
	}
	if (NULL != m_pKeypointAlarmSetting) {
		delete m_pKeypointAlarmSetting;
		m_pKeypointAlarmSetting = NULL;
	}
	if (NULL != m_pSpeedAlarmSetting) {
		delete m_pSpeedAlarmSetting;
		m_pSpeedAlarmSetting = NULL;
	}
	if (NULL != m_pOfflineAlarmSetting) {
		delete m_pOfflineAlarmSetting;
		m_pOfflineAlarmSetting = NULL;
	}
	if (NULL != m_pAreaAlarmSetting) {
		delete m_pAreaAlarmSetting;
		m_pAreaAlarmSetting = NULL;
	}
	if (NULL != m_pBaseAlarmSetting) {
		delete m_pBaseAlarmSetting;
		m_pBaseAlarmSetting = NULL;
	}
	if (NULL != m_pCurrentTabList) {
		delete m_pCurrentTabList;
		m_pCurrentTabList = NULL;
	}
}


void AlarmManagement::showAlarmSetting()
{
	if (!m_pCurrentTabList->contains(m_pBaseAlarmSetting)) {
		m_pCurrentTabList->append(m_pBaseAlarmSetting);
		ui.tabWidget->addTab(m_pBaseAlarmSetting, QString("基础报警设置"));
	}
	ui.tabWidget->setCurrentWidget(m_pBaseAlarmSetting);
}
void AlarmManagement::showAlarmMonitor()
{
	if (!m_pCurrentTabList->contains(m_pAlarmMonitor)) {
		m_pCurrentTabList->append(m_pAlarmMonitor);
		ui.tabWidget->addTab(m_pAlarmMonitor, QString("报警监控"));
	}
	ui.tabWidget->setCurrentWidget(m_pAlarmMonitor);
}
void AlarmManagement::showAlarmSuper()
{
	if (!m_pCurrentTabList->contains(m_pAlarmSuper)) {
		m_pCurrentTabList->append(m_pAlarmSuper);
		ui.tabWidget->addTab(m_pAlarmSuper, QString("报警督办"));
	}
	ui.tabWidget->setCurrentWidget(m_pAlarmSuper);
}
void AlarmManagement::showAlarmStatistics()
{
	if (!m_pCurrentTabList->contains(m_pAlarmStatistics)) {
		m_pCurrentTabList->append(m_pAlarmStatistics);
		ui.tabWidget->addTab(m_pAlarmStatistics, QString("报警统计"));
	}
	ui.tabWidget->setCurrentWidget(m_pAlarmStatistics);
}


void AlarmManagement::onTreeItemClicked(QTreeWidgetItem * item, int column)
{
	if (NULL == item)
		return;
	if (item->text(column) == QString("报警设置")) {
		showAlarmSetting();
	}
	if (item->text(column) == QString("报警监控")) {
		showAlarmMonitor();
	}
	if (item->text(column) == QString("报警督办")) {
		showAlarmSuper();
	}
	if (item->text(column) == QString("报警统计")) {
		showAlarmStatistics();
	}

	if (item->text(column) == QString("基础报警设置")) {
		if (!m_pCurrentTabList->contains(m_pBaseAlarmSetting)) {
			m_pCurrentTabList->append(m_pBaseAlarmSetting);
			ui.tabWidget->addTab(m_pBaseAlarmSetting, QString("基础报警设置"));
		}
		ui.tabWidget->setCurrentWidget(m_pBaseAlarmSetting);
	}
	if (item->text(column) == QString("进出区域报警设置")) {
		if (!m_pCurrentTabList->contains(m_pAreaAlarmSetting)) {
			m_pCurrentTabList->append(m_pAreaAlarmSetting);
			ui.tabWidget->addTab(m_pAreaAlarmSetting, QString("进出区域报警设置"));
		}
		ui.tabWidget->setCurrentWidget(m_pAreaAlarmSetting);
	}
	if (item->text(column) == QString("离线报警设置")) {
		if (!m_pCurrentTabList->contains(m_pOfflineAlarmSetting)) {
			m_pCurrentTabList->append(m_pOfflineAlarmSetting);
			ui.tabWidget->addTab(m_pOfflineAlarmSetting, QString("离线报警设置"));
		}
		ui.tabWidget->setCurrentWidget(m_pOfflineAlarmSetting);
	}
	if (item->text(column) == QString("高速低速报警设置")) {
		if (!m_pCurrentTabList->contains(m_pSpeedAlarmSetting)) {
			m_pCurrentTabList->append(m_pSpeedAlarmSetting);
			ui.tabWidget->addTab(m_pSpeedAlarmSetting, QString("高速低速报警设置"));
		}
		ui.tabWidget->setCurrentWidget(m_pSpeedAlarmSetting);
	}
	if (item->text(column) == QString("关键点报警设置")) {
		if (!m_pCurrentTabList->contains(m_pKeypointAlarmSetting)) {
			m_pCurrentTabList->append(m_pKeypointAlarmSetting);
			ui.tabWidget->addTab(m_pKeypointAlarmSetting, QString("关键点报警设置"));
		}
		ui.tabWidget->setCurrentWidget(m_pKeypointAlarmSetting);
	}
	if (item->text(column) == QString("报警通知规则设置")) {
		if (!m_pCurrentTabList->contains(m_pAlarmRuleSetting)) {
			m_pCurrentTabList->append(m_pAlarmRuleSetting);
			ui.tabWidget->addTab(m_pAlarmRuleSetting, QString("报警通知规则设置"));
		}
		ui.tabWidget->setCurrentWidget(m_pAlarmRuleSetting);
	}
}

void AlarmManagement::onTabCurrentChanged(int index)
{

}

void AlarmManagement::onTabClosed(int index)
{
	if (m_pCurrentTabList->count() > 1 && index < m_pCurrentTabList->count()) {
		if (index == ui.tabWidget->currentIndex()) {
			ui.tabWidget->setCurrentIndex(index - 1);
		}
		m_pCurrentTabList->removeAt(index);
		ui.tabWidget->removeTab(index);
	}
}