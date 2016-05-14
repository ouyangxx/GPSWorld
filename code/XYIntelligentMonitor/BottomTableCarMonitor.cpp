#pragma execution_character_set("utf-8")
#include "BottomTableCarMonitor.h"
#include "HDataManager\HDataManager.h"
#include "ExcelOperator\ExcelOperator.h"
#include <QMessageBox>

BottomTableCarMonitor::BottomTableCarMonitor(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_pTableModel = new QStandardItemModel;
	ui.tableView_carMonitor->setModel(m_pTableModel);
	initStyle();

	ui.tableView_carMonitor->viewport()->installEventFilter(this);  //注册事件过滤器

	connect(&HDataManager::instance(), &HDataManager::sig_updateDeviceInfo, this, &BottomTableCarMonitor::onUpdateDeviceInfo);
}

BottomTableCarMonitor::~BottomTableCarMonitor()
{
	if (NULL != m_pTableModel) {
		delete m_pTableModel;
		m_pTableModel = NULL;
	}
}

void BottomTableCarMonitor::initStyle()
{
	/* 设置tableView_carMonitor样式 */
	ui.tableView_carMonitor->setFrameShape(QFrame::NoFrame);    //设置不显示表格边框
	ui.tableView_carMonitor->verticalHeader()->setHidden(true); //设置不显示垂直表头
	ui.tableView_carMonitor->setShowGrid(false);                //设置不显示方格线
	ui.tableView_carMonitor->setFocusPolicy(Qt::NoFocus);       //设置不显示选中时的虚线框
	ui.tableView_carMonitor->setEditTriggers(QAbstractItemView::NoEditTriggers);  //禁止编辑
	ui.tableView_carMonitor->setSelectionBehavior(QAbstractItemView::SelectRows); //按行选中
	ui.tableView_carMonitor->setSelectionMode(QAbstractItemView::SingleSelection);//只能单选
	ui.tableView_carMonitor->setContextMenuPolicy(Qt::CustomContextMenu);  //启用customContextMenuRequested信号
	ui.tableView_carMonitor->setMouseTracking(true);                        //如果省略，则默认是要按住鼠标键拖动才能捕获到mouseMove事件
	ui.tableView_carMonitor->horizontalHeader()->setStretchLastSection(true);                    //设置方格内容充满其宽度                
	ui.tableView_carMonitor->horizontalHeader()->setSortIndicatorShown(true);//显示表头排序小三角
	ui.tableView_carMonitor->horizontalHeader()->setSectionsClickable(true); //启用sectionClicked(int)信号

	/* 设置tableView_carMonitor表头 */
	m_pTableModel->setColumnCount(8);
	m_pTableModel->setHeaderData(0, Qt::Horizontal, "轨迹");
	m_pTableModel->setHeaderData(1, Qt::Horizontal, "设备号");
	m_pTableModel->setHeaderData(2, Qt::Horizontal, "车牌号");
	m_pTableModel->setHeaderData(3, Qt::Horizontal, "公司");
	m_pTableModel->setHeaderData(4, Qt::Horizontal, "速度");
	m_pTableModel->setHeaderData(5, Qt::Horizontal, "方向");
	m_pTableModel->setHeaderData(6, Qt::Horizontal, "最后时间");
	m_pTableModel->setHeaderData(7, Qt::Horizontal, "详细地址");

	/* 设置tableView_carMonitor表头列宽 */
	ui.tableView_carMonitor->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed); //固定列宽
	ui.tableView_carMonitor->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed); //固定列宽
	ui.tableView_carMonitor->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed); //固定列宽
	ui.tableView_carMonitor->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed); //固定列宽
	ui.tableView_carMonitor->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed); //固定列宽
	ui.tableView_carMonitor->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed); //固定列宽
	ui.tableView_carMonitor->horizontalHeader()->setSectionResizeMode(7, QHeaderView::Fixed); //固定列宽
}

