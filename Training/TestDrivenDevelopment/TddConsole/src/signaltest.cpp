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

#include "../inc/signaltest.hpp"
#include "../inc/signalclass.hpp"

SignalTest::SignalTest( QObject* parent) : QObject{parent}{}
SignalTest::~SignalTest(){}

#pragma Test cases {

#ifdef QT_DEBUG
// Place test case definitions here
void SignalTest::SignalTestMustHandleEnterSignals()
{
    // QFAIL("TDD fail");
    SignalClass signalClass;
    QSignalSpy spyEntering(&signalClass, SIGNAL( entering() ) );
    QSignalSpy spyEnteringEnum(&signalClass, SIGNAL( stateChanged( Qt::ApplicationState ) ) );

    signalClass.enter();

    QCOMPARE( spyEntering.count(), 1 );
    QCOMPARE( spyEnteringEnum.count(), 1 );

    QList<QVariant> arguments = spyEnteringEnum.takeFirst();

    QVERIFY( arguments.at(0).toInt() == Qt::ApplicationSuspended );
}

void SignalTest::SignalTestMustHandleRunSignals()
{
    // QFAIL("TDD fail");
    SignalClass signalClass;
    QSignalSpy spyRunning(&signalClass, SIGNAL( running() ) );
    QSignalSpy spyRunningEnum(&signalClass, SIGNAL( stateChanged( Qt::ApplicationState ) ) );

    signalClass.run();

    QCOMPARE( spyRunning.count(), 1 );
    QCOMPARE( spyRunningEnum.count(), 1 );

    QList<QVariant> arguments = spyRunningEnum.takeFirst();

    QVERIFY( arguments.at(0).toInt() == Qt::ApplicationActive );
}

void SignalTest::SignalTestMustHandleExitSignals()
{
    // QFAIL("TDD fail");
    SignalClass signalClass;
    QSignalSpy spyExiting(&signalClass, SIGNAL( exiting() ) );
    QSignalSpy spyExitingEnum(&signalClass, SIGNAL( stateChanged( Qt::ApplicationState ) ) );

    signalClass.exit();

    QCOMPARE( spyExiting.count(), 1 );
    QCOMPARE( spyExitingEnum.count(), 1 );

    QList<QVariant> arguments = spyExitingEnum.takeFirst();

    QVERIFY( arguments.at(0).toInt() == Qt::ApplicationInactive );
}

#endif

#pragma Test cases }

