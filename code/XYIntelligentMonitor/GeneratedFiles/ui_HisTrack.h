/********************************************************************************
** Form generated from reading UI file 'HisTrack.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTRACK_H
#define UI_HISTRACK_H

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

class Ui_HisTrack
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *HisTrack)
    {
        if (HisTrack->objectName().isEmpty())
            HisTrack->setObjectName(QStringLiteral("HisTrack"));
        HisTrack->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HisTrack->sizePolicy().hasHeightForWidth());
        HisTrack->setSizePolicy(sizePolicy);
        HisTrack->setStyleSheet(QLatin1String("QWidget#HisTrack{\n"
"	background-color: rgb(207,228,249);\n"
"}"));
        horizontalLayout = new QHBoxLayout(HisTrack);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(HisTrack);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(HisTrack);

        QMetaObject::connectSlotsByName(HisTrack);
    } // setupUi

    void retranslateUi(QWidget *HisTrack)
    {
        HisTrack->setWindowTitle(QApplication::translate("HisTrack", "HisTrack", 0));
        label->setText(QApplication::translate("HisTrack", "<html><head/><body><p></p><p><span style=\" font-size:24pt; font-weight:600; color:#909090;\">HisTrack</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class HisTrack: public Ui_HisTrack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTRACK_H
