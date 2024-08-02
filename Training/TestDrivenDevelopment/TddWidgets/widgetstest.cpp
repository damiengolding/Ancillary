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

#include "widgetstest.hpp"

WidgetsTest::WidgetsTest( QObject* parent) : QObject{parent}{}
WidgetsTest::~WidgetsTest(){}

void WidgetsTest::initTestCase()
{
    ui->tabWidget->setCurrentIndex(1);
}

#pragma MustSetWidgets {

// void WidgetsTest::MustSetWidgets()
// {
//     // QFAIL("TDD fail");
//     ui->lineEditPlain->setText("Hello world!");
//     QVERIFY( ui->lineEditPlain->text() == "Hello world!");

//     //
//     ui->lineEditPassword->setText("Password123");
//     QVERIFY( ui->lineEditPassword->text() == "Password123");

//     //
//     QString loremIpsum = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt"
//                          " ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris "
//                          "nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse "
//                          "cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui "
//                          "officia deserunt mollit anim id est laborum.";
//     ui->textEdit->setText(loremIpsum);
//     QVERIFY( ui->textEdit->toPlainText() == loremIpsum );

//     //
//     QList<QTreeWidgetItem*> items = ui->treeWidget->findItems("TddMain", Qt::MatchCaseSensitive, 0 );
//     QVERIFY2( items.count() == 1, qPrintable( QString("Items count: %1").arg(items.count() ) ) );
//     QTreeWidgetItem* item = items.at(0);
//     ui->treeWidget->expandItem( item );
//     QVERIFY2( item->childCount() == 3, qPrintable( QString("Child count: %1").arg(item->childCount() ) ) );
//     QTreeWidgetItem* child = item->child(1);
//     ui->treeWidget->setCurrentItem(child);
//     QVERIFY( ui->treeWidget->currentItem()->text(0) == "includes" );

//     //
//     ui->listWidget->addItem("Another test project");
//     QVERIFY( ui->listWidget->count() == 4 );

//     //
//     ui->tableWidget->setRowCount(0);
//     QVERIFY( ui->tableWidget->rowCount() == 0 );

//     //
//     ui->comboBox->setCurrentText("JavaScript");
//     QVERIFY( ui->comboBox->currentText() == "JavaScript" );

//     //
//     QFont font("Open Sans", 11);
//     ui->fontComboBox->setCurrentFont(font);
//     QVERIFY( ui->fontComboBox->currentFont() == font );

//     //
//     ui->spinBox->setValue(42);
//     QVERIFY( ui->spinBox->value() == 42 );

//     //
//     ui->doubleSpinBox->setValue(3.141);
//     QVERIFY( ui->doubleSpinBox->value() == 3.141 );

//     //
//     ui->dial->setValue(42);
//     QVERIFY( ui->dial->value() == 42 );

//     //
//     QTime timeNow = QTime::currentTime();
//     ui->timeEdit->setTime(timeNow);
//     QVERIFY( ui->timeEdit->time() == timeNow );

//     //
//     QDate dateNow = QDate::currentDate();
//     ui->dateEdit->setDate(dateNow);
//     QVERIFY( ui->dateEdit->date() == dateNow );

//     //
//     ui->horizontalScrollBar->setValue(42);
//     QVERIFY( ui->horizontalScrollBar->value() == 42 );

//     //
//     ui->horizontalSlider->setValue(42);
//     QVERIFY( ui->horizontalSlider->value() == 42 );

//     //
//     ui->progressBar->setValue(42);
//     QVERIFY( ui->progressBar->value() == 42 );

//     //
//     ui->lcdNumber->display("299792458");
//     QVERIFY( ui->lcdNumber->value() == 299792458 );

//     //
//     ui->labelImage->setPixmap( QPixmap(":/icons/logo.png") );
// }

#pragma MustSetWidgets }

#pragma MustSetWidgetsWithWait {

// void WidgetsTest::MustSetWidgetsWithWait()
// {
//     // QFAIL("TDD fail");
//     ui->lineEditPlain->setText("Hello world!");
//     QVERIFY( ui->lineEditPlain->text() == "Hello world!");
//     // QTest::qSleep(5000);
//     QTest::qWait(1000);

//     //
//     ui->lineEditPassword->setText("Password123");
//     QVERIFY( ui->lineEditPassword->text() == "Password123");
//     QTest::qWait(1000);

//     //
//     QString loremIpsum = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt"
//                          " ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris "
//                          "nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse "
//                          "cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui "
//                          "officia deserunt mollit anim id est laborum.";
//     ui->textEdit->setText(loremIpsum);
//     QVERIFY( ui->textEdit->toPlainText() == loremIpsum );
//     QTest::qWait(1000);

