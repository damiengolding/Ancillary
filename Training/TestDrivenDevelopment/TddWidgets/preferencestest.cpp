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

#include "preferencestest.hpp"

PreferencesTest::PreferencesTest( QObject* parent) : QObject{parent}{}
PreferencesTest::~PreferencesTest(){}

#pragma Test cases {

void PreferencesTest::initTestCase()
{
    QVERIFY( uiMw != nullptr );
    // QSettings initialisation - see cleanupTestCase
    QFont uiFont( "Broadway", 22, QFont::Bold );
    QString projectHome = QDir::homePath() % QDir::separator() % "Training";
    QSettings s;
    s.setValue("ui_font",uiFont.toString());
    s.setValue("ui_language","Sanskrit");
    s.setValue("ui_mode","Light");
    s.setValue("prj_dir", projectHome );

    // PreferencesDialog setup
    preferencesDialog = new PreferencesDialog();
    preferencesDialog->setWindowTitle("Test preferences dialog");

}

void PreferencesTest::cleanupTestCase()
{
    // QSettings reset - see initTestCase
    QFont uiFont( "Broadway", 22, QFont::Bold );
    QString projectHome = QDir::homePath() % QDir::separator() % "Training";
    QSettings s;
    s.setValue("ui_font",uiFont);
    s.setValue("ui_language","Sanskrit");
    s.setValue("ui_mode","Light");
    s.setValue("prj_dir", projectHome );
}

void PreferencesTest::MustChangePersistentSettings()
{
    // QFAIL("TDD fail");
    QVERIFY( preferencesDialog != nullptr );
    // preferencesDialog->exec();
    preferencesDialog->show();
    // QVERIFY( QTest::qWaitForWindowActive(pd->window() ) );
    uiPd = preferencesDialog->getUi();
    QVERIFY2( uiPd != nullptr, "PreferencesDialog returned a nullptr for the ui object" );
    QTest::qWait(1000);

    uiPd->tabWidget->setCurrentIndex(0);
    QTest::qWait(1000);

    uiPd->fontComboBox->setCurrentText("Open Sans");
    QTest::qWait(1000);

    uiPd->comboBoxLanguage->setCurrentText("Latin");
    QTest::qWait(1000);

    uiPd->radioButtonDark->setChecked(true);
    QTest::qWait(1000);

    uiPd->tabWidget->setCurrentIndex(1);
    QTest::qWait(1000);

    QString newHome = QDir::homePath() % QDir::separator() % "TestDirectory";
    uiPd->lineEditDirectory->setText(  QDir::toNativeSeparators( newHome ) );

    preferencesDialog->updateRegistry();

    // Now do the QSettings test
    QSettings s;
    QVERIFY( s.value("ui_mode").toString() == "Dark" );
    QVERIFY( s.value("ui_language").toString() == "Latin" );
    QVERIFY( s.value("prj_dir").toString() == QDir::toNativeSeparators( newHome ) );

    QFont font;
    font.fromString( s.value("ui_font" ).toString() );
    QVERIFY( font.family() == "Open Sans" );

    QTest::qWait(2000);
    preferencesDialog->close();
}

#pragma Test cases }
