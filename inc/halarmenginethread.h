#ifndef HALARMENGINETHREAD_H
#define HALARMENGINETHREAD_H

#include <QThread>

class HAlarmEngineThread : public QThread
{
public:
    explicit HAlarmEngineThread(QObject * parent = 0);
    virtual ~HAlarmEngineThread();

protected:
    virtual void run();
};

#endif // HALARMENGINETHREAD_H
