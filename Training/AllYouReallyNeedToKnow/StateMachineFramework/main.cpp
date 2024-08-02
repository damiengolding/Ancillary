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
#include <QtConcurrent>

#include "states.hpp"

void initReconPushdown();
void initWeaponPushdown();
void initDeliverPushdown();
void initExploitPushdown();
void initInstallPushdown();
void initC2Pushdown();
void initActionsPushdown();

void startMachine();
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
    initDeliverPushdown();
    initExploitPushdown();
    initInstallPushdown();
    initC2Pushdown();
    initActionsPushdown();

    // QStateMachine
    // Add pushdowns here
    stateMachine->addState(reconPushdown);
    stateMachine->addState(weaponPushdown);
    stateMachine->addState(deliverPushdown);
    stateMachine->addState(exploitPushdown);
    stateMachine->addState(installPushdown);
    stateMachine->addState(c2Pushdown);
    stateMachine->addState(actionsPushdown);
    stateMachine->setInitialState(reconPushdown);

    // Pushdown transitions
    reconPushdown->addTransition(reconPushdown, &QState::finished, weaponPushdown);
    weaponPushdown->addTransition(weaponPushdown, &QState::finished, deliverPushdown);
    deliverPushdown->addTransition(deliverPushdown, &QState::finished, exploitPushdown);
    exploitPushdown->addTransition(exploitPushdown, &QState::finished, installPushdown);
    installPushdown->addTransition(installPushdown, &QState::finished, c2Pushdown);
    c2Pushdown->addTransition(c2Pushdown, &QState::finished, actionsPushdown);

    // Final state
    actionsPushdown->addTransition(actionsPushdown, &QState::finished, stateMachineDone);
    stateMachine->addState(stateMachineDone);

    stateMachine->start();
    // QtConcurrent::run( startMachine );

    return a.exec();
}

void initReconPushdown(){
    reconPushdown = new QState(QState::ParallelStates);
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
    reconDone->setObjectName("reconDone");

    // Add manager connections
    QObject::connect( reconPushdown, &QState::entered, stateManager, &StateManager::statePushdownEntered, Qt::QueuedConnection );
    QObject::connect( reconPushdown, &QState::exited, stateManager, &StateManager::statePushdownExited, Qt::QueuedConnection );
    QObject::connect( reconPushdown, &QState::finished, stateManager, &StateManager::statePushdownFinished, Qt::QueuedConnection );

    QObject::connect( emailAddresses, &QState::entered, stateManager, &StateManager::emailAddressesEnteredAction, Qt::QueuedConnection );
    QObject::connect( identEmployees, &QState::entered, stateManager, &StateManager::publicTechEnteredAction, Qt::QueuedConnection );
    QObject::connect( collectMarketing, &QState::entered, stateManager, &StateManager::collectMarketingEnteredAction, Qt::QueuedConnection );
    QObject::connect( publicTech, &QState::entered, stateManager, &StateManager::publicTechEnteredAction, Qt::QueuedConnection );

}

void initWeaponPushdown(){
    // Instantiation
    weaponPushdown = new QState();
    developExploit = new QState(weaponPushdown);
    developMalware = new QState(weaponPushdown);
    developPayload = new QState(weaponPushdown);
    weaponDone = new QFinalState(weaponPushdown);
    weaponPushdown->setInitialState(developExploit);

    // Object names
    weaponPushdown->setObjectName("weaponPushdown");
    developExploit->setObjectName("developExploit");
    developMalware->setObjectName("developMalware");
    developPayload->setObjectName("developPayload");
    weaponDone->setObjectName("weaponDone");

    // Add manager connections
    QObject::connect( weaponPushdown, &QState::entered, stateManager, &StateManager::statePushdownEntered, Qt::QueuedConnection );
    QObject::connect( weaponPushdown, &QState::exited, stateManager, &StateManager::statePushdownExited, Qt::QueuedConnection );
    QObject::connect( weaponPushdown, &QState::finished, stateManager, &StateManager::statePushdownFinished, Qt::QueuedConnection );

    QObject::connect( developExploit, &QState::entered, stateManager, &StateManager::developExploitEnteredAction, Qt::QueuedConnection );
    QObject::connect( developMalware, &QState::entered, stateManager, &StateManager::developMalwareEnteredAction, Qt::QueuedConnection );
    QObject::connect( developPayload, &QState::entered, stateManager, &StateManager::developPayloadEnteredAction, Qt::QueuedConnection );

    // Add transitions
    developExploit->addTransition( developExploit, &QState::entered, developMalware );
    developMalware->addTransition( developMalware, &QState::entered, developPayload );
    developPayload->addTransition( developPayload, &QState::entered, weaponDone );

}

void initDeliverPushdown(){
    // Instantiation
    deliverPushdown = new QState();
    selectMechanism = new QState(deliverPushdown);;
    controllingOrReleasing = new QState(QState::ParallelStates, deliverPushdown);
    adversaryControlling = new QState(controllingOrReleasing);
    adversaryReleasing = new QState(controllingOrReleasing);
    QFinalState* corDone = new QFinalState(controllingOrReleasing);
    deliverDone = new QFinalState(deliverPushdown);
    deliverPushdown->setInitialState(selectMechanism);

    // Object names
    deliverPushdown->setObjectName("deliverPushdown");
    selectMechanism->setObjectName("selectMechanism");
    controllingOrReleasing->setObjectName("controllingOrReleasing");
    adversaryControlling->setObjectName("adversaryControlling");
    adversaryReleasing->setObjectName("adversaryReleasing");
    deliverDone->setObjectName("deliverDone");

    // Add manager connections
    QObject::connect( deliverPushdown, &QState::entered, stateManager, &StateManager::statePushdownEntered, Qt::QueuedConnection );
    QObject::connect( deliverPushdown, &QState::exited, stateManager, &StateManager::statePushdownExited, Qt::QueuedConnection );
    QObject::connect( deliverPushdown, &QState::finished, stateManager, &StateManager::statePushdownFinished, Qt::QueuedConnection );

    QObject::connect( controllingOrReleasing, &QState::entered, stateManager, &StateManager::statePushdownEntered, Qt::QueuedConnection );
    QObject::connect( controllingOrReleasing, &QState::exited, stateManager, &StateManager::statePushdownExited, Qt::QueuedConnection );
    QObject::connect( controllingOrReleasing, &QState::finished, stateManager, &StateManager::statePushdownFinished, Qt::QueuedConnection );

    QObject::connect( selectMechanism, &QState::entered, stateManager, &StateManager::selectMechanismEnteredAction, Qt::QueuedConnection );
    // QObject::connect( controllingOrReleasing, &QState::entered, stateManager, &StateManager::controllingOrReleasingEnteredAction, Qt::QueuedConnection );
    QObject::connect( adversaryControlling, &QState::entered, stateManager, &StateManager::adversaryControllingEnteredAction, Qt::QueuedConnection );
    QObject::connect( adversaryReleasing, &QState::entered, stateManager, &StateManager::adversaryReleasingEnteredAction, Qt::QueuedConnection );

    // Add transitions
    selectMechanism->addTransition( selectMechanism, &QState::entered, controllingOrReleasing );
    controllingOrReleasing->addTransition( controllingOrReleasing, &QState::entered, deliverDone );
}

