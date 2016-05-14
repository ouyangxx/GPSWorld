/********************************************************************************
** Form generated from reading UI file 'LeftNaviMonitorList.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEFTNAVIMONITORLIST_H
#define UI_LEFTNAVIMONITORLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LeftNaviMonitorList
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_search;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QTreeWidget *treeWidget_car;

    void setupUi(QWidget *LeftNaviMonitorList)
    {
        if (LeftNaviMonitorList->objectName().isEmpty())
            LeftNaviMonitorList->setObjectName(QStringLiteral("LeftNaviMonitorList"));
        LeftNaviMonitorList->resize(294, 568);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LeftNaviMonitorList->sizePolicy().hasHeightForWidth());
        LeftNaviMonitorList->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(LeftNaviMonitorList);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_search = new QWidget(LeftNaviMonitorList);
        widget_search->setObjectName(QStringLiteral("widget_search"));
        sizePolicy.setHeightForWidth(widget_search->sizePolicy().hasHeightForWidth());
        widget_search->setSizePolicy(sizePolicy);
        widget_search->setMinimumSize(QSize(0, 30));
        widget_search->setMaximumSize(QSize(16777215, 30));
        horizontalLayout = new QHBoxLayout(widget_search);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget_search);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(150, 20));
        lineEdit->setMaximumSize(QSize(150, 20));

        horizontalLayout->addWidget(lineEdit);

        pushButton_3 = new QPushButton(widget_search);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMinimumSize(QSize(20, 20));
        pushButton_3->setMaximumSize(QSize(20, 20));
        QIcon icon;
        icon.addFile(QStringLiteral(":/IntelligentMonitor/Resources/image/srch_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButton_3);

        pushButton = new QPushButton(widget_search);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(20, 20));
        pushButton->setMaximumSize(QSize(20, 20));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/IntelligentMonitor/Resources/image/srch_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_search);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMinimumSize(QSize(20, 20));
        pushButton_2->setMaximumSize(QSize(20, 20));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/IntelligentMonitor/Resources/image/srch_3.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget_search);

        treeWidget_car = new QTreeWidget(LeftNaviMonitorList);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget_car->setHeaderItem(__qtreewidgetitem);
        treeWidget_car->setObjectName(QStringLiteral("treeWidget_car"));

        verticalLayout->addWidget(treeWidget_car);


        retranslateUi(LeftNaviMonitorList);

        QMetaObject::connectSlotsByName(LeftNaviMonitorList);
    } // setupUi

    void retranslateUi(QWidget *LeftNaviMonitorList)
    {
        LeftNaviMonitorList->setWindowTitle(QApplication::translate("LeftNaviMonitorList", "LeftNaviMonitorList", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("LeftNaviMonitorList", "\346\237\245\350\257\242", 0));
#endif // QT_NO_TOOLTIP
        pushButton_3->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("LeftNaviMonitorList", "\350\256\276\347\275\256\350\275\246\350\276\206\346\230\276\347\244\272", 0));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("LeftNaviMonitorList", "\350\256\276\347\275\256\351\202\256\347\256\261\345\217\202\346\225\260", 0));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LeftNaviMonitorList: public Ui_LeftNaviMonitorList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFTNAVIMONITORLIST_H
