/********************************************************************************
** Form generated from reading UI file 'OfflineAlarmSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OFFLINEALARMSETTING_H
#define UI_OFFLINEALARMSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OfflineAlarmSetting
{
public:

    void setupUi(QWidget *OfflineAlarmSetting)
    {
        if (OfflineAlarmSetting->objectName().isEmpty())
            OfflineAlarmSetting->setObjectName(QStringLiteral("OfflineAlarmSetting"));
        OfflineAlarmSetting->resize(400, 300);

        retranslateUi(OfflineAlarmSetting);

        QMetaObject::connectSlotsByName(OfflineAlarmSetting);
    } // setupUi

    void retranslateUi(QWidget *OfflineAlarmSetting)
    {
        OfflineAlarmSetting->setWindowTitle(QApplication::translate("OfflineAlarmSetting", "OfflineAlarmSetting", 0));
    } // retranslateUi

};

namespace Ui {
    class OfflineAlarmSetting: public Ui_OfflineAlarmSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OFFLINEALARMSETTING_H
