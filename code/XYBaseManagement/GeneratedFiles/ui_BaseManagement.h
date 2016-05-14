/********************************************************************************
** Form generated from reading UI file 'BaseManagement.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASEMANAGEMENT_H
#define UI_BASEMANAGEMENT_H

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

class Ui_BaseManagement
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *BaseManagement)
    {
        if (BaseManagement->objectName().isEmpty())
            BaseManagement->setObjectName(QStringLiteral("BaseManagement"));
        BaseManagement->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BaseManagement->sizePolicy().hasHeightForWidth());
        BaseManagement->setSizePolicy(sizePolicy);
        BaseManagement->setStyleSheet(QLatin1String("QWidget#BaseManagement{\n"
"	background-color:#CCCCFF;\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(BaseManagement);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(BaseManagement);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(BaseManagement);

        QMetaObject::connectSlotsByName(BaseManagement);
    } // setupUi

    void retranslateUi(QWidget *BaseManagement)
    {
        BaseManagement->setWindowTitle(QApplication::translate("BaseManagement", "BaseManagement", 0));
        label->setText(QApplication::translate("BaseManagement", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; color:#909090;\">BaseManagement</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class BaseManagement: public Ui_BaseManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASEMANAGEMENT_H
