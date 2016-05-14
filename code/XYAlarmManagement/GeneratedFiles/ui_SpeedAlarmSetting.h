/********************************************************************************
** Form generated from reading UI file 'SpeedAlarmSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPEEDALARMSETTING_H
#define UI_SPEEDALARMSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpeedAlarmSetting
{
public:

    void setupUi(QWidget *SpeedAlarmSetting)
    {
        if (SpeedAlarmSetting->objectName().isEmpty())
            SpeedAlarmSetting->setObjectName(QStringLiteral("SpeedAlarmSetting"));
        SpeedAlarmSetting->resize(400, 300);

        retranslateUi(SpeedAlarmSetting);

        QMetaObject::connectSlotsByName(SpeedAlarmSetting);
    } // setupUi

    void retranslateUi(QWidget *SpeedAlarmSetting)
    {
        SpeedAlarmSetting->setWindowTitle(QApplication::translate("SpeedAlarmSetting", "SpeedAlarmSetting", 0));
    } // retranslateUi

};

namespace Ui {
    class SpeedAlarmSetting: public Ui_SpeedAlarmSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPEEDALARMSETTING_H
