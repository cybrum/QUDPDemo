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
signals:

public slots:
    QString readData();

private:
    QUdpSocket *m_pSocket = nullptr;

};

#endif // MYUDP_H
