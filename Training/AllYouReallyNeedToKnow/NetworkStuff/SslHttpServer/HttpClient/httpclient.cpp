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


    /*
        --- Connections ---
    */

    connect(m_manager,&QNetworkAccessManager::authenticationRequired,this,&HttpClient::authenticationRequired);
    connect(m_manager,&QNetworkAccessManager::encrypted,this,&HttpClient::encrypted);
    connect(m_manager,&QNetworkAccessManager::preSharedKeyAuthenticationRequired,this,&HttpClient::preSharedKeyAuthenticationRequired);
    connect(m_manager,&QNetworkAccessManager::proxyAuthenticationRequired,this,&HttpClient::proxyAuthenticationRequired);
    connect(m_manager,&QNetworkAccessManager::sslErrors,this,&HttpClient::sslErrors);
    connect(m_manager,&QNetworkAccessManager::finished,this,&HttpClient::finished);

}

HttpClient::~HttpClient()
{
    m_manager->deleteLater();
}

void HttpClient::get()
{
    qInfo() << "Testing get verb";
    QString url = "https://127.0.0.1";
    QNetworkReply* reply = m_manager->get( QNetworkRequest( QUrl( url ) )  );
    connect( reply, &QNetworkReply::readyRead, this, &HttpClient::readyRead );
}

void HttpClient::put()
{
    qInfo() << "Testing put verb";
}

void HttpClient::post()
{
    qInfo() << "Testing put verb";
}

void HttpClient::readyRead()
{
    qInfo() << "readyRead";
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    qInfo() << "Reply:" << reply->readAll();
}

void HttpClient::authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    qInfo() << "authenticationRequired";
}

void HttpClient::encrypted(QNetworkReply *reply)
{
    qInfo() << "encrypted";
}

void HttpClient::finished(QNetworkReply *reply)
{
    qInfo() << "finished";
    reply->deleteLater();
    emit complete();
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
