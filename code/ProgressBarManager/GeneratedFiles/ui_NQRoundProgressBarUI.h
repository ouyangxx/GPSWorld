/********************************************************************************
** Form generated from reading UI file 'NQRoundProgressBarUI.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NQROUNDPROGRESSBARUI_H
#define UI_NQROUNDPROGRESSBARUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NQRoundProgressBarUI
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *m_PixLabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *m_TipLabel;

    void setupUi(QWidget *NQRoundProgressBarUI)
    {
        if (NQRoundProgressBarUI->objectName().isEmpty())
            NQRoundProgressBarUI->setObjectName(QStringLiteral("NQRoundProgressBarUI"));
        NQRoundProgressBarUI->setWindowModality(Qt::ApplicationModal);
        NQRoundProgressBarUI->resize(120, 120);
        NQRoundProgressBarUI->setMinimumSize(QSize(120, 120));
        NQRoundProgressBarUI->setMaximumSize(QSize(120, 120));
        NQRoundProgressBarUI->setMouseTracking(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/EBIM.ico"), QSize(), QIcon::Normal, QIcon::Off);
        NQRoundProgressBarUI->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(NQRoundProgressBarUI);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_PixLabel = new QLabel(NQRoundProgressBarUI);
        m_PixLabel->setObjectName(QStringLiteral("m_PixLabel"));
        m_PixLabel->setMinimumSize(QSize(80, 80));
        m_PixLabel->setMaximumSize(QSize(80, 80));
        m_PixLabel->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(m_PixLabel);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        m_TipLabel = new QLabel(NQRoundProgressBarUI);
        m_TipLabel->setObjectName(QStringLiteral("m_TipLabel"));
        m_TipLabel->setMaximumSize(QSize(110, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        m_TipLabel->setFont(font);
        m_TipLabel->setScaledContents(true);
        m_TipLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(m_TipLabel);


        retranslateUi(NQRoundProgressBarUI);

        QMetaObject::connectSlotsByName(NQRoundProgressBarUI);
    } // setupUi

    void retranslateUi(QWidget *NQRoundProgressBarUI)
    {
        NQRoundProgressBarUI->setWindowTitle(QApplication::translate("NQRoundProgressBarUI", "\350\277\233\345\272\246", 0));
        m_PixLabel->setText(QApplication::translate("NQRoundProgressBarUI", "TextLabel", 0));
        m_TipLabel->setText(QApplication::translate("NQRoundProgressBarUI", "\346\255\243\345\234\250\345\212\240\350\275\275", 0));
    } // retranslateUi

};

namespace Ui {
    class NQRoundProgressBarUI: public Ui_NQRoundProgressBarUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NQROUNDPROGRESSBARUI_H
