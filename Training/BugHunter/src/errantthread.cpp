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

#include "../inc/errantthread.hpp"

// #include <QLoggingCategory>
// Q_LOGGING_CATEGORY(TrainingThread,"Training.Thread");

ErrantThread::ErrantThread(QObject *parent): QObject{parent}
{

}

void ErrantThread::run()
{
    DataSink dataSink;
    int numThreads = 5;
    std::srand((unsigned) time(NULL));
    int errantThread = std::rand() % numThreads;

#ifdef QT_DEBUG
    qDebug() << "My errant thread will be number:" << QString::number( errantThread );
#endif

    ++BugConfig::counter;

    for( int i = 0; i < numThreads; ++i ){

#ifdef QT_DEBUG
        qDebug() << "Data sink qDebug:" << dataSink;
        // qDebug() << "Data sink debug:" << dataSink.debugState();
#endif

        QThread *ownerThread = new QThread();
        ownerThread->setObjectName("Errant thread #" % QString::number( i ) );

        DataSource *dataSource = new DataSource();
        dataSource->setObjectName("DataSource #" % QString::number( i ) );
        i == errantThread ? dataSource->setIsErrant(true) : dataSource->setIsErrant(false);
        dataSource->moveToThread(ownerThread);

        connect(dataSource, &DataSource::newData, &dataSink, &DataSink::addData, Qt::UniqueConnection);
        connect(ownerThread, &QThread::started, dataSource, &DataSource::execute, Qt::UniqueConnection);

        ownerThread->start();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DataSource::DataSource(QObject* parent){
    Q_UNUSED(parent)
    dataSink = new DataSink();
    isErrant = false;
}

void DataSource::setDataSink(DataSink *newDataSink)
{
    dataSink = newDataSink;
}

void DataSource::setIsErrant(bool newIsErrant)
{
    isErrant = newIsErrant;
}

void DataSource::execute()
{
    QThread::currentThread()->msleep(2000);
    std::srand((unsigned) time(NULL));
    int r = std::rand() % 100 + 1;
    if( isErrant ){
        dataSink->addData(r);
    }
    else{
        emit newData(r);
    }
}

void DataSink::addData(int data)
{
    dataMap.insert(sender()->objectName(), data);
}

