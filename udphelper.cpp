#include "udphelper.h"

UDPHelper::UDPHelper(QObject *parent) :
    QObject(parent)
{
    // Create an QUDP socket
    m_pSocket = new QUdpSocket(this);
    m_pSocket->bind(QHostAddress::LocalHost, 1234);

    connect(m_pSocket, SIGNAL(readyRead()),
            this, SLOT(readPendingDatagrams()));
}

void UDPHelper::readPendingDatagrams()
 {
     while (m_pSocket->hasPendingDatagrams()) {

         //Refer Qt documentation for available platform support.
         //Some features of QNetworkDatagram are not supported in all operating systems.
         //Only the address and ports of the remote host (sender in received packets and
         //destination for outgoing packets) are supported in all systems.
         //On most operating systems, the other features are supported only for IPv6.
         //Software should check at runtime whether the rest could be determined for IPv4 addresses.

         //TODO: send read data here?
         //QNetworkDatagram datagram = m_pSocket->receiveDatagram();
         emit dataReceived();
     }
 }

void UDPHelper::sendMessage(QString strMsg)
{
    QByteArray Data;
    Data.append(strMsg);
    m_pSocket->writeDatagram(Data, QHostAddress::LocalHost, 1234);
}

QString UDPHelper::readData()
{
    QByteArray buffer;
    buffer.clear();
    buffer.resize(m_pSocket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    m_pSocket->readDatagram(buffer.data(), buffer.size(),&sender, &senderPort);
   // QString readString = "\nMessage from: "+  sender.toString()+ "\nMessage port: "+ senderPort + "\nMessage: " + buffer;

    m_strIPAddress = sender.toString();
    m_strPort = QString::number(senderPort);
//    qDebug() << "Message from: " << sender.toString();
//    qDebug() << "Message port: " << senderPort;
//    qDebug() << "Message: " << buffer;
//    if(buffer.isEmpty())
//    {
//        return "Connection established.";
//    }
    return buffer;
}
