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
#include <QtTest>
#include <QDebug>

#include "simplesignal.hpp"
#include "simpleslot.hpp"
#include "testconnect.hpp"
#include "fakestate.hpp"

class AutoConnectClass : public QObject
{
    Q_OBJECT

public:
    AutoConnectClass();
    ~AutoConnectClass();

private slots:
    void MustAutoConnect();
    void MustAutoConnectArbitrary();
    void MustAutoConnectArbitraryListSingleParent();
    void MustAutoConnectArbitraryListMultipleParents();

};

void AutoConnectClass::MustAutoConnect()
{
    // QFAIL("TDD Fail");
    SimpleSignal* simpleSignal = new SimpleSignal();
    simpleSignal->setObjectName("simpleSignal");

    SimpleSlot* simpleSlot = new SimpleSlot();
    simpleSlot->setObjectName("simpleSlot");

    TestConnect::multiConnect(simpleSignal, simpleSlot);

    QSignalSpy spy( simpleSignal, &SimpleSignal::testing );
    simpleSignal->testing();
    QCOMPARE( spy.count(), 1 );
}

void AutoConnectClass::MustAutoConnectArbitrary()
{
    // QFAIL("TDD Fail");
    FakeState* fakeState1 = new FakeState();
    fakeState1->setObjectName("fakeState1");

    FakeState* fakeState2 = new FakeState();
    fakeState2->setObjectName("fakeState2");

    TestConnect::multiConnect( "exiting()", "enter()", fakeState1, fakeState2 );

    QSignalSpy spy( fakeState1, &FakeState::exiting );
    fakeState1->exiting();
    QCOMPARE( spy.count(), 1 );
}

void AutoConnectClass::MustAutoConnectArbitraryListSingleParent()
{
    // QFAIL("TDD Fail");
    FakeState* parent1 = new FakeState();
    parent1->setObjectName("parent1");

    FakeState* child1 = new FakeState();
    child1->setObjectName("child1");

    FakeState* child2 = new FakeState();
    child2->setObjectName("child2");

    FakeState* child3 = new FakeState();
    child3->setObjectName("child3");

    QList<QObject*> list1;
    list1 << parent1;

    QList<QObject*> list2;
    list2 << child1 << child2 << child3;

    TestConnect::multiConnect("exiting()", "enter()", list1, list2);
    parent1->exiting();
}

void AutoConnectClass::MustAutoConnectArbitraryListMultipleParents()
{
    // QFAIL("TDD Fail");
    FakeState* parent1 = new FakeState();
    parent1->setObjectName("parent1");

    FakeState* parent2 = new FakeState();
    parent2->setObjectName("parent2");

    FakeState* child1 = new FakeState();
    child1->setObjectName("child1");

    FakeState* child2 = new FakeState();
    child2->setObjectName("child2");

    FakeState* child3 = new FakeState();
    child3->setObjectName("child3");

    QList<QObject*> list1;
    list1 << parent1 << parent2;

    QList<QObject*> list2;
    list2 << child1 << child2 << child3;

    TestConnect::multiConnect("exiting()", "enter()", list1, list2);
    parent1->exiting();
    parent2->exiting();
}

AutoConnectClass::AutoConnectClass()
{

}

AutoConnectClass::~AutoConnectClass()
{

}

QTEST_APPLESS_MAIN(AutoConnectClass)

#include "tst_autoconnect.moc"
