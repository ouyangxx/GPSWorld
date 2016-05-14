#pragma execution_character_set("utf-8")
#include "ExcelOperator\ExcelOperator.h"

ExcelOperator::ExcelOperator()
{
	m_Excel = NULL;
	m_Workbooks = NULL;
	m_ActiveWorkbook = NULL;
}

ExcelOperator::~ExcelOperator()
{
	close();
}

bool ExcelOperator::isSheetValid(int sheetIndex)
{
	bool valid(false);
	if (sheetIndex > 0 && sheetIndex <= getSheetCount())
		valid = true;
	return valid;
}

bool ExcelOperator::isCellValid(int row, int column)
{
	bool valid(false);
	if (row > 0 && column > 0)
		valid = true;
	return valid;
}



bool ExcelOperator::open(const QString &fileName)
{
	close();

	m_Excel = new QAxObject("Excel.Application");   //连接Excel控件
	if (m_Excel->isNull()) return false;            //没有找到EXCEL应用程序
	m_Excel->setProperty("Visible", false);         //不显示当前窗口
	m_Excel->setProperty("DisplayAlerts", false);   //不显示任何警告信息

	m_Workbooks = m_Excel->querySubObject("WorkBooks"); //获取工作簿集合
	if (!QFile::exists(fileName)) {        //如果fileName不存在
		m_Workbooks->dynamicCall("Add");   //新建一个工作簿
		m_ActiveWorkbook = m_Excel->querySubObject("ActiveWorkBook");    //获取当前活动工作簿
		saveAs(fileName);
		close();
		return open(fileName);
	}
	m_Workbooks->dynamicCall("Open (const QString&)", fileName);         //打开已存在的工作簿
	m_ActiveWorkbook = m_Excel->querySubObject("ActiveWorkBook");        //获取当前活动工作簿
	if (!m_ActiveWorkbook)	return false;
	return true;
}

void ExcelOperator::save()
{
	if (m_ActiveWorkbook) {
		m_ActiveWorkbook->dynamicCall("Save()"); //保存文件
	}
}

void ExcelOperator::saveAs(const QString &newFileName)
{
	if (m_ActiveWorkbook) {
		m_ActiveWorkbook->dynamicCall("SaveAs(const QString&)", newFileName);
	}
}

void ExcelOperator::close()
{
	if (m_ActiveWorkbook)
		m_ActiveWorkbook->dynamicCall("Close(Boolean)", false); //关闭文件
	if (m_Excel)
		m_Excel->dynamicCall("Quit(void)");  //退出
	if (m_ActiveWorkbook) { delete m_ActiveWorkbook;  m_ActiveWorkbook = NULL; }
	if (m_Workbooks){ delete m_Workbooks;  m_Workbooks = NULL; }
	if (m_Excel) { delete m_Excel; m_Excel = NULL; }
}



QString ExcelOperator::getActiveWorkbookName()
{
	QString title;
	if (m_Excel)
		title = m_Excel->property("Caption").toString();
	return title;
}

void ExcelOperator::setActiveWorkbookName(const QString &title)
{
	if (m_Excel)
		m_Excel->setProperty("Caption", title);
}



int ExcelOperator::getSheetCount()
{
	int count = 0;
	if (m_ActiveWorkbook) {
		QAxObject *sheets = m_ActiveWorkbook->querySubObject("WorkSheets");
		count = sheets->property("Count").toInt();
	}
	return count;
}

void ExcelOperator::appendSheet()
{
	if (m_ActiveWorkbook) {
		QAxObject *sheets = m_ActiveWorkbook->querySubObject("WorkSheets");
		QAxObject *lastSheet = sheets->querySubObject("Item(int)", getSheetCount());
		QAxObject *newSheet = sheets->querySubObject("Add(QVariant)", lastSheet->asVariant());
		lastSheet->dynamicCall("Move(QVariant)", newSheet->asVariant());
		QString title = "Sheet" + QString::number(getSheetCount());
		setSheetName(getSheetCount(), title);
	}
}

void ExcelOperator::insertSheet(int sheetIndex)
{
	if (m_ActiveWorkbook && isSheetValid(sheetIndex)) {
		QAxObject *sheets = m_ActiveWorkbook->querySubObject("WorkSheets");
		QAxObject *posSheet = sheets->querySubObject("Item(int)", sheetIndex);
		QAxObject *newSheet = sheets->querySubObject("Add(QVariant)", posSheet->asVariant());
		posSheet->dynamicCall("Move(QVariant)", newSheet->asVariant());
		QString title = "Sheet" + QString::number(getSheetCount());
		setSheetName(sheetIndex + 1, title);
	}
}

