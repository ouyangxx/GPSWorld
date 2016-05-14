#ifndef HMAPUDPRECEIVER_H
#define HMAPUDPRECEIVER_H

#include <QObject>
#include <QThread>

class HMapUdpManager;

class HMapUdpReceiverThread : public QThread
{
public:
    explicit HMapUdpReceiverThread(HMapUdpManager * parent);
    virtual ~HMapUdpReceiverThread();

protected:
    virtual void run();

private:
    HMapUdpManager              * m_pManager;
};

class HMapUdpReceiver : public QObject
{
    Q_OBJECT
public:
    explicit HMapUdpReceiver(HMapUdpManager *parent);
    virtual ~HMapUdpReceiver();
    void startReceiverThread();

signals:

public slots:


public:
    HMapUdpReceiverThread           * m_pReceiverThread;
    HMapUdpManager              * m_pManager;
};

#endif // HMAPUDPRECEIVER_H
