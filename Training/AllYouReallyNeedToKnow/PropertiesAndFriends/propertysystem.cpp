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
    --- Readable enums ---
*/
void PropertySystem::MustPrintReadableEnums(){
    GoodCitizen goodCitizen;
    goodCitizen.setTestTeam( GoodCitizen::PurpleTeam );
    goodCitizen.setTestType( GoodCitizen::Wireless);

    qInfo() << "Team:" << goodCitizen.testTeam();
    qInfo() << "Type:" << goodCitizen.testType();

    GoodCitizen::TestTeam team = goodCitizen.testTeam();

    QVERIFY( team & GoodCitizen::RedTeam );
    QVERIFY( team & GoodCitizen::BlueTeam );
    QVERIFY( team == GoodCitizen::PurpleTeam  );
}

/*
    --- Dynamic properties ---
*/
void PropertySystem::MustProvideDynamicProperties()
{
    GoodCitizen goodCitizen;
    int propCount = goodCitizen.metaObject()->propertyCount();
    QCOMPARE( propCount, 3 );
    for( int i = 0; i < propCount; ++i ){
        QMetaProperty metaProp = goodCitizen.metaObject()->property(i);
        qInfo() << "Property:" << metaProp.name();
        qInfo() << "Property is an enum type:" << metaProp.isEnumType();
    }

    goodCitizen.setProperty("versNumber", "1.0.0");
    QCOMPARE( propCount, 3 );
    QList<QByteArray> dynProps = goodCitizen.dynamicPropertyNames();
    for( auto dynProp : dynProps ){
        qInfo() << "Dynamic property:" << dynProp;
        qInfo() << "Dynamic property value:" << goodCitizen.property(dynProp).toString();
    }
}

/*
        --- Bindable properties ---
*/
void PropertySystem::MustProvideBindableProperties()
{
    // QFAIL("TDD Fail");

    /*
        --- Old fashioned way ---
    */
    // QString ipAddress = "192.168.4.1";
    // int portNumber = 80;
    // QString portState = "open";
    // QString serviceState = ipAddress + " " + QString::number(portNumber)  + " " + portState;
    // QCOMPARE( serviceState, "192.168.4.1 80 open" );

    // portNumber = 81;
    // portState = "closed";
    // QCOMPARE( serviceState, "192.168.4.1 81 closed" );

    /*
        --- Bindable properties ---
    */
    QProperty<QString> ipAddress("192.168.4.1");
    QProperty<int> portNumber(80);
    QProperty<QString> portState("open");

    QProperty<QString> serviceState;
    serviceState.setBinding([&](){
        return( ipAddress.value() + " " + QString::number(portNumber)  + " " + portState.value() );
    });

    serviceState.subscribe( [&](){
        bindableCallback();
    });

    QCOMPARE( serviceState.value(), "192.168.4.1 80 open" );

    portNumber = 81;
    portState = "closed";

    QCOMPARE( serviceState.value(), "192.168.4.1 81 closed" );
}

/*
        --- Built-in auto-connect ---
*/
void PropertySystem::MustProvideAutoConnect()
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
    --- Custom types / QVariant ---
*/
void PropertySystem::MustAllowCustomQtTypes()
{
    QSettings s1("Golding's Gym","propstest");
    MyVariant myVar1;
    myVar1.setIpAddress("192.168.4.1");
    myVar1.setPortNumber(80);
    myVar1.setPortState("open");
    qDebug() << "myVar1:" << myVar1;

    QVariant qVar1 = QVariant::fromValue(myVar1);
    // qVar1.setValue(myVar1);
    s1.setValue("portscan", qVar1);

    QSettings s2("Golding's Gym","propstest");
    QVariant qVar2 = s2.value("portscan");
    MyVariant myVar2 = qvariant_cast<MyVariant>(qVar2);

    qDebug() << "myVar2:" << myVar2;
}






void PropertySystem::BenchmarkBindableProperties()
{
    QBENCHMARK_ONCE{
        QProperty<QString> ipAddress("127.0.0.1");
        QProperty<int> portNumber(-1);
        QProperty<QString> portState("indeterminate");

        QProperty<QString> serviceState;
        serviceState.setBinding([&](){
            return( ipAddress.value() + " " + QString::number(portNumber)  + " " + portState.value() );
        });

        for( int i = 0; i < 65535; ++i ){
            portNumber = i;
            portState = "closed";
        }
    }
}

void PropertySystem::BenchmarkNonBindableProperties()
{
    QBENCHMARK_ONCE{
        QString ipAddress = "127.0.0.1";
        int portNumber = -1;
        QString portState = "indeterminate";

        for( int i = 0; i < 65535; ++i ){
            portNumber = i;
            portState = "closed";
            QString serviceState = ipAddress + " " + QString::number(portNumber)  + " " + portState;
        }
    }

}