void ExcelOperator::deleteSheet(int sheetIndex)
{
	if (m_ActiveWorkbook && isSheetValid(sheetIndex)) {
		QAxObject *delSheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		delSheet->dynamicCall("delete");
	}
}



QString ExcelOperator::getSheetName(int sheetIndex)
{
	QString sheetName;
	if (m_ActiveWorkbook && isSheetValid(sheetIndex)) {
		QAxObject *sheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		sheetName = sheet->property("Name").toString();  //获取工作表名称
	}
	return sheetName;
}

/**
* 修改规则: 如sheetName="Sheet1",
*     (1) 若Sheet1已存在，则尝试修改为"Sheet (2)";
*     (2) 若"Sheet (2)"已存在，则尝试修改为"Sheet (3)";
*     (3) 依此类推, 直到sheetName在当前工作簿中是唯一的，则正确修改;
*/
void ExcelOperator::setSheetName(int sheetIndex, const QString &sheetName)
{
	static int copyNumber = 1;
	static QString copyName(sheetName);

	if (m_ActiveWorkbook && isSheetValid(sheetIndex)) {
		int sheetCount = getSheetCount();
		for (int index = 1; index != sheetIndex && index <= sheetCount; ++index) {
			QString name = getSheetName(index);
			if (name == sheetName)  {
				++copyNumber;
				QString currentName(copyName);
				currentName += QString(" (");
				currentName += QString::number(copyNumber);
				currentName += QString(")");
				setSheetName(sheetIndex, currentName);
				return;
			}
		}
		QAxObject *sheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		sheet->setProperty("Name", sheetName);  //设置工作表名称
		copyNumber = 1;
	}
}

int ExcelOperator::getStartRow(int sheetIndex)
{
	int startRow = 0;
	if (m_ActiveWorkbook && isSheetValid(sheetIndex)) {
		QAxObject *sheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		QAxObject *usedRange = sheet->querySubObject("UsedRange");
		startRow = usedRange->property("Row").toInt();  //获取起始行
	}
	return startRow;
}

int ExcelOperator::getStartColumn(int sheetIndex)
{
	int startColumn = 0;
	if (m_ActiveWorkbook && isSheetValid(sheetIndex)) {
		QAxObject *sheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		QAxObject *usedRange = sheet->querySubObject("UsedRange");
		startColumn = usedRange->property("Column").toInt();  //获取起始列
	}
	return startColumn;
}

int ExcelOperator::getRowCount(int sheetIndex)
{
	int rowCount = 0;
	if (m_ActiveWorkbook && isSheetValid(sheetIndex)) {
		QAxObject *sheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		QAxObject *usedRange = sheet->querySubObject("UsedRange");
		QAxObject *rows = usedRange->querySubObject("Rows");
		rowCount = rows->property("Count").toInt();  //获取行数
	}
	return rowCount;
}

int ExcelOperator::getColumnCount(int sheetIndex)
{
	int columnCount = 0;
	if (m_ActiveWorkbook && isSheetValid(sheetIndex)) {
		QAxObject *sheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		QAxObject *usedRange = sheet->querySubObject("UsedRange");
		QAxObject *columns = usedRange->querySubObject("Columns");
		columnCount = columns->property("Count").toInt();  //获取列数
	}
	return columnCount;
}



QVariant ExcelOperator::getCellValue(int sheetIndex, int row, int column)
{
	QVariant value;
	if (m_ActiveWorkbook && isSheetValid(sheetIndex) && isCellValid(row, column)) {
		QAxObject *sheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		QAxObject *cell = sheet->querySubObject("Cells(int,int)", row, column);
		value = cell->dynamicCall("Value2()");  //获取单元格内容
	}
	return value;
}

void ExcelOperator::setCellPixture(int sheetIndex, int row, int column, int width, int height, const QString &picDir)
{
	if (m_ActiveWorkbook && isSheetValid(sheetIndex) && isCellValid(row, column) && isCellValid(width, height)) {
		QAxObject *sheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		QAxObject *cell = sheet->querySubObject("Cells(int,int)", row, column);
		cell->setProperty("ColumnWidth", width / 6.3);
		cell->setProperty("RowHeight", height);
		int left = cell->property("Left").toInt();
		int top = cell->property("Top").toInt();

		QAxObject *shapes = sheet->querySubObject("Shapes");
		shapes->dynamicCall("AddPicture( QString&, bool, bool, double, double, double, double", picDir, true, true, left, top, width, height);
	}
}

void ExcelOperator::setCellValue(int sheetIndex, int row, int column, QVariant value)
{
	if (m_ActiveWorkbook && isSheetValid(sheetIndex) && isCellValid(row, column)) {
		QAxObject *sheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		QAxObject *cell = sheet->querySubObject("Cells(int,int)", row, column);
		cell->dynamicCall("SetValue(const QVariant&)", value); //设置单元格的值
	}
}

