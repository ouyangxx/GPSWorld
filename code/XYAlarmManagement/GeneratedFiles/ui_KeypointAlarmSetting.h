/********************************************************************************
** Form generated from reading UI file 'KeypointAlarmSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYPOINTALARMSETTING_H
#define UI_KEYPOINTALARMSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KeypointAlarmSetting
{
public:

    void setupUi(QWidget *KeypointAlarmSetting)
    {
        if (KeypointAlarmSetting->objectName().isEmpty())
            KeypointAlarmSetting->setObjectName(QStringLiteral("KeypointAlarmSetting"));
        KeypointAlarmSetting->resize(400, 300);

        retranslateUi(KeypointAlarmSetting);

        QMetaObject::connectSlotsByName(KeypointAlarmSetting);
    } // setupUi

    void retranslateUi(QWidget *KeypointAlarmSetting)
    {
        KeypointAlarmSetting->setWindowTitle(QApplication::translate("KeypointAlarmSetting", "KeypointAlarmSetting", 0));
    } // retranslateUi

};

namespace Ui {
    class KeypointAlarmSetting: public Ui_KeypointAlarmSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYPOINTALARMSETTING_H
