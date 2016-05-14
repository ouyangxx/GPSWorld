#pragma execution_character_set("utf-8")
#include "LeftNaviMonitorList.h"
#include "HDataManager\HDataManager.h"

#define TREE_ITEM_COMPANY	    ":/IntelligentMonitor/Resources/image/company.png"
#define TREE_ITEM_CAR			":/IntelligentMonitor/Resources/image/car.png"

LeftNaviMonitorList::LeftNaviMonitorList(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(&HDataManager::instance(), &HDataManager::sig_updateCarInfo, this, &LeftNaviMonitorList::onUpdateCarInfo);
	connect(ui.treeWidget_car, &QTreeWidget::itemChanged, this, &LeftNaviMonitorList::onTreeItemChanged);
}

LeftNaviMonitorList::~LeftNaviMonitorList()
{

}

void LeftNaviMonitorList::onUpdateCarInfo()
{
	ui.treeWidget_car->setSelectionMode(QAbstractItemView::SingleSelection);//只能单选
	ui.treeWidget_car->setHeaderHidden(true);

	ui.treeWidget_car->clear();
	for (auto company : HDataManager::instance().m_CompanyList) {
		QTreeWidgetItem * companyItem = new QTreeWidgetItem(ui.treeWidget_car);
		companyItem->setText(0, company);
		companyItem->setIcon(0, QIcon(TREE_ITEM_COMPANY));

		for (auto deviceInfo : HDataManager::instance().m_DeviceInfoList) {
			QTreeWidgetItem * carItem = new QTreeWidgetItem(companyItem);
			carItem->setText(0, deviceInfo->VericleNumber);
			carItem->setIcon(0, QIcon(TREE_ITEM_CAR));
			carItem->setData(0, XYDeviceHeader::DeviceId, deviceInfo->DeviceNum);
		}
		companyItem->setCheckState(0, Qt::Checked);
		ui.treeWidget_car->expandAll();
	}
}

void LeftNaviMonitorList::onTreeItemChanged(QTreeWidgetItem *item, int column)
{
	if (NULL == item)
		return;
	Qt::CheckState state = item->checkState(0);

	// 一级节点
	if (!item->parent()) {
		if (state == Qt::Checked) {
			for (int i = 0; i < item->childCount(); ++i) {
				item->child(i)->setCheckState(0, Qt::Checked);
			}
			item->setCheckState(0, Qt::Checked);
		}
		else if (state == Qt::Unchecked) {
			for (int i = 0; i < item->childCount(); ++i) {
				item->child(i)->setCheckState(0, Qt::Unchecked);
			}
			item->setCheckState(0, Qt::Unchecked);
		}
	}
	else {
		// 中级节点
		if (item->child(0)) {
			if (state == Qt::Checked) {
				for (int i = 0; i < item->childCount(); ++i) {
					item->child(i)->setCheckState(0, Qt::Checked);
				}
				item->setCheckState(0, Qt::Checked);
			}
			else if (state == Qt::Unchecked) {
				for (int i = 0; i < item->childCount(); ++i) {
					item->child(i)->setCheckState(0, Qt::Unchecked);
				}
				item->setCheckState(0, Qt::Unchecked);
			}
			else {
				item->setCheckState(0, Qt::PartiallyChecked);
			}
			UpdateParentTreeItemState(item->parent());
		}
		// 叶子节点
		else {
			QString DeviceId = item->data(0, XYDeviceHeader::DeviceId).toString();
			if (state == Qt::Checked) {
				item->setCheckState(0, Qt::Checked);
				bool isExist(false);
				for (auto deviceInfo : m_CheckedDevices) {
					if (deviceInfo->DeviceNum == DeviceId) {
						isExist = true;
						break;
					}
				}
				if (!isExist) {
					for (auto deviceInfo : HDataManager::instance().m_DeviceInfoList) {
						if (deviceInfo->DeviceNum == DeviceId) {
							m_CheckedDevices.append(deviceInfo);
							emit HDataManager::instance().sig_updateDeviceInfo(m_CheckedDevices);
							break;
						}
					}
				}
			}
			else if (state == Qt::Unchecked) {
				item->setCheckState(0, Qt::Unchecked);
				for (int index = 0; index < m_CheckedDevices.count(); ++index) {
					auto deviceInfo = m_CheckedDevices.at(index);
					if (deviceInfo->DeviceNum == DeviceId) {
						m_CheckedDevices.removeAt(index);
						emit HDataManager::instance().sig_updateDeviceInfo(m_CheckedDevices);
						break;
					}
				}
			}
			UpdateParentTreeItemState(item->parent());
		}
	}
}

void LeftNaviMonitorList::UpdateParentTreeItemState(QTreeWidgetItem * parent)
{
	if (NULL == parent)
		return;
	int checkedCount = 0;
	int partiallyCheckedCount = 0;
	int childCount = parent->childCount();
	for (int i = 0; i < childCount; ++i) {
		Qt::CheckState state = parent->child(i)->checkState(0);
		if (state == Qt::Checked)
			++checkedCount;
		else if (state == Qt::PartiallyChecked)
			++partiallyCheckedCount;
	}
	if (partiallyCheckedCount > 0)  //只有中间节点才会有这种状态
		parent->setCheckState(0, Qt::PartiallyChecked);
	else if (checkedCount == 0)
		parent->setCheckState(0, Qt::Unchecked);
	else if (checkedCount == childCount)
		parent->setCheckState(0, Qt::Checked);
	else  //只有叶子节点才会有这种状态
		parent->setCheckState(0, Qt::PartiallyChecked);
}