void ExcelOperator::mergeCell(int sheetIndex, int startRow, int startColumn, int endRow, int endColumn, bool merge)
{
	if (m_ActiveWorkbook && isSheetValid(sheetIndex) && isCellValid(startRow, startColumn) && isCellValid(endRow, endColumn)) {
		QAxObject *sheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		QString mergeCell;
		mergeCell.append(QChar(startColumn - 1 + 'A'));  //初始列
		mergeCell.append(QString::number(startRow));     //初始行
		mergeCell.append(":");
		mergeCell.append(QChar(endColumn - 1 + 'A'));    //终止列
		mergeCell.append(QString::number(endRow));       //终止行
		QAxObject *mergeRange = sheet->querySubObject("Range(const QString&)", mergeCell);
		mergeRange->setProperty("HorizontalAlignment", -4108);
		mergeRange->setProperty("VerticalAlignment", -4108);
		mergeRange->setProperty("WrapText", true);
		mergeRange->setProperty("MergeCells", merge);  //true合并,false拆分
	}
}

void ExcelOperator::clearCellContent(int sheetIndex, int row, int column)
{
	if (m_ActiveWorkbook && isSheetValid(sheetIndex) && isCellValid(row, column)) {
		QAxObject *sheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		QAxObject *cell = sheet->querySubObject("Cells(int,int)", row, column);
		cell->dynamicCall("ClearContents()");  //清空单元格内容
	}
}

void ExcelOperator::setCellWidth(int sheetIndex, int row, int column, int value)
{
	if (m_ActiveWorkbook && isSheetValid(sheetIndex) && isCellValid(row, column)) {
		QAxObject *sheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		QAxObject *cell = sheet->querySubObject("Cells(int,int)", row, column);
		cell->setProperty("ColumnWidth", value / 6.3);  //设置单元格列宽
	}
}

void ExcelOperator::setCellHeight(int sheetIndex, int row, int column, int value)
{
	if (m_ActiveWorkbook && isSheetValid(sheetIndex) && isCellValid(row, column)) {
		QAxObject *sheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		QAxObject *cell = sheet->querySubObject("Cells(int,int)", row, column);
		cell->setProperty("RowHeight", value);  //设置单元格行高
	}
}

void ExcelOperator::setCellAlighment(int sheetIndex, int row, int column, Alignment align)
{
	if (m_ActiveWorkbook && isSheetValid(sheetIndex) && isCellValid(row, column)) {
		QAxObject *sheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		QAxObject *cell = sheet->querySubObject("Cells(int,int)", row, column);
		cell->setProperty("HorizontalAlignment", align);
		cell->setProperty("VerticalAlignment", align);
		cell->setProperty("WrapText", true);  //内容过多，自动换行
	}
}

void ExcelOperator::setCellBackgroundColor(int sheetIndex, int row, int column, const QColor &color)
{
	if (m_ActiveWorkbook && isSheetValid(sheetIndex) && isCellValid(row, column)) {
		QAxObject *sheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		QAxObject *cell = sheet->querySubObject("Cells(int,int)", row, column);
		QAxObject* interior = cell->querySubObject("Interior");
		interior->setProperty("Color", color);
	}
}

void ExcelOperator::setCellBorderColor(int sheetIndex, int row, int column, const QColor &color)
{
	if (m_ActiveWorkbook && isSheetValid(sheetIndex) && isCellValid(row, column)) {
		QAxObject *sheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		QAxObject *cell = sheet->querySubObject("Cells(int,int)", row, column);
		QAxObject* border = cell->querySubObject("Borders");
		border->setProperty("Color", color);
	}
}

void ExcelOperator::setCellFont(int sheetIndex, int row, int column, const QString &fontType, int size, const QColor &color, bool isBold, bool isItalic)
{
	if (m_ActiveWorkbook && isSheetValid(sheetIndex) && isCellValid(row, column)) {
		QAxObject *sheet = m_ActiveWorkbook->querySubObject("WorkSheets(int)", sheetIndex);
		QAxObject *cell = sheet->querySubObject("Cells(int,int)", row, column);
		QAxObject *font = cell->querySubObject("Font");  //获取单元格字体
		font->setProperty("Name", fontType);     //设置单元格字体
		font->setProperty("Size", size);         //设置单元格字体大小
		font->setProperty("Color", color);       //设置单元格字体颜色
		font->setProperty("Bold", isBold);       //设置单元格字体是否加粗
		font->setProperty("Italic", isItalic);   //设置单元格字体是否斜体
	}
}