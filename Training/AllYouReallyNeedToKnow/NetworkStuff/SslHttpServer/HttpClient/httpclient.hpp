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
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkReply>
#include <QNetworkCookie>
#include <QSslConfiguration>

class HttpClient : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QNetworkAccessManager *manager READ manager WRITE setManager NOTIFY managerChanged FINAL)
    Q_PROPERTY(QString ipAddress READ ipAddress WRITE setIpAddress NOTIFY ipAddressChanged FINAL)
    Q_PROPERTY(qint64 portNumber READ portNumber WRITE setPortNumber NOTIFY portNumberChanged FINAL)
public:
    explicit HttpClient(QObject *parent = nullptr);
    ~HttpClient();

    QNetworkAccessManager *manager() const;
    void setManager(QNetworkAccessManager *newManager);
    QString ipAddress() const;
    void setIpAddress(const QString &newIpAddress);
    qint64 portNumber() const;
    void setPortNumber(qint64 newPortNumber);

public slots:
    void get();
    void put();
    void post();
    // Connections
    void readyRead();
    void authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator);
    void encrypted(QNetworkReply *reply);
    void finished(QNetworkReply *reply);
    void preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator);
    void proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator);
    void sslErrors(QNetworkReply *reply, const QList<QSslError> &errors);

private:
    QNetworkAccessManager* m_manager = nullptr;
    QString m_ipAddress = "127.0.0.1";
    qint64 m_portNumber = 443;
    QSslConfiguration m_config;

signals:
    void complete();
    void managerChanged();
    void ipAddressChanged();
    void portNumberChanged();
};

