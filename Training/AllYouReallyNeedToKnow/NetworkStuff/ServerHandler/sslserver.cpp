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

#include <QFile>
#include <QSslKey>
#include <QThreadPool>

SslServer::SslServer(QObject *parent)
    : QSslServer{parent}
{
  initConfig();
}

SslServer::~SslServer()
{

}

void SslServer::incomingConnection(qintptr handle)
{
    qInfo() << Q_FUNC_INFO;
    qInfo() << "Receiving connection" << handle << "in thread" << QThread::currentThread();
    ReceiveSocket* recvSocket = new ReceiveSocket( handle );

    QThreadPool* pool = QThreadPool::globalInstance();
    pool->start(recvSocket);
}

void SslServer::initConfig(){
    m_sslConfiguration = QSslConfiguration::defaultConfiguration();

    QFile certFile( ":/ssl/res/server.crt");
    if( !certFile.open( QIODevice::ReadOnly | QIODevice::Text) ){
        qWarning() << "Couldn't open certificate file";
        return;
    }
    QFile keyFile( ":/ssl/res/server.key" );
    if( !keyFile.open( QIODevice::ReadOnly | QIODevice::Text ) ){
        qWarning() << "Couldn't open key file";
        return;
    }

    QSslKey key( keyFile.readAll(), QSsl::Rsa, QSsl::Pem);
    m_sslConfiguration.setPrivateKey( key );

    QSslCertificate certificate;
    certificate.fromPath(":/ssl/res/server.crt", QSsl::Pem);
    QList<QSslCertificate> certChain = QSslCertificate::fromPath( ":/ssl/res/server.crt" );
    // if( certChain.empty() ){
    //     qInfo() << "certChain.empty()";
    // }
    // else{
    //     for( auto cert : certChain ){
    //         qInfo() << "Certificate:" << cert.issuerDisplayName();
    //     }
    // }

    m_sslConfiguration.setCaCertificates( certChain );
    m_sslConfiguration.setLocalCertificate( certificate );

    m_sslConfiguration.setPeerVerifyMode( QSslSocket::VerifyNone );
    m_sslConfiguration.setProtocol(  QSsl::SslProtocol::TlsV1_3OrLater );

}