//     //
//     QList<QTreeWidgetItem*> items = ui->treeWidget->findItems("TddMain", Qt::MatchCaseSensitive, 0 );
//     QVERIFY2( items.count() == 1, qPrintable( QString("Items count: %1").arg(items.count() ) ) );
//     QTreeWidgetItem* item = items.at(0);
//     ui->treeWidget->expandItem( item );
//     QVERIFY2( item->childCount() == 3, qPrintable( QString("Child count: %1").arg(item->childCount() ) ) );
//     QTreeWidgetItem* child = item->child(1);
//     ui->treeWidget->setCurrentItem(child);
//     QVERIFY( ui->treeWidget->currentItem()->text(0) == "includes" );
//     QTest::qWait(1000);

//     //
//     ui->listWidget->addItem("Another test project");
//     QVERIFY( ui->listWidget->count() == 4 );
//     QTest::qWait(1000);

//     //
//     ui->tableWidget->setRowCount(0);
//     QVERIFY( ui->tableWidget->rowCount() == 0 );
//     QTest::qWait(1000);

//     //
//     ui->comboBox->setCurrentText("JavaScript");
//     QVERIFY( ui->comboBox->currentText() == "JavaScript" );
//     QTest::qWait(1000);

//     //
//     QFont font("Open Sans", 11);
//     ui->fontComboBox->setCurrentFont(font);
//     QVERIFY( ui->fontComboBox->currentFont() == font );
//     QTest::qWait(1000);

//     //
//     ui->spinBox->setValue(42);
//     QVERIFY( ui->spinBox->value() == 42 );
//     QTest::qWait(1000);

//     //
//     ui->doubleSpinBox->setValue(3.141);
//     QVERIFY( ui->doubleSpinBox->value() == 3.141 );
//     QTest::qWait(1000);

//     //
//     ui->dial->setValue(42);
//     QVERIFY( ui->dial->value() == 42 );
//     QTest::qWait(1000);

//     //
//     QTime timeNow = QTime::currentTime();
//     ui->timeEdit->setTime(timeNow);
//     QVERIFY( ui->timeEdit->time() == timeNow );
//     QTest::qWait(1000);

//     //
//     QDate dateNow = QDate::currentDate();
//     ui->dateEdit->setDate(dateNow);
//     QVERIFY( ui->dateEdit->date() == dateNow );
//     QTest::qWait(1000);

//     //
//     ui->horizontalScrollBar->setValue(42);
//     QVERIFY( ui->horizontalScrollBar->value() == 42 );
//     QTest::qWait(1000);

//     //
//     ui->horizontalSlider->setValue(42);
//     QVERIFY( ui->horizontalSlider->value() == 42 );
//     QTest::qWait(1000);

//     //
//     ui->progressBar->setValue(42);
//     QVERIFY( ui->progressBar->value() == 42 );
//     QTest::qWait(1000);

//     //
//     ui->lcdNumber->display("299792458");
//     QVERIFY( ui->lcdNumber->value() == 299792458 );
//     QTest::qWait(1000);

//     //
//     ui->labelImage->setPixmap( QPixmap(":/icons/logo.png") );
// }

#pragma MustSetWidgetsWithWait }

#pragma MustSetWidgetsWithWaitKeysMouse {

void WidgetsTest::MustSetWidgetsWithWaitKeysMouse()
{
    // QFAIL("TDD fail");
    QTest::qWait(1500);
    QTest::mouseMove(ui->lineEditPlain);
    QTest::qWait(1500);

    QTest::mouseMove(ui->lineEditPassword);
    QTest::qWait(1500);

    QTest::mouseMove(ui->textEdit);
    QTest::qWait(1500);

    QTest::mouseMove(ui->treeWidget);
    QTest::qWait(1500);

    QTest::mouseMove(ui->listWidget);
    QTest::qWait(1500);

    QTest::mouseMove(ui->tableWidget);
    QTest::qWait(1500);

    QTest::keyClick(ui->tabWidget, Qt::Key_Tab);
    QTest::qWait(1000);
    QTest::keyClicks(ui->lineEditPlain, "rufus.drumknott@discworld.io");
    QTest::qWait(1500);

    QTest::keyClick(ui->lineEditPlain, Qt::Key_Tab);

    QWidget* currentWidget = qApp->focusWidget();
    if( !currentWidget ){
        QFAIL("There is no widget with focus");
    }
    if( currentWidget->objectName()  != "lineEditPassword" ){
        QFAIL("The current widget is not the password line edit - tab order FAIL");
    }

    QLineEdit* passwordEdit = qobject_cast<QLineEdit*>(currentWidget);
    if( !passwordEdit ){
        QFAIL("passwordEdit == nullptr");
    }
    QTest::qWait(1000);
    QTest::keyClicks(passwordEdit, "Password123");
    QTest::keyClick(passwordEdit, Qt::Key_Tab);
}

#pragma MustSetWidgetsWithWaitKeysMouse }
