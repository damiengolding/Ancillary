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

#include "exec/commands.hpp"

void initArgumentParser(QCoreApplication &app, QCommandLineParser &parser);
void initArgumentOptions(QCoreApplication &app, QCommandLineParser &parser);
void processArgumentOptions(QCoreApplication &app, QCommandLineParser &parser);

QList<QCommandLineOption> commandLineOptions;

QString targetIpAddress = "";
qint64 targetPortNumber = 443;
bool writeToXml = false;
QString outputFileName = "";
QString nicForIpAddress = "";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCommandLineParser p;
    initArgumentParser(a,p);

    // CODECOMP Add logic after arguments are parsed

    return(0);
    // return(a.exec());
}

void initArgumentParser(QCoreApplication &app, QCommandLineParser &parser){
    app.setApplicationName("qsslrecon");
    app.setApplicationVersion("0.0.1");
    app.setOrganizationName("Golding's Gym");
    app.setOrganizationDomain("https://github.com/damiengolding");

    // Convenience options
    parser.addHelpOption();
    parser.addVersionOption();
    parser.setApplicationDescription("qsslrecon Queries an SSL server and examines certificate details. Can also provide details of internal networking configuration.");

    initArgumentOptions(app,parser);
    parser.process(app);
    processArgumentOptions(app, parser);
}

void initArgumentOptions(QCoreApplication &app, QCommandLineParser &parser){
    // Options
    parser.addOption({{"t","target"},"Host to query","IP Address"});
    parser.addOption({{"p","port"},"Port number [443]","int"});
    parser.addOption({{"o","output"},"Write to XML file. This is ignored operations.","file"});
    parser.addOption({{"n","nic-for-ip"},"Show the NIC associated with an IP Address","IP Address"});

    // Postitional arguments
    parser.addPositionalArgument("list-nics", "List all registered Network Interface Cards");
    parser.addPositionalArgument("list-nic-config", "Show the configuration for each registered Network Interface Card");
    parser.addPositionalArgument("list-ips", "List all addresses associated with this host");
}

void processArgumentOptions(QCoreApplication &app, QCommandLineParser &parser){

    if( parser.isSet("output") ){
        outputFileName = parser.value("output");
        if( !outputFileName.endsWith(".xml") ){
            outputFileName += ".xml";
        }
        writeToXml = true;
    }

    if( parser.isSet("nic-for-ip") ){
        nicForIpAddress = parser.value("nic-for-ip");
        showNicForIp( nicForIpAddress );
    }

    /*
        --- Process positional arguments and options with brief output first.
            Certificate interrogation switches are ignored except and treated as a separate operational entity ---
    */

    QStringList arguments = parser.positionalArguments();
    if( !arguments.empty() ){
        if( arguments.contains( "list-nics" ) ){
            showAllNics();
        }

        if( arguments.contains( "list-ips" ) ){
            showAllAddresses();
        }

        if( writeToXml ){
            writeOutput( outputFileName );
        }
        return;
    }

    /*
        --- Certificate interrogation options ---
    */

    if ( parser.isSet("target") ){
        targetIpAddress = parser.value("target");
            if( parser.isSet("port") ){
                targetPortNumber = parser.value("port").toInt();
                return;
            }
    }

    /*
       Individually:
        if(parser.isSet(<QString name|QCommandLineOption>)){
            Either get the value of an option:
                QString s = parser.value(<QString name|QCommandLineOption>);
            Or operate on a switch, e.g. parser.isSet("verbose"):
        }
       Grouped as QString names:
            for(QString n : parser.optionNames()){
                As above, but no isSet(...) test need
            }
       Grouped as QCommandLineOptions:
            for(QCommandLineOption clo : commandLineOptions ){
                As above
            }
       Manage incorrect/unrecognised/missing options:
            for( QString opt : parser.unknownOptionNames() ){
                qWarning() << ""; // recoverable error
                qCritical() << ""; // non-recoverable error, usually a system error such as read/write/execute privileges
                qFatal(""); // non-recoverable error, will exit and dump core
            }
        Poistional arguments:
            for(QString pos : parser.positionalArguments()){
                qDebug() << "[debug] Positional argument: " << pos;
            }
    */

}

