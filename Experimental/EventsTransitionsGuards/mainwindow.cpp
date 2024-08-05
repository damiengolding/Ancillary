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

#include <QThread>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readSettings();
    initStateMachine();
    m_statemachine->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readSettings(){
    QSettings settings;
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
}

void MainWindow::initStateMachine()
{
    m_statemachine = new QStateMachine(this);
    idle = new QState();
    opening = new QState();
    saving = new QState();
    creating = new QState();
    sleeping = new QState();
    closing = new QState();
    done = new QFinalState();

    m_statemachine->addState(idle);
    m_statemachine->addState(opening);
    m_statemachine->addState(saving);
    m_statemachine->addState(creating);
    m_statemachine->addState(sleeping);
    m_statemachine->addState(closing);
    m_statemachine->addState(done);

    m_statemachine->setInitialState(idle);

    // Ad-hoc transition objects
    toIdle = new EnumTransition(EnumStruct::EnterIdling);
    toOpening = new EnumTransition(EnumStruct::EnterOpening);
    toSaving = new EnumTransition(EnumStruct::EnterSaving);
    toCreating = new EnumTransition(EnumStruct::EnterCreating);
    toSleeping = new EnumTransition(EnumStruct::EnterSleeping);
    toClosing = new EnumTransition(EnumStruct::EnterClosing);

    // Transitions
    toIdle->setTargetState(idle);

    toOpening->setTargetState(opening);
    // opening->addTransition(toIdle);

    toSaving->setTargetState(saving);
    // saving->addTransition(toIdle);

    toCreating->setTargetState(creating);
    // creating->addTransition(toIdle);

    toSleeping->setTargetState(sleeping);
    // sleeping->addTransition(toIdle);

    toClosing->setTargetState(closing);
    // closing->addTransition(toIdle);

    idle->addTransition(toSaving);
    idle->addTransition(toOpening);
    idle->addTransition(toCreating);
    idle->addTransition(toSleeping);
    idle->addTransition(toClosing);

    // Properties
    idle->assignProperty(ui->label, "text", "In idle state");
    idle->assignProperty(ui->menubar, "enabled", true);
    idle->assignProperty(ui->toolBar, "enabled", true);

    opening->assignProperty(ui->label, "text", "In opening state");
    saving->assignProperty(ui->label, "text", "In saving state");
    creating->assignProperty(ui->label ,"text", "In creating state");
    closing->assignProperty(ui->label ,"text", "In closing state");

    sleeping->assignProperty(ui->label, "text", "In sleeping state");
    sleeping->assignProperty(ui->menubar, "enabled", false);
    sleeping->assignProperty(ui->toolBar, "enabled", false);
}

void MainWindow::on_actionSleepTest_triggered()
{
    sleeping->addTransition(toIdle);
    ui->statusbar->showMessage("Starting state test",5000);
    m_statemachine->postEvent( new EnumEvent( EnumStruct::EnterSleeping) );
    QTimer::singleShot(5000, this, &MainWindow::onSleepingStateExited);
}

void MainWindow::onSleepingStateExited(){
    m_statemachine->postEvent( new EnumEvent( EnumStruct::EnterIdling) );
    ui->statusbar->showMessage("End of state test",2000);
}

void MainWindow::on_actionOpen_triggered()
{
    opening->addTransition(toIdle);
    m_statemachine->postEvent( new EnumEvent( EnumStruct::EnterOpening) );
    QString filePath = QFileDialog::getOpenFileName(this, "open a file");
    m_statemachine->postEvent( new EnumEvent( EnumStruct::EnterIdling) );
}

void MainWindow::on_actionNew_triggered()
{
    creating->addTransition(toIdle);
    m_statemachine->postEvent( new EnumEvent( EnumStruct::EnterCreating ) );
    QString filePath = QFileDialog::getSaveFileName(this, "open a file");
    m_statemachine->postEvent( new EnumEvent( EnumStruct::EnterIdling) );
}

void MainWindow::on_actionClose_triggered()
{
    closing->addTransition(toIdle);
    m_statemachine->postEvent( new EnumEvent( EnumStruct::EnterClosing ) );
    QMessageBox::information(this, "Close current file","Do you really want to close this file?");
    m_statemachine->postEvent( new EnumEvent( EnumStruct::EnterIdling) );
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings;
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    QMainWindow::closeEvent(event);
}

void MainWindow::on_actionAboutQt_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}


