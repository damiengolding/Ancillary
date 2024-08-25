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
#include "sslserver.hpp"

SslServer::SslServer(QObject *parent)
    : QTcpServer{parent}
{
    init();
}

SslServer::~SslServer()
{
    m_server->deleteLater();
}

void SslServer::incomingConnection(qintptr handle)
{
    if (m_server->setSocketDescriptor(handle)) {
        addPendingConnection(m_server);
        m_server->startServerEncryption();
    } else {
        m_server->close();
    }
}

void SslServer::init()
{
    m_server = new QSslSocket(this);
    m_server->setObjectName("socket");

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

    m_server->setPrivateKey( ssl_key );
    m_server->setLocalCertificate( ssl_cert );

    // TODO - is this necessary/useful?
    m_server->setSocketOption( QAbstractSocket::KeepAliveOption, true );

    /*
        --- Connections ---
    */
    connect( m_server, &QSslSocket::disconnected, this, &SslServer::disconnected );
    connect( m_server, &QSslSocket::readyRead, this, &SslServer::readyRead );
    connect( m_server, &QSslSocket::encrypted, this, &SslServer::encrypted );
    connect( m_server, &QSslSocket::encryptedBytesWritten, this, &SslServer::encryptedBytesWritten );
    connect( m_server, &QSslSocket::modeChanged, this, &SslServer::modeChanged );
    connect( m_server, &QSslSocket::peerVerifyError, this, &SslServer::peerVerifyError );
    connect( m_server, &QSslSocket::errorOccurred, this, &SslServer::errorOccurred );
    // The one that dares to be different
    connect(m_server, QOverload<const QList<QSslError> &>::of(&QSslSocket::sslErrors), this, &SslServer::sslErrors);
}

#pragma Slots {

void SslServer::disconnected()
{
    qInfo() << "Disconnected";
    m_server->deleteLater();
}

void SslServer::readyRead()
{
    qInfo() << "readyRead";
    qInfo() << "Read from client:" << m_server->readAll();
    // QByteArray readComp = m_server->readAll();
    // QByteArray readDecomp = qUncompress( readComp );
    // qInfo() << "Read from client:" << readDecomp;

    QByteArray response = "I'm sorry, Dave. I'm afraid I can't do that.";

    m_server->write(response);
    m_server->waitForBytesWritten();

    m_server->close();
    m_server->deleteLater();
}

void SslServer::encrypted()
{
    qInfo() << "encrypted";
}

void SslServer::encryptedBytesWritten(qint64 written)
{
    qInfo() << "encryptedBytesWritten:" << written;
}

void SslServer::modeChanged(QSslSocket::SslMode mode)
{
    qInfo() << "modeChanged:" << mode;
}

void SslServer::peerVerifyError(const QSslError &error)
{
    qInfo() << "Peer verify error:" << error.errorString();
}

void SslServer::errorOccurred(QAbstractSocket::SocketError err)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketError>();
    qInfo() << "Error occurred:"<< metaEnum.valueToKey( err );
}

void SslServer::sslErrors(const QList<QSslError> &errors)
{
    qInfo() << "SSL Errors:" << errors;
    m_server->ignoreSslErrors( errors );
}

#pragma Slots }
