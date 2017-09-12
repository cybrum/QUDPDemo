#ifndef UDPHELPER_H
#define UDPHELPER_H

#include <QObject>
#include <QUdpSocket>

class UDPHelper : public QObject
{
    Q_OBJECT
public:
    explicit UDPHelper(QObject *parent = 0);
    void sendMessage(QString strMsg);
    QString senderIPAddress() {  return m_strIPAddress;}
    QString senderPort()  {  return m_strPort;}

signals:
    void dataReceived();
public slots:
    QString readData();
    void readPendingDatagrams();

private:
    QUdpSocket *m_pSocket = nullptr;
    QString m_strPort = "";
    QString m_strIPAddress = "";

};

#endif // UDPHELPER_H
