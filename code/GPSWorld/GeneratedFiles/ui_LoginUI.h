/********************************************************************************
** Form generated from reading UI file 'LoginUI.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINUI_H
#define UI_LOGINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginUI
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *fameBack;
    QComboBox *comb_usrName;
    QLineEdit *lineEdit_pwd;
    QPushButton *btn_login;
    QPushButton *btn_min;
    QPushButton *btn_close;
    QCheckBox *checkbox_remeberPassword;
    QCheckBox *checkbox_autoLogin;
    QPushButton *btn_register;
    QPushButton *btn_findPassword;
    QPushButton *btn_setting;

    void setupUi(QWidget *LoginUI)
    {
        if (LoginUI->objectName().isEmpty())
            LoginUI->setObjectName(QStringLiteral("LoginUI"));
        LoginUI->resize(448, 331);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginUI->sizePolicy().hasHeightForWidth());
        LoginUI->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/GPSWorld/Resources/image/EBIM.ico"), QSize(), QIcon::Normal, QIcon::Off);
        LoginUI->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(LoginUI);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        fameBack = new QFrame(LoginUI);
        fameBack->setObjectName(QStringLiteral("fameBack"));
        fameBack->setStyleSheet(QLatin1String("QFrame#fameBack\n"
"{\n"
"background-image: url(:/Login/Resources/login/background.png);\n"
"}\n"
"\n"
""));
        fameBack->setFrameShape(QFrame::StyledPanel);
        fameBack->setFrameShadow(QFrame::Raised);
        fameBack->setLineWidth(1);
        comb_usrName = new QComboBox(fameBack);
        comb_usrName->setObjectName(QStringLiteral("comb_usrName"));
        comb_usrName->setGeometry(QRect(88, 160, 263, 30));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comb_usrName->sizePolicy().hasHeightForWidth());
        comb_usrName->setSizePolicy(sizePolicy1);
        comb_usrName->setAutoFillBackground(false);
        comb_usrName->setStyleSheet(QLatin1String("QComboBox#comb_usrName::hover{\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.534, y1:1, x2:0.545, y2:0, stop:0 rgba(36, 132, 238, 255), stop:0.982955 rgba(143, 192, 255, 0));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:0.506, x2:1, y2:0.511364, stop:0 rgba(36, 132, 238, 255), stop:0.982955 rgba(143, 192, 255, 0));\n"
"	border-bottom-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.5, y2:1, stop:0 rgba(36, 132, 238, 255), stop:0.982955 rgba(143, 192, 255, 0));\n"
"	border-left-color: qlineargradient(spread:pad, x1:1, y1:0.579545, x2:0, y2:0.574, stop:0 rgba(36, 132, 238, 255), stop:0.982955 rgba(143, 192, 255, 0));\n"
"}  \n"
"\n"
"QComboBox#comb_usrName{\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.471273, y1:0.71, x2:0.483, y2:0, stop:0 rgba(191, 191, 191, 255), stop:0.982955 rgba(143, 192, 255, 0));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0.301, y1:0.510682, x2:1, y2:0.522, stop:0 rgba(191, 191, 191, 255), stop:0.982955 rgba(143, 192, 255, 0));\n"
""
                        "	border-bottom-color: qlineargradient(spread:pad, x1:0.523, y1:0.294455, x2:0.528, y2:1, stop:0 rgba(191, 191, 191, 255), stop:0.982955 rgba(143, 192, 255, 0));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.682091, y1:0.544, x2:0, y2:0.557, stop:0 rgba(191, 191, 191, 255), stop:0.982955 rgba(143, 192, 255, 0));\n"
"} "));
        comb_usrName->setEditable(true);
        lineEdit_pwd = new QLineEdit(fameBack);
        lineEdit_pwd->setObjectName(QStringLiteral("lineEdit_pwd"));
        lineEdit_pwd->setGeometry(QRect(88, 205, 263, 30));
        lineEdit_pwd->setStyleSheet(QLatin1String("QLineEdit#lineEdit_pwd::hover{\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.534, y1:1, x2:0.545, y2:0, stop:0 rgba(36, 132, 238, 255), stop:0.982955 rgba(143, 192, 255, 0));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:0.506, x2:1, y2:0.511364, stop:0 rgba(36, 132, 238, 255), stop:0.982955 rgba(143, 192, 255, 0));\n"
"	border-bottom-color: qlineargradient(spread:pad, x1:0.517, y1:0, x2:0.5, y2:1, stop:0 rgba(36, 132, 238, 255), stop:0.982955 rgba(143, 192, 255, 0));\n"
"	border-left-color: qlineargradient(spread:pad, x1:1, y1:0.579545, x2:0, y2:0.574, stop:0 rgba(36, 132, 238, 255), stop:0.982955 rgba(143, 192, 255, 0));\n"
"}  \n"
"\n"
"QLineEdit#lineEdit_pwd{\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.471273, y1:0.71, x2:0.483, y2:0, stop:0 rgba(191, 191, 191, 255), stop:0.982955 rgba(143, 192, 255, 0));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0.301, y1:0.510682, x2:1, y2:0.522, stop:0 rgba(191, 191, 191, 255), stop:0.982955 rgba(143, 192, 255, 0));\n"
""
                        "	border-bottom-color: qlineargradient(spread:pad, x1:0.523, y1:0.294455, x2:0.528, y2:1, stop:0 rgba(191, 191, 191, 255), stop:0.982955 rgba(143, 192, 255, 0));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.682091, y1:0.544, x2:0, y2:0.557, stop:0 rgba(191, 191, 191, 255), stop:0.982955 rgba(143, 192, 255, 0));\n"
"	padding-left:3px;\n"
"	padding-right: 25px;\n"
"	font: 9pt \"Meiryo\";\n"
"}  \n"
""));
        lineEdit_pwd->setEchoMode(QLineEdit::Password);
        btn_login = new QPushButton(fameBack);
        btn_login->setObjectName(QStringLiteral("btn_login"));
        btn_login->setGeometry(QRect(88, 273, 263, 36));
        btn_login->setStyleSheet(QLatin1String("QPushButton#btn_login:hover{\n"
"border-image: url(:/Login/Resources/login/button_login_hover.png);\n"
"}\n"
"\n"
"QPushButton#btn_login:pressed{\n"
"border-image: url(:/Login/Resources/login/button_login_down.png);\n"
"}\n"
"\n"
"QPushButton#btn_login{\n"
"border-image: url(:/Login/Resources/login/button_login_normal.png);\n"
"}\n"
""));
        btn_login->setIconSize(QSize(263, 36));
        btn_login->setFlat(true);
        btn_min = new QPushButton(fameBack);
        btn_min->setObjectName(QStringLiteral("btn_min"));
        btn_min->setGeometry(QRect(388, 0, 30, 30));
        btn_min->setStyleSheet(QLatin1String("QPushButton#btn_min:hover{\n"
"border-image: url(:/Login/Resources/login/min_hover.png);\n"
"}\n"
"\n"
"QPushButton#btn_min:pressed{\n"
"border-image: url(:/Login/Resources/login/min_close.png);\n"
"}\n"
"\n"
"QPushButton#btn_min{\n"
"border-image: url(:/Login/Resources/login/min_normal.png);\n"
"}\n"
""));
        btn_min->setIconSize(QSize(39, 20));
        btn_min->setFlat(true);
        btn_close = new QPushButton(fameBack);
        btn_close->setObjectName(QStringLiteral("btn_close"));
        btn_close->setGeometry(QRect(418, 0, 30, 30));
        btn_close->setStyleSheet(QLatin1String("QPushButton#btn_close:hover{\n"
"border-image: url(:/Login/Resources/login/close_hover.png);\n"
"}\n"
"\n"
"QPushButton#btn_close:pressed{\n"
"border-image: url(:/Login/Resources/login/close_click.png);\n"
"}\n"
"\n"
"QPushButton#btn_close{\n"
"border-image: url(:/Login/Resources/login/close_normal.png);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/login/btn_close_normal.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_close->setIcon(icon1);
        btn_close->setIconSize(QSize(39, 20));
        btn_close->setFlat(true);
        checkbox_remeberPassword = new QCheckBox(fameBack);
        checkbox_remeberPassword->setObjectName(QStringLiteral("checkbox_remeberPassword"));
        checkbox_remeberPassword->setGeometry(QRect(88, 249, 71, 16));
        checkbox_remeberPassword->setAutoFillBackground(false);
        checkbox_remeberPassword->setStyleSheet(QLatin1String("QCheckBox#checkbox_remeberPassword::indicator{\n"
"width:15px;\n"
"height:15px;\n"
"border-image: url(:/Login/Resources/login/checkbox_normal.png);\n"
"}\n"
"\n"
"\n"
"QCheckBox#checkbox_remeberPassword::indicator:hover:unchecked{\n"
"border-image: url(:/Login/Resources/login/checkbox_hover.png)\n"
"}\n"
"\n"
"QCheckBox#checkbox_remeberPassword::indicator:checked{\n"
"	border-image: url(:/Login/Resources/login/checkbox_checked.png);\n"
"}\n"
"QCheckBox#checkbox_remeberPassword::indicator:hover:checked{\n"
"	border-image: url(:/Login/Resources/login/checkbox_hold.png);\n"
"}\n"
"\n"
"QCheckBox#checkbox_remeberPassword { color: white }\n"
""));
        checkbox_autoLogin = new QCheckBox(fameBack);
        checkbox_autoLogin->setObjectName(QStringLiteral("checkbox_autoLogin"));
        checkbox_autoLogin->setGeometry(QRect(284, 249, 71, 16));
        checkbox_autoLogin->setStyleSheet(QLatin1String("QCheckBox#checkbox_autoLogin::indicator{\n"
"width:15px;\n"
"height:15px;\n"
"border-image: url(:/Login/Resources/login/checkbox_normal.png);\n"
"}\n"
"\n"
"QCheckBox#checkbox_autoLogin::indicator:hover:unchecked{\n"
"border-image: url(:/Login/Resources/login/checkbox_hover.png)\n"
"}\n"
"\n"
"QCheckBox#checkbox_autoLogin::indicator:checked{\n"
"	border-image: url(:/Login/Resources/login/checkbox_checked.png);\n"
"}\n"
"QCheckBox#checkbox_autoLogin::indicator:hover:checked{\n"
"	border-image: url(:/Login/Resources/login/checkbox_hold.png);\n"
"}\n"
"\n"
"QCheckBox#checkbox_autoLogin { color: white }"));
        btn_register = new QPushButton(fameBack);
        btn_register->setObjectName(QStringLiteral("btn_register"));
        btn_register->setGeometry(QRect(360, 167, 51, 16));
        btn_register->setStyleSheet(QLatin1String("QPushButton#btn_register:hover{\n"
"border-image: url(:/Login/Resources/login/register_hover.png);\n"
"}\n"
"\n"
"QPushButton#btn_register:pressed{\n"
"border-image: url(:/Login/Resources/login/register_press.png);\n"
"}\n"
"\n"
"QPushButton#btn_register{\n"
"border-image: url(:/Login/Resources/login/register_pressnormal.png);\n"
"}"));
        btn_register->setIconSize(QSize(51, 16));
        btn_findPassword = new QPushButton(fameBack);
        btn_findPassword->setObjectName(QStringLiteral("btn_findPassword"));
        btn_findPassword->setGeometry(QRect(360, 212, 51, 16));
        btn_findPassword->setStyleSheet(QLatin1String("QPushButton#btn_findPassword:hover{\n"
"border-image: url(:/Login/Resources/login/findpassword_hover.png);\n"
"}\n"
"\n"
"QPushButton#btn_findPassword:pressed{\n"
"border-image: url(:/Login/Resources/login/findpassword_press.png);\n"
"}\n"
"\n"
"QPushButton#btn_findPassword{\n"
"border-image: url(:/Login/Resources/login/findpassword_normal.png);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        btn_findPassword->setIconSize(QSize(51, 16));
        btn_setting = new QPushButton(fameBack);
        btn_setting->setObjectName(QStringLiteral("btn_setting"));
        btn_setting->setGeometry(QRect(360, 283, 31, 34));
        btn_setting->setStyleSheet(QLatin1String("QPushButton#btn_setting:hover{\n"
"border-image: url(:/Login/Resources/login/btn_set_hover.png);\n"
"}\n"
"\n"
"QPushButton#btn_setting:pressed{\n"
"border-image: url(:/Login/Resources/login/btn_set_press.png);\n"
"}\n"
"\n"
"QPushButton#btn_setting{\n"
"border-image: url(:/Login/Resources/login/btn_set_hover.png);\n"
"}"));
        btn_setting->setIconSize(QSize(31, 34));

        verticalLayout->addWidget(fameBack);


        retranslateUi(LoginUI);

        QMetaObject::connectSlotsByName(LoginUI);
    } // setupUi

    void retranslateUi(QWidget *LoginUI)
    {
        LoginUI->setWindowTitle(QApplication::translate("LoginUI", "\347\231\273\345\275\225", 0));
        lineEdit_pwd->setInputMask(QString());
        lineEdit_pwd->setText(QString());
        lineEdit_pwd->setPlaceholderText(QApplication::translate("LoginUI", "\345\257\206\347\240\201", 0));
        btn_login->setText(QString());
        btn_min->setText(QString());
        btn_close->setText(QString());
        checkbox_remeberPassword->setText(QApplication::translate("LoginUI", "\350\256\260\344\275\217\345\257\206\347\240\201", 0));
        checkbox_autoLogin->setText(QApplication::translate("LoginUI", "\350\207\252\345\212\250\347\231\273\345\275\225", 0));
        btn_register->setText(QString());
        btn_findPassword->setText(QString());
        btn_setting->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginUI: public Ui_LoginUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINUI_H
