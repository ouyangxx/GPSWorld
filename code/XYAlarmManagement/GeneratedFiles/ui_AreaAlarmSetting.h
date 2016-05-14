/********************************************************************************
** Form generated from reading UI file 'AreaAlarmSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AREAALARMSETTING_H
#define UI_AREAALARMSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AreaAlarmSetting
{
public:

    void setupUi(QWidget *AreaAlarmSetting)
    {
        if (AreaAlarmSetting->objectName().isEmpty())
            AreaAlarmSetting->setObjectName(QStringLiteral("AreaAlarmSetting"));
        AreaAlarmSetting->resize(400, 300);

        retranslateUi(AreaAlarmSetting);

        QMetaObject::connectSlotsByName(AreaAlarmSetting);
    } // setupUi

    void retranslateUi(QWidget *AreaAlarmSetting)
    {
        AreaAlarmSetting->setWindowTitle(QApplication::translate("AreaAlarmSetting", "AreaAlarmSetting", 0));
    } // retranslateUi

};

namespace Ui {
    class AreaAlarmSetting: public Ui_AreaAlarmSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AREAALARMSETTING_H
