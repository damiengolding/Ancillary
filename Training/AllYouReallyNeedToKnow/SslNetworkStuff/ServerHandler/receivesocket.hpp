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
#include <QDebug>
#include <QAbstractSocket>
#include <QSslSocket>
#include <QSslServer>
#include <QMetaEnum>
#include <QRunnable>
#include <QThread>
#include <QFile>
#include <QSslKey>

#include "signalhandler.hpp"
#include "ServerHandlerConfig.hpp"

class ReceiveSocket : public QObject, public QRunnable
{
    Q_OBJECT

public:
    explicit ReceiveSocket( qint64 handle, QObject *parent = nullptr);
    ~ReceiveSocket();

signals:

    void socketChanged();

public:
    void run() override;

private:
    qintptr m_handle;
    QSslSocket* m_socket;
    SignalHandler* m_signalHandler;
    QSslConfiguration m_sslConfiguration;
};

