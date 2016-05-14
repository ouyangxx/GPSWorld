#ifndef HVEHICLEREPORT_H
#define HVEHICLEREPORT_H

#include <QtCore/qglobal.h>
#include <QtCore>
#include <QSqlQuery>

#if defined(HVEHICLEREPORT_LIBRARY)
#  define HVEHICLEREPORTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define HVEHICLEREPORTSHARED_EXPORT Q_DECL_IMPORT
#endif

class HVEHICLEREPORTSHARED_EXPORT HVehicleReport : public QObject
{
    Q_OBJECT

public:
    explicit HVehicleReport();
    virtual ~HVehicleReport();

    //for example deviceIDs, 700123,700124,700125
    //返回值表示规则是否有误
    bool parseRunLogs(const QString& deviceIDs, QDateTime startTime,
                           QDateTime endTime, quint16 runDuration, quint16 stayDuration);

    //sumType 1按天汇总，2按月汇总
    bool sumRunLogs(const QString& deviceIDs, QDateTime startTime,
                    QDateTime endTime, quint16 runDuration, quint16 stayDuration,
                    quint16 sumType);

signals:
    //pQuery参数需要在槽函数，客户手动释放 以下是返回字段
    //设备ID： "701110629100"
//    公司名称： company1
//    车牌： 鄂F8C199
//    开始行驶时间： QDateTime(2016-01-12 11:08:21.000 中国标准时间)
//    结束行驶时间 QDateTime(2016-01-12 11:34:50.000 中国标准时间 )
//    行驶时间： 1465  单位:秒
//    停留时间： 149    单位:秒
//    行驶里程： 134    单位：0.1公里
//    平均速度： 29      单位：公里/每小时
//    油耗： 0              单位：0.1升
    void sig_respondParseRunLogs(QSqlQuery *pQuery);

    void sig_respondSumRunLogs(QSqlQuery *pQuery, quint16 sumType);

public:
    static QStringList getDeviceIDList(const QString& str);

private:
//    HParseRunLogsReport                 * m_pParseRunLogsReport;
};

#endif // HVEHICLEREPORT_H
