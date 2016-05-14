#pragma execution_character_set("utf-8")
#include "BottomTableTracking.h"
#include "HDataManager\HDataManager.h"
#include "ExcelOperator\ExcelOperator.h"
#include <QMessageBox>

BottomTableTracking::BottomTableTracking(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_pTableModel = new QStandardItemModel;
	ui.tableView_track->setModel(m_pTableModel);

	initStyle();

	connect(&HDataManager::instance(), &HDataManager::sig_updateTrackInfo, this, &BottomTableTracking::onUpdateTrackInfo);
}

BottomTableTracking::~BottomTableTracking()
{
	if (NULL != m_pTableModel) {
		delete m_pTableModel;
		m_pTableModel = NULL;
	}
}

void BottomTableTracking::initStyle()
{
	/* ����tableView_track��ʽ */
	ui.tableView_track->setFrameShape(QFrame::NoFrame);    //���ò���ʾ���߿�
	ui.tableView_track->verticalHeader()->setHidden(true); //���ò���ʾ��ֱ��ͷ
	ui.tableView_track->setShowGrid(false);                //���ò���ʾ������
	ui.tableView_track->setFocusPolicy(Qt::NoFocus);       //���ò���ʾѡ��ʱ�����߿�
	ui.tableView_track->setEditTriggers(QAbstractItemView::NoEditTriggers);  //��ֹ�༭
	ui.tableView_track->setSelectionBehavior(QAbstractItemView::SelectRows); //����ѡ��
	ui.tableView_track->setSelectionMode(QAbstractItemView::SingleSelection);//ֻ�ܵ�ѡ
	ui.tableView_track->setContextMenuPolicy(Qt::CustomContextMenu);  //����customContextMenuRequested�ź�
	ui.tableView_track->setMouseTracking(true);                        //���ʡ�ԣ���Ĭ����Ҫ��ס�����϶����ܲ���mouseMove�¼�
	ui.tableView_track->horizontalHeader()->setStretchLastSection(true);                    //���÷������ݳ�������   
	ui.tableView_track->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);     //����Ӧ�п�
	ui.tableView_track->horizontalHeader()->setSortIndicatorShown(true);//��ʾ��ͷ����С����
	ui.tableView_track->horizontalHeader()->setSectionsClickable(true); //����sectionClicked(int)�ź�

	/* ����tableView_track��ͷ */
	m_pTableModel->setColumnCount(16);
	m_pTableModel->setHeaderData(0, Qt::Horizontal, "�豸��");
	m_pTableModel->setHeaderData(1, Qt::Horizontal, "����");
	m_pTableModel->setHeaderData(2, Qt::Horizontal, "����");
	m_pTableModel->setHeaderData(3, Qt::Horizontal, "γ��");
	m_pTableModel->setHeaderData(4, Qt::Horizontal, "�߳�");
	m_pTableModel->setHeaderData(5, Qt::Horizontal, "�ٶ�");
	m_pTableModel->setHeaderData(6, Qt::Horizontal, "����");
	m_pTableModel->setHeaderData(7, Qt::Horizontal, "���ʱ��");
	m_pTableModel->setHeaderData(8, Qt::Horizontal, "ACC״̬");
	m_pTableModel->setHeaderData(9, Qt::Horizontal, "ֹͣ");
	m_pTableModel->setHeaderData(10, Qt::Horizontal, "��γ");
	m_pTableModel->setHeaderData(11, Qt::Horizontal, "����");
	m_pTableModel->setHeaderData(12, Qt::Horizontal, "����");
	m_pTableModel->setHeaderData(13, Qt::Horizontal, "����");
	m_pTableModel->setHeaderData(14, Qt::Horizontal, "��·");
	m_pTableModel->setHeaderData(15, Qt::Horizontal, "��ַ");
}


void BottomTableTracking::updateCurrentDevice(const QString &currentDeviceId)
{
	m_CurrentDeviceId = currentDeviceId;
	m_pTableModel->setRowCount(0);
}

void BottomTableTracking::onUpdateTrackInfo()
{
	for (auto deviceInfo : HDataManager::instance().m_DeviceInfoList) {
		if (m_CurrentDeviceId != deviceInfo->DeviceNum)	continue;
		int currentRowCount = m_pTableModel->rowCount();
		m_pTableModel->setRowCount(currentRowCount + 1);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 0, QModelIndex()), deviceInfo->DeviceNum, XYDeviceHeader::DeviceId);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 0, QModelIndex()), deviceInfo->DeviceNum);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 1, QModelIndex()), deviceInfo->Alarm);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 2, QModelIndex()), deviceInfo->Lng);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 3, QModelIndex()), deviceInfo->Lat);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 4, QModelIndex()), deviceInfo->Alt);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 5, QModelIndex()), deviceInfo->Vel);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 6, QModelIndex()), "");
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 7, QModelIndex()), deviceInfo->Time);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 8, QModelIndex()), deviceInfo->ACC);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 9, QModelIndex()), "");
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 10, QModelIndex()), deviceInfo->isNorthLat);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 11, QModelIndex()), deviceInfo->isEastLng);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 12, QModelIndex()), deviceInfo->isRunning);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 13, QModelIndex()), deviceInfo->Ori);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 14, QModelIndex()), deviceInfo->isElectricityWell);
		m_pTableModel->setData(m_pTableModel->index(currentRowCount, 15, QModelIndex()), deviceInfo->Address);

		for (size_t column = 0; column < 16; column++)
		{
			auto itemText = m_pTableModel->item(currentRowCount, column);
			itemText->setTextAlignment(Qt::AlignCenter);
		}
	}
}

bool BottomTableTracking::writeDataToExcel(const QString &file)
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
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 1, 100);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 1, 100);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 2, 100);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 3, 100);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 4, 100);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 5, 100);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 6, 100);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 7, 100);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 8, 100);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 9, 100);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 10, 100);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 11, 100);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 12, 100);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 13, 100);
	pExcelOperator->setCellWidth(curExcelSheetIndex, 1, 14, 100);

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