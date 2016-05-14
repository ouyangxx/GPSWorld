/********************************************************************************
** Form generated from reading UI file 'AlarmSuper.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMSUPER_H
#define UI_ALARMSUPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlarmSuper
{
public:

    void setupUi(QWidget *AlarmSuper)
    {
        if (AlarmSuper->objectName().isEmpty())
            AlarmSuper->setObjectName(QStringLiteral("AlarmSuper"));
        AlarmSuper->resize(400, 300);

        retranslateUi(AlarmSuper);

        QMetaObject::connectSlotsByName(AlarmSuper);
    } // setupUi

    void retranslateUi(QWidget *AlarmSuper)
    {
        AlarmSuper->setWindowTitle(QApplication::translate("AlarmSuper", "AlarmSuper", 0));
    } // retranslateUi

};

namespace Ui {
    class AlarmSuper: public Ui_AlarmSuper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMSUPER_H
