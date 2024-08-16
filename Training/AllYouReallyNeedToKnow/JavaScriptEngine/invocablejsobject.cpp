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
#include "invocablejsobject.hpp"

InvocableJSObject::InvocableJSObject(QObject *parent)
    : QObject{parent}
{
    qInfo() << "InvocableJSObject constructor";
}

InvocableJSObject::~InvocableJSObject(){
    qInfo() << "InvocableJSObject destructor";
}

int InvocableJSObject::getVariable4() const
{
    return variable4;
}

void InvocableJSObject::setVariable4(int newVariable4)
{
    if (variable4 == newVariable4)
        return;
    variable4 = newVariable4;
    emit variable4Changed();
}

int InvocableJSObject::getVariable5() const
{
    return variable5;
}

void InvocableJSObject::setVariable5(int newVariable5)
{
    if (variable5 == newVariable5)
        return;
    variable5 = newVariable5;
    emit variable5Changed();
}

QString InvocableJSObject::getVariable6() const
{
    return variable6;
}

void InvocableJSObject::setVariable6(const QString &newVariable6)
{
    if (variable6 == newVariable6)
        return;
    variable6 = newVariable6;
    emit variable6Changed();
}

void InvocableJSObject::testPrint()
{
    qInfo() << "Test qInfo() from an invocable JavaScript object";
    qInfo() << "Variable 4:" << variable4;
    qInfo() << "Variable 5:" << variable5;
    qInfo() << "Variable 6:" << variable6;
}

