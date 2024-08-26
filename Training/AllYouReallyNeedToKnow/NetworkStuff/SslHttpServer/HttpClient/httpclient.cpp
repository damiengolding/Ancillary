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
#include "httpclient.hpp"

HttpClient::HttpClient(QObject *parent)
    : QObject{parent}
{
    m_manager = new QNetworkAccessManager(this);
    init();
}

void HttpClient::init(){
    /*
        --- SSL Configuration ---
    */
    // QByteArray certBytes;

    // QFile certFile(":/res/SERVER-CERT.pem");
    // if(certFile.open(QIODevice::ReadOnly)){
    //     certBytes = certFile.readAll();
    //     certFile.close();
    // }
    // else{
    //     qDebug() << certFile.errorString();
    // }
    // QSslCertificate sslCert(certBytes);

    QSslCertificate sslCert = QSslCertificate::fromPath( ":/res/SERVER-CERT.pem" ).first();

    QList<QSslCertificate> certificateList;
    certificateList.append(sslCert);
    m_config.setCaCertificates(certificateList);

    /*
        --- QNetworkAccessManager connections ---
    */
    connect(m_manager, &QNetworkAccessManager::authenticationRequired, this, &HttpClient::authenticationRequired);
    connect(m_manager, &QNetworkAccessManager::encrypted ,this, &HttpClient::encrypted);
    connect(m_manager, &QNetworkAccessManager::preSharedKeyAuthenticationRequired, this, &HttpClient::preSharedKeyAuthenticationRequired);
    connect(m_manager, &QNetworkAccessManager::proxyAuthenticationRequired, this, &HttpClient::proxyAuthenticationRequired);
    connect(m_manager, &QNetworkAccessManager::sslErrors, this, &HttpClient::sslErrors);
    connect(m_manager, &QNetworkAccessManager::finished, this, &HttpClient::finished);

}

HttpClient::~HttpClient()
{
    m_manager->deleteLater();
}

void HttpClient::get()
{
    qInfo() << "Testing get verb";
    // QString url = "https://127.0.0.1/upload?file=handbook.pdf";
    // lastFileRequest = "handbook.pdf";

    // QString url = "https://127.0.0.1/upload?file=notes.txt";
    // lastFileRequest = "notes.txt";

    // QString url = "https://127.0.0.1/upload?file=style_guide_color.docx";
    // lastFileRequest = "style_guide_color.docx";

    QString url = "https://127.0.0.1/upload?file=source.zip";
    lastFileRequest = "source.zip";

    // QNetworkReply* reply = m_manager->get( QNetworkRequest( QUrl( url ) ) );

    QNetworkRequest request;
    request.setUrl( QUrl( url ) );
    request.setSslConfiguration( m_config );
    QNetworkReply* reply = m_manager->get( request );

    connect( reply, &QNetworkReply::errorOccurred, this, &HttpClient::errorOccurred );
    // connect( reply, &QNetworkReply::readyRead, this, &HttpClient::readyRead );
}

void HttpClient::post()
{
    qInfo() << "Testing post verb";
    QString url = "https://127.0.0.1/download";
    QFileInfo fileInfo( "./Source/source.zip" );
    if( !fileInfo.exists() ){
        qInfo() << "File"<< fileInfo.absoluteFilePath()<<"doesn't exist";
        return;
    }
    QFile postFile( fileInfo.absoluteFilePath() );
    if( !postFile.open( QIODevice::ReadOnly )  ){
        qInfo() << "Couldn't open POST file for reading";
        return;
    }
    QByteArray data = postFile.readAll();
    postFile.close();

    // QNetworkReply* reply = m_manager->post( QNetworkRequest( QUrl( url ) ), data );

    QNetworkRequest request;
    request.setUrl( QUrl( url ) );
    request.setSslConfiguration( m_config );
    request.setHeader( QNetworkRequest::ContentTypeHeader, "multipart/x-zip" );
    request.setRawHeader("File-Name", "source.zip");
    QNetworkReply* reply = m_manager->post( request, data );

    connect( reply, &QNetworkReply::readyRead, this, &HttpClient::readyRead );
    connect( reply, &QNetworkReply::errorOccurred, this, &HttpClient::errorOccurred );
    connect( reply, &QNetworkReply::finished, this, &HttpClient::replyFinished );
}