void initExploitPushdown(){
    // Instantiation
    exploitPushdown = new QState();
    selectingTarget = new QState(exploitPushdown);
    selectingExploit = new QState(exploitPushdown);
    adversaryOrVictim  = new QState(QState::ParallelStates, exploitPushdown);
    adversaryTriggered = new QState(adversaryOrVictim);
    victimTriggered = new QState(adversaryOrVictim);
    QFinalState* aovDone = new QFinalState(adversaryOrVictim);
    exploitDone = new QFinalState(exploitPushdown);
    exploitPushdown->setInitialState(selectingTarget);

    // Object names
    exploitPushdown->setObjectName("exploitPushdown");
    selectingTarget->setObjectName("selectingTarget");
    selectingExploit->setObjectName("selectingExploit");
    adversaryOrVictim->setObjectName("adversaryOrVictim");
    adversaryTriggered->setObjectName("adversaryTriggered");
    victimTriggered->setObjectName("victimTriggered");
    exploitDone->setObjectName("exploitDone");

    // Add manager connections
    QObject::connect( exploitPushdown, &QState::entered, stateManager, &StateManager::statePushdownEntered, Qt::QueuedConnection );
    QObject::connect( exploitPushdown, &QState::exited, stateManager, &StateManager::statePushdownExited, Qt::QueuedConnection );
    QObject::connect( exploitPushdown, &QState::finished, stateManager, &StateManager::statePushdownFinished, Qt::QueuedConnection );

    QObject::connect( adversaryOrVictim, &QState::entered, stateManager, &StateManager::statePushdownEntered, Qt::QueuedConnection );
    QObject::connect( adversaryOrVictim, &QState::exited, stateManager, &StateManager::statePushdownExited, Qt::QueuedConnection );
    QObject::connect( adversaryOrVictim, &QState::finished, stateManager, &StateManager::statePushdownFinished, Qt::QueuedConnection );

    QObject::connect( selectingTarget, &QState::entered, stateManager, &StateManager::selectingTargetEnteredAction, Qt::QueuedConnection );
    QObject::connect( selectingExploit, &QState::entered, stateManager, &StateManager::selectingExploitEnteredAction, Qt::QueuedConnection );
    // QObject::connect( adversaryOrVictim, &QState::entered, stateManager, &StateManager::adversaryOrVictimEnteredAction, Qt::QueuedConnection );
    QObject::connect( adversaryTriggered, &QState::entered, stateManager, &StateManager::adversaryTriggeredEnteredAction, Qt::QueuedConnection );
    QObject::connect( victimTriggered, &QState::entered, stateManager, &StateManager::victimTriggeredEnteredAction, Qt::QueuedConnection );

    // Add transitions
    selectingTarget->addTransition( selectingTarget, &QState::entered, selectingExploit );
    selectingExploit->addTransition( selectingExploit, &QState::entered, adversaryOrVictim );
    adversaryOrVictim->addTransition( adversaryOrVictim, &QState::entered, exploitDone );

}

void initInstallPushdown(){
    // Instantiation
    installPushdown = new QState();
    installingAccessPoints = new QState(installPushdown);
    establishingPersistence = new QState(installPushdown);
    coverTracks = new QState(installPushdown);
    installDone = new QFinalState(installPushdown);
    installPushdown->setInitialState(installingAccessPoints);

    // Object names
    installPushdown->setObjectName("InstallPushdown");
    installingAccessPoints->setObjectName("installingAccessPoints");
    establishingPersistence->setObjectName("establishingPersistence");
    coverTracks->setObjectName("coverTracks");
    installDone->setObjectName("installDone");

    // Add manager connections
    QObject::connect( installPushdown, &QState::entered, stateManager, &StateManager::statePushdownEntered, Qt::QueuedConnection );
    QObject::connect( installPushdown, &QState::exited, stateManager, &StateManager::statePushdownExited, Qt::QueuedConnection );
    QObject::connect( installPushdown, &QState::finished, stateManager, &StateManager::statePushdownFinished, Qt::QueuedConnection );

    QObject::connect( installingAccessPoints, &QState::entered, stateManager, &StateManager::installingAccessPointsEnteredAction, Qt::QueuedConnection );
    QObject::connect( establishingPersistence, &QState::entered, stateManager, &StateManager::establishingPersistenceEnteredAction, Qt::QueuedConnection );
    QObject::connect( coverTracks, &QState::entered, stateManager, &StateManager::coverTracksEnteredAction, Qt::QueuedConnection );

    // Add transitions
    installingAccessPoints->addTransition( installingAccessPoints, &QState::entered, establishingPersistence );
    establishingPersistence->addTransition( establishingPersistence, &QState::entered, coverTracks );
    coverTracks->addTransition( coverTracks, &QState::entered, installDone );
}

void initC2Pushdown(){
    // Instantiation
    c2Pushdown = new QState();
    connectingToAccessPoints = new QState(c2Pushdown);
    c2Done = new QFinalState(c2Pushdown);
    c2Pushdown->setInitialState(connectingToAccessPoints);

    // Object names
    c2Pushdown->setObjectName("c2Pushdown");
    connectingToAccessPoints->setObjectName("connectingToAccessPoints");
    c2Done->setObjectName("c2Done");

    // Add manager connections
    QObject::connect( c2Pushdown, &QState::entered, stateManager, &StateManager::statePushdownEntered, Qt::QueuedConnection );
    QObject::connect( c2Pushdown, &QState::exited, stateManager, &StateManager::statePushdownExited, Qt::QueuedConnection );
    QObject::connect( c2Pushdown, &QState::finished, stateManager, &StateManager::statePushdownFinished, Qt::QueuedConnection );

    QObject::connect( connectingToAccessPoints, &QState::entered, stateManager, &StateManager::connectingToAccessPointsEnteredAction, Qt::QueuedConnection );

    // Add transitions
    connectingToAccessPoints->addTransition( connectingToAccessPoints, &QState::entered, c2Done );
}

void initActionsPushdown(){
    // Instantiation
    actionsPushdown = new QState();
    collectingCreds = new QState(actionsPushdown);
    escalatingPrivileges = new QState(actionsPushdown);
    internalReconnaissance = new QState(actionsPushdown);
    movingLaterally = new QState(actionsPushdown);
    maliciousActivities = new QState( QState::ParallelStates, actionsPushdown );
    collectExfilData = new QState(maliciousActivities);
    destroySystems = new QState(maliciousActivities);
    overWriteCorrupt = new QState(maliciousActivities);
    QFinalState* maDone = new QFinalState(maliciousActivities);
    actionsDone = new QFinalState(actionsPushdown);
    actionsPushdown->setInitialState(collectingCreds);

    // Object names
    actionsPushdown->setObjectName("actionsPushdown");
    collectingCreds->setObjectName("collectingCreds");
    escalatingPrivileges->setObjectName("escalatingPrivileges");
    internalReconnaissance->setObjectName("internalReconnaissance");
    movingLaterally->setObjectName("movingLaterally");
    maliciousActivities->setObjectName("maliciousActivities");
    collectExfilData->setObjectName("collectExfilData");
    destroySystems->setObjectName("destroySystems");
    overWriteCorrupt->setObjectName("overWriteCorrupt");

    // Add manager connections
    QObject::connect( actionsPushdown, &QState::entered, stateManager, &StateManager::statePushdownEntered, Qt::QueuedConnection );
    QObject::connect( actionsPushdown, &QState::exited, stateManager, &StateManager::statePushdownExited, Qt::QueuedConnection );
    QObject::connect( actionsPushdown, &QState::finished, stateManager, &StateManager::statePushdownFinished, Qt::QueuedConnection );

    QObject::connect( maliciousActivities, &QState::entered, stateManager, &StateManager::statePushdownEntered, Qt::QueuedConnection );
    QObject::connect( maliciousActivities, &QState::exited, stateManager, &StateManager::statePushdownExited, Qt::QueuedConnection );
    QObject::connect( maliciousActivities, &QState::finished, stateManager, &StateManager::statePushdownFinished, Qt::QueuedConnection );

    QObject::connect( collectingCreds, &QState::entered, stateManager, &StateManager::collectingCredsEnteredAction, Qt::QueuedConnection );
    QObject::connect( escalatingPrivileges, &QState::entered, stateManager, &StateManager::escalatingPrivilegesEnteredAction, Qt::QueuedConnection );
    QObject::connect( internalReconnaissance, &QState::entered, stateManager, &StateManager::internalReconnaissanceEnteredAction, Qt::QueuedConnection );
    QObject::connect( movingLaterally, &QState::entered, stateManager, &StateManager::movingLaterallyEnteredAction, Qt::QueuedConnection );
    QObject::connect( collectExfilData, &QState::entered, stateManager, &StateManager::collectExfilDataEnteredAction, Qt::QueuedConnection );
    QObject::connect( destroySystems, &QState::entered, stateManager, &StateManager::destroySystemsEnteredAction, Qt::QueuedConnection );
    QObject::connect( overWriteCorrupt, &QState::entered, stateManager, &StateManager::overwriteCorruptDataEnteredAction, Qt::QueuedConnection );

    // Add transitions
    collectingCreds->addTransition( collectingCreds, &QState::entered, escalatingPrivileges );
    escalatingPrivileges->addTransition( escalatingPrivileges, &QState::entered, internalReconnaissance );
    internalReconnaissance->addTransition( internalReconnaissance, &QState::entered, movingLaterally );
    movingLaterally->addTransition( movingLaterally, &QState::entered, maliciousActivities );
    maliciousActivities->addTransition( maliciousActivities, &QState::entered, actionsDone );

}

void startMachine(){
    stateMachine->start();
}

