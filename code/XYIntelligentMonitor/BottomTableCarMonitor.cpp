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

	ui.tableView_carMonitor->viewport()->installEventFilter(this);  //ע���¼�������

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
	/* ����tableView_carMonitor��ʽ */
	ui.tableView_carMonitor->setFrameShape(QFrame::NoFrame);    //���ò���ʾ���߿�
	ui.tableView_carMonitor->verticalHeader()->setHidden(true); //���ò���ʾ��ֱ��ͷ
	ui.tableView_carMonitor->setShowGrid(false);                //���ò���ʾ������
	ui.tableView_carMonitor->setFocusPolicy(Qt::NoFocus);       //���ò���ʾѡ��ʱ�����߿�
	ui.tableView_carMonitor->setEditTriggers(QAbstractItemView::NoEditTriggers);  //��ֹ�༭
	ui.tableView_carMonitor->setSelectionBehavior(QAbstractItemView::SelectRows); //����ѡ��
	ui.tableView_carMonitor->setSelectionMode(QAbstractItemView::SingleSelection);//ֻ�ܵ�ѡ
	ui.tableView_carMonitor->setContextMenuPolicy(Qt::CustomContextMenu);  //����customContextMenuRequested�ź�
	ui.tableView_carMonitor->setMouseTracking(true);                        //���ʡ�ԣ���Ĭ����Ҫ��ס�����϶����ܲ���mouseMove�¼�
	ui.tableView_carMonitor->horizontalHeader()->setStretchLastSection(true);                    //���÷������ݳ�������                
	ui.tableView_carMonitor->horizontalHeader()->setSortIndicatorShown(true);//��ʾ��ͷ����С����
	ui.tableView_carMonitor->horizontalHeader()->setSectionsClickable(true); //����sectionClicked(int)�ź�

	/* ����tableView_carMonitor��ͷ */
	m_pTableModel->setColumnCount(8);
	m_pTableModel->setHeaderData(0, Qt::Horizontal, "�켣");
	m_pTableModel->setHeaderData(1, Qt::Horizontal, "�豸��");
	m_pTableModel->setHeaderData(2, Qt::Horizontal, "���ƺ�");
	m_pTableModel->setHeaderData(3, Qt::Horizontal, "��˾");
	m_pTableModel->setHeaderData(4, Qt::Horizontal, "�ٶ�");
	m_pTableModel->setHeaderData(5, Qt::Horizontal, "����");
	m_pTableModel->setHeaderData(6, Qt::Horizontal, "���ʱ��");
	m_pTableModel->setHeaderData(7, Qt::Horizontal, "��ϸ��ַ");

	/* ����tableView_carMonitor��ͷ�п� */
	ui.tableView_carMonitor->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed); //�̶��п�
	ui.tableView_carMonitor->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed); //�̶��п�
	ui.tableView_carMonitor->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed); //�̶��п�
	ui.tableView_carMonitor->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed); //�̶��п�
	ui.tableView_carMonitor->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed); //�̶��п�
	ui.tableView_carMonitor->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed); //�̶��п�
	ui.tableView_carMonitor->horizontalHeader()->setSectionResizeMode(7, QHeaderView::Fixed); //�̶��п�
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
		QMessageBox::information(NULL, tr("��ʾ"), tr("��ȡ����ExcelӦ�ó���ʧ��"));
		return false;
	}

	/* ����Excel����п� */
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 1, 120);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 2, 120);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 3, 120);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 4, 80);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 5, 80);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 6, 150);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 7, 160);

	//��ȡ��ͷд����һ��
	++curExcelRow;
	for (int column = 0; column<tableC; ++column)
	{
		pExcelOperator->setCellFont(curExcelSheetIndex, curExcelRow, column + 1, "����", 11, QColor("#000000"), true);
		pExcelOperator->setCellBackgroundColor(curExcelSheetIndex, curExcelRow, column + 1, QColor("#00CD66"));
		pExcelOperator->setCellBorderColor(curExcelSheetIndex, curExcelRow, column + 1, QColor("#4000FF"));
		pExcelOperator->setCellHeight(curExcelSheetIndex, curExcelRow, column + 1, 30);
		pExcelOperator->setCellValue(curExcelSheetIndex, curExcelRow, column + 1, m_pTableModel->headerData(column, Qt::Horizontal).toString());
		pExcelOperator->setCellAlighment(1, curExcelRow, column + 1, Alignment::AlignCenter);
	}

	//д����
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

	//����
	pExcelOperator->save();
	pExcelOperator->close();

	delete pExcelOperator;
	pExcelOperator = NULL;

	return true;
}