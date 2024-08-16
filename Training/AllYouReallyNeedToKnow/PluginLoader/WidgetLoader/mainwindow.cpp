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

#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readSettings();
    loadPlugins();
}

void MainWindow::readSettings(){
    QSettings settings;
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
}

void MainWindow::loadPlugins()
{
    ui->statusbar->showMessage("Starting to load plugins");
    QString pluginPath = QDir::currentPath().append("/widgets");

    QDir pluginDir(pluginPath);

    if( !pluginDir.exists(pluginPath) || !pluginDir.isReadable() ){
        QMessageBox::warning(this, "Plugin directory", "Plugin directory is not accessible");
        ui->statusbar->showMessage("Failed to load plugins from: " % pluginPath);
        return;
    }

    ui->statusbar->showMessage("Interrogating directory:" % pluginPath);

    QStringList fileFilters;
    fileFilters << "*.dll" << "*.so";

    QFileInfoList fileInfoList = pluginDir.entryInfoList(fileFilters,QDir::Files | QDir::NoDotAndDotDot);

    for( auto fileInfo : fileInfoList){
        QPluginLoader* loader = new QPluginLoader(this);
        loader->setFileName( fileInfo.absoluteFilePath() );
        if( !loader->load() ){
            ui->statusbar->showMessage("Unable to load plugin: " % fileInfo.absoluteFilePath());
        }
        else{
            m_plugins.append(loader);
        }
    }

    for( auto loader : m_plugins ){
        if ( loader->isLoaded() ){
            WidgetPlugin* widgetPlugin = qobject_cast<WidgetPlugin*>( loader->instance() );
            if( widgetPlugin ){
                ui->tabWidget->addTab( widgetPlugin->getWidget(), widgetPlugin->getName() );
            }
        }
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings;
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    QMainWindow::closeEvent(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}

