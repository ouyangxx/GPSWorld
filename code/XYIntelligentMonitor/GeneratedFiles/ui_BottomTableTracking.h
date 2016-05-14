/********************************************************************************
** Form generated from reading UI file 'BottomTableTracking.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOTTOMTABLETRACKING_H
#define UI_BOTTOMTABLETRACKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BottomTableTracking
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView_track;

    void setupUi(QWidget *BottomTableTracking)
    {
        if (BottomTableTracking->objectName().isEmpty())
            BottomTableTracking->setObjectName(QStringLiteral("BottomTableTracking"));
        BottomTableTracking->resize(864, 192);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BottomTableTracking->sizePolicy().hasHeightForWidth());
        BottomTableTracking->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(BottomTableTracking);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView_track = new QTableView(BottomTableTracking);
        tableView_track->setObjectName(QStringLiteral("tableView_track"));
        tableView_track->setStyleSheet(QLatin1String("QTableView#tableView_track::item:selected{\n"
"	color: #F0F0F0;\n"
"}"));

        verticalLayout->addWidget(tableView_track);


        retranslateUi(BottomTableTracking);

        QMetaObject::connectSlotsByName(BottomTableTracking);
    } // setupUi

    void retranslateUi(QWidget *BottomTableTracking)
    {
        BottomTableTracking->setWindowTitle(QApplication::translate("BottomTableTracking", "BottomTableTracking", 0));
    } // retranslateUi

};

namespace Ui {
    class BottomTableTracking: public Ui_BottomTableTracking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOTTOMTABLETRACKING_H
