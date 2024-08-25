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
#include "sslclient.hpp"

#include <QMetaEnum>
#include <QSslConfiguration>

SslClient::SslClient(QObject *parent)
    : QObject{parent}
{
    init();
}

SslClient::~SslClient()
{
    m_socket->deleteLater();
}

void SslClient::connectHost(const QString &ipAddress, qint64 port)
{
    qInfo() << "Connecting to" << ipAddress << "on port" << port;
    m_socket->connectToHostEncrypted( ipAddress, port );
    m_socket->write( "Open the pod bay doors, HAL." );
    // QByteArray reqComp = qCompress( "Open the pod bay doors, HAL.", 9 );
    // m_socket->write( reqComp );
}

void SslClient::init(){
    m_socket = new QSslSocket(this);

    /*
        --- Certificate and key ---
    */
    QByteArray cert;

    QFile file_cert(":/res/SERVER-CERT.pem");
    if(file_cert.open(QIODevice::ReadOnly)){
        cert = file_cert.readAll();
        file_cert.close();
    }
    else{
        qDebug() << file_cert.errorString();
    }
    QSslCertificate ssl_cert(cert);

    QList<QSslCertificate> listCA;
    listCA.append(ssl_cert);
    QSslConfiguration conf;
    conf.setCaCertificates(listCA);
    m_socket->setSslConfiguration(conf);

    m_socket->setProtocol(QSsl::SecureProtocols);

    /*
        --- Connections ---
    */
    connect( m_socket, &QSslSocket::disconnected, this, &SslClient::disconnected );
    connect( m_socket, &QSslSocket::readyRead, this, &SslClient::readyRead );
    connect( m_socket, &QSslSocket::encrypted, this, &SslClient::encrypted );
    connect( m_socket, &QSslSocket::encryptedBytesWritten, this, &SslClient::encryptedBytesWritten );
    connect( m_socket, &QSslSocket::modeChanged, this, &SslClient::modeChanged );
    connect( m_socket, &QSslSocket::peerVerifyError, this, &SslClient::peerVerifyError );
    connect( m_socket, &QSslSocket::errorOccurred, this, &SslClient::errorOccurred );
    // The one that dares to be different
    connect(m_socket, QOverload<const QList<QSslError> &>::of(&QSslSocket::sslErrors), this, &SslClient::sslErrors);

    /*
        --- Errors to ignore ---
    */
    QList<QSslCertificate> certs = QSslCertificate::fromPath( ":/res/SERVER-CERT.pem");
    QSslError selfSignedCertError( QSslError::SelfSignedCertificate, certs.at(0) );
    QSslError hostNameMismatchError( QSslError::HostNameMismatch, certs.at(0) );

    QList<QSslError> ignoreErrors;
    ignoreErrors << selfSignedCertError << hostNameMismatchError;

    m_socket->ignoreSslErrors(ignoreErrors);

}

#pragma  {

void SslClient::disconnected()
{
    qInfo() << "disconnected";
    m_socket->deleteLater();
    emit complete();
}

void SslClient::readyRead()
{
    qInfo() << "readyRead";
    qInfo() << "Read from server:" << m_socket->readAll();
}

void SslClient::encrypted()
{
    qInfo() << "encrypted";
}

void SslClient::encryptedBytesWritten(qint64 written)
{
    qInfo() << "encryptedBytesWritten:" << written;
}

void SslClient::modeChanged(QSslSocket::SslMode mode)
{
    qInfo() << "modeChanged:" << mode;
}

void SslClient::peerVerifyError(const QSslError &error)
{
    qInfo() << "peerVerifyError:" << error.errorString();
}

void SslClient::errorOccurred(QAbstractSocket::SocketError err)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketError>();
    qInfo() << "errorOccurred:"<< metaEnum.valueToKey( err );
}

void SslClient::sslErrors(const QList<QSslError> &errors)
{
    qInfo() << "sslErrors:" << errors;
    m_socket->ignoreSslErrors( errors );
    /*
        --- Errors to ignore ---
    */
    // QList<QSslCertificate> certs = QSslCertificate::fromPath( ":/res/SERVER-CERT.pem");
    // QSslError selfSignedCertError( QSslError::SelfSignedCertificate, certs.at(0) );
    // QSslError hostNameMismatchError( QSslError::HostNameMismatch, certs.at(0) );
    // QSslError invalidPurposeError( QSslError::InvalidPurpose, certs.at(0) );

    // QList<QSslError> ignoreErrors;
    // ignoreErrors << selfSignedCertError << hostNameMismatchError << invalidPurposeError;

    // m_socket->ignoreSslErrors(ignoreErrors);
}

#pragma Slots }
