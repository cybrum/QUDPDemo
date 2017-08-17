#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <QUdpSocket>

class MyUDP : public QObject
{
    Q_OBJECT
public:
    explicit MyUDP(QObject *parent = 0);
    void sendMessage(QString strMsg);
    QString senderIPAddress() {  return m_strIPAddress;}
    QString senderPort()  {  return m_strPort;}

public slots:
    QString readData();

private:
    QUdpSocket *m_pSocket = nullptr;
    QString m_strPort = "";
    QString m_strIPAddress = "";

};

#endif // MYUDP_H
