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
#include <QCoreApplication>
#include <QState>
#include <QStateMachine>
#include <QAbstractState>
#include <QFinalState>

#include "states.hpp"

void initReconPushdown();
void initWeaponPushdown();

void machineFinished();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Instantiate
    stateManager = new StateManager();
    stateMachine = new QStateMachine();
    stateMachineDone = new QFinalState();
    stateMachine->setObjectName("CyberKillChain");

    // StateMachine entered and exited
    QObject::connect( stateMachine, &QStateMachine::started, stateManager, &StateManager::stateMachineStarted, Qt::QueuedConnection );
    QObject::connect( stateMachine, &QStateMachine::stopped, stateManager, &StateManager::stateMachineStopped, Qt::QueuedConnection );
    QObject::connect( stateMachine, &QStateMachine::finished, stateManager, &StateManager::stateMachineFinished, Qt::QueuedConnection );

    // Initialise pushdowns
    initReconPushdown();
    initWeaponPushdown();
    // QStateMachine
    // Add pushdowns here
    stateMachine->addState(reconPushdown);
    stateMachine->addState(weaponPushdown);
    stateMachine->setInitialState(reconPushdown);

    // Pushdown transitions
    reconPushdown->addTransition(reconPushdown, &QState::finished, weaponPushdown);

    // Final state
    weaponPushdown->addTransition(weaponPushdown, &QState::finished, stateMachineDone);
    stateMachine->addState(stateMachineDone);
    stateMachine->start();

    int r = a.exec();
    // QObject::connect( stateMachine, &QStateMachine::finished, machineFinished );
    QObject::connect( stateMachineDone, &QFinalState::exited, machineFinished );
    while( stateMachine->isRunning() ){
        qInfo() << "Still running . . .";
    }
    // return a.exec();
    // return(0);
    return(r);
}

void initReconPushdown(){
    reconPushdown = new QState();
    emailAddresses = new QState(reconPushdown);
    identEmployees = new QState(reconPushdown);
    collectMarketing = new QState(reconPushdown);
    publicTech = new QState(reconPushdown);
    reconDone = new QFinalState(reconPushdown);

    // Set object names
    reconPushdown->setObjectName("reconPushdown");
    emailAddresses->setObjectName("emailAddresses");
    identEmployees->setObjectName("identEmployees");
    collectMarketing->setObjectName("collectMarketing");
    publicTech->setObjectName("publicTech");

    // Add manager connections
    QObject::connect( reconPushdown, &QState::entered, stateManager, &StateManager::statePushdownEntered, Qt::QueuedConnection );
    QObject::connect( reconPushdown, &QState::exited, stateManager, &StateManager::statePushdownExited, Qt::QueuedConnection );
    QObject::connect( reconPushdown, &QState::finished, stateManager, &StateManager::statePushdownFinished, Qt::QueuedConnection );

    QObject::connect( emailAddresses, &QState::entered, stateManager, &StateManager::stateEntered, Qt::QueuedConnection );
    QObject::connect( emailAddresses, &QState::exited, stateManager, &StateManager::stateExited, Qt::QueuedConnection );
    QObject::connect( emailAddresses, &QState::finished, stateManager, &StateManager::stateFinished, Qt::QueuedConnection );

    QObject::connect( identEmployees, &QState::entered, stateManager, &StateManager::stateEntered, Qt::QueuedConnection );
    QObject::connect( identEmployees, &QState::exited, stateManager, &StateManager::stateExited, Qt::QueuedConnection );
    QObject::connect( identEmployees, &QState::finished, stateManager, &StateManager::stateFinished, Qt::QueuedConnection );

    QObject::connect( collectMarketing, &QState::entered, stateManager, &StateManager::stateEntered, Qt::QueuedConnection );
    QObject::connect( collectMarketing, &QState::exited, stateManager, &StateManager::stateExited, Qt::QueuedConnection );
    QObject::connect( collectMarketing, &QState::finished, stateManager, &StateManager::stateFinished, Qt::QueuedConnection );

    QObject::connect( publicTech, &QState::entered, stateManager, &StateManager::stateEntered, Qt::QueuedConnection );
    QObject::connect( publicTech, &QState::exited, stateManager, &StateManager::stateExited, Qt::QueuedConnection );
    QObject::connect( publicTech, &QState::finished, stateManager, &StateManager::stateFinished, Qt::QueuedConnection );

    reconPushdown->setChildMode(QState::ParallelStates);
}

void initWeaponPushdown(){
    // Instantiation
    weaponPushdown = new QState();
    developExploit = new QState(weaponPushdown);
    developMalware = new QState(weaponPushdown);
    developPayload = new QState(weaponPushdown);
    weaponDone = new QFinalState(weaponPushdown);

    // Object names
    weaponPushdown->setObjectName("weaponPushdown");
    developExploit->setObjectName("developExploit");
    developMalware->setObjectName("developMalware");
    developPayload->setObjectName("developPayload");

    // Add manager connections
    QObject::connect( weaponPushdown, &QState::entered, stateManager, &StateManager::statePushdownEntered, Qt::QueuedConnection );
    QObject::connect( weaponPushdown, &QState::exited, stateManager, &StateManager::statePushdownExited, Qt::QueuedConnection );
    QObject::connect( weaponPushdown, &QState::finished, stateManager, &StateManager::statePushdownFinished, Qt::QueuedConnection );

    QObject::connect( developExploit, &QState::entered, stateManager, &StateManager::stateEntered, Qt::QueuedConnection );
    QObject::connect( developExploit, &QState::exited, stateManager, &StateManager::stateExited, Qt::QueuedConnection );
    QObject::connect( developExploit, &QState::finished, stateManager, &StateManager::stateFinished, Qt::QueuedConnection );

    QObject::connect( developMalware, &QState::entered, stateManager, &StateManager::stateEntered, Qt::QueuedConnection );
    QObject::connect( developMalware, &QState::exited, stateManager, &StateManager::stateExited, Qt::QueuedConnection );
    QObject::connect( developMalware, &QState::finished, stateManager, &StateManager::stateFinished, Qt::QueuedConnection );

    QObject::connect( developPayload, &QState::entered, stateManager, &StateManager::stateEntered, Qt::QueuedConnection );
    QObject::connect( developPayload, &QState::exited, stateManager, &StateManager::stateExited, Qt::QueuedConnection );
    QObject::connect( developMalware, &QState::finished, stateManager, &StateManager::stateFinished, Qt::QueuedConnection );

    // Add transitions
    developExploit->addTransition( developExploit, &QState::entered, developMalware );
    developMalware->addTransition( developMalware, &QState::entered, developPayload );
    developPayload->addTransition( developPayload, &QState::entered, weaponDone );

    weaponPushdown->setInitialState(developExploit);

}

void machineFinished(){
    qInfo() << "machineFinished";
    // QCoreApplication::instance()->exit(0);
}
