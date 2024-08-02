/*
MIT License

Copyright (c) Damien Golding 2024

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "../inc/benchmarktest.hpp"

BenchmarkTest::BenchmarkTest( QObject* parent) : QObject{parent}{}
BenchmarkTest::~BenchmarkTest(){}

#pragma Functions to test {

int BenchmarkTest::enumerateTcpPortRange(const QString &ipAddress, int start, int stop)
{
    int ret = -1;
    numOpenPorts = 0;
    numClosedPorts = 0;
    int portCount = 0;
    for( int i = start; i <= stop; ++i ){
        ++portCount;
        ClientSocket* clientSocket = new ClientSocket();
        clientSocket->setTargetHost(ipAddress);
        clientSocket->setTargetPort(i);
        clientSocket->setObjectName( QString("%1:%2").arg(ipAddress).arg(i) );

        QObject::connect(clientSocket, &ClientSocket::success, this, &BenchmarkTest::success );
        QObject::connect(clientSocket, &ClientSocket::failString, this, &BenchmarkTest::fail );

        clientSocket->connectToHost(ipAddress, i);
    }
    qInfo() << "Tested" << portCount <<  "ports (range)";
    return(numOpenPorts);
}

int BenchmarkTest::enumerateTcpPortList(const QString &ipAddress, QList<int> ports)
{
    int ret = -1;
    numOpenPorts = 0;
    numClosedPorts = 0;
    int portCount = 0;
    for( auto port : ports){
        ++portCount;
        ClientSocket* clientSocket = new ClientSocket();
        clientSocket->setTargetHost(ipAddress);
        clientSocket->setTargetPort(port);
        clientSocket->setObjectName( QString("%1:%2").arg(ipAddress).arg(port) );

        QObject::connect(clientSocket, &ClientSocket::success, this, &BenchmarkTest::success );
        QObject::connect(clientSocket, &ClientSocket::failString, this, &BenchmarkTest::fail );

        clientSocket->connectToHost(ipAddress, port);
    }
    qInfo() << "Tested" << portCount <<  "ports (list)";
    return(numOpenPorts);
}

void BenchmarkTest::success()
{
    numOpenPorts++;
    if( sender() == nullptr )
        return;
    ClientSocket* socket = qobject_cast<ClientSocket*>(sender());
    if( socket )
        qInfo() << "Successful connection for host: " << socket->getTargetHost() <<"on port:" <<socket->getTargetPort();
}

void BenchmarkTest::fail(const QString &msg)
{
    numClosedPorts++;
    if( sender() == nullptr  )
        return;
    ClientSocket* socket = qobject_cast<ClientSocket*>(sender());
    if( socket )
        qInfo() << "Failed connection for host: " << socket->getTargetHost() <<"on port:" <<socket->getTargetPort();
}

#pragma Functions to test }

#pragma Test cases {

#ifdef QT_DEBUG

void BenchmarkTest::initTestCase_data()
{
    QTest::addColumn<QList<int>>("ports");
    QList<int> tcpPorts;
    tcpPorts << 21
        << 22
        << 23
        << 25
        << 80
        << 135
        << 139
        << 443
        << 445
        << 666
        << 3306
        << 3389
        << 4443
        << 5985
        << 8009
        << 8020
        << 8080
        << 8081
        << 8027
        << 8080
        << 8383
        << 8484
        << 8585
        << 9200
        << 9300
        << 47001
        << 49152
        << 49153
        << 49154
        << 49155
        << 49156
        << 49161
        << 49162
        << 49250
        << 49251;
    QTest::newRow("tcp_ports") << tcpPorts;
}

void BenchmarkTest::NetworkTestAllPortsMustBeReallyFast()
{
    QSKIP("Won't complete - needs threading to avoid a timeout");
    QBENCHMARK{
        enumerateTcpPortRange("192.168.4.36", 1, 65535);
    }

    // QBENCHMARK_ONCE{
    //     enumerateTcpPortRange("192.168.4.36", 1, 65535);
    // }

    qDebug() << "Open ports (all ports):" << numOpenPorts;
    qDebug() << "Closed ports (all ports):" << numClosedPorts;
}

void BenchmarkTest::NetworkTestSelectedPortsMustBeReallyFast()
{
    QFETCH_GLOBAL( QList<int>, ports );
    QSKIP("Won't complete - needs threading to avoid a timeout");
    // QBENCHMARK{
    //     enumerateTcpPortList("192.168.4.36", ports);
    // }

    QBENCHMARK_ONCE{
        enumerateTcpPortList("192.168.4.36", ports);
    }

    qDebug() << "Open ports (selected):" << numOpenPorts;
    qDebug() << "Closed ports selected):" << numClosedPorts;
}

#endif

#pragma Test cases }

