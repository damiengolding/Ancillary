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
#include "simplejsobject.hpp"

SimpleJSObject::SimpleJSObject(QObject *parent)
    : QObject{parent}
{

}

int SimpleJSObject::getVariable1() const
{
    return variable1;
}

void SimpleJSObject::setVariable1(int newVariable1)
{
    if (variable1 == newVariable1)
        return;
    variable1 = newVariable1;
    emit variable1Changed();
}

int SimpleJSObject::getVariable2() const
{
    return variable2;
}

void SimpleJSObject::setVariable2(int newVariable2)
{
    if (variable2 == newVariable2)
        return;
    variable2 = newVariable2;
    emit variable2Changed();
}

QString SimpleJSObject::getVariable3() const
{
    return variable3;
}

void SimpleJSObject::setVariable3(const QString &newVariable3)
{
    if (variable3 == newVariable3)
        return;
    variable3 = newVariable3;
    emit variable3Changed();
}

void SimpleJSObject::testPrint()
{
    qInfo() << "Test qInfo() from a simple JavaScript object";
    qInfo() << "Variable 1:" << variable1;
    qInfo() << "Variable 2:" << variable2;
    qInfo() << "Variable 3:" << variable3;
}
