/********************************************************************************
** Form generated from reading UI file 'IntelligentMonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTELLIGENTMONITOR_H
#define UI_INTELLIGENTMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IntelligentMonitor
{
public:
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QWidget *widget_left;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_navi;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_navi1;
    QPushButton *btn_navi2;
    QPushButton *btn_navi3;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget_navi;
    QWidget *widget_right;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_2;
    QWidget *widget_rTop;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_tool;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_fresh;
    QPushButton *btn_distance;
    QPushButton *btn_point;
    QPushButton *btn_zhexian;
    QPushButton *btn_juxing;
    QPushButton *btn_circle;
    QPushButton *btn_duobian;
    QPushButton *btn_exitedit;
    QPushButton *btn_tuceng;
    QPushButton *btn_model;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_map;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_rBottom;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_data;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_carMonitor;
    QPushButton *btn_curvey;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *comb_car;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_excel;
    QStackedWidget *stackedWidget_data;

    void setupUi(QWidget *IntelligentMonitor)
    {
        if (IntelligentMonitor->objectName().isEmpty())
            IntelligentMonitor->setObjectName(QStringLiteral("IntelligentMonitor"));
        IntelligentMonitor->resize(1096, 613);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(IntelligentMonitor->sizePolicy().hasHeightForWidth());
        IntelligentMonitor->setSizePolicy(sizePolicy);
        IntelligentMonitor->setStyleSheet(QLatin1String("QWidget#IntelligentMonitor{\n"
"	background-color: rgb(207,228,249);\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(IntelligentMonitor);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(IntelligentMonitor);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget_left = new QWidget(splitter);
        widget_left->setObjectName(QStringLiteral("widget_left"));
        sizePolicy.setHeightForWidth(widget_left->sizePolicy().hasHeightForWidth());
        widget_left->setSizePolicy(sizePolicy);
        widget_left->setMaximumSize(QSize(300, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget_left);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, 0, 0, 0);
        widget_navi = new QWidget(widget_left);
        widget_navi->setObjectName(QStringLiteral("widget_navi"));
        sizePolicy.setHeightForWidth(widget_navi->sizePolicy().hasHeightForWidth());
        widget_navi->setSizePolicy(sizePolicy);
        widget_navi->setMinimumSize(QSize(0, 45));
        widget_navi->setMaximumSize(QSize(16777215, 45));
        widget_navi->setStyleSheet(QStringLiteral("background-color: rgb(170, 170, 255);"));
        horizontalLayout_2 = new QHBoxLayout(widget_navi);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_navi1 = new QPushButton(widget_navi);
        btn_navi1->setObjectName(QStringLiteral("btn_navi1"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_navi1->sizePolicy().hasHeightForWidth());
        btn_navi1->setSizePolicy(sizePolicy1);
        btn_navi1->setMinimumSize(QSize(0, 38));
        btn_navi1->setMaximumSize(QSize(48, 38));
        QIcon icon;
        icon.addFile(QStringLiteral(":/IntelligentMonitor/Resources/image/navi_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_navi1->setIcon(icon);
        btn_navi1->setIconSize(QSize(48, 38));

        horizontalLayout_2->addWidget(btn_navi1);

        btn_navi2 = new QPushButton(widget_navi);
        btn_navi2->setObjectName(QStringLiteral("btn_navi2"));
        sizePolicy1.setHeightForWidth(btn_navi2->sizePolicy().hasHeightForWidth());
        btn_navi2->setSizePolicy(sizePolicy1);
        btn_navi2->setMinimumSize(QSize(0, 38));
        btn_navi2->setMaximumSize(QSize(48, 38));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/IntelligentMonitor/Resources/image/navi_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_navi2->setIcon(icon1);
        btn_navi2->setIconSize(QSize(48, 38));

        horizontalLayout_2->addWidget(btn_navi2);

        btn_navi3 = new QPushButton(widget_navi);
        btn_navi3->setObjectName(QStringLiteral("btn_navi3"));
        sizePolicy1.setHeightForWidth(btn_navi3->sizePolicy().hasHeightForWidth());
        btn_navi3->setSizePolicy(sizePolicy1);
        btn_navi3->setMinimumSize(QSize(0, 38));
        btn_navi3->setMaximumSize(QSize(48, 38));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/IntelligentMonitor/Resources/image/navi_3.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_navi3->setIcon(icon2);
        btn_navi3->setIconSize(QSize(48, 38));

        horizontalLayout_2->addWidget(btn_navi3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(widget_navi);

        stackedWidget_navi = new QStackedWidget(widget_left);
        stackedWidget_navi->setObjectName(QStringLiteral("stackedWidget_navi"));
        sizePolicy.setHeightForWidth(stackedWidget_navi->sizePolicy().hasHeightForWidth());
        stackedWidget_navi->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(stackedWidget_navi);

        splitter->addWidget(widget_left);
        widget_right = new QWidget(splitter);
        widget_right->setObjectName(QStringLiteral("widget_right"));
        sizePolicy.setHeightForWidth(widget_right->sizePolicy().hasHeightForWidth());
        widget_right->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(widget_right);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        splitter_2 = new QSplitter(widget_right);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        widget_rTop = new QWidget(splitter_2);
        widget_rTop->setObjectName(QStringLiteral("widget_rTop"));
        sizePolicy.setHeightForWidth(widget_rTop->sizePolicy().hasHeightForWidth());
        widget_rTop->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(widget_rTop);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_tool = new QWidget(widget_rTop);
        widget_tool->setObjectName(QStringLiteral("widget_tool"));
        sizePolicy.setHeightForWidth(widget_tool->sizePolicy().hasHeightForWidth());
        widget_tool->setSizePolicy(sizePolicy);
        widget_tool->setMinimumSize(QSize(0, 30));
        widget_tool->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_3 = new QHBoxLayout(widget_tool);
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(6, 2, 0, 2);
        btn_fresh = new QPushButton(widget_tool);
        btn_fresh->setObjectName(QStringLiteral("btn_fresh"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_fresh->sizePolicy().hasHeightForWidth());
        btn_fresh->setSizePolicy(sizePolicy2);
        btn_fresh->setMinimumSize(QSize(25, 25));
        btn_fresh->setMaximumSize(QSize(25, 25));
        btn_fresh->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/IntelligentMonitor/Resources/image/map_refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_fresh->setIcon(icon3);
        btn_fresh->setIconSize(QSize(25, 25));
        btn_fresh->setFlat(false);

        horizontalLayout_3->addWidget(btn_fresh);

        btn_distance = new QPushButton(widget_tool);
        btn_distance->setObjectName(QStringLiteral("btn_distance"));
        sizePolicy2.setHeightForWidth(btn_distance->sizePolicy().hasHeightForWidth());
        btn_distance->setSizePolicy(sizePolicy2);
        btn_distance->setMinimumSize(QSize(25, 25));
        btn_distance->setMaximumSize(QSize(25, 25));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/IntelligentMonitor/Resources/image/map_distance.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_distance->setIcon(icon4);
        btn_distance->setIconSize(QSize(25, 25));
        btn_distance->setFlat(false);

        horizontalLayout_3->addWidget(btn_distance);

        btn_point = new QPushButton(widget_tool);
        btn_point->setObjectName(QStringLiteral("btn_point"));
        sizePolicy2.setHeightForWidth(btn_point->sizePolicy().hasHeightForWidth());
        btn_point->setSizePolicy(sizePolicy2);
        btn_point->setMinimumSize(QSize(25, 25));
        btn_point->setMaximumSize(QSize(25, 25));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/IntelligentMonitor/Resources/image/map_point.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_point->setIcon(icon5);
        btn_point->setIconSize(QSize(25, 25));
        btn_point->setFlat(false);

        horizontalLayout_3->addWidget(btn_point);

        btn_zhexian = new QPushButton(widget_tool);
        btn_zhexian->setObjectName(QStringLiteral("btn_zhexian"));
        sizePolicy2.setHeightForWidth(btn_zhexian->sizePolicy().hasHeightForWidth());
        btn_zhexian->setSizePolicy(sizePolicy2);
        btn_zhexian->setMinimumSize(QSize(25, 25));
        btn_zhexian->setMaximumSize(QSize(25, 25));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/IntelligentMonitor/Resources/image/map_zhexian.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_zhexian->setIcon(icon6);
        btn_zhexian->setIconSize(QSize(25, 25));
        btn_zhexian->setFlat(false);

        horizontalLayout_3->addWidget(btn_zhexian);

        btn_juxing = new QPushButton(widget_tool);
        btn_juxing->setObjectName(QStringLiteral("btn_juxing"));
        sizePolicy2.setHeightForWidth(btn_juxing->sizePolicy().hasHeightForWidth());
        btn_juxing->setSizePolicy(sizePolicy2);
        btn_juxing->setMinimumSize(QSize(25, 25));
        btn_juxing->setMaximumSize(QSize(25, 25));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/IntelligentMonitor/Resources/image/map_juxing.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_juxing->setIcon(icon7);
        btn_juxing->setIconSize(QSize(25, 25));
        btn_juxing->setFlat(false);

        horizontalLayout_3->addWidget(btn_juxing);

        btn_circle = new QPushButton(widget_tool);
        btn_circle->setObjectName(QStringLiteral("btn_circle"));
        sizePolicy2.setHeightForWidth(btn_circle->sizePolicy().hasHeightForWidth());
        btn_circle->setSizePolicy(sizePolicy2);
        btn_circle->setMinimumSize(QSize(25, 25));
        btn_circle->setMaximumSize(QSize(25, 25));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/IntelligentMonitor/Resources/image/map_circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_circle->setIcon(icon8);
        btn_circle->setIconSize(QSize(25, 25));
        btn_circle->setFlat(false);

        horizontalLayout_3->addWidget(btn_circle);

        btn_duobian = new QPushButton(widget_tool);
        btn_duobian->setObjectName(QStringLiteral("btn_duobian"));
        sizePolicy2.setHeightForWidth(btn_duobian->sizePolicy().hasHeightForWidth());
        btn_duobian->setSizePolicy(sizePolicy2);
        btn_duobian->setMinimumSize(QSize(25, 25));
        btn_duobian->setMaximumSize(QSize(25, 25));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/IntelligentMonitor/Resources/image/map_duobianxing.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_duobian->setIcon(icon9);
        btn_duobian->setIconSize(QSize(25, 25));
        btn_duobian->setFlat(false);

        horizontalLayout_3->addWidget(btn_duobian);

        btn_exitedit = new QPushButton(widget_tool);
        btn_exitedit->setObjectName(QStringLiteral("btn_exitedit"));
        sizePolicy2.setHeightForWidth(btn_exitedit->sizePolicy().hasHeightForWidth());
        btn_exitedit->setSizePolicy(sizePolicy2);
        btn_exitedit->setMinimumSize(QSize(25, 25));
        btn_exitedit->setMaximumSize(QSize(25, 25));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/IntelligentMonitor/Resources/image/map_exitEdit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_exitedit->setIcon(icon10);
        btn_exitedit->setIconSize(QSize(25, 25));
        btn_exitedit->setFlat(false);

        horizontalLayout_3->addWidget(btn_exitedit);

        btn_tuceng = new QPushButton(widget_tool);
        btn_tuceng->setObjectName(QStringLiteral("btn_tuceng"));
        sizePolicy2.setHeightForWidth(btn_tuceng->sizePolicy().hasHeightForWidth());
        btn_tuceng->setSizePolicy(sizePolicy2);
        btn_tuceng->setMinimumSize(QSize(25, 25));
        btn_tuceng->setMaximumSize(QSize(25, 25));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/IntelligentMonitor/Resources/image/map_tuceng.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_tuceng->setIcon(icon11);
        btn_tuceng->setIconSize(QSize(25, 25));
        btn_tuceng->setFlat(false);

        horizontalLayout_3->addWidget(btn_tuceng);

        btn_model = new QPushButton(widget_tool);
        btn_model->setObjectName(QStringLiteral("btn_model"));
        sizePolicy2.setHeightForWidth(btn_model->sizePolicy().hasHeightForWidth());
        btn_model->setSizePolicy(sizePolicy2);
        btn_model->setMinimumSize(QSize(25, 25));
        btn_model->setMaximumSize(QSize(25, 25));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/IntelligentMonitor/Resources/image/map_model.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_model->setIcon(icon12);
        btn_model->setIconSize(QSize(25, 25));
        btn_model->setFlat(false);

        horizontalLayout_3->addWidget(btn_model);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label = new QLabel(widget_tool);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(374, 26));
        label->setMaximumSize(QSize(16777215, 26));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_3->addWidget(widget_tool);

        widget_map = new QWidget(widget_rTop);
        widget_map->setObjectName(QStringLiteral("widget_map"));
        sizePolicy.setHeightForWidth(widget_map->sizePolicy().hasHeightForWidth());
        widget_map->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(widget_map);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));

        verticalLayout_3->addWidget(widget_map);

        splitter_2->addWidget(widget_rTop);
        widget_rBottom = new QWidget(splitter_2);
        widget_rBottom->setObjectName(QStringLiteral("widget_rBottom"));
        sizePolicy.setHeightForWidth(widget_rBottom->sizePolicy().hasHeightForWidth());
        widget_rBottom->setSizePolicy(sizePolicy);
        widget_rBottom->setMaximumSize(QSize(16777215, 250));
        verticalLayout_5 = new QVBoxLayout(widget_rBottom);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_data = new QWidget(widget_rBottom);
        widget_data->setObjectName(QStringLiteral("widget_data"));
        sizePolicy.setHeightForWidth(widget_data->sizePolicy().hasHeightForWidth());
        widget_data->setSizePolicy(sizePolicy);
        widget_data->setMinimumSize(QSize(0, 27));
        widget_data->setMaximumSize(QSize(16777215, 27));
        horizontalLayout_4 = new QHBoxLayout(widget_data);
        horizontalLayout_4->setSpacing(4);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(6, 2, 6, 0);
        btn_carMonitor = new QPushButton(widget_data);
        btn_carMonitor->setObjectName(QStringLiteral("btn_carMonitor"));
        sizePolicy2.setHeightForWidth(btn_carMonitor->sizePolicy().hasHeightForWidth());
        btn_carMonitor->setSizePolicy(sizePolicy2);
        btn_carMonitor->setMinimumSize(QSize(78, 28));
        btn_carMonitor->setMaximumSize(QSize(70, 25));
        btn_carMonitor->setStyleSheet(QLatin1String("QPushButton#btn_carMonitor {\n"
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
"QPushButton#btn_carMonitor:selected,QPushButton#btn_carMonitor:hover {\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #1B89CA, stop:1 #1077B5); \n"
"}\n"
""));
        btn_carMonitor->setAutoDefault(true);
        btn_carMonitor->setFlat(false);

        horizontalLayout_4->addWidget(btn_carMonitor);

        btn_curvey = new QPushButton(widget_data);
        btn_curvey->setObjectName(QStringLiteral("btn_curvey"));
        sizePolicy2.setHeightForWidth(btn_curvey->sizePolicy().hasHeightForWidth());
        btn_curvey->setSizePolicy(sizePolicy2);
        btn_curvey->setMinimumSize(QSize(78, 28));
        btn_curvey->setMaximumSize(QSize(70, 25));
        btn_curvey->setStyleSheet(QLatin1String("QPushButton#btn_curvey {\n"
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
"QPushButton#btn_curvey:selected, QPushButton#btn_curvey:hover {\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #1B89CA, stop:1 #1077B5); \n"
"}\n"
""));
        btn_curvey->setAutoDefault(true);

        horizontalLayout_4->addWidget(btn_curvey);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        comb_car = new QComboBox(widget_data);
        comb_car->setObjectName(QStringLiteral("comb_car"));
        sizePolicy2.setHeightForWidth(comb_car->sizePolicy().hasHeightForWidth());
        comb_car->setSizePolicy(sizePolicy2);
        comb_car->setMinimumSize(QSize(120, 25));
        comb_car->setMaximumSize(QSize(120, 25));
        comb_car->setStyleSheet(QLatin1String("QComboBox#comb_car{\n"
"	border-radius: 3px;\n"
"	padding: 1px 10px 1px 5px;\n"
"	border: 1px solid #5CACEE;\n"
"}\n"
"\n"
"QComboBox#comb_car::item {\n"
"	min-height:16px;\n"
"}\n"
"\n"
"QComboBox#comb_car::drop-down {\n"
"	subcontrol-origin: padding;\n"
"	subcontrol-position: top right;\n"
"	width: 15px; \n"
"	border-left-width: 1px;\n"
"	border-left-style: solid;\n"
"	border-top-right-radius: 3px;\n"
"	border-bottom-right-radius: 3px;\n"
"	border-left-color: #5CACEE;\n"
"}\n"
"\n"
"QComboBox#comb_car::down-arrow{\n"
"	image: url(:/IntelligentMonitor/Resources/image/array_down.png); \n"
"}"));

        horizontalLayout_4->addWidget(comb_car);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        btn_excel = new QPushButton(widget_data);
        btn_excel->setObjectName(QStringLiteral("btn_excel"));
        btn_excel->setMinimumSize(QSize(18, 20));
        btn_excel->setMaximumSize(QSize(18, 20));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/IntelligentMonitor/Resources/image/excel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_excel->setIcon(icon13);
        btn_excel->setIconSize(QSize(18, 20));

        horizontalLayout_4->addWidget(btn_excel);


        verticalLayout_5->addWidget(widget_data);

        stackedWidget_data = new QStackedWidget(widget_rBottom);
        stackedWidget_data->setObjectName(QStringLiteral("stackedWidget_data"));
        sizePolicy.setHeightForWidth(stackedWidget_data->sizePolicy().hasHeightForWidth());
        stackedWidget_data->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(stackedWidget_data);

        splitter_2->addWidget(widget_rBottom);

        verticalLayout->addWidget(splitter_2);

        splitter->addWidget(widget_right);

        horizontalLayout->addWidget(splitter);


        retranslateUi(IntelligentMonitor);

        btn_carMonitor->setDefault(false);


        QMetaObject::connectSlotsByName(IntelligentMonitor);
    } // setupUi

    void retranslateUi(QWidget *IntelligentMonitor)
    {
        IntelligentMonitor->setWindowTitle(QApplication::translate("IntelligentMonitor", "IntelligentMonitor", 0));
#ifndef QT_NO_TOOLTIP
        btn_navi1->setToolTip(QApplication::translate("IntelligentMonitor", "\347\233\221\346\216\247\345\210\227\350\241\250", 0));
#endif // QT_NO_TOOLTIP
        btn_navi1->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_navi2->setToolTip(QApplication::translate("IntelligentMonitor", "\345\267\245\345\216\202\345\267\245\345\234\260", 0));
#endif // QT_NO_TOOLTIP
        btn_navi2->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_navi3->setToolTip(QApplication::translate("IntelligentMonitor", "\346\210\221\347\232\204\345\234\260\345\233\276", 0));
#endif // QT_NO_TOOLTIP
        btn_navi3->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_fresh->setToolTip(QApplication::translate("IntelligentMonitor", "\345\210\267\346\226\260\345\234\260\345\233\276", 0));
#endif // QT_NO_TOOLTIP
        btn_fresh->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_distance->setToolTip(QApplication::translate("IntelligentMonitor", "\346\265\213\350\267\235", 0));
#endif // QT_NO_TOOLTIP
        btn_distance->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_point->setToolTip(QApplication::translate("IntelligentMonitor", "\346\240\207\346\263\250", 0));
#endif // QT_NO_TOOLTIP
        btn_point->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_zhexian->setToolTip(QApplication::translate("IntelligentMonitor", "\346\212\230\347\272\277", 0));
#endif // QT_NO_TOOLTIP
        btn_zhexian->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_juxing->setToolTip(QApplication::translate("IntelligentMonitor", "\347\237\251\345\275\242", 0));
#endif // QT_NO_TOOLTIP
        btn_juxing->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_circle->setToolTip(QApplication::translate("IntelligentMonitor", "\345\234\206\345\275\242", 0));
#endif // QT_NO_TOOLTIP
        btn_circle->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_duobian->setToolTip(QApplication::translate("IntelligentMonitor", "\345\244\232\350\276\271\345\275\242", 0));
#endif // QT_NO_TOOLTIP
        btn_duobian->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_exitedit->setToolTip(QApplication::translate("IntelligentMonitor", "\351\200\200\345\207\272\347\274\226\350\276\221", 0));
#endif // QT_NO_TOOLTIP
        btn_exitedit->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_tuceng->setToolTip(QApplication::translate("IntelligentMonitor", "\346\230\276\347\244\272\345\233\276\345\261\202", 0));
#endif // QT_NO_TOOLTIP
        btn_tuceng->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_model->setToolTip(QApplication::translate("IntelligentMonitor", "\346\250\241\345\236\213", 0));
#endif // QT_NO_TOOLTIP
        btn_model->setText(QString());
        label->setText(QApplication::translate("IntelligentMonitor", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#ff0000;\">* \346\273\221\345\212\250\346\273\221\350\275\256\346\224\276\345\244\247/\347\274\251\345\260\217\345\234\260\345\233\276,\346\213\226\345\212\250\351\274\240\346\240\207\346\224\271\345\217\230\344\275\215\347\275\256,\345\217\214\345\207\273\351\274\240\346\240\207\347\273\223\346\235\237\347\274\226\350\276\221</span></p></body></html>", 0));
        btn_carMonitor->setText(QApplication::translate("IntelligentMonitor", "\350\275\246\350\276\206\347\233\221\346\216\247", 0));
        btn_curvey->setText(QApplication::translate("IntelligentMonitor", "\350\275\250\350\277\271\350\267\237\350\270\252", 0));
        comb_car->clear();
        comb_car->insertItems(0, QStringList()
         << QApplication::translate("IntelligentMonitor", "-\350\257\267\351\200\211\346\213\251\350\275\246\350\276\206-", 0)
        );
        btn_excel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class IntelligentMonitor: public Ui_IntelligentMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTELLIGENTMONITOR_H
