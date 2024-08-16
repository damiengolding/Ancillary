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

class InvocableJSObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int variable4 READ getVariable4 WRITE setVariable4 NOTIFY variable4Changed FINAL)
    Q_PROPERTY(int variable5 READ getVariable5 WRITE setVariable5 NOTIFY variable5Changed FINAL)
    Q_PROPERTY(QString variable6 READ getVariable6 WRITE setVariable6 NOTIFY variable6Changed FINAL)

public:
    Q_INVOKABLE explicit InvocableJSObject(QObject *parent = nullptr);
    ~InvocableJSObject();

    int getVariable4() const;
    void setVariable4(int newVariable4);
    int getVariable5() const;
    void setVariable5(int newVariable5);
    QString getVariable6() const;
    void setVariable6(const QString &newVariable6);

public slots:
    void testPrint();

signals:
    void variable4Changed();
    void variable5Changed();
    void variable6Changed();

private:
    int variable4 = 42;
    int variable5 = 24;
    QString variable6 = "So long and thanks for all the fish";

};

