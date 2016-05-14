#pragma execution_character_set("utf-8")
#include "IconHelper\IconHelper.h"

IconHelper* IconHelper::_instance = 0;
IconHelper::IconHelper(QObject *) : QObject(qApp)
{
	int fontId = QFontDatabase::addApplicationFont(":/IconHelper/Resources/fontawesome-webfont.ttf");
	QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
	iconFont = QFont(fontName);
}

void IconHelper::SetIcon(QLabel* lab, QChar c, int size)
{
	iconFont.setPointSize(size);
	lab->setFont(iconFont);
	lab->setText(c);
}

void IconHelper::SetIcon(QPushButton* btn, QChar c, int size)
{
	iconFont.setPointSize(size);
	btn->setFont(iconFont);
	btn->setText(c);
}