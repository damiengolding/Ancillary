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
#include <QCoreApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QList>
#include <QDomDocument>
#include <QFile>
#include <cstdlib>

#include "inc/bugs.hpp"
#include "inc/bugconfig.hpp"

int bugIndex = -1;
bool randomSelection = false;
QStringList bugs;

void initArgumentParser(QCoreApplication &app, QCommandLineParser &parser);
void initArgumentOptions(QCoreApplication &app, QCommandLineParser &parser);
void processArgumentOptions(QCoreApplication &app, QCommandLineParser &parser);

QList<QCommandLineOption> commandLineOptions;

void createBugs();
int getRandom();
void showBugs();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    createBugs();
    QCommandLineParser p;
    initArgumentParser(a,p);
    if( bugIndex == -1 ) return(0);

    // Set bugIndex in the global config
    ++BugConfig::counter;

    // Crash the app
    crash_app(bugIndex);

    return(a.exec());
}

void initArgumentParser(QCoreApplication &app, QCommandLineParser &parser){
    app.setApplicationName("BugHunter");
    app.setApplicationVersion("0.0.1");
    app.setOrganizationName("Golding's Gym");
    app.setOrganizationDomain("https://github.com/damiengolding");
    // Convenience options
    parser.addHelpOption();
    parser.addVersionOption();

    parser.setApplicationDescription("BugHunter Selects from a number of operations, each of which will cause the software to crash. If no bug index is provided, the defect is selected randomly.\r\nThis is an exercise for debugging.");
    initArgumentOptions(app,parser);
    parser.process(app);
    processArgumentOptions(app, parser);
}

void initArgumentOptions(QCoreApplication &app, QCommandLineParser &parser){
    parser.addOption({{"i","index"},"Index number of the defect to cause. use --show-bugs to list. If absent, a random bug is selected","int"});
    parser.addPositionalArgument("show-bugs", "List bugs");
}

void processArgumentOptions(QCoreApplication &app, QCommandLineParser &parser){
    for( QString pos : parser.positionalArguments() ){
        if( pos == "show-bugs" ){
            showBugs();
            return;
        }
    }

    if( parser.isSet("index")  ){
        bool ok;
        int index = parser.value("index").toInt(&ok);
        if( !ok || index > bugs.count() ){
            qInfo() << "Supplied bug index" << "index is invalid, using a random selection";
            randomSelection = true;
            bugIndex = getRandom();
        }
        else{
            qInfo() << "Using bug number: " << index <<"(" << bugs.at(index-1) << ")" ;
            bugIndex = index;
        }
    }
    else{
        randomSelection = true;
        bugIndex = getRandom();
    }
}

void createBugs(){
    ++BugConfig::counter;
    bugs.append("nullptr");
    bugs.append("QScopedPointer data return");
    bugs.append("Use before new");
    bugs.append("Divide by zero");
    bugs.append("Out of range");
    bugs.append("Defective thread");
    // bugs.append("");
}

int getRandom(){
    std::srand((unsigned) time(NULL));
    int r = std::rand() % bugs.count() + 1;
    qInfo() << "Random selection:"  << r <<"(" << bugs.at(r-1) << ")" ;
    return(r);
}

void showBugs(){
    qInfo() << "Currently available bugs:";
    int i = 1;
    for(auto bug : bugs ){
        qInfo() << "\t" << i << ". " << bug ;
        ++i;
    }
}

void crash_app(int index){
     ++BugConfig::counter;
    BugConfig::bugIndex = index;
    qInfo() << "Crashing app: "<<bugs.at(index-1);
    switch (index) {
    case 1:{
        CrashNullptr();
        break;
    }
    case 2:{
        CrashDataReturn();
        break;
    }
    case 3:{
        CrashUseBeforeNew();
        break;
    }
    case 4:{
        CrashDivideByZero();
        break;
    }
    case 5:{
        CrashOutOfRange();
        break;
    }
    case 6:{
        CrashDefectiveThread();
        break;
    }
    default:{
        CrashNullptr();
        break;
    }
    }
}
