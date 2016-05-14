#pragma execution_character_set("utf-8")
#include "IntelligentMonitor.h"
#include "HDataManager\HDataManager.h"
#include "ProgressBarManager\ProgressBarManager.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>

IntelligentMonitor::IntelligentMonitor(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);

	m_pLeftNaviMonitorList = new LeftNaviMonitorList;
	m_pLeftNaviFactory = new LeftNaviFactory;
	m_pLeftNaviMap = new LeftNaviMap;
	m_pBottomTableCarMonitor = new BottomTableCarMonitor;
	m_pBottomTableTracking = new BottomTableTracking;

	ui.stackedWidget_navi->addWidget(m_pLeftNaviMonitorList);
	ui.stackedWidget_navi->addWidget(m_pLeftNaviFactory);
	ui.stackedWidget_navi->addWidget(m_pLeftNaviMap);
	ui.stackedWidget_navi->setCurrentWidget(m_pLeftNaviMonitorList);
	ui.stackedWidget_data->addWidget(m_pBottomTableCarMonitor);
	ui.stackedWidget_data->addWidget(m_pBottomTableTracking);
	ui.stackedWidget_data->setCurrentWidget(m_pBottomTableCarMonitor);

	connect(&HDataManager::instance(), &HDataManager::sig_updateCarInfo, this, &IntelligentMonitor::onUpdateCarBox);

	ProgressBarManager::instance().startProgressBar(ui.widget_map, RoundBar);
	HDataManager::instance().m_pMaps = new HMaps(ui.widget_map, "61.136.156.152", 5136);
	HDataManager::instance().m_pMaps->setGeometry(0, 0, ui.widget_map->width(), ui.widget_map->height());
	connect(HDataManager::instance().m_pMaps, SIGNAL(sig_clickVehicleShapes(QMap<QString, HVehicleShape*>)),
	       	this, SLOT(onClickVechicleShapes(QMap<QString, HVehicleShape*>)));
	ui.widget_map->installEventFilter(this);
	HDataManager::instance().startMapEngine();
	ProgressBarManager::instance().stopProgressBar();
}

IntelligentMonitor::~IntelligentMonitor()
{
	ui.stackedWidget_navi->removeWidget(m_pLeftNaviMonitorList);
	ui.stackedWidget_navi->removeWidget(m_pLeftNaviFactory);
	ui.stackedWidget_navi->removeWidget(m_pLeftNaviMap);
	ui.stackedWidget_data->removeWidget(m_pBottomTableCarMonitor);
	ui.stackedWidget_data->removeWidget(m_pBottomTableTracking);
	if (NULL != m_pBottomTableTracking) {
		delete m_pBottomTableTracking;
		m_pBottomTableTracking = NULL;
	}
	if (NULL != m_pBottomTableCarMonitor) {
		delete m_pBottomTableCarMonitor;
		m_pBottomTableCarMonitor = NULL;
	}
	if (NULL != m_pLeftNaviMap) {
		delete m_pLeftNaviMap;
		m_pLeftNaviMap = NULL;
	}
	if (NULL != m_pLeftNaviFactory) {
		delete m_pLeftNaviFactory;
		m_pLeftNaviFactory = NULL;
	}
	if (NULL != m_pLeftNaviMonitorList) {
		delete m_pLeftNaviMonitorList;
		m_pLeftNaviMonitorList = NULL;
	}
}


void IntelligentMonitor::on_btn_navi1_clicked()
{
	ui.stackedWidget_navi->setCurrentWidget(m_pLeftNaviMonitorList);
	ui.btn_navi1->setIcon(QIcon(":/IntelligentMonitor/Resources/image/navi_11.png"));	ui.btn_navi1->setIconSize(QSize(48,38));
	ui.btn_navi2->setIcon(QIcon(":/IntelligentMonitor/Resources/image/navi_2.png"));	ui.btn_navi2->setIconSize(QSize(48, 38));
	ui.btn_navi3->setIcon(QIcon(":/IntelligentMonitor/Resources/image/navi_3.png"));	ui.btn_navi3->setIconSize(QSize(48, 38));
}

