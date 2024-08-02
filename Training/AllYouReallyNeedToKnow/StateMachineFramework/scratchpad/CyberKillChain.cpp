//
// Statemachine code from reading SCXML file 'CyberKillChain.scxml'
// Created by: The Qt SCXML Compiler version 2 (Qt 6.7.1)
// WARNING! All changes made in this file will be lost!
//

#include "CyberKillChain.h"

#include <qscxmlinvokableservice.h>
#include <qscxmltabledata.h>
#include <QtCore/qtmochelpers.h>
#include <QScxmlNullDataModel>

#if !defined(Q_QSCXMLC_OUTPUT_REVISION)
#error "The header file 'CyberKillChain.scxml' doesn't include <qscxmltabledata.h>."
#elif Q_QSCXMLC_OUTPUT_REVISION != 2
#error "This file was generated using the qscxmlc from 6.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The qscxmlc has changed too much.)"
#endif

struct CyberKillChain::Data: private QScxmlTableData {
    Data(CyberKillChain &stateMachine)
        : stateMachine(stateMachine)
    {}

    void init() {
        stateMachine.setTableData(this);
        stateMachine.setDataModel(&dataModel);
    }

    QString name() const override final
    { return string(0); }

    QScxmlExecutableContent::ContainerId initialSetup() const override final
    { return -1; }

    QScxmlExecutableContent::InstructionId *instructions() const override final
    { return theInstructions; }

    QScxmlExecutableContent::StringId *dataNames(int *count) const override final
    { *count = 0; return dataIds; }

    QScxmlExecutableContent::EvaluatorInfo evaluatorInfo(QScxmlExecutableContent::EvaluatorId evaluatorId) const override final
    { Q_ASSERT(evaluatorId >= 0); Q_ASSERT(evaluatorId < 0); return evaluators[evaluatorId]; }

    QScxmlExecutableContent::AssignmentInfo assignmentInfo(QScxmlExecutableContent::EvaluatorId assignmentId) const override final
    { Q_ASSERT(assignmentId >= 0); Q_ASSERT(assignmentId < 0); return assignments[assignmentId]; }

    QScxmlExecutableContent::ForeachInfo foreachInfo(QScxmlExecutableContent::EvaluatorId foreachId) const override final
    { Q_ASSERT(foreachId >= 0); Q_ASSERT(foreachId < 0); return foreaches[foreachId]; }

    QString string(QScxmlExecutableContent::StringId id) const override final
    {
        Q_ASSERT(id >= QScxmlExecutableContent::NoString); Q_ASSERT(id < 56);
        if (id == QScxmlExecutableContent::NoString) return QString();
        const auto dataOffset = strings.offsetsAndSize[id * 2];
        const auto dataSize = strings.offsetsAndSize[id * 2 + 1];
        return QString::fromRawData(reinterpret_cast<const QChar*>(&strings.stringdata[dataOffset]), dataSize);
    }

    const qint32 *stateMachineTable() const override final
    { return theStateMachineTable; }

    QScxmlInvokableServiceFactory *serviceFactory(int id) const override final;

    CyberKillChain &stateMachine;
    QScxmlNullDataModel dataModel;

    static QScxmlExecutableContent::ParameterInfo param(QScxmlExecutableContent::StringId name,
                                                        QScxmlExecutableContent::EvaluatorId expr,
                                                        QScxmlExecutableContent::StringId location)
    {
        QScxmlExecutableContent::ParameterInfo p;
        p.name = name;
        p.expr = expr;
        p.location = location;
        return p;
    }

    static QScxmlExecutableContent::InvokeInfo invoke(
            QScxmlExecutableContent::StringId id,
            QScxmlExecutableContent::StringId prefix,
            QScxmlExecutableContent::EvaluatorId expr,
            QScxmlExecutableContent::StringId location,
            QScxmlExecutableContent::StringId context,
            QScxmlExecutableContent::ContainerId finalize,
            bool autoforward)
    {
        QScxmlExecutableContent::InvokeInfo i;
        i.id = id;
        i.prefix = prefix;
        i.expr = expr;
        i.location = location;
        i.context = context;
        i.finalize = finalize;
        i.autoforward = autoforward;
        return i;
    }

    static qint32 theInstructions[];
    static QScxmlExecutableContent::StringId dataIds[];
    static QScxmlExecutableContent::EvaluatorInfo evaluators[];
    static QScxmlExecutableContent::AssignmentInfo assignments[];
    static QScxmlExecutableContent::ForeachInfo foreaches[];
    static const qint32 theStateMachineTable[];
    static struct Strings {
        const uint offsetsAndSize[56 * 2];
        char16_t stringdata[1034];
    } strings;
};

CyberKillChain::CyberKillChain(QObject *parent)
    : QScxmlStateMachine(&staticMetaObject, parent)
    , data(new Data(*this))
{ qRegisterMetaType<CyberKillChain *>(); data->init(); }

CyberKillChain::~CyberKillChain()
{ delete data; }

QScxmlInvokableServiceFactory *CyberKillChain::Data::serviceFactory(int id) const
{
    Q_UNUSED(id);
    Q_UNREACHABLE();
}

qint32 CyberKillChain::Data::theInstructions[] = {
12, 55, -1, -1, 0
};

QScxmlExecutableContent::StringId CyberKillChain::Data::dataIds[] = {
-1
};

QScxmlExecutableContent::EvaluatorInfo CyberKillChain::Data::evaluators[] = {
{ -1, -1 }
};

QScxmlExecutableContent::AssignmentInfo CyberKillChain::Data::assignments[] = {
{ -1, -1, -1 }
};

QScxmlExecutableContent::ForeachInfo CyberKillChain::Data::foreaches[] = {
{ -1, -1, -1, -1 }
};

