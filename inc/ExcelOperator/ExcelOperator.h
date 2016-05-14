#ifndef EXCELOPERATOR_H
#define EXCELOPERATOR_H

#include "exceloperator_global.h"

#include <QAxObject>
#include <QString>
#include <QColor>
#include <QTextStream>
#include <QList>
#include <QVector>
#include <QIODevice>
#include <QFile>

enum Alignment {
	AlignLeft = -4131,
	AlignRight = -4152,
	AlignCenter = -4108,
	AlignTop = -4160,
	AlignBottom = -4107
};


/**
* @brief The ExcelOperator class
*
* @row: 从1开始编号
* @column: 从1开始编号
* @sheet index: 从1开始编号
*/
class EXCELOPERATOR_EXPORT ExcelOperator
{
public:
	explicit ExcelOperator();
	virtual ~ExcelOperator();

	/**
	* 高效率处理大数据量文本导出, 避开COM,直接采用文件流输出
	* 注意: 经测试，不能和COM方法组合使用，即只有一种处理方法会生效
	* 应用场景：该方法只用于导出全文本内容到Excel的场景(即不支持图片)
	*/
	static bool streamTextToExcel(const QList<QVector<QString>> &text, const QString &excelFile)
	{
		QFile file(excelFile);
		if (!file.isOpen() && !file.open(QIODevice::ReadWrite))
			return false;
		QTextStream out(&file);
		QString lineSplit("\r\n");
		QString cellSplit("\t");
		for (auto lineText : text){
			for (auto cellText : lineText) {
				out << cellText;
				out << cellSplit;
			}
			out << lineSplit;
		}
		out.flush();
		file.close();
		return true;
	}

	/* 打开一个Excel工作簿, 若不存在默认先创建再打开 */
	bool open(const QString &fileName);

	/* 保存对当前活动Excel工作簿的修改操作 */
	void save();

	/* 将当前活动工作簿另存为一个新的工作簿 */
	void saveAs(const QString &newFileName);

	/* 关闭当前的活动Excel工作簿 */
	void close();



	/* 获取当前活动工作簿的标题 */
	QString getActiveWorkbookName();

	/* 设置当前活动工作簿的标题 */
	void setActiveWorkbookName(const QString &title);



	/* 获取当前活动工作簿中sheet的数目 */
	int getSheetCount();

	/* 在当前活动工作簿中追加一个新sheet */
	void appendSheet();

	/* 在当前活动工作簿中指定sheet之后插入一个新sheet */
	void insertSheet(int sheetIndex);

	/* 在当前活动工作簿中删除指定的sheet */
	void deleteSheet(int sheetIndex);



	/* 获得当前活动工作簿中某个sheet的名字 */
	QString getSheetName(int sheetIndex);

	/* 设置当前活动工作簿中某个sheet的名字 */
	void setSheetName(int sheetIndex, const QString &sheetName);

	/* 获得当前活动工作簿中某个sheet起始行 */
	int getStartRow(int sheetIndex);

	/* 获得当前活动工作簿中某个sheet起始列 */
	int getStartColumn(int sheetIndex);

	/* 获得当前活动工作簿中某个sheet的总行数 */
	int getRowCount(int sheetIndex);

	/* 获得当前活动工作簿中某个sheet的总列数 */
	int getColumnCount(int sheetIndex);



	/* 获取单元格的值 */
	QVariant getCellValue(int sheetIndex, int row, int column);

	/* 设置单元格为图片 */
	void setCellPixture(int sheetIndex, int row, int column, int width, int height, const QString &picDir);

	/* 设置单元格的值 */
	void setCellValue(int sheetIndex, int row, int column, QVariant value);

	/* 合并/拆分 单元格, merge=true合并,merge=false拆分 */
	void mergeCell(int sheetIndex, int startRow, int startColumn, int endRow, int endColumn, bool merge = true);

	/* 清除单元格内容 */
	void clearCellContent(int sheetIndex, int row, int column);



	/* 设置sheet某一列的列宽 */
	void setCellWidth(int sheetIndex, int row, int column, int value);

	/* 设置sheet某一行的行高 */
	void setCellHeight(int sheetIndex, int row, int column, int value);

	/* 设置sheet中内容的对齐策略 */
	void setCellAlighment(int sheetIndex, int row, int column, Alignment align);



	/* 设置单元格背景色 */
	void setCellBackgroundColor(int sheetIndex, int row, int column, const QColor &color);

	/* 设置单元格边框色 */
	void setCellBorderColor(int sheetIndex, int row, int column, const QColor &color);

	/* 设置单元格字体 */
	void setCellFont(int sheetIndex, int row, int column, const QString &fontType, int size = 20, const QColor &color = QColor(255, 0, 0), bool isBold = false, bool isItalic = false);

private:
	/* 判断当前活动工作簿中是否存在该sheet */
	bool isSheetValid(int sheetIndex);

	/* 判断方格行列是否有效 */
	bool isCellValid(int row, int column);

private:
	QAxObject * m_Excel;            //当前Excel
	QAxObject * m_Workbooks;        //工作簿集合
	QAxObject * m_ActiveWorkbook;   //当前活动工作簿

};

#endif // EXCELOPERATOR_H
