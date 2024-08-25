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
#include <QNetworkInterface>

#include "ServerHandlerLogger.hpp"
#include "ServerHandlerConfig.hpp"

#include "netutils.hpp"
#include "sslserver.hpp"

void initArgumentParser(QCoreApplication &app, QCommandLineParser &parser);
void initArgumentOptions(QCoreApplication &app, QCommandLineParser &parser);
void processArgumentOptions(QCoreApplication &app, QCommandLineParser &parser);

QList<QCommandLineOption> commandLineOptions;

QString interfaceName = "any";
qint64 portNumber = 443;

    /*
        --- Notes ---
        openssl req -x509 -out SERVER-CERT.pem -subj "/CN=acme.com" -nodes -newkey rsa:1024 -keyout SERVER-KEY.pem
    */

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ServerHandlerLogger::fileName = "serverhandlerlog.txt";
    ServerHandlerLogger::install();

    qInfo() << "TLS Backend:" << QSslSocket::activeBackend();
    for( auto backend : QSslSocket::availableBackends() ){
        qInfo() << "Available backend:" << backend;
    }
    ServerHandlerConfig::certificateFile = ":/ssl/res/SERVER-CERT.pem";
    ServerHandlerConfig::keyFile = ":/ssl/res/SERVER-KEY.pem";
    ServerHandlerConfig::sslProtocol =  QSsl::SslProtocol::TlsV1_3;

    QCommandLineParser p;
    initArgumentParser(a,p);

    // CODECOMP Add logic after arguments are parsed
    SslServer server;
    server.listen(QHostAddress::Any, 443);

    // return(0);
    return(a.exec());
}

void initArgumentParser(QCoreApplication &app, QCommandLineParser &parser){
    app.setApplicationName("server");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("Golding's Gym");
    app.setOrganizationDomain("https://github.com/damiengolding");
    // Convenience options
    parser.addHelpOption();
    parser.addVersionOption();

    parser.setApplicationDescription("server Test server: TLS/TCP");
    // Init options from here, defined separately in initArgumentOptions
    initArgumentOptions(app,parser);
    // Process the supplied arguments into the parser
    parser.process(app);
    // Process the arguments supplied to the application so we can use them
    processArgumentOptions(app, parser);
}

void initArgumentOptions(QCoreApplication &app, QCommandLineParser &parser){
    parser.addPositionalArgument("list-interfaces", "List available NICs");
    parser.addPositionalArgument("list-ipv4-addresses", "List IP V4 Addresses");
    parser.addPositionalArgument("list-ipv6-addresses", "List IP V6 Addresses");

    parser.addOption({{"p","port"},"Port to listen on","0-65535 [443]"});
    parser.addOption({{"i","interface"},"Interface to listen on (optional)","NIC [any]"});
}

void processArgumentOptions(QCoreApplication &app, QCommandLineParser &parser){
    for(QString pos : parser.positionalArguments()){
        if( pos.toLower() == "list-interfaces"  ){
            QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
            for( auto interface : interfaces ){
                qInfo() << interface.name() << "-" << interface.hardwareAddress() << "-" << interface.humanReadableName();
            }
            return;
        }
        else if( pos.toLower() == "list-ipv4-addresses"  ){
            QList<QHostAddress> addresses = QNetworkInterface::allAddresses();
            for( auto address : addresses ){
                if( address.protocol() == 0 ){
                    QString ipAddress = address.toString();
                    QString nicName = IpAddressToNicName(ipAddress);
                    qInfo() << ipAddress << "-" << nicName;
                }
            }
            return;
        }
        else if( pos.toLower() == "list-ipv6-addresses"  ){
            QList<QHostAddress> addresses = QNetworkInterface::allAddresses();
            for( auto address : addresses ){
                if( address.protocol() == 1 ){
                    QString ipAddress = address.toString();
                    QString nicName = IpAddressToNicName(ipAddress);
                    qInfo() << ipAddress << "-" << nicName;
                }
            }
            return;
        }
    }

    if( parser.isSet("port") ){
        portNumber = parser.value("port").toInt();
    }
    else{
        portNumber = 443;
    }

    if( parser.isSet("interface")  ){
        interfaceName = parser.value("interface");
    }
    else{
        interfaceName = "any";
    }
    qInfo() << "Port set to:" << portNumber;
    qInfo() << "Interface set to:" << interfaceName;
}

