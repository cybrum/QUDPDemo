# QUDPDemo
Qt Based UDP Demo Logger

Features:
1.Qt based UI
2.Send and receive message through UDP in localhost.
3.Log UDP message in log.txt with time stamp.

About UDP:

UDP (User Datagram Protocol) is an alternative communications protocol to Transmission Control Protocol (TCP) used primarily for establishing low-latency and loss tolerating connections between applications on the Internet. Both UDP and TCP run on top of the Internet Protocol (IP) and are sometimes referred to as UDP/IP or TCP/IP. Both protocols send short packets of data, called datagrams.


UDP provides two services not provided by the IP layer. It provides port numbers to help distinguish different user requests and, optionally, a checksum capability to verify that the data arrived intact.


UDP is faster than TCP, and the simple reason is because its nonexistent acknowledge packet (ACK) that permits a continuous packet stream, instead of TCP that acknowledges a set of packets, calculated by using the TCP window size and round-trip time (RTT).


From Qt5 document:

"UDP (User Datagram Protocol) is a lightweight, unreliable, datagram-oriented, connectionless protocol. 
It can be used when reliability isn't important. QUdpSocket is a subclass of QAbstractSocket that allows you to send and receive UDP datagrams."


Copyright: Nibedit Dey,2017
 