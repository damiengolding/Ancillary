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
#pragma once

#include <QObject>
#include <QString>
#include <QMap>
#include <QThread>
#include <QThreadPool>
#include <QRunnable>
#include <QDebug>

#include "bugconfig.hpp"

class DataSource;
class DataSink;

class ErrantThread : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit ErrantThread(QObject *parent = nullptr);
    virtual ~ErrantThread() {}

public:
    void run() override;

};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class DataSink : public QObject
{
    Q_OBJECT
public:
    explicit DataSink(QObject* parent = nullptr) {}
    virtual ~DataSink() {}

    // QString debugState(){
    //     return( "Debug output: "% QString::number( dataMap.count() ) );
    // }

private:
    QMap<QString,int> dataMap;

public:
    friend QDebug operator<<(QDebug debug, const DataSink& c)
    {
        QDebugStateSaver saver(debug);
        debug.nospace() << "Debug output: "<< QString::number( c.dataMap.count() );
        return debug;
    }

public slots:
    void addData(int data);

};

class DataSource : public QObject
{
    Q_OBJECT
public:
    explicit DataSource(QObject* parent = nullptr);
    virtual ~DataSource() {}

    void setDataSink(DataSink *newDataSink);
    void setIsErrant(bool newIsErrant);

public slots:
    void execute();

private:
    DataSink *dataSink;
    bool isErrant;

signals:
    void newData( int );

};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
