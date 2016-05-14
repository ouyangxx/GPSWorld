/********************************************************************************
** Form generated from reading UI file 'AlarmMonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMMONITOR_H
#define UI_ALARMMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlarmMonitor
{
public:

    void setupUi(QWidget *AlarmMonitor)
    {
        if (AlarmMonitor->objectName().isEmpty())
            AlarmMonitor->setObjectName(QStringLiteral("AlarmMonitor"));
        AlarmMonitor->resize(400, 300);

        retranslateUi(AlarmMonitor);

        QMetaObject::connectSlotsByName(AlarmMonitor);
    } // setupUi

    void retranslateUi(QWidget *AlarmMonitor)
    {
        AlarmMonitor->setWindowTitle(QApplication::translate("AlarmMonitor", "AlarmMonitor", 0));
    } // retranslateUi

};

namespace Ui {
    class AlarmMonitor: public Ui_AlarmMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMMONITOR_H
