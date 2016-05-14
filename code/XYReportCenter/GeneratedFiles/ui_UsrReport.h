/********************************************************************************
** Form generated from reading UI file 'UsrReport.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USRREPORT_H
#define UI_USRREPORT_H

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

class Ui_UsrReport
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *UsrReport)
    {
        if (UsrReport->objectName().isEmpty())
            UsrReport->setObjectName(QStringLiteral("UsrReport"));
        UsrReport->resize(564, 399);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UsrReport->sizePolicy().hasHeightForWidth());
        UsrReport->setSizePolicy(sizePolicy);
        UsrReport->setStyleSheet(QLatin1String("QWidget#UsrReport{\n"
"	background-color: rgb(207,228,249);\n"
"}"));
        horizontalLayout = new QHBoxLayout(UsrReport);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(UsrReport);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(UsrReport);

        QMetaObject::connectSlotsByName(UsrReport);
    } // setupUi

    void retranslateUi(QWidget *UsrReport)
    {
        UsrReport->setWindowTitle(QApplication::translate("UsrReport", "UsrReport", 0));
        label->setText(QApplication::translate("UsrReport", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; color:#909090;\">UsrReport</span></p></body></html>\n"
"", 0));
    } // retranslateUi

};

namespace Ui {
    class UsrReport: public Ui_UsrReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRREPORT_H
