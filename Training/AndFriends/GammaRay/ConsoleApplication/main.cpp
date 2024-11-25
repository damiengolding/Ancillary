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

#include "ConsoleApplicationLogger.hpp"
#include "ConsoleApplicationConfig.hpp"

void initArgumentParser(QCoreApplication &app, QCommandLineParser &parser);
void initArgumentOptions(QCoreApplication &app, QCommandLineParser &parser);
void processArgumentOptions(QCoreApplication &app, QCommandLineParser &parser);

QList<QCommandLineOption> commandLineOptions;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ConsoleApplicationLogger::fileName = "ConsoleApplication_log.txt";
    ConsoleApplicationLogger::install();

    QCommandLineParser p;
    initArgumentParser(a,p);

    // CODECOMP Add logic after arguments are parsed

    return(0);
    // return(a.exec());
}

void initArgumentParser(QCoreApplication &app, QCommandLineParser &parser){
    // CODECOMP Application name
    app.setApplicationName("name");
    // CODECOMP Application version
    app.setApplicationVersion("0.0.1");
    // CODECOMP Organization name
    app.setOrganizationName("Golding's Gym");
    // CODECOMP Organization domain (web presence)
    app.setOrganizationDomain("https://github.com/damiengolding");
    // Convenience options
    parser.addHelpOption();
    parser.addVersionOption();
    // CODECOMP Application description
    parser.setApplicationDescription("myapp description");
    // Init options from here, defined separately in initArgumentOptions
    initArgumentOptions(app,parser);
    // Process the supplied arguments into the parser
    parser.process(app);
    // Process the arguments supplied to the application so we can use them
    processArgumentOptions(app, parser);
}

void initArgumentOptions(QCoreApplication &app, QCommandLineParser &parser){
    // CODECOMP Add options
    /*
        Various ways to create options:
            Simplest:
                parser.addOption({{"o","output"},"Write to file","file"});
            Create a list:
                QList<QCommandLineOption> commandLineOptions;
                QCommandLineOption op1("short name","description","long name");
                parser.addOption(op1);
                commandLineOptions.append(op1);
        Positional arguments
            parser.addPositionalArgument("list-types", "List supported types");
    */

}

void processArgumentOptions(QCoreApplication &app, QCommandLineParser &parser){
    // CODECOMP Process supplied options
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

