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
#include "../inc/clientsocket.hpp"

ClientSocket::ClientSocket(QObject *parent)
    : QObject{parent}
{
    socket = new QTcpSocket();
    connect(socket,&QTcpSocket::connected, this, &ClientSocket::connected);
    connect(socket,&QTcpSocket::disconnected, this, &ClientSocket::disconnected);
    connect(socket,&QTcpSocket::errorOccurred, this, &ClientSocket::errorOccurred);
    connect(socket,&QTcpSocket::stateChanged, this, &ClientSocket::stateChanged);
    connect(socket,&QTcpSocket::readyRead, this, &ClientSocket::readyRead);
    currentStateEnum = QAbstractSocket::UnconnectedState;
    targetHost = "";
    targetPort = -1;
}

ClientSocket::~ClientSocket()
{
    if( socket && socket->isOpen() ){
        socket->close();
        socket->deleteLater();
    }
}

// CODECOMP: Add implementation specific code
void ClientSocket::connectToHost(const QString &ipAddress, int port)
{
    if( socket->isOpen()  )
        disconnect();
    targetHost = ipAddress;
    targetPort = port;
    socket->connectToHost(ipAddress,port);
    socket->waitForConnected();
    disconnect();
}

void ClientSocket::disconnect()
{
    socket->close();
    emit complete();
}

// CODECOMP: Add implementation specific code
void ClientSocket::connected()
{
    socket->write("HELLO_WORLD\r\n");
    emit success();
}

// CODECOMP: Add implementation specific code
void ClientSocket::disconnected()
{
    emit complete();
}

void ClientSocket::errorOccurred(QAbstractSocket::SocketError socketError)
{
    lastErrorEnum = socketError;
    lastErrorString = socket->errorString();
    emit failString(lastErrorString);
    emit failEnum(socketError);
}

void ClientSocket::stateChanged(QAbstractSocket::SocketState socketState)
{
    currentStateEnum = socketState;
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    currentStateString = metaEnum.valueToKey(socketState);
}

// CODECOMP: Add implementation specific code
void ClientSocket::readyRead()
{
    int recvSize = socket->bytesAvailable();
    QString recvData = socket->readAll();
}

// Accessors and mutators
int ClientSocket::getTargetPort() const
{
    return targetPort;
}

void ClientSocket::setTargetPort(int newTargetPort)
{
    targetPort = newTargetPort;
}

QString ClientSocket::getTargetHost() const
{
    return targetHost;
}

void ClientSocket::setTargetHost(const QString &newTargetHost)
{
    targetHost = newTargetHost;
}

QString ClientSocket::getCurrentStateString() const
{
    return currentStateString;
}

QAbstractSocket::SocketError ClientSocket::getLastErrorEnum() const
{
    return lastErrorEnum;
}

QString ClientSocket::getLastErrorString() const
{
    return lastErrorString;
}

QAbstractSocket::SocketState ClientSocket::getCurrentStateEnum() const
{
    return currentStateEnum;
}
