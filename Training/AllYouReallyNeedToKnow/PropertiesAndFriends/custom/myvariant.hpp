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

#include <QMetaType>
#include <QDebug>

class MyVariant
{
public:
    MyVariant() = default;
    ~MyVariant() = default;
    MyVariant(const MyVariant &) = default;
    MyVariant &operator=(const MyVariant &) = default;

public:
    friend QDebug operator<<(QDebug debug, const MyVariant &c)
    {
        QDebugStateSaver saver(debug);
        debug << c.m_ipAddress << QString::number( c.m_portNumber ) << c.m_portState;
        return debug;
    }

    friend QDataStream & operator << (QDataStream &arch, const MyVariant &c )
    {
        arch << c.m_ipAddress;
        arch << c.m_portNumber;
        arch << c.m_portState;
        return arch;
    }

    friend QDataStream & operator >> (QDataStream &arch, MyVariant &c )
    {
        arch >> c.m_ipAddress;
        arch >> c.m_portNumber;
        arch >> c.m_portState;
        return arch;
    }

    QString ipAddress() const;
    void setIpAddress(const QString &newIpAddress);
    int portNumber() const;
    void setPortNumber(int newPortNumber);
    QString portState() const;
    void setPortState(const QString &newPortState);

protected:
    QString m_ipAddress;
    int m_portNumber;
    QString m_portState;
};

Q_DECLARE_METATYPE(MyVariant);
// #error "Qt custom type declared. Ensure that you are calling qRegisterMetaType<...>(); before use, then delete this error."

