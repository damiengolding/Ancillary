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
#include <QTcpServer>
#include <QSslSocket>
#include <QFile>
#include <QSslKey>
#include <QMetaEnum>

class SslServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit SslServer(QObject *parent = nullptr);
    ~SslServer();

public slots:
    void disconnected();
    void readyRead();
    void encrypted();
    void encryptedBytesWritten(qint64 written);
    void modeChanged(QSslSocket::SslMode mode);
    void peerVerifyError(const QSslError &error);
    void errorOccurred(QAbstractSocket::SocketError err);

    void sslErrors(const QList<QSslError> &errors);

private: // Functions
    void init();

private: // Members
    QSslSocket* m_server = nullptr;

    // QTcpServer interface
protected:
    void incomingConnection(qintptr handle) override;
};

