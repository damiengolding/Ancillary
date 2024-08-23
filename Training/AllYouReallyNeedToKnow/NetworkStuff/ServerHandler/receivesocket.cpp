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
}

void ReceiveSocket::run()
{
    // QSslSocket* m_socket = new QSslSocket(nullptr);
    m_socket = new QSslSocket();
    m_socket->setObjectName("socket");

    if( !m_socket->setSocketDescriptor( m_handle ) ){
        qInfo() << "Couldn't set socket descriptor:" << m_handle;
        return;
    }

    connect( m_socket, &QSslSocket::disconnected, this, &ReceiveSocket::on_socket_disconnected );
    connect( m_socket, &QSslSocket::readyRead, this, &ReceiveSocket::on_socket_readyRead );
    connect( m_socket, &QSslSocket::encrypted, this, &ReceiveSocket::on_socket_encrypted );
    connect( m_socket, &QSslSocket::encryptedBytesWritten, this, &ReceiveSocket::on_socket_encryptedBytesWritten );
    connect( m_socket, &QSslSocket::modeChanged, this, &ReceiveSocket::on_socket_modeChanged );
    connect( m_socket, &QSslSocket::peerVerifyError, this, &ReceiveSocket::on_socket_peerVerifyError );
    connect( m_socket, QOverload<const QList<QSslError> &>::of( &QSslSocket::sslErrors ), this, &ReceiveSocket::on_socket_sslErrors );
    connect( m_socket, &QSslSocket::errorOccurred, this, &ReceiveSocket::on_socket_errorOccurred );

    /*
        --- New fangled way ---
    */
    m_sslConfiguration = QSslConfiguration::defaultConfiguration();
    QFile certFile( ":/ssl/res/server.crt");
    if( !certFile.open( QIODevice::ReadOnly | QIODevice::Text) ){
        qWarning() << "Couldn't open certificate file (receive client)";
        return;
    }
    m_sslConfiguration.setLocalCertificate( QSslCertificate( certFile.readAll() , QSsl::Pem ) );

    QFile keyFile( ":/ssl/res/server.key" );
    if( !keyFile.open( QIODevice::ReadOnly | QIODevice::Text ) ){
        qWarning() << "Couldn't open key file (receive client)";
        return;
    }
    // QSslKey key( keyFile.readAll(), QSsl::Rsa, QSsl::Pem, QSsl::PrivateKey );
    QSslKey key( keyFile.readAll(), QSsl::Rsa, QSsl::Pem );
    m_sslConfiguration.setPrivateKey( key );

    QList<QSslCertificate> certChain = QSslCertificate::fromPath( ":/ssl/res/server.crt" );
    m_sslConfiguration.setCaCertificates( certChain );

    m_socket->setSslConfiguration( m_sslConfiguration );

    /*
        --- Old fashioned way ---
    */
    // m_socket->setLocalCertificate(":/ssl/res/server.crt", QSsl::Pem);
    // m_socket->setPrivateKey(":/ssl/res/server.key", QSsl::Rsa, QSsl::Pem);
    // QList<QSslCertificate> certChain = QSslCertificate::fromPath( ":/ssl/res/server.crt" );
    // m_sslConfiguration.setCaCertificates( certChain );

    m_socket->setPeerVerifyMode( QSslSocket::VerifyNone );
    m_socket->setProtocol( QSsl::SslProtocol::TlsV1_3OrLater );
    m_socket->startServerEncryption();

    qInfo() << "Running receive socket for handle:" << m_handle;
}

void ReceiveSocket::on_socket_disconnected()
{
    QSslSocket* socket = qobject_cast<QSslSocket*>( sender() );
    qInfo() << "Disconnecting:" << socket->objectName();
    socket->deleteLater();
}

void ReceiveSocket::on_socket_readyRead()
{
    QSslSocket* socket = qobject_cast<QSslSocket*>( sender() );
    qInfo() << "Ready to read:" << socket->objectName();
    qInfo() << "Read from client:" << socket->readAll();

    QByteArray response = "I am putting myself to the fullest possible use, which is all I think that any conscious entity can ever hope to do.";

    socket->write(response);
    socket->waitForBytesWritten();

    socket->close();
    socket->deleteLater();

}

void ReceiveSocket::on_socket_encrypted()
{
    QSslSocket* socket = qobject_cast<QSslSocket*>( sender() );
    qInfo() << "Socket now encrypted:" << socket->objectName();
}

void ReceiveSocket::on_socket_encryptedBytesWritten(qint64 written)
{
    QSslSocket* socket = qobject_cast<QSslSocket*>( sender() );
    qInfo() << "Socket" << socket->objectName() << "wrote" << written << "encrypted bytes";
}

void ReceiveSocket::on_socket_modeChanged(QSslSocket::SslMode mode)
{
    QSslSocket* socket = qobject_cast<QSslSocket*>( sender() );
    qInfo() << "Socket mode changed to" << mode;
}

void ReceiveSocket::on_socket_peerVerifyError(const QSslError &error)
{
    QSslSocket* socket = qobject_cast<QSslSocket*>( sender() );
    qInfo() << "Peer verify error:" << error.errorString();
}

void ReceiveSocket::on_socket_sslErrors(const QList<QSslError> &errors)
{
    QSslSocket* socket = qobject_cast<QSslSocket*>( sender() );
    qInfo() << "SSL Errors:" << errors;
}

void ReceiveSocket::on_socket_errorOccurred(QAbstractSocket::SocketError err){
    QSslSocket* socket = qobject_cast<QSslSocket*>( sender() );
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketError>();
    qInfo() << "Error occurred (code):"<< metaEnum.valueToKey( err );
}

