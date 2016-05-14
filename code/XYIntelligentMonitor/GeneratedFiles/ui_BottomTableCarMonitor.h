/********************************************************************************
** Form generated from reading UI file 'BottomTableCarMonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOTTOMTABLECARMONITOR_H
#define UI_BOTTOMTABLECARMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BottomTableCarMonitor
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView_carMonitor;

    void setupUi(QWidget *BottomTableCarMonitor)
    {
        if (BottomTableCarMonitor->objectName().isEmpty())
            BottomTableCarMonitor->setObjectName(QStringLiteral("BottomTableCarMonitor"));
        BottomTableCarMonitor->resize(864, 192);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BottomTableCarMonitor->sizePolicy().hasHeightForWidth());
        BottomTableCarMonitor->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(BottomTableCarMonitor);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView_carMonitor = new QTableView(BottomTableCarMonitor);
        tableView_carMonitor->setObjectName(QStringLiteral("tableView_carMonitor"));
        tableView_carMonitor->setStyleSheet(QLatin1String("QTableView#tableView_carMonitor::item:selected{\n"
"	color: #F0F0F0;\n"
"}"));

        verticalLayout->addWidget(tableView_carMonitor);


        retranslateUi(BottomTableCarMonitor);

        QMetaObject::connectSlotsByName(BottomTableCarMonitor);
    } // setupUi

    void retranslateUi(QWidget *BottomTableCarMonitor)
    {
        BottomTableCarMonitor->setWindowTitle(QApplication::translate("BottomTableCarMonitor", "BottomTableCarMonitor", 0));
    } // retranslateUi

};

namespace Ui {
    class BottomTableCarMonitor: public Ui_BottomTableCarMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOTTOMTABLECARMONITOR_H
