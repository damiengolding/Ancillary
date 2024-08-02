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
#include "testwizard.hpp"
#include "ui_testwizard.h"

#include <QDir>
#include <QFile>

TestWizard::TestWizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::TestWizard)
{
    ui->setupUi(this);
    connect( this,
             &QWizard::accepted,
             this,
             &TestWizard::createProject
                );
}

TestWizard::~TestWizard()
{
    delete ui;
}

Ui::TestWizard *TestWizard::getUi() const
{
    return ui;
}

void TestWizard::createProject()
{
    QString dirPath = field("project.location").toString() % QDir::separator() % field("project.name").toString();
    QDir dir;
    dir.mkpath( dirPath );

    QString filePath = dirPath % QDir::separator() % field("project.name").toString() % ".xml";
    QFile f( filePath );
    if( !f.open(QIODevice::WriteOnly) ){
        qInfo() << "Could not open"<< filePath << "for writing";
    }
    f.write("Test project file");
    f.close();
}