void HttpClient::put()
{
    qInfo() << "Testing put verb";
    QString url = "https://127.0.0.1/download";
    QFileInfo fileInfo( "./Source/source.zip" );
    if( !fileInfo.exists() ){
        qInfo() << "File"<< fileInfo.absoluteFilePath()<<"doesn't exist";
        return;
    }
    // qInfo() << "PUT file"<<fileInfo.absoluteFilePath();
    QFile putFile( fileInfo.absoluteFilePath() );
    if( !putFile.open( QIODevice::ReadOnly )  ){
        qInfo() << "Couldn't open PUT file for reading";
        return;
    }

    QByteArray data = putFile.readAll();
    putFile.close();

    // QNetworkReply* reply = m_manager->put( QNetworkRequest( QUrl( url ) ), data );

    QNetworkRequest request;
    request.setUrl( QUrl( url ) );
    request.setSslConfiguration( m_config );
    request.setHeader( QNetworkRequest::ContentTypeHeader, "application/zip" );
    request.setRawHeader("File-Name", "source.zip");
    QNetworkReply* reply = m_manager->put( request, data );

    connect( reply, &QNetworkReply::readyRead, this, &HttpClient::readyRead );
    connect( reply, &QNetworkReply::errorOccurred, this, &HttpClient::errorOccurred );
}

void HttpClient::getResponse(QNetworkReply *reply)
{
    qInfo() << "GET response";
    qInfo() << "Headers:";
    qint64 contentLength = -1;
    for( auto pair : reply->rawHeaderPairs() ){
        qInfo() << "Header:" << pair.first << "Value:" << pair.second;
        if( pair.first == "Content-Length" ){
            contentLength = QString( pair.second ).toInt();
            qInfo() << "Length:" << contentLength;
        }
    }
    qInfo() << "lastFileRequest:"<<lastFileRequest;
    QByteArray fileContents = reply->readAll();
    QString fileLocation = "./Upload" % QDir::separator() % lastFileRequest;
    QFileInfo fileInfo( fileLocation );
    QFile downloadFile( fileInfo.absoluteFilePath() );
    if( !downloadFile.open( QIODevice::WriteOnly  )  ){
        qInfo() << "Couldn't open"<< fileInfo.absoluteFilePath() << "for writing";
        return;
    }
    QDataStream outputStream(&downloadFile);
    outputStream << fileContents;
    downloadFile.flush();
    downloadFile.close();
}

void HttpClient::putResponse(QNetworkReply *reply)
{
    qInfo() << "PUT response";
    qInfo() << "Reply payload:" << reply->readAll();
}

void HttpClient::postResponse(QNetworkReply *reply)
{
    qInfo() << "POST response";
    qInfo() << "Reply payload:" << reply->readAll();
}

#pragma QNetworkReply slots {

void HttpClient::errorOccurred(QNetworkReply::NetworkError code){
    qInfo() << "QNetworkReply error";
}

void HttpClient::replyFinished(){
    qInfo() << "QNetworkReply finished";
}

#pragma QNetworkReply slots }

#pragma QNetworkAccessManager slots {

void HttpClient::readyRead()
{
    qInfo() << "readyRead";
}

void HttpClient::finished(QNetworkReply *reply)
{
    qInfo() << "finished";
    qInfo() << "Response status code:" << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QNetworkAccessManager::Operation operation = reply->operation();

    switch( operation ){
    case 2:{
        qInfo() << "GET response";
        getResponse(reply);
        break;
    }
    case 3:{
        qInfo() << "PUT response";
        putResponse(reply);
        break;
    }
    case 4:{
        qInfo() << "POST response";
        postResponse(reply);
        break;
    }

    }

    reply->deleteLater();
    emit complete();
}

void HttpClient::authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    qInfo() << "authenticationRequired";
}

void HttpClient::encrypted(QNetworkReply *reply)
{
    qInfo() << "encrypted";
}

void HttpClient::preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator)
{
    qInfo() << "preSharedKeyAuthenticationRequired";
}

void HttpClient::proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator)
{
    qInfo() << "proxyAuthenticationRequired";
}

void HttpClient::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    qInfo() << "sslErrors" << errors;
    reply->ignoreSslErrors();
}

#pragma QNetworkAccessManager slots }

#pragma Accessors and mutators {

QNetworkAccessManager *HttpClient::manager() const
{
    return m_manager;
}

void HttpClient::setManager(QNetworkAccessManager *newManager)
{
    if (m_manager == newManager)
        return;
    m_manager = newManager;
    emit managerChanged();
}

QString HttpClient::ipAddress() const
{
    return m_ipAddress;
}

void HttpClient::setIpAddress(const QString &newIpAddress)
{
    if (m_ipAddress == newIpAddress)
        return;
    m_ipAddress = newIpAddress;
    emit ipAddressChanged();
}

qint64 HttpClient::portNumber() const
{
    return m_portNumber;
}

void HttpClient::setPortNumber(qint64 newPortNumber)
{
    if (m_portNumber == newPortNumber)
        return;
    m_portNumber = newPortNumber;
    emit portNumberChanged();
}

#pragma Accessors and mutators }
