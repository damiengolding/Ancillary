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

#include "tddtestcase.hpp"

void TddTestCase::NetworkTestAllPortsMustBeReallyFast()
{
    QFAIL("TDD fail");
    // BenchmarkTest benchmarkTest;
    // QSKIP("Won't complete - needs threading to avoid a timeout");
    // QBENCHMARK{
    //     benchmarkTest.enumerateTcpPortRange("192.168.4.36", 1, 65535);
    // }

    // // QBENCHMARK_ONCE{
    // //     benchmarkTest.enumerateTcpPortRange("192.168.4.36", 1, 65535);
    // // }

    // // qDebug() << "Open ports (all ports):" << benchmarkTest.numOpenPorts;
    // // qDebug() << "Closed ports (all ports):" << benchmarkTest.numClosedPorts;
}

void TddTestCase::NetworkTestSelectedPortsMustBeReallyFast()
{
    QFAIL("TDD fail");
    // BenchmarkTest benchmarkTest;
    // QFETCH_GLOBAL( QList<int>, ports );
    // QSKIP("Won't complete - needs threading to avoid a timeout");
    // // QBENCHMARK{
    // //     benchmarkTest.enumerateTcpPortList("192.168.4.36", ports);
    // // }

    // QBENCHMARK_ONCE{
    //     benchmarkTest.enumerateTcpPortList("192.168.4.36", ports);
    // }

    // // qDebug() << "Open ports (selected):" << benchmarkTest.numOpenPorts;
    // // qDebug() << "Closed ports selected):" << benchmarkTest.numClosedPorts;
}

