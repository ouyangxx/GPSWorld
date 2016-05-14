#ifndef HMAPUDPSENDER_H
#define HMAPUDPSENDER_H

#include <QObject>
#include <QThread>

class HMapUdpManager;

class HMapUdpSenderThread : public QThread
{
public:
    explicit HMapUdpSenderThread(HMapUdpManager *parent);
    virtual ~HMapUdpSenderThread();

protected:
    virtual void run();

private:
    HMapUdpManager          * m_pManager;
};

class HMapUdpSender : public QObject
{
    Q_OBJECT
public:
    explicit HMapUdpSender(HMapUdpManager *parent);
    virtual ~HMapUdpSender();
    void startSenderThread();

signals:

public slots:


public:
    HMapUdpSenderThread         * m_pSenderThread;
    HMapUdpManager                  * m_pManager;
};

#endif // HMAPUDPSENDER_H
