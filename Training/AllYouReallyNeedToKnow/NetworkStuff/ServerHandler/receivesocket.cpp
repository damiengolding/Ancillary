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

#include <QDir>

ReceiveSocket::ReceiveSocket(qint64 handle, QObject *parent)
    : QObject{parent}
{
    m_handle = handle;
}

ReceiveSocket::~ReceiveSocket()
{
    m_signalHandler->deleteLater();
}

void ReceiveSocket::run()
{
    m_signalHandler = new SignalHandler();
    m_socket = new QSslSocket( m_signalHandler );
    m_socket->setObjectName("socket");

    if( !m_socket->setSocketDescriptor( m_handle ) ){
        qInfo() << "Couldn't set socket descriptor:" << m_handle;
        return;
    }
    QMetaObject::connectSlotsByName( m_signalHandler );

    /*
        --- Old fashioned way ---
    */
    // m_socket->setLocalCertificate( ServerHandlerConfig::certificateFile, QSsl::Pem);
    // m_socket->setPrivateKey( ServerHandlerConfig::keyFile, QSsl::Rsa, QSsl::Pem);
    // QList<QSslCertificate> certChain = QSslCertificate::fromPath( ServerHandlerConfig::certificateFile );
    // m_sslConfiguration.setCaCertificates( certChain );

    /*
        --- New fangled way ---
    */
    m_sslConfiguration = QSslConfiguration::defaultConfiguration();
    // QFile certFile( ":/ssl/res/server.crt");
    QFile certFile( ServerHandlerConfig::certificateFile );
    if( !certFile.open( QIODevice::ReadOnly | QIODevice::Text) ){
        qWarning() << "Couldn't open certificate file (receive client)";
        return;
    }
    m_sslConfiguration.setLocalCertificate( QSslCertificate( certFile.readAll() , QSsl::Pem ) );

    // QFile keyFile( ":/ssl/res/server.key" );
    QFile keyFile( ServerHandlerConfig::keyFile );
    if( !keyFile.open( QIODevice::ReadOnly | QIODevice::Text ) ){
        qWarning() << "Couldn't open key file (receive client)";
        return;
    }

    QSslKey key( keyFile.readAll(), QSsl::Rsa, QSsl::Pem );
    m_sslConfiguration.setPrivateKey( key );

    QList<QSslCertificate> certChain = QSslCertificate::fromPath( ServerHandlerConfig::certificateFile );
    // m_sslConfiguration.setCaCertificates( certChain );
    m_sslConfiguration.addCaCertificates( certChain );

    m_socket->setSslConfiguration( m_sslConfiguration );
    m_socket->setPeerVerifyMode( QSslSocket::VerifyNone );
    m_socket->setProtocol( ServerHandlerConfig::sslProtocol );
    m_socket->ignoreSslErrors();
    m_socket->startServerEncryption();

    qInfo() << "Running receive socket for handle:" << m_handle;
}

