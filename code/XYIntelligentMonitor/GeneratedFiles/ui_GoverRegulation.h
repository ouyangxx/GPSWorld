/********************************************************************************
** Form generated from reading UI file 'GoverRegulation.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOVERREGULATION_H
#define UI_GOVERREGULATION_H

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

class Ui_GoverRegulation
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *GoverRegulation)
    {
        if (GoverRegulation->objectName().isEmpty())
            GoverRegulation->setObjectName(QStringLiteral("GoverRegulation"));
        GoverRegulation->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GoverRegulation->sizePolicy().hasHeightForWidth());
        GoverRegulation->setSizePolicy(sizePolicy);
        GoverRegulation->setStyleSheet(QLatin1String("QWidget#GoverRegulation{\n"
"	background-color: rgb(207,228,249);\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(GoverRegulation);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(GoverRegulation);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(GoverRegulation);

        QMetaObject::connectSlotsByName(GoverRegulation);
    } // setupUi

    void retranslateUi(QWidget *GoverRegulation)
    {
        GoverRegulation->setWindowTitle(QApplication::translate("GoverRegulation", "GoverRegulation", 0));
        label->setText(QApplication::translate("GoverRegulation", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; color:#909090;\">GoverRegulation</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class GoverRegulation: public Ui_GoverRegulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOVERREGULATION_H
