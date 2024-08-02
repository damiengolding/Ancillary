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

#include "inc/logger.hpp"
#include "inc/xmltest.hpp"
#include "inc/benchmarktest.hpp"
#include "inc/signaltest.hpp"

void initArgumentParser(QCoreApplication &app, QCommandLineParser &parser);
void initArgumentOptions(QCoreApplication &app, QCommandLineParser &parser);
void processArgumentOptions(QCoreApplication &app, QCommandLineParser &parser);

void execTests();

QList<QCommandLineOption> commandLineOptions;
QString testsToRun;
bool runTests = false;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCommandLineParser p;
    Logger::fileName = "console_test_log.txt";
    Logger::install();

    initArgumentParser(a,p);

    if( runTests ){
        qputenv("QTEST_FUNCTION_TIMEOUT", "900000");
        execTests();
    }
    // return(a.exec());
    return(0);
}

void initArgumentParser(QCoreApplication &app, QCommandLineParser &parser){
    app.setApplicationName("Qt Essentials: Test Driven Development (Console)");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("Golding's Gym");
    app.setOrganizationDomain("https://github.com/damiengolding");
    parser.addHelpOption();
    parser.addVersionOption();
#ifdef QT_DEBUG
    parser.setApplicationDescription("tddcd Test Driven Development example - Console Application (debug)");
#else
    parser.setApplicationDescription("tddc Test Driven Development example - Console Application (release)");
#endif
    initArgumentOptions(app,parser);
    parser.process(app);
    processArgumentOptions(app, parser);
}

void initArgumentOptions(QCoreApplication &app, QCommandLineParser &parser){
#ifdef QT_DEBUG
    // parser.addOption({{"t","test"},"Tests to run","file"});
    parser.addPositionalArgument("run-test", "Runs the supported tests");
#endif
}

void processArgumentOptions(QCoreApplication &app, QCommandLineParser &parser){
    for(QString pos : parser.positionalArguments()){
        if( pos.toLower() == "run-test"  ){
#ifdef QT_DEBUG
            runTests = true;
            return;
#else
            qInfo() << "Testing is only supported in debug mode";
            parser.showHelp(1);
#endif
        }
    }
}

void execTests(){
    XmlTest xmlTest;
    BenchmarkTest benchmarkTest;
    SignalTest signalTest;
    QTest::qExec(&xmlTest);
    QTest::qExec(&benchmarkTest);
    QTest::qExec(&signalTest);
}
