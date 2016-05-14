/********************************************************************************
** Form generated from reading UI file 'LeftNaviFactory.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEFTNAVIFACTORY_H
#define UI_LEFTNAVIFACTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LeftNaviFactory
{
public:
    QLabel *label;

    void setupUi(QWidget *LeftNaviFactory)
    {
        if (LeftNaviFactory->objectName().isEmpty())
            LeftNaviFactory->setObjectName(QStringLiteral("LeftNaviFactory"));
        LeftNaviFactory->resize(294, 568);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LeftNaviFactory->sizePolicy().hasHeightForWidth());
        LeftNaviFactory->setSizePolicy(sizePolicy);
        label = new QLabel(LeftNaviFactory);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 170, 131, 41));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);

        retranslateUi(LeftNaviFactory);

        QMetaObject::connectSlotsByName(LeftNaviFactory);
    } // setupUi

    void retranslateUi(QWidget *LeftNaviFactory)
    {
        LeftNaviFactory->setWindowTitle(QApplication::translate("LeftNaviFactory", "LeftNaviFactory", 0));
        label->setText(QApplication::translate("LeftNaviFactory", "LeftNaviFactory", 0));
    } // retranslateUi

};

namespace Ui {
    class LeftNaviFactory: public Ui_LeftNaviFactory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFTNAVIFACTORY_H
