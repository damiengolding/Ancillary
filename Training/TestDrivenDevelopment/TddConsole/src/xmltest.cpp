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

#include "../inc/xmltest.hpp"

XmlTest::XmlTest( QObject* parent) : QObject{parent}{}
XmlTest::~XmlTest(){}

#pragma  Functions to test{

bool XmlTest::loadNmapFromFile(const QString &fileName)
{
    QScopedPointer<QFile> file( new QFile(fileName) );
    QScopedPointer<QDomDocument> doc(new QDomDocument("doc"));

    if( file->open(QIODevice::ReadOnly) ){
        fileOpened = true;
    }else{
        return(false);
    }

    if( doc->setContent(file->readAll()) ){
        contentLoaded = true;
    }else{
        return(false);
    }
    QDomElement rootElem = doc->documentElement();
    if( rootElem.hasAttribute("scanner") ){
        if( rootElem.attribute("scanner").toLower() == "nmap" ){
            correctXml = true;
        }else{
            return(false);
        }
    }
    else{
        return(false);
    }
    return(true);
}

bool XmlTest::loadNmapFromString(const QString &xmlString)
{
    QScopedPointer<QDomDocument> doc(new QDomDocument("doc"));
    fileOpened = true;

    if( doc->setContent(xmlString) ){
        contentLoaded = true;
    }else{
        return(false);
    }
    QDomElement rootElem = doc->documentElement();
    if( rootElem.hasAttribute("scanner") ){
        if( rootElem.attribute("scanner").toLower() == "nmap" ){
            correctXml = true;
        }else{
            return(false);
        }
    }
    else{
        return(false);
    }
    return(true);
}

int XmlTest::countHosts(const QString &xmlFile)
{
    int ret = 0;

    QScopedPointer<QFile> file( new QFile(xmlFile) );
    QScopedPointer<QDomDocument> doc(new QDomDocument("doc"));

    if( file->open(QIODevice::ReadOnly) ){
        fileOpened = true;
    }else{
        return(ret);
    }

    if( doc->setContent(file->readAll()) ){
        contentLoaded = true;
    }else{
        return(ret);
    }

    QDomNodeList nodeList = doc->elementsByTagName("host");

    return(nodeList.count());
}

#pragma Functions to test }

#pragma Test cases {

#ifdef QT_DEBUG
// Place test case definitions here

void XmlTest::XmlTestMustParseNmap_data()
{
    QTest::addColumn<QString>("tool");
    QTest::addColumn<QString>("file");
    QString nmapSource = QFINDTESTDATA("nmap.xml");
    QVERIFY( !nmapSource.isEmpty() );
    QTest::newRow( "nmap_data") << "nmap" << nmapSource;
}

void XmlTest::XmlTestMustParseNmap()
{
    // QFAIL("TDD fail");
    QFETCH(QString,tool);
    QFETCH(QString,file);
    QFile nmapFile(file);
    QVERIFY2( nmapFile.open(QIODevice::ReadOnly), qPrintable( QString("Unable to open %1 for parsing").arg(file) ) );
    QString xmlContent = nmapFile.readAll();
    nmapFile.close();
    QVERIFY(loadNmapFromString(xmlContent));
    QVERIFY(loadNmapFromFile(file));
}

void XmlTest::XmlTestWontParseOtherXml_data()
{
    QTest::addColumn<QString>("tool");
    QTest::addColumn<QString>("file");
    QString otherSource = QFINDTESTDATA("nessus.nessus");
    QVERIFY( !otherSource.isEmpty() );
    QTest::newRow( "other_data") << "other" << otherSource;
}

void XmlTest::XmlTestWontParseOtherXml()
{
    // QFAIL("TDD fail");
    QFETCH(QString,tool);
    QFETCH(QString,file);
    QFile otherFile(file);
    QVERIFY2( otherFile.open(QIODevice::ReadOnly), qPrintable( QString("Unable to open %1 for parsing").arg(file) ) );
    QString xmlContent = otherFile.readAll();
    otherFile.close();
    // QVERIFY(loadNmapFromString(xmlContent) == false);
    // QVERIFY(loadNmapFromFile(file) == false);

    // QCOMPARE( loadNmapFromString(xmlContent), false );
    // QCOMPARE(loadNmapFromFile(file), false);

    QEXPECT_FAIL("", "File is nessus XML not nmap XML", Continue);
    QVERIFY( loadNmapFromString(xmlContent) );
    QEXPECT_FAIL("","File is nessus XML not  nmap XML", Continue);
    QCOMPARE(loadNmapFromFile(file), true);
}

void XmlTest::XmlTestMustCountNmapHosts_data()
{
    QTest::addColumn<QString>("scan");
    QTest::addColumn<int>("hosts");
    QTest::newRow( "discworld_hosts") << "discworld" << 7;
}

void XmlTest::XmlTestMustCountNmapHosts()
{
    // QFAIL("TDD fail");
    QFETCH(QString,scan);
    QFETCH(int,hosts);
    QCOMPARE( countHosts( "nmap.xml" ), hosts );
    QVERIFY( countHosts( "nmap.xml" ) == hosts );
    QVERIFY2( countHosts( "nmap.xml" ) == hosts, "Wrong host count" );
}

#endif

#pragma Test cases }

