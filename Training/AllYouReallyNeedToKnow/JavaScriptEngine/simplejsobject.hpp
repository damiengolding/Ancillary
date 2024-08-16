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

#include <QObject>
#include <QDebug>

class SimpleJSObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int variable1 READ getVariable1 WRITE setVariable1 NOTIFY variable1Changed FINAL)
    Q_PROPERTY(int variable2 READ getVariable2 WRITE setVariable2 NOTIFY variable2Changed FINAL)
    Q_PROPERTY(QString variable3 READ getVariable3 WRITE setVariable3 NOTIFY variable3Changed FINAL)

public:
    explicit SimpleJSObject(QObject *parent = nullptr);

    int getVariable1() const;
    void setVariable1(int newVariable1);
    int getVariable2() const;
    void setVariable2(int newVariable2);
    QString getVariable3() const;
    void setVariable3(const QString &newVariable3);

public slots:
void testPrint();

signals:
    void variable1Changed();
    void variable2Changed();
    void variable3Changed();

private:
    int variable1;
    int variable2;
    QString variable3;

};

