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

void TddTestCase::XmlTestMustParseNmap_data()
{
    QTest::addColumn<QString>("tool");
    QTest::addColumn<QString>("file");
    QString nmapSource = QFINDTESTDATA("nmap.xml");
    QVERIFY( !nmapSource.isEmpty() );
    QTest::newRow( "nmap_data") << "nmap" << nmapSource;
}

void TddTestCase::XmlTestMustParseNmap()
{
    QFAIL("TDD fail");
    // XmlTest xmlTest;
    // QFETCH(QString,tool);
    // QFETCH(QString,file);
    // QFile nmapFile(file);
    // QVERIFY2( nmapFile.open(QIODevice::ReadOnly), qPrintable( QString("Unable to open %1 for parsing").arg(file) ) );
    // QString xmlContent = nmapFile.readAll();
    // nmapFile.close();
    // QVERIFY(xmlTest.loadNmapFromString(xmlContent));
    // QVERIFY(xmlTest.loadNmapFromFile(file));
}

void TddTestCase::XmlTestWontParseOtherXml_data()
{
    QTest::addColumn<QString>("tool");
    QTest::addColumn<QString>("file");
    QString otherSource = QFINDTESTDATA("nessus.nessus");
    QVERIFY( !otherSource.isEmpty() );
    QTest::newRow( "other_data") << "other" << otherSource;
}

void TddTestCase::XmlTestWontParseOtherXml()
{
    QFAIL("TDD fail");
    // XmlTest xmlTest;
    // QFETCH(QString,tool);
    // QFETCH(QString,file);
    // QFile otherFile(file);
    // QVERIFY2( otherFile.open(QIODevice::ReadOnly), qPrintable( QString("Unable to open %1 for parsing").arg(file) ) );
    // QString xmlContent = otherFile.readAll();
    // otherFile.close();
    // QVERIFY(xmlTest.loadNmapFromString(xmlContent) == false);
    // QVERIFY(xmlTest.loadNmapFromFile(file) == false);

    // QCOMPARE(xmlTest.loadNmapFromString(xmlContent), false );
    // QCOMPARE(xmlTest.loadNmapFromFile(file), false);

    // // QEXPECT_FAIL("", "File is nessus XML not nmap XML", Continue);
    // // QVERIFY( loadNmapFromString(xmlContent) );
    // // QEXPECT_FAIL("","File is nessus XML not  nmap XML", Continue);
    // // QCOMPARE(loadNmapFromFile(file), true);
}

void TddTestCase::XmlTestMustCountNmapHosts_data()
{
    QTest::addColumn<QString>("scan");
    QTest::addColumn<int>("hosts");
    QTest::newRow( "discworld_hosts") << "discworld" << 7;
}

void TddTestCase::XmlTestMustCountNmapHosts()
{
    QFAIL("TDD fail");
    // XmlTest xmlTest;
    // QFETCH(QString,scan);
    // QFETCH(int,hosts);
    // QCOMPARE( xmlTest.countHosts( "nmap.xml" ), hosts );
    // QVERIFY( xmlTest.countHosts( "nmap.xml" ) == hosts );
    // QVERIFY2( xmlTest.countHosts( "nmap.xml" ) == hosts, "Wrong host count" );
}
