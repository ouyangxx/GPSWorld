/********************************************************************************
** Form generated from reading UI file 'VideoMonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOMONITOR_H
#define UI_VIDEOMONITOR_H

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

class Ui_VideoMonitor
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *VideoMonitor)
    {
        if (VideoMonitor->objectName().isEmpty())
            VideoMonitor->setObjectName(QStringLiteral("VideoMonitor"));
        VideoMonitor->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VideoMonitor->sizePolicy().hasHeightForWidth());
        VideoMonitor->setSizePolicy(sizePolicy);
        VideoMonitor->setStyleSheet(QLatin1String("QWidget#VideoMonitor{\n"
"	background-color: rgb(207,228,249);\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(VideoMonitor);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(VideoMonitor);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(VideoMonitor);

        QMetaObject::connectSlotsByName(VideoMonitor);
    } // setupUi

    void retranslateUi(QWidget *VideoMonitor)
    {
        VideoMonitor->setWindowTitle(QApplication::translate("VideoMonitor", "VideoMonitor", 0));
        label->setText(QApplication::translate("VideoMonitor", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; color:#909090;\">VideoMonitor</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class VideoMonitor: public Ui_VideoMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOMONITOR_H
