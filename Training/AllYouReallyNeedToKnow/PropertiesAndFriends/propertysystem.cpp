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

#include "propertysystem.hpp"
#include "basicslotclass.hpp"
#include "basicsignalclass.hpp"

#include <QProperty>

    /*
            --- Built-in auto-connect ---
    */
void PropertySystem::MustAutoConnect1()
{
    // QFAIL("TDD Fail");
    BasicSlotClass* slotClass = new BasicSlotClass();
    slotClass->setObjectName("slotClass");

    BasicSignalClass* signalClass1 = new BasicSignalClass(slotClass);
    signalClass1->setObjectName("signalClass1");

    BasicSignalClass* signalClass2 = new BasicSignalClass(slotClass);
    signalClass2->setObjectName("signalClass2");

    QSignalSpy spyClass1(signalClass1, SIGNAL( initialized() ) );
    QSignalSpy spyClass2(signalClass2, SIGNAL( initialized() ) );

    QMetaObject::connectSlotsByName(slotClass);
    signalClass1->emitInitialized();
    signalClass2->initialized();

    QCOMPARE( spyClass1.count(), 1 );
    QCOMPARE( spyClass2.count(), 1 );
}

    /*
            --- Multiple auto-connect ---
    */
void PropertySystem::MustAutoConnect2()
{
    QFAIL("TDD Fail");
}

    /*
            --- Variable auto-connect ---
    */
void PropertySystem::MustAutoConnect3()
{
    QFAIL("TDD Fail");
}

    /*
            --- QList auto-connect ---
    */
void PropertySystem::MustAutoConnect4()
{
    QFAIL("TDD Fail");
}

    /*
            --- Bindable properties ---
    */
void PropertySystem::MustProvideBindableProperties()
{
    // QFAIL("TDD Fail");
    QProperty<QString> ipAddress("192.168.4.1");
    QProperty<int> portNumber(80);
    QProperty<QString> portState("open");

    QProperty<QString> serviceState;

    serviceState.setBinding([&](){
        return( ipAddress.value() + " " + QString::number(portNumber)  + " " + portState.value() );
    });

    QCOMPARE( serviceState.value(), "192.168.4.1 80 open" );

    portNumber = 81;
    portState = "closed";

    QCOMPARE( serviceState.value(), "192.168.4.1 81 closed" );
}