void IntelligentMonitor::on_btn_navi2_clicked()
{
	ui.stackedWidget_navi->setCurrentWidget(m_pLeftNaviFactory);
	ui.btn_navi2->setIcon(QIcon(":/IntelligentMonitor/Resources/image/navi_22.png"));	ui.btn_navi2->setIconSize(QSize(48, 38));
	ui.btn_navi1->setIcon(QIcon(":/IntelligentMonitor/Resources/image/navi_1.png"));	ui.btn_navi1->setIconSize(QSize(48, 38));
	ui.btn_navi3->setIcon(QIcon(":/IntelligentMonitor/Resources/image/navi_3.png"));	ui.btn_navi3->setIconSize(QSize(48, 38));
}

void IntelligentMonitor::on_btn_navi3_clicked()
{
	ui.stackedWidget_navi->setCurrentWidget(m_pLeftNaviMap);
	ui.btn_navi3->setIcon(QIcon(":/IntelligentMonitor/Resources/image/navi_33.png"));	ui.btn_navi3->setIconSize(QSize(48, 38));
	ui.btn_navi1->setIcon(QIcon(":/IntelligentMonitor/Resources/image/navi_1.png"));	ui.btn_navi1->setIconSize(QSize(48, 38));
	ui.btn_navi2->setIcon(QIcon(":/IntelligentMonitor/Resources/image/navi_2.png"));	ui.btn_navi2->setIconSize(QSize(48, 38));
}

void IntelligentMonitor::on_btn_carMonitor_clicked()
{
	ui.comb_car->hide();
	ui.stackedWidget_data->setCurrentWidget(m_pBottomTableCarMonitor);
}

void IntelligentMonitor::on_btn_curvey_clicked()
{
	ui.comb_car->show();
	ui.stackedWidget_data->setCurrentWidget(m_pBottomTableTracking);
}

//导出到Excel
void IntelligentMonitor::on_btn_excel_clicked()
{
	QString savePath = QFileDialog::getSaveFileName(this, "选择导出路径", QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), "Excel Files(*.xls *.xlsx)");
	if (savePath.isEmpty())     return;
	ProgressBarManager::instance().startProgressBar(NULL, RoundBar, QString("正在导出"));
	if (writeDataToExcel(QDir::toNativeSeparators(savePath))) {
		ProgressBarManager::instance().stopProgressBar();
		QMessageBox mess(QMessageBox::Question, "完成", "文件已经导出，是否现在打开？", NULL);
		QPushButton *okButton = mess.addButton(tr("确定"), QMessageBox::AcceptRole);
		QPushButton *cancelButton = mess.addButton(tr("取消"), QMessageBox::RejectRole);
		//mess.setWindowIcon(QIcon(":/YZRCodePrinter/Resources/EBIM.ico"));

		mess.exec();
		if ((QPushButton*)mess.clickedButton() == okButton)
		{
			QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(savePath)));
		}
	}
	else
		ProgressBarManager::instance().stopProgressBar();
}

bool IntelligentMonitor::writeDataToExcel(const QString &file)
{
	if (ui.stackedWidget_data->currentWidget() == m_pBottomTableCarMonitor)
		return m_pBottomTableCarMonitor->writeDataToExcel(file);
	return m_pBottomTableTracking->writeDataToExcel(file);
}

bool IntelligentMonitor::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == ui.widget_map) {
		if (event->type() == QEvent::Resize){
			HDataManager::instance().m_pMaps->setGeometry(0, 0, ui.widget_map->width(), ui.widget_map->height());
		}
	}
	return QWidget::eventFilter(obj, event);
}

void IntelligentMonitor::onClickVechicleShapes(QMap<QString, HVehicleShape *>)
{

}

void IntelligentMonitor::onCarcurrentIndexChanged(int index)
{
	int currentIndex = ui.comb_car->currentIndex();
	if (currentIndex == 0) return;
	QString currentDeviceId = ui.comb_car->itemData(currentIndex, XYDeviceHeader::DeviceId).toString();
	m_pBottomTableTracking->updateCurrentDevice(currentDeviceId);
}

void IntelligentMonitor::onUpdateCarBox()
{
	for (int index = 0; index < HDataManager::instance().m_DeviceInfoList.count(); ++index) {
		auto deviceInfo = HDataManager::instance().m_DeviceInfoList.at(index);
		ui.comb_car->addItem(deviceInfo->VericleNumber);
		ui.comb_car->setItemData(index+1, deviceInfo->DeviceNum, XYDeviceHeader::DeviceId);
	}
	connect(ui.comb_car, SIGNAL(currentIndexChanged(int)), this, SLOT(onCarcurrentIndexChanged(int)));
}