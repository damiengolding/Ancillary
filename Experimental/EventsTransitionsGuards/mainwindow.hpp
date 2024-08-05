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

#include <QMainWindow>
#include <QStyle>
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QAbstractState>
#include <QTimer>
#include <QFileDialog>
#include <QMessageBox>

#include "etg.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
#include <QSettings>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

protected:
    void closeEvent(QCloseEvent *event) override;
    void readSettings();
private slots:
    void initStateMachine();
    void onSleepingStateExited();

    void on_actionAboutQt_triggered();
    void on_actionExit_triggered();
    void on_actionOpen_triggered();
    void on_actionSleepTest_triggered();
    void on_actionNew_triggered();
    void on_actionClose_triggered();

private: // State machine
    QStateMachine* m_statemachine;
    QState* idle;
    QState* opening;
    QState* saving;
    QState* creating;
    QState* sleeping;
    QState* closing;
    QFinalState* done;

    EnumTransition* toIdle;
    EnumTransition* toOpening;
    EnumTransition* toSaving;
    EnumTransition* toCreating;
    EnumTransition* toSleeping;
    EnumTransition* toClosing;

};
