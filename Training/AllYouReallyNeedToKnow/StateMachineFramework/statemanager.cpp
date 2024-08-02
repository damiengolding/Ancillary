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
#include <QRandomGenerator>

StateManager::StateManager(QObject *parent)
    : QObject{parent}
{

}

#pragma Machine and pushdown {

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
    QCoreApplication::instance()->exit();
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

#pragma Machine and pushdown }

#pragma State specific slots {

/*
    ReconPushdown
*/

void StateManager::emailAddressesEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::identEmployeesEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::collectMarketingEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::publicTechEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

/*
WeaponPushDown
*/

void StateManager::developExploitEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::developMalwareEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::developPayloadEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

/*
DeliverPushdown
*/

void StateManager::selectMechanismEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::controllingOrReleasingEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::adversaryControllingEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::adversaryReleasingEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

/*
 * ExploitPushdown
 */

void StateManager::selectingTargetEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::selectingExploitEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::adversaryOrVictimEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::adversaryTriggeredEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::victimTriggeredEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

/*
 * InstallPushdown
 */

void StateManager::installingAccessPointsEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::establishingPersistenceEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::coverTracksEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

/*
 * C2Pushdown
 */

void StateManager::connectingToAccessPointsEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

/*
 * ActionsOnObjectivesPushdown
 */

void StateManager::collectingCredsEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::escalatingPrivilegesEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::internalReconnaissanceEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::movingLaterallyEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::collectExfilDataEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::destroySystemsEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

void StateManager::overwriteCorruptDataEnteredAction()
{
    qInfo() << "In slot:" << Q_FUNC_INFO << "called by:" << sender()->objectName();
}

#pragma State specific slots }


