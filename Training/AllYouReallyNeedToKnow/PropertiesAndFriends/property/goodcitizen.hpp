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

class GoodCitizen : public QObject
{
    Q_OBJECT
    Q_PROPERTY(TestType testType READ testType WRITE setTestType NOTIFY testTypeChanged FINAL)
    Q_PROPERTY(TestTeam testTeam READ testTeam WRITE setTestTeam NOTIFY testTeamChanged FINAL)

public:
    explicit GoodCitizen(QObject *parent = nullptr);

    enum TestType{
        Infrastructure,
        Web,
        Wireless,
        Phishing
    };
    Q_ENUM( TestType )

    enum TestTeam{
        NoTeam = 0x0000,
        WhiteTeam = 0x0001,
        RedTeam = 0x0002,
        BlueTeam = 0x0004,
        PurpleTeam = RedTeam | BlueTeam
    };
    Q_DECLARE_FLAGS( TestTeams, TestTeam )
    Q_FLAG( TestTeams )

    TestType testType() const;
    void setTestType(TestType newTestType);
    TestTeam testTeam() const;
    void setTestTeam(TestTeam newTestTeam);

public slots:
    void doStuff();
    void doSomeStuff();
    void doMoreStuff();
    void doEvenMoreStuff();
    void doLoadsaStuff();

private:
    TestType m_testType;
    TestTeam m_testTeam;

signals:

    void testTypeChanged();
    void testTeamChanged();
};

