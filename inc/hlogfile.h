#ifndef HLOGFILE
#define HLOGFILE

#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QString>
#include <QDir>

#define initServerLogFile "serverLogs.txt"
#define initClientLogFile "clientLogs.txt"

class HLogFile
{
public:
    HLogFile(const QString& logFile);

    int writeLog(const QString& logContent);

public:
    QString                     m_logFile;
};

#endif // HLOGFILE

