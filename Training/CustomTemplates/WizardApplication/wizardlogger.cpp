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

#include "wizardlogger.hpp"

QString WizardLogger::fileName = QDir::currentPath() % QDir::separator() % "log.txt";
bool WizardLogger::isLogging = false;
QFile WizardLogger::outFile(WizardLogger::fileName);
static const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);
WizardLogger::WizardLogger( QObject* parent) : QObject{parent}{}

void WizardLogger::install()
{
    WizardLogger::outFile.setFileName(WizardLogger::fileName);
    if( !WizardLogger::outFile.open(QIODevice::Append) ){
        qCritical() << "Unable to open log file:"<<WizardLogger::fileName<<"for QIODevice::Append";
        return;
    }
    WizardLogger::isLogging = true;
    qInstallMessageHandler(WizardLogger::messageHandler);
}

void WizardLogger::uninstall()
{
    if( WizardLogger::outFile.isOpen() ){
        WizardLogger::outFile.close();
    }
    qInstallMessageHandler(nullptr);
}

void WizardLogger::messageHandler(QtMsgType type, const QMessageLogContext &ctxt, const QString &msg)
{
    if( WizardLogger::isLogging ){
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
            if( !WizardLogger::outFile.isOpen() ){
                WizardLogger::outFile.setFileName(WizardLogger::fileName);
                WizardLogger::outFile.open(QIODevice::Append);
            }
            QTextStream ts(&WizardLogger::outFile);
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

WizardLogger::~WizardLogger(){}
