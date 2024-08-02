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

#include <QState>
#include <QStateMachine>
#include <QAbstractState>
#include <QFinalState>
#include "statemanager.hpp"

// QStateMachine
StateManager* stateManager;
QStateMachine* stateMachine;
QFinalState* stateMachineDone;

// ReconPushdown
QState* reconPushdown;
QState* emailAddresses;
QState* identEmployees;
QState* collectMarketing;
QState* publicTech;
QFinalState* reconDone;

// WeaponPushdown
QState* weaponPushdown;
QState* developExploit;
QState* developMalware;
QState* developPayload;
QFinalState* weaponDone;

// DeliverPushdown
QState* deliverPushdown;
QState* selectMechanism;
QState* controllingOrReleasing;
QState* adversaryControlling;
QState* adversaryReleasing;
QFinalState* deliverDone;

// ExploitPushdown
QState* exploitPushdown;
QState* selectingTarget;
QState* selectingExploit;
QState* adversaryOrVictim;
QState* adversaryTriggered;
QState* victimTriggered;
QFinalState* exploitDone;

// installPushdown
QState* installPushdown;
QState* installingAccessPoints;
QState* establishingPersistence;
QState* coverTracks;
QFinalState* installDone;

// C2Pushdown
QState* c2Pushdown;
QState* connectingToAccessPoints;
QFinalState* c2Done;

// ActionsOnObjectivesPushdown
QState* actionsPushdown;
QState* collectingCreds;
QState* escalatingPrivileges;
QState* internalReconnaissance;
QState* movingLaterally;
QState* maliciousActivities; // pushdown automaton - parallel
QState* collectExfilData;
QState* destroySystems;
QState* overWriteCorrupt;
QFinalState* actionsDone;
