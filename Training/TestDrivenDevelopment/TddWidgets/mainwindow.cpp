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
#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "widgetstest.hpp"
#include "preferencestest.hpp"
#include "wizardtest.hpp"

#include "wizard/testwizard.hpp"
#include "wizard/introwizardpage.hpp"
#include "wizard/projectwizardpage.hpp"
#include "wizard/confirmationwizardpage.hpp"

#include "dialog/preferencesdialog.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Housekeeping
    connect( ui->actionExit, &QAction::triggered, this, &MainWindow::exit );
    connect( ui->actionAbout, &QAction::triggered, this, &MainWindow::about );
    connect( ui->actionAboutQt, &QAction::triggered, this, &MainWindow::aboutQt );
    connect( ui->actionPreferencesDialog, &QAction::triggered, this, &MainWindow::preferences );
    connect( ui->actionNewProject, &QAction::triggered, this, &MainWindow::wizard);

    // QTest stuff
    connect( ui->actionWidgets, &QAction::triggered, this, &MainWindow::testWidgets );
    connect( ui->actionWizard, &QAction::triggered, this, &MainWindow::testWizard );
    connect( ui->actionPreferences, &QAction::triggered, this, &MainWindow::testPreferences );
}

#pragma Housekeeping {
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exit()
{
    QCoreApplication::exit();
}

void MainWindow::about()
{
    QMessageBox::information(this,"About widget app test",
                             "Author: Damien Golding\r"
                             "License: MIT\r"
                             "Date: July 2024\r"
                             );
}

void MainWindow::preferences()
{
    PreferencesDialog* pd = new PreferencesDialog();
    pd->setWindowIcon(this->windowIcon());
    pd->setWindowTitle("Real preferences dialog");
    pd->exec();
}

void MainWindow::wizard()
{
    TestWizard testWizard;
    testWizard.setWindowTitle("Real GUI test wizard");
    IntroWizardPage introPage;
    testWizard.addPage(&introPage);
    testWizard.addPage(new ProjectWizardPage());
    testWizard.addPage(new ConfirmationWizardPage());
    testWizard.exec();
}

void MainWindow::aboutQt()
{
    QApplication::aboutQt();
}
#pragma Housekeeping }

#pragma QTest stuff {

void MainWindow::testWidgets()
{
    WidgetsTest widgetsTest;
    widgetsTest.ui = this->ui;
    QTest::qExec(&widgetsTest);
}

void MainWindow::testPreferences()
{
    PreferencesTest preferencesTest;
    preferencesTest.uiMw = this->ui;
    QTest::qExec(&preferencesTest);
}

void MainWindow::testWizard()
{
    WizardTest wizardTest;
    wizardTest.uiMw = this->ui;
    QTest::qExec(&wizardTest);
}

#pragma QTest stuff }
