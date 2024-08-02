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
#pragma once

#include <QObject>
#include <QDebug>
#include <QCoreApplication>

class StateManager : public QObject
{
    Q_OBJECT
public:
    explicit StateManager(QObject *parent = nullptr);

public slots:
#pragma Machine and pushdown {

    void stateMachineStarted();
    void stateMachineStopped();
    void stateMachineFinished();

    void statePushdownEntered();
    void statePushdownExited();
    void statePushdownFinished();

#pragma Machine and pushdown }

#pragma State specific slots {

    // ReconPushdown
    void emailAddressesEnteredAction();
    void identEmployeesEnteredAction();
    void collectMarketingEnteredAction();
    void publicTechEnteredAction();
    // WeaponPushdown
    void developExploitEnteredAction();
    void developMalwareEnteredAction();
    void developPayloadEnteredAction();
    // DeliverPushdown
    void selectMechanismEnteredAction();
    void controllingOrReleasingEnteredAction();
    void adversaryControllingEnteredAction();
    void adversaryReleasingEnteredAction();
    // ExploitPushdown
    void selectingTargetEnteredAction();
    void selectingExploitEnteredAction();
    void adversaryOrVictimEnteredAction();
    void adversaryTriggeredEnteredAction();
    void victimTriggeredEnteredAction();
    // InstallPushdown
    void installingAccessPointsEnteredAction();
    void establishingPersistenceEnteredAction();
    void coverTracksEnteredAction();
    // C2Pushdown
    void connectingToAccessPointsEnteredAction();
    // ActionsOnObjectivesPushdown
    void collectingCredsEnteredAction();
    void escalatingPrivilegesEnteredAction();
    void internalReconnaissanceEnteredAction();
    void movingLaterallyEnteredAction();
    void collectExfilDataEnteredAction();
    void destroySystemsEnteredAction();
    void overwriteCorruptDataEnteredAction();

#pragma State specific slots }

signals:

};

