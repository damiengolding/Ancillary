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

#include "commands.hpp"
#include "../utils/netutils.hpp"

/*
    --- Internal variables for XML output ---
*/
QList<QNetworkInterface> interfaces;
QList<QHostAddress> addresses;

void showNicForIp(const QString &ipAddress)
{
    qInfo().noquote() << IpAddressToNicName( ipAddress );
}

void showAllNics()
{
    qInfo() << "########## Network Interface Cards ##########";
    interfaces = QNetworkInterface::allInterfaces();
    for( auto interface : interfaces ){
        QString interfaceType = StringFromEnum<QNetworkInterface::InterfaceType>(interface.type());
        QString output = QString("%1 - %2 - %3 - %4 - %5")
                .arg( interface.name() )
                .arg( interface.humanReadableName() )
                .arg( interface.hardwareAddress() )
                .arg( interfaceType )
                .arg( interface.index() );
        qInfo().noquote() << output;
    }
    qInfo() << "";
}

void showAllAddresses()
{
    qInfo() << "########## Host Addresses ##########";
    addresses = QNetworkInterface::allAddresses();
    for( auto address : addresses ){
        QString nic = IpAddressToNicName( address.toString() );
        QString prot = address.protocol() == 0 ? "IPV4" : "IPV6";
        QString output = QString( "%1 - %2 - %3" )
                .arg( prot )
                .arg( address.toString() )
                .arg( nic );
        qInfo().noquote() << output;
    }
    qInfo() << "";
}

/*
    --- Admin ---
*/
void writeOutput(const QString &outputFile)
{
    qInfo() << "Writing output to:" << outputFile;
    qInfo() << "No, really . . .";
}

