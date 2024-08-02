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
#include "preferencesdialog.hpp"
#include "ui_preferencesdialog.h"

PreferencesDialog::PreferencesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferencesDialog)
{
    ui->setupUi(this);
    connect( ui->pushButtonDirectory,
             &QPushButton::clicked, this,
             &PreferencesDialog::chooseDirectory );

    connect( this,
             &QDialog::accepted,
             this,
             &PreferencesDialog::updateRegistry
             );

    QSettings s;
    QFont font;
    font.fromString( s.value("ui_font" ).toString() );
    ui->fontComboBox->setCurrentFont( font );
    ui->comboBoxLanguage->setCurrentText( s.value("ui_language" ).toString() );
    ui->lineEditDirectory->setText( s.value("prj_dir").toString() );

    QString mode = s.value( "ui_mode" ).toString();
    if( mode == "Dark" ){
        ui->radioButtonDark->setChecked(true);
    }
    else if( mode == "Light" ){
        ui->radioButtonLight->setChecked(true);
    }
    else{
        ui->radioButtonWindows->setChecked(true);
    }

}

PreferencesDialog::~PreferencesDialog()
{
    delete ui;
}

Ui::PreferencesDialog *PreferencesDialog::getUi() const
{
    return ui;
}

void PreferencesDialog::updateRegistry()
{
    QSettings s;
    s.setValue("ui_font",ui->fontComboBox->currentFont());
    s.setValue("ui_language",ui->comboBoxLanguage->currentText());
    s.setValue("ui_mode",ui->buttonGroupMode->checkedButton()->text());
    s.setValue("prj_dir", ui->lineEditDirectory->text() );
}

void PreferencesDialog::chooseDirectory()
{
    QString newDir = QFileDialog::getExistingDirectory(this,"Choose default projects directory",QDir::homePath());
    if( newDir.isEmpty() )
        return;

    ui->lineEditDirectory->setText(newDir);
}
