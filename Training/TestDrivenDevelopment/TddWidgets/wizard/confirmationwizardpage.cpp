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
#include "confirmationwizardpage.hpp"
#include "ui_confirmationwizardpage.h"

ConfirmationWizardPage::ConfirmationWizardPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::ConfirmationWizardPage)
{
    ui->setupUi(this);
}

void ConfirmationWizardPage::initializePage()
{
    QString projectType;
    switch (field("project.type").toInt()) {
    case 0:{
        projectType = "Infrastructure";
        break;
    }
    case 1:{
        projectType = "Web application";
        break;
    }
    case 2:{
        projectType = "Wireless";
        break;
    }
    case 3:{
        projectType = "Mobile";
        break;
    }
    case 4:{
        projectType = "IoT";
        break;
    }
    case 5:{
        projectType = "SCADA";
        break;
    }
    default:{
        projectType = "Infrastructure";
        break;
    }
    }

    QString projectLocation = field("project.location").toString() % QDir::separator() % field("project.name").toString();

    QString details = QString("Name: %1\nType: %2\nLocation: %3")
            .arg( field("project.name").toString() )
            .arg( projectType )
            .arg( projectLocation );
    ui->plainTextEditSummary->setPlainText(details);
}

ConfirmationWizardPage::~ConfirmationWizardPage()
{
    delete ui;
}

Ui::ConfirmationWizardPage *ConfirmationWizardPage::getUi() const
{
    return ui;
}
