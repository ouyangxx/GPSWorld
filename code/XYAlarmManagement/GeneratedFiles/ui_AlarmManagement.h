/********************************************************************************
** Form generated from reading UI file 'AlarmManagement.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMMANAGEMENT_H
#define UI_ALARMMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlarmManagement
{
public:
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QTreeWidget *treeWidget;
    QTabWidget *tabWidget;

    void setupUi(QWidget *AlarmManagement)
    {
        if (AlarmManagement->objectName().isEmpty())
            AlarmManagement->setObjectName(QStringLiteral("AlarmManagement"));
        AlarmManagement->resize(1096, 613);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AlarmManagement->sizePolicy().hasHeightForWidth());
        AlarmManagement->setSizePolicy(sizePolicy);
        AlarmManagement->setStyleSheet(QLatin1String("QWidget#AlarmManagement {\n"
"	background-color: rgb(207,228,249);\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(AlarmManagement);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(AlarmManagement);
        splitter->setObjectName(QStringLiteral("splitter"));
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        treeWidget = new QTreeWidget(splitter);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        __qtreewidgetitem->setBackground(0, QColor(0, 0, 0));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        QIcon icon;
        icon.addFile(QStringLiteral(":/AlarmManagement/Resources/image/alarmsetting.png"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font;
        font.setPointSize(9);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/AlarmManagement/Resources/image/basealarmsetting.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/AlarmManagement/Resources/image/areaalarmsetting.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/AlarmManagement/Resources/image/offlinealarmsetting.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/AlarmManagement/Resources/image/speedalarmSetting.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/AlarmManagement/Resources/image/keypointalarmsetting.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/AlarmManagement/Resources/image/alarmrulesetting.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/AlarmManagement/Resources/image/alarmmonitor.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/AlarmManagement/Resources/image/alarmsuper.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/AlarmManagement/Resources/image/alarmstatistics.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem1->setFont(0, font);
        __qtreewidgetitem1->setIcon(0, icon);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem2->setIcon(0, icon1);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem3->setIcon(0, icon2);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem4->setIcon(0, icon3);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem5->setIcon(0, icon4);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem6->setIcon(0, icon5);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem7->setIcon(0, icon6);
        QTreeWidgetItem *__qtreewidgetitem8 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem8->setIcon(0, icon7);
        QTreeWidgetItem *__qtreewidgetitem9 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem9->setIcon(0, icon8);
        QTreeWidgetItem *__qtreewidgetitem10 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem10->setIcon(0, icon9);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMinimumSize(QSize(0, 0));
        treeWidget->setMaximumSize(QSize(300, 16777215));
        treeWidget->setStyleSheet(QLatin1String("QTreeWidget#treeWidget{ \n"
"	background-color:rgb(207,228,249);\n"
"}\n"
"QTreeWidget#treeWidget:item{\n"
"	height:40px;\n"
"	border: 1px dashed rgb(103,114,124);\n"
"	color: #000000;\n"
"	border-style: none none dashed none;  \n"
"	border-radius:0px;  \n"
"	background-color:rgb(207,228,249);\n"
"}\n"
"\n"
"QTreeWidget#treeWidget:item:hover{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgb(206,234,247), stop:1 #4F94CD);\n"
"}\n"
"\n"
"QTreeWidget#treeWidget:item:pressed\n"
"{\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #1B89CA, stop:1 #4F94CD);\n"
"\n"
"}"));
        splitter->addWidget(treeWidget);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QLatin1String("QTabBar::tab {\n"
"	border-bottom-left-radius:0px;\n"
"	border-bottom-right-radius:0px;\n"
"	color: #F0F0F0;\n"
"	min-width: 60px;\n"
"	min-height: 20px;\n"
"	padding: 3px 8px 3px 8px;\n"
"	margin:1px;\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #5CACEE, stop:1 #4F94CD); \n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #1B89CA, stop:1 #1077B5); \n"
"}\n"
""));
        splitter->addWidget(tabWidget);

        horizontalLayout->addWidget(splitter);


        retranslateUi(AlarmManagement);

        QMetaObject::connectSlotsByName(AlarmManagement);
    } // setupUi

    void retranslateUi(QWidget *AlarmManagement)
    {
        AlarmManagement->setWindowTitle(QApplication::translate("AlarmManagement", "AlarmManagement", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("AlarmManagement", "\346\212\245\350\255\246\347\256\241\347\220\206", 0));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("AlarmManagement", "\346\212\245\350\255\246\350\256\276\347\275\256", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("AlarmManagement", "\345\237\272\347\241\200\346\212\245\350\255\246\350\256\276\347\275\256", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("AlarmManagement", "\350\277\233\345\207\272\345\214\272\345\237\237\346\212\245\350\255\246\350\256\276\347\275\256", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QApplication::translate("AlarmManagement", "\347\246\273\347\272\277\346\212\245\350\255\246\350\256\276\347\275\256", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem1->child(3);
        ___qtreewidgetitem5->setText(0, QApplication::translate("AlarmManagement", "\351\253\230\351\200\237\344\275\216\351\200\237\346\212\245\350\255\246\350\256\276\347\275\256", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem1->child(4);
        ___qtreewidgetitem6->setText(0, QApplication::translate("AlarmManagement", "\345\205\263\351\224\256\347\202\271\346\212\245\350\255\246\350\256\276\347\275\256", 0));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem1->child(5);
        ___qtreewidgetitem7->setText(0, QApplication::translate("AlarmManagement", "\346\212\245\350\255\246\351\200\232\347\237\245\350\247\204\345\210\231\350\256\276\347\275\256", 0));
        QTreeWidgetItem *___qtreewidgetitem8 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem8->setText(0, QApplication::translate("AlarmManagement", "\346\212\245\350\255\246\347\233\221\346\216\247", 0));
        QTreeWidgetItem *___qtreewidgetitem9 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem9->setText(0, QApplication::translate("AlarmManagement", "\346\212\245\350\255\246\347\235\243\345\212\236", 0));
        QTreeWidgetItem *___qtreewidgetitem10 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem10->setText(0, QApplication::translate("AlarmManagement", "\346\212\245\350\255\246\347\273\237\350\256\241", 0));
        treeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class AlarmManagement: public Ui_AlarmManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMMANAGEMENT_H
