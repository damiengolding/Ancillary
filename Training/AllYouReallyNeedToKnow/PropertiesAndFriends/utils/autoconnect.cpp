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
#include "autoconnect.hpp"

AutoConnect::AutoConnect(QObject *parent): QObject{parent}
{

}

void AutoConnect::connect(QObject *sender, QObject *receiver)
{
    if(!sender || !receiver) return;

    QList<QByteArray> senderSignals = scanType(sender,QMetaMethod::Signal);
    QList<QByteArray> receiverSlots = scanType(receiver,QMetaMethod::Slot);
    for(QByteArray signature : senderSignals){
        if(receiverSlots.contains(signature)){
            QObject::connect(sender,"2"+signature, receiver,"1"+signature);
        }
    }
}

void AutoConnect::connect(const QByteArray &signal, const QByteArray &slot, QObject *sender, QObject *receiver)
{

}

QList<QByteArray> AutoConnect::scanType(QObject *object, QMetaMethod::MethodType type)
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
