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
#include "../inc/naughtyobject.hpp"
#include <QFile>

void NaughtyObject::BugNullptr(QDomDocument *doc)
{
    doc->setContent("My XML string");
}

QDomDocument* NaughtyObject::BugDataReturn()
{
    QScopedPointer<QDomDocument> doc(new QDomDocument("doc"));
    return( doc.data());
}

void NaughtyObject::BugUseBeforeNew()
{
    QDomDocument *doc;
    doc->setContent("My XML string");
}

void NaughtyObject::BugDivideByZero()
{
    int speedOfLight = 299792458;
    int badValue = speedOfLight / 0;
}

void NaughtyObject::BugOutOfRange()
{
    QList<int> intList;
    intList.fill(1,10);
    intList.count();
    int testAtIndex = 10;
    int item = intList.at(testAtIndex);
}

#pragma Simple handler {
    // if( doc ){
    //     qInfo() << "doc OK";
    //     doc->setContent("My XML string");
    // }
    // else{
    //     qInfo() << "doc nullptr";
    //     return;
    // }
#pragma Simple handler }

#pragma Debug macros {
    // Q_CHECK_PTR(doc);
    // Q_ASSERT_X( doc != nullptr, "NaughtyObject::BugNullptr(QDomDocument *doc)", "doc  == nullptr" );
    // Q_ASSERT( doc != nullptr );
#pragma Debug macros }
