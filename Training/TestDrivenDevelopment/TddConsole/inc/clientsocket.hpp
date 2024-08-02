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
#pragma once

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QMetaEnum>
#include <QRunnable>

class ClientSocket : public QObject
{
    Q_OBJECT
public:
    explicit ClientSocket(QObject *parent = nullptr);
    ~ClientSocket();

    QString getLastErrorString() const;
    QAbstractSocket::SocketError getLastErrorEnum() const;

    QString getCurrentStateString() const;
    QAbstractSocket::SocketState getCurrentStateEnum() const;

    QString getTargetHost() const;
    void setTargetHost(const QString &newTargetHost);

    int getTargetPort() const;
    void setTargetPort(int newTargetPort);

public slots:
    void connectToHost(const QString& ipAddress, int port);

private slots:
    void disconnect();
    void connected();
    void disconnected();
    void errorOccurred(QAbstractSocket::SocketError socketError);
    void stateChanged(QAbstractSocket::SocketState socketState);
    void readyRead();

signals:
    void success();
    void failString(const QString&);
    void failEnum(QAbstractSocket::SocketError);
    void complete();
    void stateChangedEnum(QAbstractSocket::SocketState);
    void stateChangedString(const QString&);

private:
    QTcpSocket* socket;
    QString targetHost;
    int targetPort;
    QString currentStateString;
    QAbstractSocket::SocketState currentStateEnum;
    QString lastErrorString;
    QAbstractSocket::SocketError lastErrorEnum;

};

