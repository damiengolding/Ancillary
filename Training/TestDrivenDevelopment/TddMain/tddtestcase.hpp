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

#include <QTest>
#include <QSignalSpy>
#include <QDomDocument>

#include "xmltest.hpp"
#include "benchmarktest.hpp"
#include "signalclass.hpp"
#include "signaltest.hpp"
#include "clientsocket.hpp"

class TddTestCase : public QObject
{
    Q_OBJECT

public:
    TddTestCase();
    ~TddTestCase();

private slots:
#pragma Housekeeping {
    void initTestCase_data();
    // void initTestCase();
    // void cleanupTestCase();
#pragma Housekeeping }

#pragma XmlTest {
    void XmlTestMustParseNmap_data();
    void XmlTestMustParseNmap();
    void XmlTestMustCountNmapHosts_data();
    void XmlTestMustCountNmapHosts();
    void XmlTestWontParseOtherXml_data();
    void XmlTestWontParseOtherXml();
#pragma XmlTest }

#pragma BenchmarkTest {
    void NetworkTestAllPortsMustBeReallyFast();
    void NetworkTestSelectedPortsMustBeReallyFast();
#pragma BenchmarkTest }

#pragma SignalTest {
    void SignalTestMustHandleEnterSignals();
    void SignalTestMustHandleRunSignals();
    void SignalTestMustHandleExitSignals();
#pragma SignalTest }
};