CyberKillChain::Data::Strings CyberKillChain::Data::strings = {{
0, 14, 15, 10, 26, 9, 36, 15, 52, 14, 67, 16, 84, 16, 101, 17, 119, 26, 146, 23,
170, 10, 181, 9, 191, 26, 218, 25, 244, 22, 267, 20, 288, 18, 307, 11, 319, 10,
330, 17, 348, 14, 363, 17, 381, 14, 396, 17, 414, 14, 429, 13, 443, 24, 468, 25,
494, 20, 515, 19, 535, 24, 560, 32, 593, 14, 608, 20, 629, 19, 649, 19, 669, 29,
699, 17, 717, 25, 743, 15, 759, 14, 774, 15, 790, 16, 807, 10, 818, 9, 828, 22,
851, 13, 865, 23, 889, 22, 912, 11, 924, 17, 942, 11, 954, 24, 979, 14, 994, 4,
999, 33
},{
0x43,0x79,0x62,0x65,0x72,0x4b,0x69,0x6c,0x6c,0x43,0x68,0x61,0x69,0x6e,0, // 0: CyberKillChain
0x45,0x78,0x70,0x6c,0x6f,0x69,0x74,0x69,0x6e,0x67,0, // 1: Exploiting
0x45,0x78,0x70,0x6c,0x6f,0x69,0x74,0x65,0x64,0, // 2: Exploited
0x53,0x65,0x6c,0x65,0x63,0x74,0x69,0x6e,0x67,0x54,0x61,0x72,0x67,0x65,0x74,0, // 3: SelectingTarget
0x53,0x65,0x6c,0x65,0x63,0x74,0x65,0x64,0x54,0x61,0x72,0x67,0x65,0x74,0, // 4: SelectedTarget
0x53,0x65,0x6c,0x65,0x63,0x74,0x69,0x6e,0x67,0x45,0x78,0x70,0x6c,0x6f,0x69,0x74,0, // 5: SelectingExploit
0x45,0x78,0x70,0x6c,0x6f,0x69,0x74,0x44,0x65,0x76,0x65,0x6c,0x6f,0x70,0x65,0x64,0, // 6: ExploitDeveloped
0x41,0x64,0x76,0x65,0x72,0x73,0x61,0x72,0x79,0x4f,0x72,0x56,0x69,0x63,0x74,0x69,0x6d,0, // 7: AdversaryOrVictim
0x41,0x64,0x76,0x65,0x72,0x73,0x61,0x72,0x79,0x54,0x72,0x69,0x67,0x67,0x65,0x72,0x69,0x6e,0x67,0x45,0x78,0x70,0x6c,0x6f,0x69,0x74,0, // 8: AdversaryTriggeringExploit
0x56,0x69,0x63,0x74,0x69,0x6d,0x54,0x72,0x69,0x67,0x67,0x65,0x72,0x69,0x6e,0x67,0x45,0x78,0x70,0x6c,0x6f,0x69,0x74,0, // 9: VictimTriggeringExploit
0x44,0x65,0x6c,0x69,0x76,0x65,0x72,0x69,0x6e,0x67,0, // 10: Delivering
0x44,0x65,0x6c,0x69,0x76,0x65,0x72,0x65,0x64,0, // 11: Delivered
0x53,0x65,0x6c,0x65,0x63,0x74,0x69,0x6e,0x67,0x44,0x65,0x6c,0x69,0x76,0x65,0x72,0x79,0x4d,0x65,0x63,0x68,0x61,0x6e,0x69,0x73,0x6d,0, // 12: SelectingDeliveryMechanism
0x44,0x65,0x6c,0x69,0x76,0x65,0x72,0x79,0x4d,0x65,0x63,0x68,0x61,0x6e,0x69,0x73,0x6d,0x53,0x65,0x6c,0x65,0x63,0x74,0x65,0x64,0, // 13: DeliveryMechanismSelected
0x43,0x6f,0x6e,0x74,0x72,0x6f,0x6c,0x6c,0x69,0x6e,0x67,0x4f,0x72,0x52,0x65,0x6c,0x65,0x61,0x73,0x69,0x6e,0x67,0, // 14: ControllingOrReleasing
0x41,0x64,0x76,0x65,0x72,0x73,0x61,0x72,0x79,0x43,0x6f,0x6e,0x74,0x72,0x6f,0x6c,0x6c,0x69,0x6e,0x67,0, // 15: AdversaryControlling
0x41,0x64,0x76,0x65,0x72,0x73,0x61,0x72,0x79,0x52,0x65,0x6c,0x65,0x61,0x73,0x69,0x6e,0x67,0, // 16: AdversaryReleasing
0x57,0x65,0x61,0x70,0x6f,0x6e,0x69,0x73,0x69,0x6e,0x67,0, // 17: Weaponising
0x57,0x65,0x61,0x70,0x6f,0x6e,0x69,0x73,0x65,0x64,0, // 18: Weaponised
0x44,0x65,0x76,0x65,0x6c,0x6f,0x70,0x69,0x6e,0x67,0x45,0x78,0x70,0x6c,0x6f,0x69,0x74,0, // 19: DevelopingExploit
0x44,0x65,0x76,0x65,0x6c,0x6f,0x70,0x45,0x78,0x70,0x6c,0x6f,0x69,0x74,0, // 20: DevelopExploit
0x44,0x65,0x76,0x65,0x6c,0x6f,0x70,0x69,0x6e,0x67,0x4d,0x61,0x6c,0x77,0x61,0x72,0x65,0, // 21: DevelopingMalware
0x44,0x65,0x76,0x65,0x6c,0x6f,0x70,0x50,0x61,0x79,0x6c,0x6f,0x61,0x64,0, // 22: DevelopPayload
0x44,0x65,0x76,0x65,0x6c,0x6f,0x70,0x69,0x6e,0x67,0x50,0x61,0x79,0x6c,0x6f,0x61,0x64,0, // 23: DevelopingPayload
0x52,0x65,0x63,0x6f,0x6e,0x6e,0x61,0x69,0x73,0x73,0x61,0x6e,0x63,0x65,0, // 24: Reconnaissance
0x49,0x6e,0x74,0x65,0x6c,0x47,0x61,0x74,0x68,0x65,0x72,0x65,0x64,0, // 25: IntelGathered
0x48,0x61,0x72,0x76,0x65,0x73,0x74,0x69,0x6e,0x67,0x45,0x6d,0x61,0x69,0x6c,0x41,0x64,0x64,0x72,0x65,0x73,0x73,0x65,0x73,0, // 26: HarvestingEmailAddresses
0x45,0x6e,0x75,0x6d,0x65,0x72,0x61,0x74,0x65,0x50,0x75,0x62,0x6c,0x69,0x63,0x54,0x65,0x63,0x68,0x6e,0x6f,0x6c,0x6f,0x67,0x79,0, // 27: EnumeratePublicTechnology
0x49,0x64,0x65,0x6e,0x74,0x69,0x66,0x79,0x69,0x6e,0x67,0x45,0x6d,0x70,0x6c,0x6f,0x79,0x65,0x65,0x73,0, // 28: IdentifyingEmployees
0x43,0x6f,0x6c,0x6c,0x65,0x63,0x74,0x69,0x6e,0x67,0x4d,0x61,0x72,0x6b,0x65,0x74,0x69,0x6e,0x67,0, // 29: CollectingMarketing
0x54,0x61,0x6b,0x69,0x6e,0x67,0x41,0x63,0x74,0x69,0x6f,0x6e,0x4f,0x6e,0x4f,0x62,0x6a,0x65,0x63,0x74,0x69,0x76,0x65,0x73,0, // 30: TakingActionOnObjectives
0x50,0x65,0x72,0x66,0x6f,0x72,0x6d,0x69,0x6e,0x67,0x49,0x6e,0x74,0x65,0x72,0x6e,0x61,0x6c,0x52,0x65,0x63,0x6f,0x6e,0x6e,0x61,0x69,0x73,0x73,0x61,0x6e,0x63,0x65,0, // 31: PerformingInternalReconnaissance
0x52,0x65,0x63,0x6f,0x6e,0x50,0x65,0x72,0x66,0x6f,0x72,0x6d,0x65,0x64,0, // 32: ReconPerformed
0x45,0x73,0x63,0x61,0x6c,0x61,0x74,0x69,0x6e,0x67,0x50,0x72,0x69,0x76,0x69,0x6c,0x65,0x67,0x65,0x73,0, // 33: EscalatingPrivileges
0x50,0x72,0x69,0x76,0x69,0x6c,0x69,0x67,0x65,0x73,0x45,0x73,0x63,0x61,0x6c,0x61,0x74,0x65,0x64,0, // 34: PriviligesEscalated
0x4d,0x61,0x6c,0x69,0x63,0x69,0x6f,0x75,0x73,0x41,0x63,0x74,0x69,0x76,0x69,0x74,0x69,0x65,0x73,0, // 35: MaliciousActivities
0x43,0x6f,0x6c,0x6c,0x65,0x63,0x74,0x69,0x6e,0x67,0x41,0x6e,0x64,0x45,0x78,0x66,0x69,0x6c,0x74,0x72,0x61,0x74,0x69,0x6e,0x67,0x44,0x61,0x74,0x61,0, // 36: CollectingAndExfiltratingData
0x44,0x65,0x73,0x74,0x72,0x6f,0x79,0x69,0x6e,0x67,0x53,0x79,0x73,0x74,0x65,0x6d,0x73,0, // 37: DestroyingSystems
0x4f,0x76,0x65,0x72,0x77,0x72,0x69,0x74,0x69,0x6e,0x67,0x43,0x6f,0x72,0x72,0x75,0x70,0x74,0x69,0x6e,0x67,0x44,0x61,0x74,0x61,0, // 38: OverwritingCorruptingData
0x43,0x6f,0x6c,0x6c,0x65,0x63,0x74,0x69,0x6e,0x67,0x43,0x72,0x65,0x64,0x73,0, // 39: CollectingCreds
0x43,0x72,0x65,0x64,0x73,0x43,0x6f,0x6c,0x6c,0x65,0x63,0x74,0x65,0x64,0, // 40: CredsCollected
0x4d,0x6f,0x76,0x69,0x6e,0x67,0x4c,0x61,0x74,0x65,0x72,0x61,0x6c,0x6c,0x79,0, // 41: MovingLaterally
0x4d,0x6f,0x76,0x65,0x6d,0x65,0x6e,0x74,0x43,0x6f,0x6d,0x70,0x6c,0x65,0x74,0x65,0, // 42: MovementComplete
0x49,0x6e,0x73,0x74,0x61,0x6c,0x6c,0x69,0x6e,0x67,0, // 43: Installing
0x49,0x6e,0x73,0x74,0x61,0x6c,0x6c,0x65,0x64,0, // 44: Installed
0x49,0x6e,0x73,0x74,0x61,0x6c,0x6c,0x69,0x6e,0x67,0x41,0x63,0x63,0x65,0x73,0x73,0x50,0x6f,0x69,0x6e,0x74,0x73,0, // 45: InstallingAccessPoints
0x41,0x63,0x63,0x65,0x73,0x73,0x45,0x6e,0x61,0x62,0x6c,0x65,0x64,0, // 46: AccessEnabled
0x45,0x73,0x74,0x61,0x62,0x6c,0x69,0x73,0x68,0x69,0x6e,0x67,0x50,0x65,0x72,0x73,0x69,0x73,0x74,0x65,0x6e,0x63,0x65,0, // 47: EstablishingPersistence
0x50,0x65,0x72,0x73,0x69,0x73,0x74,0x65,0x6e,0x63,0x65,0x45,0x73,0x74,0x61,0x62,0x6c,0x69,0x73,0x68,0x65,0x64,0, // 48: PersistenceEstablished
0x43,0x6f,0x76,0x65,0x72,0x54,0x72,0x61,0x63,0x6b,0x73,0, // 49: CoverTracks
0x43,0x6f,0x6d,0x6d,0x61,0x6e,0x64,0x41,0x6e,0x64,0x43,0x6f,0x6e,0x74,0x72,0x6f,0x6c,0, // 50: CommandAndControl
0x43,0x6f,0x6e,0x74,0x72,0x6f,0x6c,0x6c,0x69,0x6e,0x67,0, // 51: Controlling
0x43,0x6f,0x6e,0x6e,0x65,0x63,0x74,0x69,0x6e,0x67,0x54,0x6f,0x41,0x63,0x63,0x65,0x73,0x73,0x50,0x6f,0x69,0x6e,0x74,0x73,0, // 52: ConnectingToAccessPoints
0x41,0x74,0x74,0x61,0x63,0x6b,0x43,0x6f,0x6d,0x70,0x6c,0x65,0x74,0x65,0, // 53: AttackComplete
0x45,0x78,0x69,0x74,0, // 54: Exit
0x66,0x69,0x6e,0x61,0x6c,0x20,0x69,0x6e,0x73,0x74,0x72,0x75,0x63,0x74,0x69,0x6f,0x6e,0x20,0x69,0x6e,0x20,0x73,0x74,0x61,0x74,0x65,0x20,0x28,0x6e,0x6f,0x6e,0x65,0x29,0 // 55: final instruction in state (none)
}};

