/********************************************************************************
** Form generated from reading UI file 'BaseReport.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASEREPORT_H
#define UI_BASEREPORT_H

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

class Ui_BaseReport
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *BaseReport)
    {
        if (BaseReport->objectName().isEmpty())
            BaseReport->setObjectName(QStringLiteral("BaseReport"));
        BaseReport->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BaseReport->sizePolicy().hasHeightForWidth());
        BaseReport->setSizePolicy(sizePolicy);
        BaseReport->setStyleSheet(QLatin1String("QWidget#BaseReport{\n"
"	background-color: rgb(207,228,249);\n"
"}"));
        horizontalLayout = new QHBoxLayout(BaseReport);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(BaseReport);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(BaseReport);

        QMetaObject::connectSlotsByName(BaseReport);
    } // setupUi

    void retranslateUi(QWidget *BaseReport)
    {
        BaseReport->setWindowTitle(QApplication::translate("BaseReport", "BaseReport", 0));
        label->setText(QApplication::translate("BaseReport", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; color:#909090;\">BaseReport</span></p></body></html>\n"
"", 0));
    } // retranslateUi

};

namespace Ui {
    class BaseReport: public Ui_BaseReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASEREPORT_H
