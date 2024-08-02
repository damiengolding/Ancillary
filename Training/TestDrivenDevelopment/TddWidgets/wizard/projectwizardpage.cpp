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
#include "projectwizardpage.hpp"
#include "ui_projectwizardpage.h"

ProjectWizardPage::ProjectWizardPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::ProjectWizardPage)
{
    ui->setupUi(this);
    registerField("project.name*", ui->lineEditName);
    registerField("project.type", ui->comboBoxProjectType);
    registerField("project.location*", ui->lineEditLocation);

    connect(ui->pushButtonDirectoryChooser, &QPushButton::clicked, this, &ProjectWizardPage::selectDirectory );
}

ProjectWizardPage::~ProjectWizardPage()
{
    delete ui;
}

void ProjectWizardPage::selectDirectory()
{
    QString homeDirectory = QDir::homePath();
    QString directory = QFileDialog::getExistingDirectory(this,"Select a project directory", homeDirectory);
    if( !directory.isEmpty() )
        ui->lineEditLocation->setText(directory);
}

Ui::ProjectWizardPage *ProjectWizardPage::getUi() const
{
    return ui;
}
