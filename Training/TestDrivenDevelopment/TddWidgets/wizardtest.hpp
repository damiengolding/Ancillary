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
#include <QTest>

#include "wizard/testwizard.hpp"
#include "wizard/introwizardpage.hpp"
#include "wizard/projectwizardpage.hpp"
#include "wizard/confirmationwizardpage.hpp"

#include "ui_mainwindow.h"
#include "ui_preferencesdialog.h"
#include "ui_projectwizardpage.h"

class WizardTest : public QObject
{
    Q_OBJECT
public:
    explicit WizardTest(QObject *parent = nullptr);
    ~WizardTest();

    friend QDebug operator<<(QDebug debug, const WizardTest &c)
    {
        QDebugStateSaver saver(debug);
        debug.nospace() << "";
        return debug;
    }

    Ui::MainWindow *uiMw;

private:
    // Wizard and pages
    TestWizard* testWizard;
    IntroWizardPage* introPage;
    ProjectWizardPage* projectPage;
    ConfirmationWizardPage* confPage;

    // Ui objects
    Ui::TestWizard *uiTw;
    Ui::IntroWizardPage *uiIwp;
    Ui::ProjectWizardPage *uiPwp;
    Ui::ConfirmationWizardPage *uiCwp;

private slots: // for QTest module
    void initTestCase();
    void cleanupTestCase();
    void MustCreateNewProject();

};
