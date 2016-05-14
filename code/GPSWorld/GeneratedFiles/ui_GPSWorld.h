/********************************************************************************
** Form generated from reading UI file 'GPSWorld.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GPSWORLD_H
#define UI_GPSWORLD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GPSWorld
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_icon;
    QLabel *lab_title;
    QWidget *widget_style;
    QWidget *widget_notice;
    QPushButton *Warnning;
    QPushButton *OnlineNotice;
    QWidget *widget_terminal;
    QPushButton *terminalSetting;
    QPushButton *terminalCommand;
    QWidget *widget_btnMenu;
    QPushButton *btnMenu_Close;
    QPushButton *btnMenu_Max;
    QPushButton *btnMenu;
    QPushButton *btnMenu_Min;
    QWidget *widget_tool;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lab_Logo;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_toolBtn;
    QWidget *widget_repTool;
    QLabel *labelText5;
    QPushButton *reportButton;
    QWidget *widget_baseTool;
    QLabel *labelText4;
    QPushButton *baseButton;
    QWidget *widget_warnTool;
    QPushButton *warningButton;
    QLabel *labelText2;
    QWidget *widget_proTool;
    QLabel *labelText3;
    QPushButton *proButton;
    QWidget *widget_watchTool;
    QLabel *labelText1;
    QPushButton *watchButton;
    QSpacerItem *horizontalSpacer_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QWidget *GPSWorld)
    {
        if (GPSWorld->objectName().isEmpty())
            GPSWorld->setObjectName(QStringLiteral("GPSWorld"));
        GPSWorld->resize(1096, 700);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GPSWorld->sizePolicy().hasHeightForWidth());
        GPSWorld->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/GPSWorld/Resources/image/GPS.ico"), QSize(), QIcon::Normal, QIcon::Off);
        GPSWorld->setWindowIcon(icon);
        GPSWorld->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(GPSWorld);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_title = new QWidget(GPSWorld);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_title->sizePolicy().hasHeightForWidth());
        widget_title->setSizePolicy(sizePolicy1);
        widget_title->setMinimumSize(QSize(0, 25));
        widget_title->setMaximumSize(QSize(16777215, 25));
        horizontalLayout = new QHBoxLayout(widget_title);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_icon = new QPushButton(widget_title);
        btn_icon->setObjectName(QStringLiteral("btn_icon"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_icon->sizePolicy().hasHeightForWidth());
        btn_icon->setSizePolicy(sizePolicy2);
        btn_icon->setMinimumSize(QSize(25, 25));
        btn_icon->setMaximumSize(QSize(25, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/GPSWorld/Resources/image/GPS.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_icon->setIcon(icon1);
        btn_icon->setIconSize(QSize(25, 25));
        btn_icon->setAutoDefault(true);
        btn_icon->setFlat(true);

        horizontalLayout->addWidget(btn_icon);

        lab_title = new QLabel(widget_title);
        lab_title->setObjectName(QStringLiteral("lab_title"));
        sizePolicy1.setHeightForWidth(lab_title->sizePolicy().hasHeightForWidth());
        lab_title->setSizePolicy(sizePolicy1);
        lab_title->setMinimumSize(QSize(0, 25));
        lab_title->setMaximumSize(QSize(16777215, 25));
        QFont font;
        font.setPointSize(12);
        lab_title->setFont(font);
        lab_title->setLayoutDirection(Qt::LeftToRight);
        lab_title->setStyleSheet(QLatin1String("QLabel#lab_title{\n"
"	background: #1B89CA;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
""));

        horizontalLayout->addWidget(lab_title);

        widget_style = new QWidget(widget_title);
        widget_style->setObjectName(QStringLiteral("widget_style"));
        sizePolicy2.setHeightForWidth(widget_style->sizePolicy().hasHeightForWidth());
        widget_style->setSizePolicy(sizePolicy2);
        widget_style->setMinimumSize(QSize(268, 25));
        widget_style->setMaximumSize(QSize(268, 25));
        widget_style->setStyleSheet(QLatin1String("QWidget#widget_style{\n"
"		background: #1B89CA;\n"
"		color:#1B89CA;\n"
"}"));
        widget_notice = new QWidget(widget_style);
        widget_notice->setObjectName(QStringLiteral("widget_notice"));
        widget_notice->setGeometry(QRect(0, 0, 55, 25));
        sizePolicy2.setHeightForWidth(widget_notice->sizePolicy().hasHeightForWidth());
        widget_notice->setSizePolicy(sizePolicy2);
        Warnning = new QPushButton(widget_notice);
        Warnning->setObjectName(QStringLiteral("Warnning"));
        Warnning->setGeometry(QRect(0, 0, 25, 25));
        sizePolicy2.setHeightForWidth(Warnning->sizePolicy().hasHeightForWidth());
        Warnning->setSizePolicy(sizePolicy2);
        Warnning->setMinimumSize(QSize(25, 25));
        Warnning->setMaximumSize(QSize(25, 25));
        Warnning->setStyleSheet(QLatin1String("QPushButton#Warnning{\n"
"	border-radius:0px;\n"
"	color: #F0F0F0;\n"
"	background-color: rgb(25, 130, 191);\n"
"	border-style:none;\n"
"}\n"
"QPushButton#Warnning:hover{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(25, 134, 199, 0), stop:1 #5CACEE);\n"
"}"));
        Warnning->setIconSize(QSize(23, 23));
        Warnning->setAutoDefault(false);
        Warnning->setFlat(true);
        OnlineNotice = new QPushButton(widget_notice);
        OnlineNotice->setObjectName(QStringLiteral("OnlineNotice"));
        OnlineNotice->setGeometry(QRect(30, 0, 25, 25));
        sizePolicy2.setHeightForWidth(OnlineNotice->sizePolicy().hasHeightForWidth());
        OnlineNotice->setSizePolicy(sizePolicy2);
        OnlineNotice->setMinimumSize(QSize(25, 25));
        OnlineNotice->setMaximumSize(QSize(25, 25));
        OnlineNotice->setStyleSheet(QLatin1String("QPushButton#OnlineNotice{\n"
"	border-radius:0px;\n"
"	color: #F0F0F0;\n"
"	background-color: rgb(25, 130, 191);\n"
"	border-style:none;\n"
"}\n"
"QPushButton#OnlineNotice:hover{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(25, 134, 199, 0), stop:1 #5CACEE);\n"
"}"));
        OnlineNotice->setIconSize(QSize(25, 25));
        OnlineNotice->setAutoDefault(false);
        OnlineNotice->setFlat(true);
        widget_terminal = new QWidget(widget_style);
        widget_terminal->setObjectName(QStringLiteral("widget_terminal"));
        widget_terminal->setGeometry(QRect(65, 0, 64, 25));
        sizePolicy2.setHeightForWidth(widget_terminal->sizePolicy().hasHeightForWidth());
        widget_terminal->setSizePolicy(sizePolicy2);
        terminalSetting = new QPushButton(widget_terminal);
        terminalSetting->setObjectName(QStringLiteral("terminalSetting"));
        terminalSetting->setGeometry(QRect(0, 0, 32, 23));
        sizePolicy2.setHeightForWidth(terminalSetting->sizePolicy().hasHeightForWidth());
        terminalSetting->setSizePolicy(sizePolicy2);
        terminalSetting->setMinimumSize(QSize(32, 23));
        terminalSetting->setMaximumSize(QSize(32, 23));
        terminalSetting->setCursor(QCursor(Qt::ArrowCursor));
        terminalSetting->setFocusPolicy(Qt::NoFocus);
        terminalSetting->setStyleSheet(QLatin1String("QPushButton#terminalSetting{\n"
"	border-radius:0px;\n"
"	color: #F0F0F0;\n"
"	background-color:rgba(0,0,0,0);\n"
"	border-style:none;\n"
"}\n"
"QPushButton#terminalSetting:hover{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(25, 134, 199, 0), stop:1 #5CACEE);\n"
"}"));
        terminalSetting->setAutoDefault(true);
        terminalSetting->setFlat(true);
        terminalCommand = new QPushButton(widget_terminal);
        terminalCommand->setObjectName(QStringLiteral("terminalCommand"));
        terminalCommand->setGeometry(QRect(32, 0, 32, 23));
        sizePolicy2.setHeightForWidth(terminalCommand->sizePolicy().hasHeightForWidth());
        terminalCommand->setSizePolicy(sizePolicy2);
        terminalCommand->setMinimumSize(QSize(32, 23));
        terminalCommand->setMaximumSize(QSize(32, 23));
        terminalCommand->setCursor(QCursor(Qt::ArrowCursor));
        terminalCommand->setFocusPolicy(Qt::NoFocus);
        terminalCommand->setStyleSheet(QLatin1String("QPushButton#terminalCommand{\n"
"	border-radius:0px;\n"
"	color: #F0F0F0;\n"
"	background-color:rgba(0,0,0,0);\n"
"	border-style:none;\n"
"}\n"
"QPushButton#terminalCommand:hover{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(25, 134, 199, 0), stop:1 #5CACEE);\n"
"}"));
        terminalCommand->setAutoDefault(true);
        terminalCommand->setFlat(true);
        widget_btnMenu = new QWidget(widget_style);
        widget_btnMenu->setObjectName(QStringLiteral("widget_btnMenu"));
        widget_btnMenu->setGeometry(QRect(140, 0, 128, 25));
        sizePolicy2.setHeightForWidth(widget_btnMenu->sizePolicy().hasHeightForWidth());
        widget_btnMenu->setSizePolicy(sizePolicy2);
        btnMenu_Close = new QPushButton(widget_btnMenu);
        btnMenu_Close->setObjectName(QStringLiteral("btnMenu_Close"));
        btnMenu_Close->setGeometry(QRect(96, 0, 32, 23));
        sizePolicy2.setHeightForWidth(btnMenu_Close->sizePolicy().hasHeightForWidth());
        btnMenu_Close->setSizePolicy(sizePolicy2);
        btnMenu_Close->setMinimumSize(QSize(32, 23));
        btnMenu_Close->setMaximumSize(QSize(32, 23));
        btnMenu_Close->setBaseSize(QSize(32, 23));
        btnMenu_Close->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Close->setFocusPolicy(Qt::NoFocus);
        btnMenu_Close->setStyleSheet(QLatin1String("QPushButton#btnMenu_Close{\n"
"	border-radius:0px;\n"
"	color: #F0F0F0;\n"
"	background-color:rgba(0,0,0,0);\n"
"	border-style:none;\n"
"}\n"
"QPushButton#btnMenu_Close:hover{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(238, 0, 0, 128), stop:1 rgba(238, 44, 44, 255));\n"
"}"));
        btnMenu_Close->setAutoDefault(true);
        btnMenu_Close->setFlat(true);
        btnMenu_Max = new QPushButton(widget_btnMenu);
        btnMenu_Max->setObjectName(QStringLiteral("btnMenu_Max"));
        btnMenu_Max->setGeometry(QRect(64, 0, 32, 23));
        sizePolicy2.setHeightForWidth(btnMenu_Max->sizePolicy().hasHeightForWidth());
        btnMenu_Max->setSizePolicy(sizePolicy2);
        btnMenu_Max->setMinimumSize(QSize(32, 23));
        btnMenu_Max->setMaximumSize(QSize(32, 23));
        btnMenu_Max->setBaseSize(QSize(32, 23));
        btnMenu_Max->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Max->setFocusPolicy(Qt::NoFocus);
        btnMenu_Max->setStyleSheet(QLatin1String("QPushButton#btnMenu_Max{\n"
"	border-radius:0px;\n"
"	color: #F0F0F0;\n"
"	background-color:rgba(0,0,0,0);\n"
"	border-style:none;\n"
"}\n"
"QPushButton#btnMenu_Max:hover{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(25, 134, 199, 0), stop:1 #5CACEE);\n"
"}"));
        btnMenu_Max->setAutoDefault(true);
        btnMenu_Max->setFlat(true);
        btnMenu = new QPushButton(widget_btnMenu);
        btnMenu->setObjectName(QStringLiteral("btnMenu"));
        btnMenu->setGeometry(QRect(0, 0, 32, 23));
        sizePolicy2.setHeightForWidth(btnMenu->sizePolicy().hasHeightForWidth());
        btnMenu->setSizePolicy(sizePolicy2);
        btnMenu->setMinimumSize(QSize(32, 23));
        btnMenu->setMaximumSize(QSize(32, 23));
        btnMenu->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu->setFocusPolicy(Qt::NoFocus);
        btnMenu->setStyleSheet(QLatin1String("QPushButton#btnMenu{\n"
"	border-radius:0px;\n"
"	color: #F0F0F0;\n"
"	background-color:rgba(0,0,0,0);\n"
"	border-style:none;\n"
"}\n"
"QPushButton#btnMenu:hover{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(25, 134, 199, 0), stop:1 #5CACEE);\n"
"}"));
        btnMenu->setAutoDefault(true);
        btnMenu->setFlat(true);
        btnMenu_Min = new QPushButton(widget_btnMenu);
        btnMenu_Min->setObjectName(QStringLiteral("btnMenu_Min"));
        btnMenu_Min->setGeometry(QRect(32, 0, 32, 23));
        sizePolicy2.setHeightForWidth(btnMenu_Min->sizePolicy().hasHeightForWidth());
        btnMenu_Min->setSizePolicy(sizePolicy2);
        btnMenu_Min->setMinimumSize(QSize(32, 23));
        btnMenu_Min->setMaximumSize(QSize(32, 23));
        btnMenu_Min->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Min->setFocusPolicy(Qt::NoFocus);
        btnMenu_Min->setStyleSheet(QLatin1String("QPushButton#btnMenu_Min{\n"
"	border-radius:0px;\n"
"	color: #F0F0F0;\n"
"	background-color:rgba(0,0,0,0);\n"
"	border-style:none;\n"
"}\n"
"QPushButton#btnMenu_Min:hover{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(25, 134, 199, 0), stop:1 #5CACEE);\n"
"}"));
        btnMenu_Min->setAutoDefault(true);
        btnMenu_Min->setFlat(true);

        horizontalLayout->addWidget(widget_style);


        verticalLayout->addWidget(widget_title);

        widget_tool = new QWidget(GPSWorld);
        widget_tool->setObjectName(QStringLiteral("widget_tool"));
        sizePolicy1.setHeightForWidth(widget_tool->sizePolicy().hasHeightForWidth());
        widget_tool->setSizePolicy(sizePolicy1);
        widget_tool->setMinimumSize(QSize(0, 62));
        widget_tool->setMaximumSize(QSize(16777215, 62));
        widget_tool->setStyleSheet(QLatin1String("QWidget#widget_tool{\n"
"	background-color:#CCCCFF;\n"
"}\n"
""));
        horizontalLayout_2 = new QHBoxLayout(widget_tool);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 6, 0, 6);
        lab_Logo = new QLabel(widget_tool);
        lab_Logo->setObjectName(QStringLiteral("lab_Logo"));
        sizePolicy2.setHeightForWidth(lab_Logo->sizePolicy().hasHeightForWidth());
        lab_Logo->setSizePolicy(sizePolicy2);
        lab_Logo->setMinimumSize(QSize(185, 50));
        lab_Logo->setMaximumSize(QSize(185, 50));

        horizontalLayout_2->addWidget(lab_Logo);

        horizontalSpacer = new QSpacerItem(508, 48, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widget_toolBtn = new QWidget(widget_tool);
        widget_toolBtn->setObjectName(QStringLiteral("widget_toolBtn"));
        sizePolicy2.setHeightForWidth(widget_toolBtn->sizePolicy().hasHeightForWidth());
        widget_toolBtn->setSizePolicy(sizePolicy2);
        widget_toolBtn->setMinimumSize(QSize(310, 50));
        widget_toolBtn->setMaximumSize(QSize(310, 50));
        widget_repTool = new QWidget(widget_toolBtn);
        widget_repTool->setObjectName(QStringLiteral("widget_repTool"));
        widget_repTool->setGeometry(QRect(260, 0, 50, 50));
        sizePolicy2.setHeightForWidth(widget_repTool->sizePolicy().hasHeightForWidth());
        widget_repTool->setSizePolicy(sizePolicy2);
        widget_repTool->setStyleSheet(QLatin1String("QWidget#widget_repTool{\n"
"	background-color:#CCCCFF;\n"
"}\n"
"QWidget#widget_repTool:hover{\n"
"	background-color: rgb(156, 156, 232);\n"
"}"));
        labelText5 = new QLabel(widget_repTool);
        labelText5->setObjectName(QStringLiteral("labelText5"));
        labelText5->setGeometry(QRect(0, 35, 50, 15));
        sizePolicy2.setHeightForWidth(labelText5->sizePolicy().hasHeightForWidth());
        labelText5->setSizePolicy(sizePolicy2);
        reportButton = new QPushButton(widget_repTool);
        reportButton->setObjectName(QStringLiteral("reportButton"));
        reportButton->setGeometry(QRect(9, 0, 32, 32));
        sizePolicy2.setHeightForWidth(reportButton->sizePolicy().hasHeightForWidth());
        reportButton->setSizePolicy(sizePolicy2);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/GPSWorld/Resources/image/reportcenter.png"), QSize(), QIcon::Normal, QIcon::Off);
        reportButton->setIcon(icon2);
        reportButton->setIconSize(QSize(32, 32));
        widget_baseTool = new QWidget(widget_toolBtn);
        widget_baseTool->setObjectName(QStringLiteral("widget_baseTool"));
        widget_baseTool->setGeometry(QRect(195, 0, 50, 50));
        sizePolicy2.setHeightForWidth(widget_baseTool->sizePolicy().hasHeightForWidth());
        widget_baseTool->setSizePolicy(sizePolicy2);
        widget_baseTool->setStyleSheet(QLatin1String("QWidget#widget_baseTool{\n"
"	background-color:#CCCCFF;\n"
"}\n"
"QWidget#widget_baseTool:hover{\n"
"	background-color: rgb(156, 156, 232);\n"
"}"));
        labelText4 = new QLabel(widget_baseTool);
        labelText4->setObjectName(QStringLiteral("labelText4"));
        labelText4->setGeometry(QRect(0, 35, 50, 15));
        sizePolicy2.setHeightForWidth(labelText4->sizePolicy().hasHeightForWidth());
        labelText4->setSizePolicy(sizePolicy2);
        baseButton = new QPushButton(widget_baseTool);
        baseButton->setObjectName(QStringLiteral("baseButton"));
        baseButton->setGeometry(QRect(9, 0, 32, 32));
        sizePolicy2.setHeightForWidth(baseButton->sizePolicy().hasHeightForWidth());
        baseButton->setSizePolicy(sizePolicy2);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/GPSWorld/Resources/image/basicmanager.png"), QSize(), QIcon::Normal, QIcon::Off);
        baseButton->setIcon(icon3);
        baseButton->setIconSize(QSize(32, 32));
        widget_warnTool = new QWidget(widget_toolBtn);
        widget_warnTool->setObjectName(QStringLiteral("widget_warnTool"));
        widget_warnTool->setGeometry(QRect(65, 0, 50, 50));
        sizePolicy2.setHeightForWidth(widget_warnTool->sizePolicy().hasHeightForWidth());
        widget_warnTool->setSizePolicy(sizePolicy2);
        widget_warnTool->setStyleSheet(QLatin1String("QWidget#widget_warnTool{\n"
"	background-color:#CCCCFF;\n"
"}\n"
"QWidget#widget_warnTool:hover{\n"
"	background-color: rgb(156, 156, 232);\n"
"}"));
        warningButton = new QPushButton(widget_warnTool);
        warningButton->setObjectName(QStringLiteral("warningButton"));
        warningButton->setGeometry(QRect(9, 0, 32, 32));
        sizePolicy2.setHeightForWidth(warningButton->sizePolicy().hasHeightForWidth());
        warningButton->setSizePolicy(sizePolicy2);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/GPSWorld/Resources/image/warningButton.png"), QSize(), QIcon::Normal, QIcon::Off);
        warningButton->setIcon(icon4);
        warningButton->setIconSize(QSize(32, 32));
        labelText2 = new QLabel(widget_warnTool);
        labelText2->setObjectName(QStringLiteral("labelText2"));
        labelText2->setGeometry(QRect(0, 35, 50, 15));
        sizePolicy2.setHeightForWidth(labelText2->sizePolicy().hasHeightForWidth());
        labelText2->setSizePolicy(sizePolicy2);
        widget_proTool = new QWidget(widget_toolBtn);
        widget_proTool->setObjectName(QStringLiteral("widget_proTool"));
        widget_proTool->setGeometry(QRect(130, 0, 50, 50));
        sizePolicy2.setHeightForWidth(widget_proTool->sizePolicy().hasHeightForWidth());
        widget_proTool->setSizePolicy(sizePolicy2);
        widget_proTool->setStyleSheet(QLatin1String("QWidget#widget_proTool{\n"
"	background-color:#CCCCFF;\n"
"}\n"
"QWidget#widget_proTool:hover{\n"
"	background-color: rgb(156, 156, 232);\n"
"}"));
        labelText3 = new QLabel(widget_proTool);
        labelText3->setObjectName(QStringLiteral("labelText3"));
        labelText3->setGeometry(QRect(0, 35, 50, 15));
        sizePolicy2.setHeightForWidth(labelText3->sizePolicy().hasHeightForWidth());
        labelText3->setSizePolicy(sizePolicy2);
        proButton = new QPushButton(widget_proTool);
        proButton->setObjectName(QStringLiteral("proButton"));
        proButton->setGeometry(QRect(9, 0, 32, 32));
        sizePolicy2.setHeightForWidth(proButton->sizePolicy().hasHeightForWidth());
        proButton->setSizePolicy(sizePolicy2);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/GPSWorld/Resources/image/engineermanager.png"), QSize(), QIcon::Normal, QIcon::Off);
        proButton->setIcon(icon5);
        proButton->setIconSize(QSize(32, 32));
        widget_watchTool = new QWidget(widget_toolBtn);
        widget_watchTool->setObjectName(QStringLiteral("widget_watchTool"));
        widget_watchTool->setGeometry(QRect(0, 0, 50, 50));
        sizePolicy2.setHeightForWidth(widget_watchTool->sizePolicy().hasHeightForWidth());
        widget_watchTool->setSizePolicy(sizePolicy2);
        widget_watchTool->setStyleSheet(QLatin1String("QWidget#widget_watchTool{\n"
"	background-color:#CCCCFF;\n"
"}\n"
"QWidget#widget_watchTool:hover{\n"
"	background-color: rgb(156, 156, 232);\n"
"}"));
        labelText1 = new QLabel(widget_watchTool);
        labelText1->setObjectName(QStringLiteral("labelText1"));
        labelText1->setGeometry(QRect(0, 35, 50, 15));
        sizePolicy2.setHeightForWidth(labelText1->sizePolicy().hasHeightForWidth());
        labelText1->setSizePolicy(sizePolicy2);
        watchButton = new QPushButton(widget_watchTool);
        watchButton->setObjectName(QStringLiteral("watchButton"));
        watchButton->setGeometry(QRect(9, 0, 32, 32));
        sizePolicy2.setHeightForWidth(watchButton->sizePolicy().hasHeightForWidth());
        watchButton->setSizePolicy(sizePolicy2);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/GPSWorld/Resources/image/intelligence.png"), QSize(), QIcon::Normal, QIcon::Off);
        watchButton->setIcon(icon6);
        watchButton->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(widget_toolBtn);

        horizontalSpacer_2 = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_tool);

        stackedWidget = new QStackedWidget(GPSWorld);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setStyleSheet(QLatin1String("QWidget#stackedWidget {\n"
"	background-color: rgb(207,228,249);\n"
"}\n"
""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(GPSWorld);

        QMetaObject::connectSlotsByName(GPSWorld);
    } // setupUi

    void retranslateUi(QWidget *GPSWorld)
    {
        GPSWorld->setWindowTitle(QApplication::translate("GPSWorld", "GPSWorld", 0));
        btn_icon->setText(QString());
        lab_title->setText(QApplication::translate("GPSWorld", "<html><b>&nbsp;GPSWorld</b></html>", 0));
#ifndef QT_NO_TOOLTIP
        Warnning->setToolTip(QApplication::translate("GPSWorld", "\344\270\212\347\272\277\346\217\220\351\206\222", 0));
#endif // QT_NO_TOOLTIP
        Warnning->setText(QString());
#ifndef QT_NO_TOOLTIP
        OnlineNotice->setToolTip(QApplication::translate("GPSWorld", "\350\255\246\345\221\212\346\212\245\350\255\246", 0));
#endif // QT_NO_TOOLTIP
        OnlineNotice->setText(QString());
#ifndef QT_NO_TOOLTIP
        terminalSetting->setToolTip(QApplication::translate("GPSWorld", "\347\273\210\347\253\257\346\216\247\345\210\266", 0));
#endif // QT_NO_TOOLTIP
        terminalSetting->setText(QString());
#ifndef QT_NO_TOOLTIP
        terminalCommand->setToolTip(QApplication::translate("GPSWorld", "\344\270\212\350\241\214\345\221\275\344\273\244", 0));
#endif // QT_NO_TOOLTIP
        terminalCommand->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Close->setToolTip(QApplication::translate("GPSWorld", "\346\234\200\345\260\217\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        btnMenu_Close->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Max->setToolTip(QApplication::translate("GPSWorld", "\350\217\234\345\215\225", 0));
#endif // QT_NO_TOOLTIP
        btnMenu_Max->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu->setToolTip(QApplication::translate("GPSWorld", "\347\273\210\347\253\257\346\216\247\345\210\266", 0));
#endif // QT_NO_TOOLTIP
        btnMenu->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Min->setToolTip(QApplication::translate("GPSWorld", "\344\270\212\350\241\214\345\221\275\344\273\244", 0));
#endif // QT_NO_TOOLTIP
        btnMenu_Min->setText(QString());
        lab_Logo->setText(QString());
        labelText5->setText(QApplication::translate("GPSWorld", "<html><head/><body><p><span style=\" font-weight:600; color:#0055ff;\">\346\212\245\350\241\250\344\270\255\345\277\203</span></p></body></html>", 0));
        reportButton->setText(QString());
        labelText4->setText(QApplication::translate("GPSWorld", "<html><head/><body><p><span style=\" font-weight:600; color:#0055ff;\">\345\237\272\347\241\200\347\256\241\347\220\206</span></p></body></html>", 0));
        baseButton->setText(QString());
        warningButton->setText(QString());
        labelText2->setText(QApplication::translate("GPSWorld", "<html><head/><body><p><span style=\" font-weight:600; color:#0055ff;\">\346\212\245\350\255\246\347\256\241\347\220\206</span></p></body></html>", 0));
        labelText3->setText(QApplication::translate("GPSWorld", "<html><head/><body><p><span style=\" font-weight:600; color:#0055ff;\">\345\267\245\347\250\213\347\256\241\347\220\206</span></p></body></html>", 0));
        proButton->setText(QString());
        labelText1->setText(QApplication::translate("GPSWorld", "<html><head/><body><p><span style=\" font-weight:600; color:#0055ff;\">\346\231\272\350\203\275\347\233\221\346\216\247</span></p></body></html>", 0));
        watchButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GPSWorld: public Ui_GPSWorld {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPSWORLD_H
