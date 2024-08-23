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
#include <QDebug>
#include <QList>
#include <QByteArray>
#include <QChildEvent>
#include <QMetaObject>
#include <QMetaMethod>

/*
    --- Notes ---
    When providing arbitrary signal/slot names, use the parentheses e.g. "exit()" and "enter()".
    If the signals/slots use parameters, enter them as type name only, not variable name, and with no spaces:
    BAD:
        exit( QString myString, QString anotherString)
    GOOD:
        exit(QString,QString)
*/

class TestConnect : public QObject
{
    Q_OBJECT
public:
    static void multiConnect(QObject *sender, QObject *receiver)
    {
        if(!sender || !receiver) return;
        QList<QByteArray> senderSignals = scanType(sender,QMetaMethod::Signal);
        QList<QByteArray> receiverSlots = scanType(receiver,QMetaMethod::Slot);
        for(QByteArray signature : senderSignals){
            if(receiverSlots.contains(signature)){
                QObject::connect(sender,"2"+signature, receiver,"1"+signature, Qt::UniqueConnection);
            }
        }
    }

    static void multiConnect(const QByteArray &signal, const QByteArray &slot, QObject *sender, QObject *receiver)
    {
        if(!sender || !receiver) return;
        QList<QByteArray> senderSignals = scanType(sender,QMetaMethod::Signal);
        QList<QByteArray> receiverSlots = scanType(receiver,QMetaMethod::Slot);
        if( senderSignals.contains( signal ) && receiverSlots.contains( slot )  ){
            QObject::connect( sender, "2"+signal, receiver, "1"+slot, Qt::UniqueConnection );
        }
    }

    static void multiConnect(const QByteArray &signal, const QByteArray &slot, QList<QObject*> senders, QList<QObject*> receivers)
    {
        QList<QByteArray> senderSignals;
        QList<QByteArray> receiverSlots;
        for( auto sender : senders ){
            if( !sender ) continue;
            senderSignals = scanType(sender,QMetaMethod::Signal);
            for( auto receiver : receivers ){
                if( !receiver ) continue;
                receiverSlots = scanType(receiver,QMetaMethod::Slot);
                if( senderSignals.contains( signal ) && receiverSlots.contains( slot )  ){
                    multiConnect( signal, slot, sender, receiver );
                }
            }
        }
    }

private:
    static QList<QByteArray> scanType(QObject *object, QMetaMethod::MethodType type)
    {
        QList<QByteArray> list;
        if(!object) return list;
        const QMetaObject *mo = object->metaObject();
        if(!mo) return list;
        for(int i = mo->methodOffset(); i < mo->methodCount(); i++){
            QMetaMethod method = mo->method(i);
            if(method.methodType() == type){
                list.append(method.methodSignature());
            }
        }
        return list;
    }

};

