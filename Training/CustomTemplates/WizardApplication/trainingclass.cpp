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

#include "trainingclass.hpp"

QString TrainingClass::fileName = QDir::currentPath() % QDir::separator() % "log.txt";
bool TrainingClass::isLogging = false;
QFile TrainingClass::outFile(TrainingClass::fileName);
static const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);
TrainingClass::TrainingClass( QObject* parent) : QObject{parent}{}

void TrainingClass::install()
{
    TrainingClass::outFile.setFileName(TrainingClass::fileName);
    if( !TrainingClass::outFile.open(QIODevice::Append) ){
        qCritical() << "Unable to open log file:"<<TrainingClass::fileName<<"for QIODevice::Append";
        return;
    }
    TrainingClass::isLogging = true;
    qInstallMessageHandler(TrainingClass::messageHandler);
}

void TrainingClass::uninstall()
{
    if( TrainingClass::outFile.isOpen() ){
        TrainingClass::outFile.close();
    }
    qInstallMessageHandler(nullptr);
}

void TrainingClass::messageHandler(QtMsgType type, const QMessageLogContext &ctxt, const QString &msg)
{
    if( TrainingClass::isLogging ){
        QString txt;
        switch (type){
        case QtInfoMsg:{
            txt = QString("[INFO] %1").arg(msg);
            break;
        }
        case QtDebugMsg:{
#ifdef QT_DEBUG
            txt = QString("[DEBUG] %1").arg(msg);
#endif
            break;
        }
        case QtWarningMsg:{
            txt = QString("[WARNING] %1").arg(msg);
            break;
        }
        case QtCriticalMsg:{
            txt = QString("[CRITICAL] %1").arg(msg);
            break;
        }
        case QtFatalMsg:{
            txt = QString("[FATAL] %1").arg(msg);
            break;
        }
        }
        if( !txt.isEmpty()){
            if( !TrainingClass::outFile.isOpen() ){
                TrainingClass::outFile.setFileName(TrainingClass::fileName);
                TrainingClass::outFile.open(QIODevice::Append);
            }
            QTextStream ts(&TrainingClass::outFile);
            ts << txt << " - "
               << QDateTime::currentDateTime().toString()
      #ifdef QT_DEBUG
               << " - "
               << " from file: " << ctxt.file
               << " in function: " << ctxt.function
               <<  " at line: " << ctxt.line
       #endif
                << "\r\n";
            ts.flush();
        }
        (*QT_DEFAULT_MESSAGE_HANDLER)(type,ctxt,txt);
    }
    else{
        (*QT_DEFAULT_MESSAGE_HANDLER)(type,ctxt,msg);
    }
}

TrainingClass::~TrainingClass(){}
