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
#include <QCoreApplication>
#include <QtGlobal>

#include "tddtestcase.hpp"

#pragma Housekeeping {

TddTestCase::TddTestCase(){}

TddTestCase::~TddTestCase(){}

void TddTestCase::initTestCase_data()
{
    QTest::addColumn<QList<int>>("ports");
    QList<int> tcpPorts;
    tcpPorts << 21
        << 22
        << 23
        << 25
        << 80
        << 135
        << 139
        << 443
        << 445
        << 666
        << 3306
        << 3389
        << 4443
        << 5985
        << 8009
        << 8020
        << 8080
        << 8081
        << 8027
        << 8080
        << 8383
        << 8484
        << 8585
        << 9200
        << 9300
        << 47001
        << 49152
        << 49153
        << 49154
        << 49155
        << 49156
        << 49161
        << 49162
        << 49250
        << 49251;
    QTest::newRow("tcp_ports") << tcpPorts;
}

#pragma Housekeeping }

QTEST_MAIN(TddTestCase)
// #include "tddtestcase.moc"
