/********************************************************************************
** Form generated from reading UI file 'BaseAlarmSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASEALARMSETTING_H
#define UI_BASEALARMSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BaseAlarmSetting
{
public:

    void setupUi(QWidget *BaseAlarmSetting)
    {
        if (BaseAlarmSetting->objectName().isEmpty())
            BaseAlarmSetting->setObjectName(QStringLiteral("BaseAlarmSetting"));
        BaseAlarmSetting->resize(400, 300);

        retranslateUi(BaseAlarmSetting);

        QMetaObject::connectSlotsByName(BaseAlarmSetting);
    } // setupUi

    void retranslateUi(QWidget *BaseAlarmSetting)
    {
        BaseAlarmSetting->setWindowTitle(QApplication::translate("BaseAlarmSetting", "BaseAlarmSetting", 0));
    } // retranslateUi

};

namespace Ui {
    class BaseAlarmSetting: public Ui_BaseAlarmSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASEALARMSETTING_H
