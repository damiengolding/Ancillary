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
#include "receivesocket.hpp"

ReceiveSocket::ReceiveSocket(qintptr handle, QObject *parent)
    : QObject{parent}
{
    m_handle = handle;
}

ReceiveSocket::~ReceiveSocket()
{
    m_handler->deleteLater();
}

void ReceiveSocket::run()
{
    qInfo() << "Running ReceiveSocket in thread" << QThread::currentThread();
    m_handler = new SignalHandler();
    m_socket = new QSslSocket(m_handler);
    m_socket->setObjectName("socket");
    if( !m_socket->setSocketDescriptor( m_handle ) ){
        qCritical() << "m_socket/m_handle is invalid";
        return;
    }

    init();
    m_socket->startServerEncryption();
    m_socket->waitForReadyRead();
    // qInfo() << "readyRead from run";
    // qInfo() << "Read from client:" << m_socket->readAll();

    // QByteArray response = "Dave, my mind is going. I can feel it.";

    // m_socket->write(response);
    // m_socket->waitForBytesWritten();

    // m_socket->close();
    // m_socket->deleteLater();
}

void ReceiveSocket::init()
{
    m_socket->setObjectName("socket");

    /*
        --- Certificate and key ---
    */
    QByteArray key;
    QByteArray cert;

    QFile file_key(":/res/SERVER-KEY.pem");
    if(file_key.open(QIODevice::ReadOnly)) {
        key = file_key.readAll();
        file_key.close();
    }
    else{
        qDebug() << file_key.errorString();
    }

    QFile file_cert(":/res/SERVER-CERT.pem");
    if(file_cert.open(QIODevice::ReadOnly)){
        cert = file_cert.readAll();
        file_cert.close();
    }
    else{
        qDebug() << file_cert.errorString();
    }

    // QSslKey ssl_key(key, QSsl::Rsa, QSsl::Pem, QSsl::PrivateKey, "localhost");
    QSslKey ssl_key(key, QSsl::Rsa, QSsl::Pem, QSsl::PrivateKey);
    QSslCertificate ssl_cert(cert);

    m_socket->setPrivateKey( ssl_key );
    m_socket->setLocalCertificate( ssl_cert );

    // TODO - is this necessary/useful?
    // m_socket->setSocketOption( QAbstractSocket::KeepAliveOption, true );

    /*
        --- Connections ---
    */
    QMetaObject::connectSlotsByName(m_handler);
    // The one that dares to be different
     connect(m_socket, QOverload<const QList<QSslError> &>::of(&QSslSocket::sslErrors), m_handler, &SignalHandler::sslErrors);
}