const qint32 CyberKillChain::Data::theStateMachineTable[] = {
	0x2, // version
	0, // name
	0, // data-model
	183, // child states array offset
	18, // transition to initial states
	-1, // initial setup
	0, // binding
	-1, // maxServiceId
	14, 37, // state offset and count
	421, 30, // transition offset and count
	601, 188, // array offset and size

	// States:
	0, -1, 0, 19, -1, -1, -1, -1, 171, 179, -1,
	1, 0, 0, 20, -1, -1, -1, -1, 22, 26, -1,
	3, 1, 0, -1, -1, -1, -1, -1, -1, 8, -1,
	5, 1, 0, -1, -1, -1, -1, -1, -1, 14, -1,
	7, 1, 1, 21, -1, -1, -1, -1, 16, -1, -1,
	8, 4, 0, -1, -1, -1, -1, -1, -1, -1, -1,
	9, 4, 0, -1, -1, -1, -1, -1, -1, -1, -1,
	10, 0, 0, 22, -1, -1, -1, -1, 46, 49, -1,
	12, 7, 0, -1, -1, -1, -1, -1, -1, 38, -1,
	14, 7, 1, 23, -1, -1, -1, -1, 40, -1, -1,
	15, 9, 0, -1, -1, -1, -1, -1, -1, -1, -1,
	16, 9, 0, -1, -1, -1, -1, -1, -1, -1, -1,
	17, 0, 0, 24, -1, -1, -1, -1, 69, 73, -1,
	19, 12, 0, -1, -1, -1, -1, -1, -1, 61, -1,
	21, 12, 0, -1, -1, -1, -1, -1, -1, 67, -1,
	23, 12, 0, -1, -1, -1, -1, -1, -1, -1, -1,
	24, 0, 1, 25, -1, -1, -1, -1, 81, 86, -1,
	26, 16, 0, -1, -1, -1, -1, -1, -1, -1, -1,
	27, 16, 0, -1, -1, -1, -1, -1, -1, -1, -1,
	28, 16, 0, -1, -1, -1, -1, -1, -1, -1, -1,
	29, 16, 0, -1, -1, -1, -1, -1, -1, -1, -1,
	30, 0, 0, 26, -1, -1, -1, -1, 125, -1, -1,
	31, 21, 0, -1, -1, -1, -1, -1, -1, 97, -1,
	33, 21, 0, -1, -1, -1, -1, -1, -1, 103, -1,
	35, 21, 1, 27, -1, -1, -1, -1, 105, -1, -1,
	36, 24, 0, -1, -1, -1, -1, -1, -1, -1, -1,
	37, 24, 0, -1, -1, -1, -1, -1, -1, -1, -1,
	38, 24, 0, -1, -1, -1, -1, -1, -1, -1, -1,
	39, 21, 0, -1, -1, -1, -1, -1, -1, 117, -1,
	41, 21, 0, -1, -1, -1, -1, -1, -1, 123, -1,
	43, 0, 0, 28, -1, -1, -1, -1, 149, 153, -1,
	45, 30, 0, -1, -1, -1, -1, -1, -1, 141, -1,
	47, 30, 0, -1, -1, -1, -1, -1, -1, 147, -1,
	49, 30, 0, -1, -1, -1, -1, -1, -1, -1, -1,
	50, 0, 0, 29, -1, -1, -1, -1, 161, 163, -1,
	52, 34, 0, -1, -1, -1, -1, -1, -1, -1, -1,
	54, -1, 2, -1, -1, -1, -1, 0, -1, -1, -1,

	// Transitions:
	2, -1, 1, 1, 0, -1, 
	6, -1, 1, 2, 4, -1, 
	12, -1, 1, 3, 10, -1, 
	32, -1, 1, 7, 30, -1, 
	36, -1, 1, 8, 34, -1, 
	55, -1, 1, 12, 53, -1, 
	59, -1, 1, 13, 57, -1, 
	65, -1, 1, 14, 63, -1, 
	79, -1, 1, 16, 77, -1, 
	95, -1, 1, 22, 93, -1, 
	101, -1, 1, 23, 99, -1, 
	115, -1, 1, 28, 113, -1, 
	121, -1, 1, 29, 119, -1, 
	135, -1, 1, 30, 133, -1, 
	139, -1, 1, 31, 137, -1, 
	145, -1, 1, 32, 143, -1, 
	159, -1, 0, 34, 157, -1, 
	169, -1, 1, 0, 167, -1, 
	-1, -1, 2, -1, 186, -1, 
	-1, -1, 2, 0, 181, -1, 
	-1, -1, 2, 1, 28, -1, 
	-1, -1, 2, 4, 19, -1, 
	-1, -1, 2, 7, 51, -1, 
	-1, -1, 2, 9, 43, -1, 
	-1, -1, 2, 12, 75, -1, 
	-1, -1, 2, 16, 88, -1, 
	-1, -1, 2, 21, 131, -1, 
	-1, -1, 2, 24, 109, -1, 
	-1, -1, 2, 30, 155, -1, 
	-1, -1, 2, 34, 165, -1, 

	// Arrays:
	1, 30, 
	1, 2, 
	1, 3, 
	1, 4, 
	1, 1, 
	1, 4, 
	1, 6, 
	1, 2, 
	2, 5, 6, 
	2, 5, 6, 
	3, 2, 3, 4, 
	1, 0, 
	1, 2, 
	1, 1, 
	1, 11, 
	1, 9, 
	1, 13, 
	1, 4, 
	2, 10, 11, 
	2, 10, 11, 
	2, 8, 9, 
	1, 3, 
	1, 8, 
	1, 7, 
	1, 18, 
	1, 14, 
	1, 20, 
	1, 6, 
	1, 15, 
	1, 22, 
	1, 7, 
	3, 13, 14, 15, 
	1, 5, 
	1, 13, 
	1, 12, 
	1, 25, 
	4, 17, 18, 19, 20, 
	1, 8, 
	4, 17, 18, 19, 20, 
	1, 29, 
	1, 32, 
	1, 9, 
	1, 22, 
	1, 34, 
	1, 10, 
	3, 25, 26, 27, 
	3, 25, 26, 27, 
	1, 23, 
	1, 40, 
	1, 11, 
	1, 24, 
	1, 42, 
	1, 12, 
	5, 22, 23, 24, 28, 29, 
	1, 28, 
	1, 34, 
	1, 44, 
	1, 32, 
	1, 46, 
	1, 14, 
	1, 33, 
	1, 48, 
	1, 15, 
	3, 31, 32, 33, 
	1, 13, 
	1, 31, 
	1, 21, 
	1, 51, 
	1, 35, 
	1, 16, 
	1, 35, 
	1, 36, 
	1, 53, 
	7, 1, 7, 12, 16, 21, 30, 34, 
	1, 17, 
	1, 16, 
	2, 0, 36, 
	1, 0, 

	0xc0ff33 // terminator
};

namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSCyberKillChainENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSCyberKillChainENDCLASS = QtMocHelpers::stringData(
    {char(0x43),char(0x79),char(0x62),char(0x65),char(0x72),char(0x4b),char(0x69),char(0x6c),char(0x6c),char(0x43),char(0x68),char(0x61),char(0x69),char(0x6e),char(0)}, // 0: CyberKillChain,
    {char(0x43),char(0x79),char(0x62),char(0x65),char(0x72),char(0x4b),char(0x69),char(0x6c),char(0x6c),char(0x43),char(0x68),char(0x61),char(0x69),char(0x6e),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 1: CyberKillChainChanged,
    {char(0)}, // 2: ,
    {char(0x61),char(0x63),char(0x74),char(0x69),char(0x76),char(0x65),char(0)}, // 3: active,
    {char(0x45),char(0x78),char(0x70),char(0x6c),char(0x6f),char(0x69),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 4: ExploitingChanged,
    {char(0x53),char(0x65),char(0x6c),char(0x65),char(0x63),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x54),char(0x61),char(0x72),char(0x67),char(0x65),char(0x74),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 5: SelectingTargetChanged,
    {char(0x53),char(0x65),char(0x6c),char(0x65),char(0x63),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x45),char(0x78),char(0x70),char(0x6c),char(0x6f),char(0x69),char(0x74),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 6: SelectingExploitChanged,
    {char(0x41),char(0x64),char(0x76),char(0x65),char(0x72),char(0x73),char(0x61),char(0x72),char(0x79),char(0x4f),char(0x72),char(0x56),char(0x69),char(0x63),char(0x74),char(0x69),char(0x6d),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 7: AdversaryOrVictimChanged,
    {char(0x41),char(0x64),char(0x76),char(0x65),char(0x72),char(0x73),char(0x61),char(0x72),char(0x79),char(0x54),char(0x72),char(0x69),char(0x67),char(0x67),char(0x65),char(0x72),char(0x69),char(0x6e),char(0x67),char(0x45),char(0x78),char(0x70),char(0x6c),char(0x6f),char(0x69),char(0x74),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 8: AdversaryTriggeringExploitChanged,
    {char(0x56),char(0x69),char(0x63),char(0x74),char(0x69),char(0x6d),char(0x54),char(0x72),char(0x69),char(0x67),char(0x67),char(0x65),char(0x72),char(0x69),char(0x6e),char(0x67),char(0x45),char(0x78),char(0x70),char(0x6c),char(0x6f),char(0x69),char(0x74),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 9: VictimTriggeringExploitChanged,
    {char(0x44),char(0x65),char(0x6c),char(0x69),char(0x76),char(0x65),char(0x72),char(0x69),char(0x6e),char(0x67),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 10: DeliveringChanged,
    {char(0x53),char(0x65),char(0x6c),char(0x65),char(0x63),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x44),char(0x65),char(0x6c),char(0x69),char(0x76),char(0x65),char(0x72),char(0x79),char(0x4d),char(0x65),char(0x63),char(0x68),char(0x61),char(0x6e),char(0x69),char(0x73),char(0x6d),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 11: SelectingDeliveryMechanismChanged,
    {char(0x43),char(0x6f),char(0x6e),char(0x74),char(0x72),char(0x6f),char(0x6c),char(0x6c),char(0x69),char(0x6e),char(0x67),char(0x4f),char(0x72),char(0x52),char(0x65),char(0x6c),char(0x65),char(0x61),char(0x73),char(0x69),char(0x6e),char(0x67),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 12: ControllingOrReleasingChanged,
    {char(0x41),char(0x64),char(0x76),char(0x65),char(0x72),char(0x73),char(0x61),char(0x72),char(0x79),char(0x43),char(0x6f),char(0x6e),char(0x74),char(0x72),char(0x6f),char(0x6c),char(0x6c),char(0x69),char(0x6e),char(0x67),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 13: AdversaryControllingChanged,
    {char(0x41),char(0x64),char(0x76),char(0x65),char(0x72),char(0x73),char(0x61),char(0x72),char(0x79),char(0x52),char(0x65),char(0x6c),char(0x65),char(0x61),char(0x73),char(0x69),char(0x6e),char(0x67),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 14: AdversaryReleasingChanged,
    {char(0x57),char(0x65),char(0x61),char(0x70),char(0x6f),char(0x6e),char(0x69),char(0x73),char(0x69),char(0x6e),char(0x67),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 15: WeaponisingChanged,
    {char(0x44),char(0x65),char(0x76),char(0x65),char(0x6c),char(0x6f),char(0x70),char(0x69),char(0x6e),char(0x67),char(0x45),char(0x78),char(0x70),char(0x6c),char(0x6f),char(0x69),char(0x74),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 16: DevelopingExploitChanged,
    {char(0x44),char(0x65),char(0x76),char(0x65),char(0x6c),char(0x6f),char(0x70),char(0x69),char(0x6e),char(0x67),char(0x4d),char(0x61),char(0x6c),char(0x77),char(0x61),char(0x72),char(0x65),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 17: DevelopingMalwareChanged,
    {char(0x44),char(0x65),char(0x76),char(0x65),char(0x6c),char(0x6f),char(0x70),char(0x69),char(0x6e),char(0x67),char(0x50),char(0x61),char(0x79),char(0x6c),char(0x6f),char(0x61),char(0x64),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 18: DevelopingPayloadChanged,
    {char(0x52),char(0x65),char(0x63),char(0x6f),char(0x6e),char(0x6e),char(0x61),char(0x69),char(0x73),char(0x73),char(0x61),char(0x6e),char(0x63),char(0x65),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 19: ReconnaissanceChanged,
    {char(0x48),char(0x61),char(0x72),char(0x76),char(0x65),char(0x73),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x45),char(0x6d),char(0x61),char(0x69),char(0x6c),char(0x41),char(0x64),char(0x64),char(0x72),char(0x65),char(0x73),char(0x73),char(0x65),char(0x73),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 20: HarvestingEmailAddressesChanged,
    {char(0x45),char(0x6e),char(0x75),char(0x6d),char(0x65),char(0x72),char(0x61),char(0x74),char(0x65),char(0x50),char(0x75),char(0x62),char(0x6c),char(0x69),char(0x63),char(0x54),char(0x65),char(0x63),char(0x68),char(0x6e),char(0x6f),char(0x6c),char(0x6f),char(0x67),char(0x79),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 21: EnumeratePublicTechnologyChanged,
    {char(0x49),char(0x64),char(0x65),char(0x6e),char(0x74),char(0x69),char(0x66),char(0x79),char(0x69),char(0x6e),char(0x67),char(0x45),char(0x6d),char(0x70),char(0x6c),char(0x6f),char(0x79),char(0x65),char(0x65),char(0x73),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 22: IdentifyingEmployeesChanged,
    {char(0x43),char(0x6f),char(0x6c),char(0x6c),char(0x65),char(0x63),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x4d),char(0x61),char(0x72),char(0x6b),char(0x65),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 23: CollectingMarketingChanged,
    {char(0x54),char(0x61),char(0x6b),char(0x69),char(0x6e),char(0x67),char(0x41),char(0x63),char(0x74),char(0x69),char(0x6f),char(0x6e),char(0x4f),char(0x6e),char(0x4f),char(0x62),char(0x6a),char(0x65),char(0x63),char(0x74),char(0x69),char(0x76),char(0x65),char(0x73),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 24: TakingActionOnObjectivesChanged,
    {char(0x50),char(0x65),char(0x72),char(0x66),char(0x6f),char(0x72),char(0x6d),char(0x69),char(0x6e),char(0x67),char(0x49),char(0x6e),char(0x74),char(0x65),char(0x72),char(0x6e),char(0x61),char(0x6c),char(0x52),char(0x65),char(0x63),char(0x6f),char(0x6e),char(0x6e),char(0x61),char(0x69),char(0x73),char(0x73),char(0x61),char(0x6e),char(0x63),char(0x65),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 25: PerformingInternalReconnaissanceChanged,
    {char(0x45),char(0x73),char(0x63),char(0x61),char(0x6c),char(0x61),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x50),char(0x72),char(0x69),char(0x76),char(0x69),char(0x6c),char(0x65),char(0x67),char(0x65),char(0x73),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 26: EscalatingPrivilegesChanged,
    {char(0x4d),char(0x61),char(0x6c),char(0x69),char(0x63),char(0x69),char(0x6f),char(0x75),char(0x73),char(0x41),char(0x63),char(0x74),char(0x69),char(0x76),char(0x69),char(0x74),char(0x69),char(0x65),char(0x73),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 27: MaliciousActivitiesChanged,
    {char(0x43),char(0x6f),char(0x6c),char(0x6c),char(0x65),char(0x63),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x41),char(0x6e),char(0x64),char(0x45),char(0x78),char(0x66),char(0x69),char(0x6c),char(0x74),char(0x72),char(0x61),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x44),char(0x61),char(0x74),char(0x61),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 28: CollectingAndExfiltratingDataChanged,
    {char(0x44),char(0x65),char(0x73),char(0x74),char(0x72),char(0x6f),char(0x79),char(0x69),char(0x6e),char(0x67),char(0x53),char(0x79),char(0x73),char(0x74),char(0x65),char(0x6d),char(0x73),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 29: DestroyingSystemsChanged,
    {char(0x4f),char(0x76),char(0x65),char(0x72),char(0x77),char(0x72),char(0x69),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x43),char(0x6f),char(0x72),char(0x72),char(0x75),char(0x70),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x44),char(0x61),char(0x74),char(0x61),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 30: OverwritingCorruptingDataChanged,
    {char(0x43),char(0x6f),char(0x6c),char(0x6c),char(0x65),char(0x63),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x43),char(0x72),char(0x65),char(0x64),char(0x73),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 31: CollectingCredsChanged,
    {char(0x4d),char(0x6f),char(0x76),char(0x69),char(0x6e),char(0x67),char(0x4c),char(0x61),char(0x74),char(0x65),char(0x72),char(0x61),char(0x6c),char(0x6c),char(0x79),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 32: MovingLaterallyChanged,
    {char(0x49),char(0x6e),char(0x73),char(0x74),char(0x61),char(0x6c),char(0x6c),char(0x69),char(0x6e),char(0x67),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 33: InstallingChanged,
    {char(0x49),char(0x6e),char(0x73),char(0x74),char(0x61),char(0x6c),char(0x6c),char(0x69),char(0x6e),char(0x67),char(0x41),char(0x63),char(0x63),char(0x65),char(0x73),char(0x73),char(0x50),char(0x6f),char(0x69),char(0x6e),char(0x74),char(0x73),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 34: InstallingAccessPointsChanged,
    {char(0x45),char(0x73),char(0x74),char(0x61),char(0x62),char(0x6c),char(0x69),char(0x73),char(0x68),char(0x69),char(0x6e),char(0x67),char(0x50),char(0x65),char(0x72),char(0x73),char(0x69),char(0x73),char(0x74),char(0x65),char(0x6e),char(0x63),char(0x65),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 35: EstablishingPersistenceChanged,
    {char(0x43),char(0x6f),char(0x76),char(0x65),char(0x72),char(0x54),char(0x72),char(0x61),char(0x63),char(0x6b),char(0x73),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 36: CoverTracksChanged,
    {char(0x43),char(0x6f),char(0x6d),char(0x6d),char(0x61),char(0x6e),char(0x64),char(0x41),char(0x6e),char(0x64),char(0x43),char(0x6f),char(0x6e),char(0x74),char(0x72),char(0x6f),char(0x6c),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 37: CommandAndControlChanged,
    {char(0x43),char(0x6f),char(0x6e),char(0x6e),char(0x65),char(0x63),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x54),char(0x6f),char(0x41),char(0x63),char(0x63),char(0x65),char(0x73),char(0x73),char(0x50),char(0x6f),char(0x69),char(0x6e),char(0x74),char(0x73),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 38: ConnectingToAccessPointsChanged,
    {char(0x45),char(0x78),char(0x69),char(0x74),char(0x43),char(0x68),char(0x61),char(0x6e),char(0x67),char(0x65),char(0x64),char(0)}, // 39: ExitChanged,
    {char(0x51),char(0x4f),char(0x62),char(0x6a),char(0x65),char(0x63),char(0x74),char(0x20),char(0x2a),char(0)}, // 40: QObject *,
    {char(0x70),char(0x61),char(0x72),char(0x65),char(0x6e),char(0x74),char(0)}, // 41: parent,
    {char(0x45),char(0x78),char(0x70),char(0x6c),char(0x6f),char(0x69),char(0x74),char(0x69),char(0x6e),char(0x67),char(0)}, // 42: Exploiting,
    {char(0x53),char(0x65),char(0x6c),char(0x65),char(0x63),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x54),char(0x61),char(0x72),char(0x67),char(0x65),char(0x74),char(0)}, // 43: SelectingTarget,
    {char(0x53),char(0x65),char(0x6c),char(0x65),char(0x63),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x45),char(0x78),char(0x70),char(0x6c),char(0x6f),char(0x69),char(0x74),char(0)}, // 44: SelectingExploit,
    {char(0x41),char(0x64),char(0x76),char(0x65),char(0x72),char(0x73),char(0x61),char(0x72),char(0x79),char(0x4f),char(0x72),char(0x56),char(0x69),char(0x63),char(0x74),char(0x69),char(0x6d),char(0)}, // 45: AdversaryOrVictim,
    {char(0x41),char(0x64),char(0x76),char(0x65),char(0x72),char(0x73),char(0x61),char(0x72),char(0x79),char(0x54),char(0x72),char(0x69),char(0x67),char(0x67),char(0x65),char(0x72),char(0x69),char(0x6e),char(0x67),char(0x45),char(0x78),char(0x70),char(0x6c),char(0x6f),char(0x69),char(0x74),char(0)}, // 46: AdversaryTriggeringExploit,
    {char(0x56),char(0x69),char(0x63),char(0x74),char(0x69),char(0x6d),char(0x54),char(0x72),char(0x69),char(0x67),char(0x67),char(0x65),char(0x72),char(0x69),char(0x6e),char(0x67),char(0x45),char(0x78),char(0x70),char(0x6c),char(0x6f),char(0x69),char(0x74),char(0)}, // 47: VictimTriggeringExploit,
    {char(0x44),char(0x65),char(0x6c),char(0x69),char(0x76),char(0x65),char(0x72),char(0x69),char(0x6e),char(0x67),char(0)}, // 48: Delivering,
    {char(0x53),char(0x65),char(0x6c),char(0x65),char(0x63),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x44),char(0x65),char(0x6c),char(0x69),char(0x76),char(0x65),char(0x72),char(0x79),char(0x4d),char(0x65),char(0x63),char(0x68),char(0x61),char(0x6e),char(0x69),char(0x73),char(0x6d),char(0)}, // 49: SelectingDeliveryMechanism,
    {char(0x43),char(0x6f),char(0x6e),char(0x74),char(0x72),char(0x6f),char(0x6c),char(0x6c),char(0x69),char(0x6e),char(0x67),char(0x4f),char(0x72),char(0x52),char(0x65),char(0x6c),char(0x65),char(0x61),char(0x73),char(0x69),char(0x6e),char(0x67),char(0)}, // 50: ControllingOrReleasing,
    {char(0x41),char(0x64),char(0x76),char(0x65),char(0x72),char(0x73),char(0x61),char(0x72),char(0x79),char(0x43),char(0x6f),char(0x6e),char(0x74),char(0x72),char(0x6f),char(0x6c),char(0x6c),char(0x69),char(0x6e),char(0x67),char(0)}, // 51: AdversaryControlling,
    {char(0x41),char(0x64),char(0x76),char(0x65),char(0x72),char(0x73),char(0x61),char(0x72),char(0x79),char(0x52),char(0x65),char(0x6c),char(0x65),char(0x61),char(0x73),char(0x69),char(0x6e),char(0x67),char(0)}, // 52: AdversaryReleasing,
    {char(0x57),char(0x65),char(0x61),char(0x70),char(0x6f),char(0x6e),char(0x69),char(0x73),char(0x69),char(0x6e),char(0x67),char(0)}, // 53: Weaponising,
    {char(0x44),char(0x65),char(0x76),char(0x65),char(0x6c),char(0x6f),char(0x70),char(0x69),char(0x6e),char(0x67),char(0x45),char(0x78),char(0x70),char(0x6c),char(0x6f),char(0x69),char(0x74),char(0)}, // 54: DevelopingExploit,
    {char(0x44),char(0x65),char(0x76),char(0x65),char(0x6c),char(0x6f),char(0x70),char(0x69),char(0x6e),char(0x67),char(0x4d),char(0x61),char(0x6c),char(0x77),char(0x61),char(0x72),char(0x65),char(0)}, // 55: DevelopingMalware,
    {char(0x44),char(0x65),char(0x76),char(0x65),char(0x6c),char(0x6f),char(0x70),char(0x69),char(0x6e),char(0x67),char(0x50),char(0x61),char(0x79),char(0x6c),char(0x6f),char(0x61),char(0x64),char(0)}, // 56: DevelopingPayload,
    {char(0x52),char(0x65),char(0x63),char(0x6f),char(0x6e),char(0x6e),char(0x61),char(0x69),char(0x73),char(0x73),char(0x61),char(0x6e),char(0x63),char(0x65),char(0)}, // 57: Reconnaissance,
    {char(0x48),char(0x61),char(0x72),char(0x76),char(0x65),char(0x73),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x45),char(0x6d),char(0x61),char(0x69),char(0x6c),char(0x41),char(0x64),char(0x64),char(0x72),char(0x65),char(0x73),char(0x73),char(0x65),char(0x73),char(0)}, // 58: HarvestingEmailAddresses,
    {char(0x45),char(0x6e),char(0x75),char(0x6d),char(0x65),char(0x72),char(0x61),char(0x74),char(0x65),char(0x50),char(0x75),char(0x62),char(0x6c),char(0x69),char(0x63),char(0x54),char(0x65),char(0x63),char(0x68),char(0x6e),char(0x6f),char(0x6c),char(0x6f),char(0x67),char(0x79),char(0)}, // 59: EnumeratePublicTechnology,
    {char(0x49),char(0x64),char(0x65),char(0x6e),char(0x74),char(0x69),char(0x66),char(0x79),char(0x69),char(0x6e),char(0x67),char(0x45),char(0x6d),char(0x70),char(0x6c),char(0x6f),char(0x79),char(0x65),char(0x65),char(0x73),char(0)}, // 60: IdentifyingEmployees,
    {char(0x43),char(0x6f),char(0x6c),char(0x6c),char(0x65),char(0x63),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x4d),char(0x61),char(0x72),char(0x6b),char(0x65),char(0x74),char(0x69),char(0x6e),char(0x67),char(0)}, // 61: CollectingMarketing,
    {char(0x54),char(0x61),char(0x6b),char(0x69),char(0x6e),char(0x67),char(0x41),char(0x63),char(0x74),char(0x69),char(0x6f),char(0x6e),char(0x4f),char(0x6e),char(0x4f),char(0x62),char(0x6a),char(0x65),char(0x63),char(0x74),char(0x69),char(0x76),char(0x65),char(0x73),char(0)}, // 62: TakingActionOnObjectives,
    {char(0x50),char(0x65),char(0x72),char(0x66),char(0x6f),char(0x72),char(0x6d),char(0x69),char(0x6e),char(0x67),char(0x49),char(0x6e),char(0x74),char(0x65),char(0x72),char(0x6e),char(0x61),char(0x6c),char(0x52),char(0x65),char(0x63),char(0x6f),char(0x6e),char(0x6e),char(0x61),char(0x69),char(0x73),char(0x73),char(0x61),char(0x6e),char(0x63),char(0x65),char(0)}, // 63: PerformingInternalReconnaissance,
    {char(0x45),char(0x73),char(0x63),char(0x61),char(0x6c),char(0x61),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x50),char(0x72),char(0x69),char(0x76),char(0x69),char(0x6c),char(0x65),char(0x67),char(0x65),char(0x73),char(0)}, // 64: EscalatingPrivileges,
    {char(0x4d),char(0x61),char(0x6c),char(0x69),char(0x63),char(0x69),char(0x6f),char(0x75),char(0x73),char(0x41),char(0x63),char(0x74),char(0x69),char(0x76),char(0x69),char(0x74),char(0x69),char(0x65),char(0x73),char(0)}, // 65: MaliciousActivities,
    {char(0x43),char(0x6f),char(0x6c),char(0x6c),char(0x65),char(0x63),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x41),char(0x6e),char(0x64),char(0x45),char(0x78),char(0x66),char(0x69),char(0x6c),char(0x74),char(0x72),char(0x61),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x44),char(0x61),char(0x74),char(0x61),char(0)}, // 66: CollectingAndExfiltratingData,
    {char(0x44),char(0x65),char(0x73),char(0x74),char(0x72),char(0x6f),char(0x79),char(0x69),char(0x6e),char(0x67),char(0x53),char(0x79),char(0x73),char(0x74),char(0x65),char(0x6d),char(0x73),char(0)}, // 67: DestroyingSystems,
    {char(0x4f),char(0x76),char(0x65),char(0x72),char(0x77),char(0x72),char(0x69),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x43),char(0x6f),char(0x72),char(0x72),char(0x75),char(0x70),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x44),char(0x61),char(0x74),char(0x61),char(0)}, // 68: OverwritingCorruptingData,
    {char(0x43),char(0x6f),char(0x6c),char(0x6c),char(0x65),char(0x63),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x43),char(0x72),char(0x65),char(0x64),char(0x73),char(0)}, // 69: CollectingCreds,
    {char(0x4d),char(0x6f),char(0x76),char(0x69),char(0x6e),char(0x67),char(0x4c),char(0x61),char(0x74),char(0x65),char(0x72),char(0x61),char(0x6c),char(0x6c),char(0x79),char(0)}, // 70: MovingLaterally,
    {char(0x49),char(0x6e),char(0x73),char(0x74),char(0x61),char(0x6c),char(0x6c),char(0x69),char(0x6e),char(0x67),char(0)}, // 71: Installing,
    {char(0x49),char(0x6e),char(0x73),char(0x74),char(0x61),char(0x6c),char(0x6c),char(0x69),char(0x6e),char(0x67),char(0x41),char(0x63),char(0x63),char(0x65),char(0x73),char(0x73),char(0x50),char(0x6f),char(0x69),char(0x6e),char(0x74),char(0x73),char(0)}, // 72: InstallingAccessPoints,
    {char(0x45),char(0x73),char(0x74),char(0x61),char(0x62),char(0x6c),char(0x69),char(0x73),char(0x68),char(0x69),char(0x6e),char(0x67),char(0x50),char(0x65),char(0x72),char(0x73),char(0x69),char(0x73),char(0x74),char(0x65),char(0x6e),char(0x63),char(0x65),char(0)}, // 73: EstablishingPersistence,
    {char(0x43),char(0x6f),char(0x76),char(0x65),char(0x72),char(0x54),char(0x72),char(0x61),char(0x63),char(0x6b),char(0x73),char(0)}, // 74: CoverTracks,
    {char(0x43),char(0x6f),char(0x6d),char(0x6d),char(0x61),char(0x6e),char(0x64),char(0x41),char(0x6e),char(0x64),char(0x43),char(0x6f),char(0x6e),char(0x74),char(0x72),char(0x6f),char(0x6c),char(0)}, // 75: CommandAndControl,
    {char(0x43),char(0x6f),char(0x6e),char(0x6e),char(0x65),char(0x63),char(0x74),char(0x69),char(0x6e),char(0x67),char(0x54),char(0x6f),char(0x41),char(0x63),char(0x63),char(0x65),char(0x73),char(0x73),char(0x50),char(0x6f),char(0x69),char(0x6e),char(0x74),char(0x73),char(0)}, // 76: ConnectingToAccessPoints,
    {char(0x45),char(0x78),char(0x69),char(0x74),char(0)} // 77: Exit
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCyberKillChainENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
      37,  350, // properties
       0,    0, // enums/sets
       1,  535, // constructors
       0,       // flags
      37,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  236,    2, 0x06,   38 /* Public */,
       4,    1,  239,    2, 0x06,   40 /* Public */,
       5,    1,  242,    2, 0x06,   42 /* Public */,
       6,    1,  245,    2, 0x06,   44 /* Public */,
       7,    1,  248,    2, 0x06,   46 /* Public */,
       8,    1,  251,    2, 0x06,   48 /* Public */,
       9,    1,  254,    2, 0x06,   50 /* Public */,
      10,    1,  257,    2, 0x06,   52 /* Public */,
      11,    1,  260,    2, 0x06,   54 /* Public */,
      12,    1,  263,    2, 0x06,   56 /* Public */,
      13,    1,  266,    2, 0x06,   58 /* Public */,
      14,    1,  269,    2, 0x06,   60 /* Public */,
      15,    1,  272,    2, 0x06,   62 /* Public */,
      16,    1,  275,    2, 0x06,   64 /* Public */,
      17,    1,  278,    2, 0x06,   66 /* Public */,
      18,    1,  281,    2, 0x06,   68 /* Public */,
      19,    1,  284,    2, 0x06,   70 /* Public */,
      20,    1,  287,    2, 0x06,   72 /* Public */,
      21,    1,  290,    2, 0x06,   74 /* Public */,
      22,    1,  293,    2, 0x06,   76 /* Public */,
      23,    1,  296,    2, 0x06,   78 /* Public */,
      24,    1,  299,    2, 0x06,   80 /* Public */,
      25,    1,  302,    2, 0x06,   82 /* Public */,
      26,    1,  305,    2, 0x06,   84 /* Public */,
      27,    1,  308,    2, 0x06,   86 /* Public */,
      28,    1,  311,    2, 0x06,   88 /* Public */,
      29,    1,  314,    2, 0x06,   90 /* Public */,
      30,    1,  317,    2, 0x06,   92 /* Public */,
      31,    1,  320,    2, 0x06,   94 /* Public */,
      32,    1,  323,    2, 0x06,   96 /* Public */,
      33,    1,  326,    2, 0x06,   98 /* Public */,
      34,    1,  329,    2, 0x06,  100 /* Public */,
      35,    1,  332,    2, 0x06,  102 /* Public */,
      36,    1,  335,    2, 0x06,  104 /* Public */,
      37,    1,  338,    2, 0x06,  106 /* Public */,
      38,    1,  341,    2, 0x06,  108 /* Public */,
      39,    1,  344,    2, 0x06,  110 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

 // constructors: parameters
    0x80000000 | 2, 0x80000000 | 40,   41,

 // properties: name, type, flags
       0, QMetaType::Bool, 0x00115001, uint(0), 0,
      42, QMetaType::Bool, 0x00115001, uint(1), 0,
      43, QMetaType::Bool, 0x00115001, uint(2), 0,
      44, QMetaType::Bool, 0x00115001, uint(3), 0,
      45, QMetaType::Bool, 0x00115001, uint(4), 0,
      46, QMetaType::Bool, 0x00115001, uint(5), 0,
      47, QMetaType::Bool, 0x00115001, uint(6), 0,
      48, QMetaType::Bool, 0x00115001, uint(7), 0,
      49, QMetaType::Bool, 0x00115001, uint(8), 0,
      50, QMetaType::Bool, 0x00115001, uint(9), 0,
      51, QMetaType::Bool, 0x00115001, uint(10), 0,
      52, QMetaType::Bool, 0x00115001, uint(11), 0,
      53, QMetaType::Bool, 0x00115001, uint(12), 0,
      54, QMetaType::Bool, 0x00115001, uint(13), 0,
      55, QMetaType::Bool, 0x00115001, uint(14), 0,
      56, QMetaType::Bool, 0x00115001, uint(15), 0,
      57, QMetaType::Bool, 0x00115001, uint(16), 0,
      58, QMetaType::Bool, 0x00115001, uint(17), 0,
      59, QMetaType::Bool, 0x00115001, uint(18), 0,
      60, QMetaType::Bool, 0x00115001, uint(19), 0,
      61, QMetaType::Bool, 0x00115001, uint(20), 0,
      62, QMetaType::Bool, 0x00115001, uint(21), 0,
      63, QMetaType::Bool, 0x00115001, uint(22), 0,
      64, QMetaType::Bool, 0x00115001, uint(23), 0,
      65, QMetaType::Bool, 0x00115001, uint(24), 0,
      66, QMetaType::Bool, 0x00115001, uint(25), 0,
      67, QMetaType::Bool, 0x00115001, uint(26), 0,
      68, QMetaType::Bool, 0x00115001, uint(27), 0,
      69, QMetaType::Bool, 0x00115001, uint(28), 0,
      70, QMetaType::Bool, 0x00115001, uint(29), 0,
      71, QMetaType::Bool, 0x00115001, uint(30), 0,
      72, QMetaType::Bool, 0x00115001, uint(31), 0,
      73, QMetaType::Bool, 0x00115001, uint(32), 0,
      74, QMetaType::Bool, 0x00115001, uint(33), 0,
      75, QMetaType::Bool, 0x00115001, uint(34), 0,
      76, QMetaType::Bool, 0x00115001, uint(35), 0,
      77, QMetaType::Bool, 0x00115001, uint(36), 0,

 // constructors: name, argc, parameters, tag, flags, initial metatype offsets
       0,    1,  347,    2, 0x0e,  112 /* Public */,

       0        // eod
};

Q_CONSTINIT const QMetaObject CyberKillChain::staticMetaObject = { {
    QMetaObject::SuperData::link<QScxmlStateMachine::staticMetaObject>(),
    qt_meta_stringdata_CLASSCyberKillChainENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCyberKillChainENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCyberKillChainENDCLASS_t,
        // property 'CyberKillChain'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'Exploiting'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'SelectingTarget'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'SelectingExploit'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'AdversaryOrVictim'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'AdversaryTriggeringExploit'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'VictimTriggeringExploit'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'Delivering'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'SelectingDeliveryMechanism'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'ControllingOrReleasing'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'AdversaryControlling'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'AdversaryReleasing'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'Weaponising'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'DevelopingExploit'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'DevelopingMalware'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'DevelopingPayload'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'Reconnaissance'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'HarvestingEmailAddresses'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'EnumeratePublicTechnology'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'IdentifyingEmployees'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'CollectingMarketing'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'TakingActionOnObjectives'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'PerformingInternalReconnaissance'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'EscalatingPrivileges'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'MaliciousActivities'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'CollectingAndExfiltratingData'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'DestroyingSystems'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'OverwritingCorruptingData'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'CollectingCreds'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'MovingLaterally'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'Installing'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'InstallingAccessPoints'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'EstablishingPersistence'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'CoverTracks'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'CommandAndControl'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'ConnectingToAccessPoints'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'Exit'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CyberKillChain, std::true_type>,
        // method 'CyberKillChainChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'ExploitingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'SelectingTargetChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'SelectingExploitChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'AdversaryOrVictimChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'AdversaryTriggeringExploitChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'VictimTriggeringExploitChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'DeliveringChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'SelectingDeliveryMechanismChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'ControllingOrReleasingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'AdversaryControllingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'AdversaryReleasingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'WeaponisingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'DevelopingExploitChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'DevelopingMalwareChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'DevelopingPayloadChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'ReconnaissanceChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'HarvestingEmailAddressesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'EnumeratePublicTechnologyChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'IdentifyingEmployeesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'CollectingMarketingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'TakingActionOnObjectivesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'PerformingInternalReconnaissanceChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'EscalatingPrivilegesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'MaliciousActivitiesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'CollectingAndExfiltratingDataChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'DestroyingSystemsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'OverwritingCorruptingDataChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'CollectingCredsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'MovingLaterallyChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'InstallingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'InstallingAccessPointsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'EstablishingPersistenceChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'CoverTracksChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'CommandAndControlChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'ConnectingToAccessPointsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'ExitChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // constructor 'CyberKillChain'
        QtPrivate::TypeAndForceComplete<QObject *, std::false_type>
    >,
    nullptr
} };

void CyberKillChain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { CyberKillChain *_r = new CyberKillChain((*reinterpret_cast<QObject **>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    } else if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) CyberKillChain((*reinterpret_cast<QObject **>(_a[1]))); } break;
        default: break;
        }
    } else if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CyberKillChain *>(_o);
        (void)_t;
        switch (_id) {
        case 0: QMetaObject::activate(_o, &staticMetaObject, 0, _a); break;
        case 1: QMetaObject::activate(_o, &staticMetaObject, 1, _a); break;
        case 2: QMetaObject::activate(_o, &staticMetaObject, 2, _a); break;
        case 3: QMetaObject::activate(_o, &staticMetaObject, 3, _a); break;
        case 4: QMetaObject::activate(_o, &staticMetaObject, 4, _a); break;
        case 5: QMetaObject::activate(_o, &staticMetaObject, 5, _a); break;
        case 6: QMetaObject::activate(_o, &staticMetaObject, 6, _a); break;
        case 7: QMetaObject::activate(_o, &staticMetaObject, 7, _a); break;
        case 8: QMetaObject::activate(_o, &staticMetaObject, 8, _a); break;
        case 9: QMetaObject::activate(_o, &staticMetaObject, 9, _a); break;
        case 10: QMetaObject::activate(_o, &staticMetaObject, 10, _a); break;
        case 11: QMetaObject::activate(_o, &staticMetaObject, 11, _a); break;
        case 12: QMetaObject::activate(_o, &staticMetaObject, 12, _a); break;
        case 13: QMetaObject::activate(_o, &staticMetaObject, 13, _a); break;
        case 14: QMetaObject::activate(_o, &staticMetaObject, 14, _a); break;
        case 15: QMetaObject::activate(_o, &staticMetaObject, 15, _a); break;
        case 16: QMetaObject::activate(_o, &staticMetaObject, 16, _a); break;
        case 17: QMetaObject::activate(_o, &staticMetaObject, 17, _a); break;
        case 18: QMetaObject::activate(_o, &staticMetaObject, 18, _a); break;
        case 19: QMetaObject::activate(_o, &staticMetaObject, 19, _a); break;
        case 20: QMetaObject::activate(_o, &staticMetaObject, 20, _a); break;
        case 21: QMetaObject::activate(_o, &staticMetaObject, 21, _a); break;
        case 22: QMetaObject::activate(_o, &staticMetaObject, 22, _a); break;
        case 23: QMetaObject::activate(_o, &staticMetaObject, 23, _a); break;
        case 24: QMetaObject::activate(_o, &staticMetaObject, 24, _a); break;
        case 25: QMetaObject::activate(_o, &staticMetaObject, 25, _a); break;
        case 26: QMetaObject::activate(_o, &staticMetaObject, 26, _a); break;
        case 27: QMetaObject::activate(_o, &staticMetaObject, 27, _a); break;
        case 28: QMetaObject::activate(_o, &staticMetaObject, 28, _a); break;
        case 29: QMetaObject::activate(_o, &staticMetaObject, 29, _a); break;
        case 30: QMetaObject::activate(_o, &staticMetaObject, 30, _a); break;
        case 31: QMetaObject::activate(_o, &staticMetaObject, 31, _a); break;
        case 32: QMetaObject::activate(_o, &staticMetaObject, 32, _a); break;
        case 33: QMetaObject::activate(_o, &staticMetaObject, 33, _a); break;
        case 34: QMetaObject::activate(_o, &staticMetaObject, 34, _a); break;
        case 35: QMetaObject::activate(_o, &staticMetaObject, 35, _a); break;
        case 36: QMetaObject::activate(_o, &staticMetaObject, 36, _a); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        (void)result;
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CyberKillChain *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isActive(0); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->isActive(1); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isActive(2); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->isActive(3); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->isActive(4); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->isActive(5); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->isActive(6); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->isActive(7); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->isActive(8); break;
        case 9: *reinterpret_cast< bool*>(_v) = _t->isActive(9); break;
        case 10: *reinterpret_cast< bool*>(_v) = _t->isActive(10); break;
        case 11: *reinterpret_cast< bool*>(_v) = _t->isActive(11); break;
        case 12: *reinterpret_cast< bool*>(_v) = _t->isActive(12); break;
        case 13: *reinterpret_cast< bool*>(_v) = _t->isActive(13); break;
        case 14: *reinterpret_cast< bool*>(_v) = _t->isActive(14); break;
        case 15: *reinterpret_cast< bool*>(_v) = _t->isActive(15); break;
        case 16: *reinterpret_cast< bool*>(_v) = _t->isActive(16); break;
        case 17: *reinterpret_cast< bool*>(_v) = _t->isActive(17); break;
        case 18: *reinterpret_cast< bool*>(_v) = _t->isActive(18); break;
        case 19: *reinterpret_cast< bool*>(_v) = _t->isActive(19); break;
        case 20: *reinterpret_cast< bool*>(_v) = _t->isActive(20); break;
        case 21: *reinterpret_cast< bool*>(_v) = _t->isActive(21); break;
        case 22: *reinterpret_cast< bool*>(_v) = _t->isActive(22); break;
        case 23: *reinterpret_cast< bool*>(_v) = _t->isActive(23); break;
        case 24: *reinterpret_cast< bool*>(_v) = _t->isActive(24); break;
        case 25: *reinterpret_cast< bool*>(_v) = _t->isActive(25); break;
        case 26: *reinterpret_cast< bool*>(_v) = _t->isActive(26); break;
        case 27: *reinterpret_cast< bool*>(_v) = _t->isActive(27); break;
        case 28: *reinterpret_cast< bool*>(_v) = _t->isActive(28); break;
        case 29: *reinterpret_cast< bool*>(_v) = _t->isActive(29); break;
        case 30: *reinterpret_cast< bool*>(_v) = _t->isActive(30); break;
        case 31: *reinterpret_cast< bool*>(_v) = _t->isActive(31); break;
        case 32: *reinterpret_cast< bool*>(_v) = _t->isActive(32); break;
        case 33: *reinterpret_cast< bool*>(_v) = _t->isActive(33); break;
        case 34: *reinterpret_cast< bool*>(_v) = _t->isActive(34); break;
        case 35: *reinterpret_cast< bool*>(_v) = _t->isActive(35); break;
        case 36: *reinterpret_cast< bool*>(_v) = _t->isActive(36); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *CyberKillChain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CyberKillChain::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCyberKillChainENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QScxmlStateMachine::qt_metacast(_clname);
}

int CyberKillChain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScxmlStateMachine::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 37;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    }
    return _id;
}

