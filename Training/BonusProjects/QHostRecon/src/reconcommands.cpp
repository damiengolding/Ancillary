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
#include "../inc/reconcommands.hpp"
#include "inc/hostreconutils.hpp"

ReconCommands::ReconCommands(QObject *parent)
    : QObject{parent}
{

}

#pragma  {

ReconCommands::~ReconCommands()
{

}

void ReconCommands::showNicToIp()
{
    qInfo() << "########## IP Address to NIC  ##########";
    m_addresses = QNetworkInterface::allAddresses();
    for( auto address : m_addresses ){
            qInfo() << address.toString() << "-" << HostReconUtils::IpAddressToNicName( address.toString() );
    }
    qInfo() << "";
}

void ReconCommands::showAllNics()
{
    qInfo() << "########## Network Interface Cards ##########";
    m_interfaces = QNetworkInterface::allInterfaces();
    for( auto interface : m_interfaces ){
        const int intRepresentation = static_cast<int>(interface.type());
        QString interfaceType = QMetaEnum::fromType<QNetworkInterface::InterfaceType>().valueToKey(intRepresentation);
        QString output = QString("%1 - %2 - %3 - %4 - %5")
                .arg( interface.name() )
                .arg( interface.humanReadableName() )
                .arg( interface.hardwareAddress() )
                .arg( interfaceType )
                .arg( interface.index() );
        qInfo() << output;
    }
    qInfo() << "";
}

void ReconCommands::showAllNicsConfig()
{
        qInfo() << "########## Network Interface Cards - all config ##########";
        m_interfaces = QNetworkInterface::allInterfaces();
        for( auto interface : m_interfaces ){
            const int intType = static_cast<int>(interface.type());
            QString interfaceType = QMetaEnum::fromType<QNetworkInterface::InterfaceType>().valueToKey(intType);
            const int intFlag = static_cast<int>(interface.type());
            QString interfaceFlag = QMetaEnum::fromType<QNetworkInterface::InterfaceType>().valueToKey(intFlag);

            qInfo() << "Name:" << interface.name();
            qInfo() << "\tSystem name:" << interface.humanReadableName();
            qInfo() << "\tHardware address:" << interface.hardwareAddress();
            qInfo() << "\tType:" << interfaceType;
            qInfo() << "\tFlag:" << interfaceFlag;
            qInfo() << "\tAddress entries:";
            QList<QNetworkAddressEntry> entries = interface.addressEntries();
            for( auto entry : entries ){
                QString broadcast = entry.broadcast().toString();
                qInfo() << "------------------------------------------------------------";
                qInfo() << "\t\tAddress:" << entry.ip().toString();
                qInfo() << "\t\tNetmask:" << entry.netmask().toString();
                if( !broadcast.isEmpty() ){
                    qInfo() << "\t\tBroadcast address:" << broadcast;
                }
            }
            qInfo() << "------------------------------------------------------------";
            qInfo() << "";
        }
}

void ReconCommands::showAllAddresses()
{
    qInfo() << "########## Host Addresses ##########";
    m_addresses = QNetworkInterface::allAddresses();
    for( auto address : m_addresses ){
        QString nic = HostReconUtils::IpAddressToNicName( address.toString() );
        QString prot = address.protocol() == 0 ? "IPV4" : "IPV6";
        QString output = QString( "%1 - %2 - %3" )
                .arg( prot )
                .arg( address.toString() )
                .arg( nic );
        qInfo() << output;
    }
    qInfo() << "";
}

void ReconCommands::showDomainHostName()
{
    qInfo() << "########## Domain and hostname ##########";
    m_domainName = QHostInfo::localDomainName();
    m_hostName = QHostInfo::localHostName();
    qInfo() << "Domain name:" << m_domainName;
    qInfo() << "Host name:" << m_hostName;
    qInfo() << "";
}

#pragma Local checks }

#pragma Housekeeping {

void ReconCommands::writeOutput()
{
    if( m_writeToXml ){
        qInfo() << "Writing output to:" << m_outputFileName;
        qInfo() << "No, really . . .";
    }
}

#pragma Housekeeping }

#pragma Properties {

QString ReconCommands::domainName() const
{
    return m_domainName;
}

void ReconCommands::setDomainName(const QString &newDomainName)
{
    if (m_domainName == newDomainName)
        return;
    m_domainName = newDomainName;
    emit domainNameChanged();
}

QString ReconCommands::hostName() const
{
    return m_hostName;
}

void ReconCommands::setHostName(const QString &newHostName)
{
    if (m_hostName == newHostName)
        return;
    m_hostName = newHostName;
    emit hostNameChanged();
}

QString ReconCommands::ipAddress() const
{
    return m_ipAddress;
}

void ReconCommands::setIpAddress(const QString &newIpAddress)
{
    if (m_ipAddress == newIpAddress)
        return;
    m_ipAddress = newIpAddress;
    emit ipAddressChanged();
}

qint64 ReconCommands::portNumber() const
{
    return m_portNumber;
}

void ReconCommands::setPortNumber(qint64 newPortNumber)
{
    if (m_portNumber == newPortNumber)
        return;
    m_portNumber = newPortNumber;
    emit portNumberChanged();
}


bool ReconCommands::writeToXml() const
{
    return m_writeToXml;
}

void ReconCommands::setWriteToXml(bool newWriteToXml)
{
    if (m_writeToXml == newWriteToXml)
        return;
    m_writeToXml = newWriteToXml;
    emit writeToXmlChanged();
}

QString ReconCommands::outputFileName() const
{
    return m_outputFileName;
}

void ReconCommands::setOutputFileName(const QString &newOutputFileName)
{
    if (m_outputFileName == newOutputFileName)
        return;
    m_outputFileName = newOutputFileName;
    emit outputFileNameChanged();
}

QList<QNetworkInterface> ReconCommands::interfaces() const
{
    return m_interfaces;
}

void ReconCommands::setInterfaces(const QList<QNetworkInterface> &newInterfaces)
{
    m_interfaces = newInterfaces;
    emit interfacesChanged();
}

QList<QHostAddress> ReconCommands::addresses() const
{
    return m_addresses;
}

void ReconCommands::setAddresses(const QList<QHostAddress> &newAddresses)
{
    if (m_addresses == newAddresses)
        return;
    m_addresses = newAddresses;
    emit addressesChanged();
}

#pragma Properties }
