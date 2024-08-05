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

#include <QAbstractTransition>
#include <QEvent>
#pragma once

/*!
 * \brief The EnumStruct class
 */

struct EnumStruct{
    enum Events{
        EnterIdling,
        EnterOpening,
        EnterSaving,
        EnterCreating,
        EnterSleeping,
        EnterClosing
    };

};

/*!
 * \brief The EnumEvent class
 */

struct EnumEvent : public QEvent
{
    EnumEvent(EnumStruct::Events eventEnum)
    : QEvent(QEvent::Type(QEvent::User+1)),
      value(eventEnum) {}

    EnumStruct::Events value;
};

/*!
 * \brief The EnumTransition class
 */

class EnumTransition : public QAbstractTransition
{
    Q_OBJECT

public:
    EnumTransition(EnumStruct::Events eventEnum)
        : m_value(eventEnum) {}

protected:
    bool eventTest(QEvent *e) override
    {
        if (e->type() != QEvent::Type(QEvent::User+1)) // EnumEvent
            return false;
        EnumEvent *ee = static_cast<EnumEvent*>(e);
        return (m_value == ee->value);
    }

    void onTransition(QEvent *) override {}

private:
    EnumStruct::Events m_value;
};
