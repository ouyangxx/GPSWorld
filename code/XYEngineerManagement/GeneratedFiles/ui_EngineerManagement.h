/********************************************************************************
** Form generated from reading UI file 'EngineerManagement.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENGINEERMANAGEMENT_H
#define UI_ENGINEERMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EngineerManagement
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *EngineerManagement)
    {
        if (EngineerManagement->objectName().isEmpty())
            EngineerManagement->setObjectName(QStringLiteral("EngineerManagement"));
        EngineerManagement->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EngineerManagement->sizePolicy().hasHeightForWidth());
        EngineerManagement->setSizePolicy(sizePolicy);
        EngineerManagement->setStyleSheet(QLatin1String("QWidget#EngineerManagement{\n"
"	background-color:#CCCCFF;\n"
"}"));
        horizontalLayout = new QHBoxLayout(EngineerManagement);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(EngineerManagement);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(EngineerManagement);

        QMetaObject::connectSlotsByName(EngineerManagement);
    } // setupUi

    void retranslateUi(QWidget *EngineerManagement)
    {
        EngineerManagement->setWindowTitle(QApplication::translate("EngineerManagement", "EngineerManagement", 0));
        label->setText(QApplication::translate("EngineerManagement", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; color:#909090;\">EngineerManagement</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class EngineerManagement: public Ui_EngineerManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENGINEERMANAGEMENT_H
