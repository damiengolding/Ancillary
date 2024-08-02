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
#include "statemanager.hpp"

StateManager::StateManager(QObject *parent)
    : QObject{parent}
{

}

void StateManager::stateMachineStarted()
{
    if( sender() ){
        qInfo() << "State machine started:" << sender()->objectName();
    }
    else{
        qInfo() << "State machine started: anonymous";
    }
}

void StateManager::stateMachineStopped()
{
    if( sender() ){
        qInfo() << "State machine stopped:" << sender()->objectName();
    }
    else{
        qInfo() << "State machine stopped: anonymous";
    }
}

void StateManager::stateMachineFinished()
{
    if( sender() ){
        qInfo() << "State machine finished:" << sender()->objectName();
    }
    else{
        qInfo() << "State machine finished: anonymous";
    }
}

void StateManager::statePushdownEntered()
{
    if( sender() ){
        qInfo() << "State pushdown Entered:" << sender()->objectName();
    }
    else{
        qInfo() << "State pushdown Entered: anonymous";
    }
}

void StateManager::statePushdownExited()
{
    if( sender() ){
        qInfo() << "State pushdown Exited:" << sender()->objectName();
    }
    else{
        qInfo() << "State pushdown Exited: anonymous";
    }
}

void StateManager::statePushdownFinished()
{
    if( sender() ){
        qInfo() << "State pushdown Finished:" << sender()->objectName();
    }
    else{
        qInfo() << "State pushdown Finished: anonymous";
    }
}

void StateManager::stateEntered()
{
    if( sender() ){
        qInfo() << "State entered:" << sender()->objectName();
    }
    else{
        qInfo() << "State entered: anonymous";
    }
}

void StateManager::stateExited()
{
    if( sender() ){
        qInfo() << "State exited:" << sender()->objectName();
    }
    else{
        qInfo() << "State exited: anonymous";
    }
}

void StateManager::stateFinished()
{
    if( sender() ){
        qInfo() << "State finished:" << sender()->objectName();
    }
    else{
        qInfo() << "State finished: anonymous";
    }
}
