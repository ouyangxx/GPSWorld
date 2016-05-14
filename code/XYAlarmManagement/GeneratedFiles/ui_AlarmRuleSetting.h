/********************************************************************************
** Form generated from reading UI file 'AlarmRuleSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMRULESETTING_H
#define UI_ALARMRULESETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlarmRuleSetting
{
public:

    void setupUi(QWidget *AlarmRuleSetting)
    {
        if (AlarmRuleSetting->objectName().isEmpty())
            AlarmRuleSetting->setObjectName(QStringLiteral("AlarmRuleSetting"));
        AlarmRuleSetting->resize(400, 300);

        retranslateUi(AlarmRuleSetting);

        QMetaObject::connectSlotsByName(AlarmRuleSetting);
    } // setupUi

    void retranslateUi(QWidget *AlarmRuleSetting)
    {
        AlarmRuleSetting->setWindowTitle(QApplication::translate("AlarmRuleSetting", "AlarmRuleSetting", 0));
    } // retranslateUi

};

namespace Ui {
    class AlarmRuleSetting: public Ui_AlarmRuleSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMRULESETTING_H
