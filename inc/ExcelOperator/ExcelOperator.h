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
* @row: ��1��ʼ���
* @column: ��1��ʼ���
* @sheet index: ��1��ʼ���
*/
class EXCELOPERATOR_EXPORT ExcelOperator
{
public:
	explicit ExcelOperator();
	virtual ~ExcelOperator();

	/**
	* ��Ч�ʴ�����������ı�����, �ܿ�COM,ֱ�Ӳ����ļ������
	* ע��: �����ԣ����ܺ�COM�������ʹ�ã���ֻ��һ�ִ���������Ч
	* Ӧ�ó������÷���ֻ���ڵ���ȫ�ı����ݵ�Excel�ĳ���(����֧��ͼƬ)
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

	/* ��һ��Excel������, ��������Ĭ���ȴ����ٴ� */
	bool open(const QString &fileName);

	/* ����Ե�ǰ�Excel���������޸Ĳ��� */
	void save();

	/* ����ǰ����������Ϊһ���µĹ����� */
	void saveAs(const QString &newFileName);

	/* �رյ�ǰ�ĻExcel������ */
	void close();



	/* ��ȡ��ǰ��������ı��� */
	QString getActiveWorkbookName();

	/* ���õ�ǰ��������ı��� */
	void setActiveWorkbookName(const QString &title);



	/* ��ȡ��ǰ���������sheet����Ŀ */
	int getSheetCount();

	/* �ڵ�ǰ���������׷��һ����sheet */
	void appendSheet();

	/* �ڵ�ǰ���������ָ��sheet֮�����һ����sheet */
	void insertSheet(int sheetIndex);

	/* �ڵ�ǰ���������ɾ��ָ����sheet */
	void deleteSheet(int sheetIndex);



	/* ��õ�ǰ���������ĳ��sheet������ */
	QString getSheetName(int sheetIndex);

	/* ���õ�ǰ���������ĳ��sheet������ */
	void setSheetName(int sheetIndex, const QString &sheetName);

	/* ��õ�ǰ���������ĳ��sheet��ʼ�� */
	int getStartRow(int sheetIndex);

	/* ��õ�ǰ���������ĳ��sheet��ʼ�� */
	int getStartColumn(int sheetIndex);

	/* ��õ�ǰ���������ĳ��sheet�������� */
	int getRowCount(int sheetIndex);

	/* ��õ�ǰ���������ĳ��sheet�������� */
	int getColumnCount(int sheetIndex);



	/* ��ȡ��Ԫ���ֵ */
	QVariant getCellValue(int sheetIndex, int row, int column);

	/* ���õ�Ԫ��ΪͼƬ */
	void setCellPixture(int sheetIndex, int row, int column, int width, int height, const QString &picDir);

	/* ���õ�Ԫ���ֵ */
	void setCellValue(int sheetIndex, int row, int column, QVariant value);

	/* �ϲ�/��� ��Ԫ��, merge=true�ϲ�,merge=false��� */
	void mergeCell(int sheetIndex, int startRow, int startColumn, int endRow, int endColumn, bool merge = true);

	/* �����Ԫ������ */
	void clearCellContent(int sheetIndex, int row, int column);



	/* ����sheetĳһ�е��п� */
	void setCellWidth(int sheetIndex, int row, int column, int value);

	/* ����sheetĳһ�е��и� */
	void setCellHeight(int sheetIndex, int row, int column, int value);

	/* ����sheet�����ݵĶ������ */
	void setCellAlighment(int sheetIndex, int row, int column, Alignment align);



	/* ���õ�Ԫ�񱳾�ɫ */
	void setCellBackgroundColor(int sheetIndex, int row, int column, const QColor &color);

	/* ���õ�Ԫ��߿�ɫ */
	void setCellBorderColor(int sheetIndex, int row, int column, const QColor &color);

	/* ���õ�Ԫ������ */
	void setCellFont(int sheetIndex, int row, int column, const QString &fontType, int size = 20, const QColor &color = QColor(255, 0, 0), bool isBold = false, bool isItalic = false);

private:
	/* �жϵ�ǰ����������Ƿ���ڸ�sheet */
	bool isSheetValid(int sheetIndex);

	/* �жϷ��������Ƿ���Ч */
	bool isCellValid(int row, int column);

private:
	QAxObject * m_Excel;            //��ǰExcel
	QAxObject * m_Workbooks;        //����������
	QAxObject * m_ActiveWorkbook;   //��ǰ�������

};

#endif // EXCELOPERATOR_H
