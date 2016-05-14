/********************************************************************************
** Form generated from reading UI file 'AlarmStatistics.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMSTATISTICS_H
#define UI_ALARMSTATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlarmStatistics
{
public:

    void setupUi(QWidget *AlarmStatistics)
    {
        if (AlarmStatistics->objectName().isEmpty())
            AlarmStatistics->setObjectName(QStringLiteral("AlarmStatistics"));
        AlarmStatistics->resize(400, 300);

        retranslateUi(AlarmStatistics);

        QMetaObject::connectSlotsByName(AlarmStatistics);
    } // setupUi

    void retranslateUi(QWidget *AlarmStatistics)
    {
        AlarmStatistics->setWindowTitle(QApplication::translate("AlarmStatistics", "AlarmStatistics", 0));
    } // retranslateUi

};

namespace Ui {
    class AlarmStatistics: public Ui_AlarmStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMSTATISTICS_H
