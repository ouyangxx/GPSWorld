/********************************************************************************
** Form generated from reading UI file 'LeftNaviMap.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEFTNAVIMAP_H
#define UI_LEFTNAVIMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LeftNaviMap
{
public:
    QLabel *label;

    void setupUi(QWidget *LeftNaviMap)
    {
        if (LeftNaviMap->objectName().isEmpty())
            LeftNaviMap->setObjectName(QStringLiteral("LeftNaviMap"));
        LeftNaviMap->resize(294, 568);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LeftNaviMap->sizePolicy().hasHeightForWidth());
        LeftNaviMap->setSizePolicy(sizePolicy);
        label = new QLabel(LeftNaviMap);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 160, 151, 61));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        retranslateUi(LeftNaviMap);

        QMetaObject::connectSlotsByName(LeftNaviMap);
    } // setupUi

    void retranslateUi(QWidget *LeftNaviMap)
    {
        LeftNaviMap->setWindowTitle(QApplication::translate("LeftNaviMap", "LeftNaviMap", 0));
        label->setText(QApplication::translate("LeftNaviMap", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#909090;\">LeftNaviMap</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class LeftNaviMap: public Ui_LeftNaviMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFTNAVIMAP_H