bool BottomTableCarMonitor::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == ui.tableView_carMonitor->viewport()) {
		if (event->type() == QEvent::Resize) {
			ui.tableView_carMonitor->setColumnWidth(0, 50);
			ui.tableView_carMonitor->setColumnWidth(1, 120);
			ui.tableView_carMonitor->setColumnWidth(2, 120);
			ui.tableView_carMonitor->setColumnWidth(3, 120);
			ui.tableView_carMonitor->setColumnWidth(4, 80);
			ui.tableView_carMonitor->setColumnWidth(5, 80);
			ui.tableView_carMonitor->setColumnWidth(6, ui.tableView_carMonitor->width() - 730);
			ui.tableView_carMonitor->setColumnWidth(7, 160);
			return true;
		}
	}

	return QWidget::eventFilter(obj, event);
}

void BottomTableCarMonitor::onUpdateDeviceInfo(QList<XYDeviceHeader::HDeviceInfo *> checkedDevices)
{
	m_pTableModel->setRowCount(0);
	QString company = HDataManager::instance().m_CompanyList.first();
	for (auto deviceInfo : checkedDevices) {
		int currentRowCount = m_pTableModel->rowCount();
		m_pTableModel->setRowCount(currentRowCount + 1);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 0, QModelIndex()), deviceInfo->DeviceNum, XYDeviceHeader::DeviceId);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 1, QModelIndex()), deviceInfo->DeviceNum);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 2, QModelIndex()), deviceInfo->VericleNumber);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 3, QModelIndex()), company);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 4, QModelIndex()), deviceInfo->Vel);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 5, QModelIndex()), deviceInfo->Ori);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 6, QModelIndex()), deviceInfo->Time);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 7, QModelIndex()), deviceInfo->Address);

		auto item = m_pTableModel->item(currentRowCount, 0);
		item->setCheckable(true);

		for (size_t column = 0; column < 8; column++)
		{
			auto itemText = m_pTableModel->item(currentRowCount, column);
			itemText->setTextAlignment(Qt::AlignCenter);
		}
	}
}

bool BottomTableCarMonitor::writeDataToExcel(const QString &file)
{
	ExcelOperator * pExcelOperator = new ExcelOperator;

	int tableR = m_pTableModel->rowCount();
	int tableC = m_pTableModel->columnCount();
	int curExcelRow = 0;
	int curExcelSheetIndex = 1;

	QFile excelFile(file);
	if (excelFile.exists()) {
		excelFile.remove();
	}
	if (!pExcelOperator->open(file)) {
		QMessageBox::information(NULL, tr("提示"), tr("获取本地Excel应用程序失败"));
		return false;
	}

	/* 设置Excel表格列宽 */
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 1, 120);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 2, 120);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 3, 120);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 4, 80);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 5, 80);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 6, 150);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 7, 160);

	//获取表头写做第一行
	++curExcelRow;
	for (int column = 0; column<tableC; ++column)
	{
		pExcelOperator->setCellFont(curExcelSheetIndex, curExcelRow, column + 1, "宋体", 11, QColor("#000000"), true);
		pExcelOperator->setCellBackgroundColor(curExcelSheetIndex, curExcelRow, column + 1, QColor("#00CD66"));
		pExcelOperator->setCellBorderColor(curExcelSheetIndex, curExcelRow, column + 1, QColor("#4000FF"));
		pExcelOperator->setCellHeight(curExcelSheetIndex, curExcelRow, column + 1, 30);
		pExcelOperator->setCellValue(curExcelSheetIndex, curExcelRow, column + 1, m_pTableModel->headerData(column, Qt::Horizontal).toString());
		pExcelOperator->setCellAlighment(1, curExcelRow, column + 1, Alignment::AlignCenter);
	}

	//写数据
	for (int row = 0; row<tableR; ++row)
	{
		auto item = m_pTableModel->item(row, 0);
		++curExcelRow;
		for (int column = 0; column<tableC - 1; ++column)
		{
			pExcelOperator->setCellValue(curExcelSheetIndex, curExcelRow, column + 1, m_pTableModel->index(row, column).data().toString());
			pExcelOperator->setCellAlighment(curExcelSheetIndex, curExcelRow, column + 1, Alignment::AlignCenter);
		}
	}

	//保存
	pExcelOperator->save();
	pExcelOperator->close();

	delete pExcelOperator;
	pExcelOperator = NULL;

	return true;
}