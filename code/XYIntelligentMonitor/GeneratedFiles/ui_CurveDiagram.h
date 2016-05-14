/********************************************************************************
** Form generated from reading UI file 'CurveDiagram.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVEDIAGRAM_H
#define UI_CURVEDIAGRAM_H

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

class Ui_CurveDiagram
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *CurveDiagram)
    {
        if (CurveDiagram->objectName().isEmpty())
            CurveDiagram->setObjectName(QStringLiteral("CurveDiagram"));
        CurveDiagram->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CurveDiagram->sizePolicy().hasHeightForWidth());
        CurveDiagram->setSizePolicy(sizePolicy);
        CurveDiagram->setStyleSheet(QLatin1String("QWidget#CurveDiagram{\n"
"	background-color: rgb(207,228,249);\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(CurveDiagram);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(CurveDiagram);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(CurveDiagram);

        QMetaObject::connectSlotsByName(CurveDiagram);
    } // setupUi

    void retranslateUi(QWidget *CurveDiagram)
    {
        CurveDiagram->setWindowTitle(QApplication::translate("CurveDiagram", "CurveDiagram", 0));
        label->setText(QApplication::translate("CurveDiagram", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; color:#909090;\">CurveDiagram</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class CurveDiagram: public Ui_CurveDiagram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVEDIAGRAM_H
