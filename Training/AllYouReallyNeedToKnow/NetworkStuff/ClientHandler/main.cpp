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
#include <QCoreApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QList>
#include <QSslSocket>
#include <QSslConfiguration>
#include <QSslKey>

#include "ClientHandlerLogger.hpp"
#include "ClientHandlerConfig.hpp"

void initArgumentParser(QCoreApplication &app, QCommandLineParser &parser);
void initArgumentOptions(QCoreApplication &app, QCommandLineParser &parser);
void processArgumentOptions(QCoreApplication &app, QCommandLineParser &parser);

QList<QCommandLineOption> commandLineOptions;

QString hostName;
qint64 portNumber;

void connectToHost();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ClientHandlerLogger::fileName = "ClientHandler_log.txt";
    ClientHandlerLogger::install();

    QCommandLineParser p;
    initArgumentParser(a,p);

    // CODECOMP Add logic after arguments are parsed
    connectToHost();

    // return(0);
    return(a.exec());
}

void initArgumentParser(QCoreApplication &app, QCommandLineParser &parser){
    app.setApplicationName("client");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("Golding's Gym");
    app.setOrganizationDomain("https://github.com/damiengolding");
    // Convenience options
    parser.addHelpOption();
    parser.addVersionOption();

    parser.setApplicationDescription("myapp description");
    // Init options from here, defined separately in initArgumentOptions
    initArgumentOptions(app,parser);
    // Process the supplied arguments into the parser
    parser.process(app);
    // Process the arguments supplied to the application so we can use them
    processArgumentOptions(app, parser);
}

void initArgumentOptions(QCoreApplication &app, QCommandLineParser &parser){
        parser.addOption({{"t","target"},"IP address to connect to","string"});
        parser.addOption({{"p","port"},"Target port to connect to","qint64"});
}

void processArgumentOptions(QCoreApplication &app, QCommandLineParser &parser){
    if( parser.isSet("target")  ){
        hostName = parser.value("target");
    }
    else{
        hostName = "127.0.0.1";
    }

    if( parser.isSet("port")  ){
        portNumber = parser.value("port").toInt();
    }
    else{
        portNumber = 443;
    }

}

void connectToHost(){
    qInfo() << "Attempting to connect to" << hostName << "on port" << portNumber;
    QSslSocket* socket = new QSslSocket();
    socket->setPeerVerifyMode( QSslSocket::VerifyNone );
    socket->setProtocol( QSsl::SslProtocol::TlsV1_2);

    QSslConfiguration m_sslConfiguration = QSslConfiguration::defaultConfiguration();

    QList<QSslCertificate> cert = QSslCertificate::fromPath(":/ssl/res/SERVER-CERT.pem");
    QFile certFile( ":/ssl/res/SERVER-CERT.pem" );
    if( !certFile.open( QIODevice::ReadOnly | QIODevice::Text) ){
        qWarning() << "Couldn't open certificate file";
        return;
    }
    QFile keyFile( ":/ssl/res/SERVER-KEY.pem" );
    if( !keyFile.open( QIODevice::ReadOnly | QIODevice::Text ) ){
        qWarning() << "Couldn't open key file";
        return;
    }

    QSslKey key( keyFile.readAll(), QSsl::Rsa, QSsl::Pem);
    m_sslConfiguration.setPrivateKey( key );

    // QSslCertificate certificate;
    // certificate.fromPath( ":/ssl/res/SERVER-CERT.pem", QSsl::Pem);
    // m_sslConfiguration.setLocalCertificate( certificate );

    QList<QSslCertificate> certChain = QSslCertificate::fromPath( ":/ssl/res/SERVER-CERT.pem" );
    m_sslConfiguration.addCaCertificates( certChain );
    m_sslConfiguration.setLocalCertificate( certChain.at(0) );

    socket->setSslConfiguration( m_sslConfiguration );
    // socket->setLocalCertificate(certChain.at(0));
    // socket->setPrivateKey(key);
    socket->connectToHostEncrypted( hostName, portNumber );

    if( !socket->waitForEncrypted() ){
        qWarning() << "Socket problem (waitForEncrypted):" << socket->errorString();
        return;
    }

    QByteArray request = "Hello world";
    socket->write(request);

    if( !socket->waitForBytesWritten() ){
        qWarning() << "Socket problem (waitForBytesWritten)" << socket->errorString();
        return;
    }

    if( !socket->waitForReadyRead() ){
        qWarning() << "Socket problem (waitForReadyRead)" << socket->errorString();
        return;
    }
    qInfo() << "Read from server:" << socket->readAll();

}


