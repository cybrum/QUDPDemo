#include "myudp.h"

MyUDP::MyUDP(QObject *parent) :
    QObject(parent)
{
    // Create an QUDP socket
    m_pSocket = new QUdpSocket(this);
    m_pSocket->bind(QHostAddress::LocalHost, 1234);
}

void MyUDP::sendMessage(QString strMsg)
{
    QByteArray Data;
    Data.append(strMsg);
    m_pSocket->writeDatagram(Data, QHostAddress::LocalHost, 1234);
}

QString MyUDP::readData()
{
    QByteArray buffer;
    buffer.resize(m_pSocket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    m_pSocket->readDatagram(buffer.data(), buffer.size(),&sender, &senderPort);
    QString readString = "\nMessage from: "+  sender.toString()+ "\nMessage port: "+ senderPort + "\nMessage: " + buffer;

    qDebug() << "Message from: " << sender.toString();
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << buffer;
    if(sender.toString().isEmpty())
    {
        return "connected";
    }
    return readString;
}
