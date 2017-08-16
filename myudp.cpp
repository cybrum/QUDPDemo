#include "myudp.h"

MyUDP::MyUDP(QObject *parent) :
    QObject(parent)
{
    // create a QUDP socket
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
    // when data comes in
    QByteArray buffer;
    buffer.resize(m_pSocket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    // qint64 QUdpSocket::readDatagram(char * data, qint64 maxSize,
    //                 QHostAddress * address = 0, quint16 * port = 0)
    // Receives a datagram no larger than maxSize bytes and stores it in data.
    // The sender's host address and port is stored in *address and *port
    // (unless the pointers are 0).

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
