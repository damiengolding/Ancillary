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
#include <QLibrary>

#include "mousetraplogger.hpp"
#include "mousetrapconfig.hpp"

void initArgumentParser(QCoreApplication &app, QCommandLineParser &parser);
void initArgumentOptions(QCoreApplication &app, QCommandLineParser &parser);
void processArgumentOptions(QCoreApplication &app, QCommandLineParser &parser);

void rundllFunc();
QString libraryPath;
QString functionDefinition;
QStringList argList;

QList<QCommandLineOption> commandLineOptions;

typedef void (*LibFunc)(QStringList);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // MouseTrapLogger::fileName = "log.txt";
    // MouseTrapLogger::install();

    QCommandLineParser p;
    initArgumentParser(a,p);

    // CODECOMP Add logic after arguments are parsed
    rundllFunc();

    return(0);
    // return(a.exec());
}

void initArgumentParser(QCoreApplication &app, QCommandLineParser &parser){
    app.setApplicationName("mousetrap");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("Golding's Gym");
    app.setOrganizationDomain("https://github.com/damiengolding");
    // Convenience options
    parser.addHelpOption();
    parser.addVersionOption();

    parser.setApplicationDescription("moustrap demonstrates a modern version of rundll32.exe");
    // Init options from here, defined separately in initArgumentOptions
    initArgumentOptions(app,parser);
    // Process the supplied arguments into the parser
    parser.process(app);
    // Process the arguments supplied to the application so we can use them
    processArgumentOptions(app, parser);
}

void initArgumentOptions(QCoreApplication &app, QCommandLineParser &parser){
    parser.addOption({{"d","dll"},"The dll to load","file"});
    parser.addOption({{"f","func"},"The function name to call","string"});
    parser.addOption({{"a","args"},"A semi-colon delimited string containing any arguments required by the function","string"});
}

void processArgumentOptions(QCoreApplication &app, QCommandLineParser &parser){
    if( parser.isSet("dll") ){
        libraryPath = parser.value("dll");
    }
    else{
        parser.showHelp(1);
    }

    if( parser.isSet("func") ){
        functionDefinition = parser.value("func");
    }
    else{
        parser.showHelp(1);
    }

    if( parser.isSet("args") ){
        argList = parser.value("args").split(";");
    }
    else{
        parser.showHelp(1);
    }

}

void rundllFunc()
{
    if( !QFile::exists(libraryPath) ){
        qWarning() << "Library cannot be found";
        return;
    }
    qInfo() << "Loading library:" << libraryPath;
    QScopedPointer<QLibrary> lib( new QLibrary() );

    lib->setFileName(libraryPath);
    lib->setLoadHints(QLibrary::ResolveAllSymbolsHint);

    if(!lib->load())
    {
        qWarning() << "Failed to load library:" << libraryPath << "Error:" << lib->errorString();
        return;
    }

    LibFunc func = (LibFunc)lib->resolve( qPrintable( functionDefinition ) );
    if( !func ){
        qWarning() << "Function" << qPrintable( functionDefinition ) << "could not be resolved" << lib->errorString();
    }
    func( argList );
    qInfo() << "Exiting mousetrap";
    lib->unload();
}

