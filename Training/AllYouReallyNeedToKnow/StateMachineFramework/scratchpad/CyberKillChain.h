//
// Statemachine code from reading SCXML file 'CyberKillChain.scxml'
// Created by: The Qt SCXML Compiler version 2 (Qt 6.7.1)
// WARNING! All changes made in this file will be lost!
//

#ifndef CYBERKILLCHAIN_H
#define CYBERKILLCHAIN_H

#include <QScxmlStateMachine>
#include <QString>
#include <QVariant>

class CyberKillChain: public QScxmlStateMachine
{
    /* qmake ignore Q_OBJECT */
    Q_OBJECT
    Q_PROPERTY(bool CyberKillChain)
    Q_PROPERTY(bool Exploiting)
    Q_PROPERTY(bool SelectingTarget)
    Q_PROPERTY(bool SelectingExploit)
    Q_PROPERTY(bool AdversaryOrVictim)
    Q_PROPERTY(bool AdversaryTriggeringExploit)
    Q_PROPERTY(bool VictimTriggeringExploit)
    Q_PROPERTY(bool Delivering)
    Q_PROPERTY(bool SelectingDeliveryMechanism)
    Q_PROPERTY(bool ControllingOrReleasing)
    Q_PROPERTY(bool AdversaryControlling)
    Q_PROPERTY(bool AdversaryReleasing)
    Q_PROPERTY(bool Weaponising)
    Q_PROPERTY(bool DevelopingExploit)
    Q_PROPERTY(bool DevelopingMalware)
    Q_PROPERTY(bool DevelopingPayload)
    Q_PROPERTY(bool Reconnaissance)
    Q_PROPERTY(bool HarvestingEmailAddresses)
    Q_PROPERTY(bool EnumeratePublicTechnology)
    Q_PROPERTY(bool IdentifyingEmployees)
    Q_PROPERTY(bool CollectingMarketing)
    Q_PROPERTY(bool TakingActionOnObjectives)
    Q_PROPERTY(bool PerformingInternalReconnaissance)
    Q_PROPERTY(bool EscalatingPrivileges)
    Q_PROPERTY(bool MaliciousActivities)
    Q_PROPERTY(bool CollectingAndExfiltratingData)
    Q_PROPERTY(bool DestroyingSystems)
    Q_PROPERTY(bool OverwritingCorruptingData)
    Q_PROPERTY(bool CollectingCreds)
    Q_PROPERTY(bool MovingLaterally)
    Q_PROPERTY(bool Installing)
    Q_PROPERTY(bool InstallingAccessPoints)
    Q_PROPERTY(bool EstablishingPersistence)
    Q_PROPERTY(bool CoverTracks)
    Q_PROPERTY(bool CommandAndControl)
    Q_PROPERTY(bool ConnectingToAccessPoints)
    Q_PROPERTY(bool Exit)


public:
    Q_INVOKABLE CyberKillChain(QObject *parent = 0);
    ~CyberKillChain();



Q_SIGNALS:


private:
    struct Data;
    friend struct Data;
    struct Data *data;
};

Q_DECLARE_METATYPE(::CyberKillChain*)

#endif // CYBERKILLCHAIN_H
