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

#include "wizardtest.hpp"

WizardTest::WizardTest( QObject* parent) : QObject{parent}{}
WizardTest::~WizardTest(){}

#pragma Test cases {

void WizardTest::initTestCase()
{
    testWizard = new TestWizard();
    introPage = new IntroWizardPage();
    projectPage = new ProjectWizardPage();
    confPage = new ConfirmationWizardPage();
    testWizard->addPage(introPage);
    testWizard->addPage(projectPage);
    testWizard->addPage(confPage);
    testWizard->setWindowTitle("Test GUI test wizard");
}

void WizardTest::cleanupTestCase()
{
    QString projectDirectory = QDir::homePath() % QDir::separator() % "TestDirectory";
    QDir d( projectDirectory );
    QVERIFY( d.removeRecursively() );
}

void WizardTest::MustCreateNewProject()
{
    // QFAIL("TDD fail");
    // Test the wizard pages
    QVERIFY( testWizard != nullptr );
    QVERIFY( introPage != nullptr );
    QVERIFY( projectPage != nullptr );
    QVERIFY( confPage != nullptr );

    // Grab the Ui objects
    uiTw = testWizard->getUi();
    uiIwp = introPage->getUi();
    uiPwp = projectPage->getUi();
    uiCwp = confPage->getUi();

    // Run the wizard
    testWizard->show();
    QTest::qWait(1000);

    testWizard->next();
    QTest::qWait(1000);

    uiPwp->lineEditName->setText("My test project");
    QTest::qWait(1000);

    uiPwp->comboBoxProjectType->setCurrentText("Web application");
    QTest::qWait(1000);

    QString projectDirectory = QDir::homePath() % QDir::separator() % "TestDirectory";
    uiPwp->lineEditLocation->setText( QDir::toNativeSeparators( projectDirectory ) );
    QTest::qWait(1000);

    testWizard->next();
    QTest::qWait(2000);

    testWizard->accept();

    // Now test the results of accepting the wizard
    QString newDirectory = projectDirectory % QDir::separator() % "My test project";
    QDir d( newDirectory );
    QString projectFile = newDirectory % QDir::separator() % "My test project.xml";

    QVERIFY( d.exists() );
    QVERIFY( QFile::exists( projectFile ) );
}

#pragma Test cases }

