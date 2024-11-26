#include <QObject>

class IFiniteState;

/*!
 * brief The IFiniteStateMachine class
 */

class IFiniteStateMachine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<IFiniteState*> actions READ getActions WRITE setActions NOTIFY actionsChanged FINAL)

public:
    enum FiniteStateMachineExitCode{
        ExitSuccess,
        ExitFailure,
        ExitIndeterminate,
        ExitTerminated,
        ExitYes,
        ExitNo
    };
    Q_ENUM(FiniteStateMachineExitCode)

public:
    QList<IFiniteState*> getActions() const;
    void setActions(const QList<IFiniteState*> &newActions);

public slots:
    void init(){
        initActions();
    }

    virtual void start() = 0;
    virtual void stop() = 0;

protected: // Properties
    QList<IFiniteState*> actions;

protected: // Internal functions
    virtual void initActions() = 0;

signals:
    void running();
    void exiting(FiniteStateMachineExitCode);
    void actionsChanged();
private:

};

/*!
 * brief The IFiniteState class
 */

class IFiniteState : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<IFiniteState *> actions READ getActions WRITE setActions NOTIFY actionsChanged FINAL)
    Q_PROPERTY(bool asynchronous READ getAsynchronous WRITE setAsynchronous NOTIFY isAsynchronousChanged FINAL)

public:
    QList<IFiniteState *> getActions() const;
    void setActions(const QList<IFiniteState *> &newActions);

    bool getAsynchronous() const;
    void setAsynchronous(bool newAsynchronous);

protected: // Properties
    QList<IFiniteState*> actions;
    bool asynchronous = true;

public slots:
    virtual void enter() = 0;

signals:
    void exitSuccess();
    void exitFailure();
    void exitIndeterminate();
    void exitYes();
    void exitNo();
    void exitMaybe();
    void exitFatal();
    void actionsChanged();
    void isAsynchronousChanged();
private:
};

/*
    Inline functions
*/

inline QList<IFiniteState*> IFiniteStateMachine::getActions() const
{
    return actions;
}

inline void IFiniteStateMachine::setActions(const QList<IFiniteState*> &newActions)
{
    if (actions == newActions)
        return;
    actions = newActions;
    emit actionsChanged();
}

inline QList<IFiniteState *> IFiniteState::getActions() const
{
    return actions;
}

inline void IFiniteState::setActions(const QList<IFiniteState *> &newActions)
{
    if (actions == newActions)
        return;
    actions = newActions;
    emit actionsChanged();
}

inline bool IFiniteState::getAsynchronous() const
{
    return asynchronous;
}

inline void IFiniteState::setAsynchronous(bool newAsynchronous)
{
    if (asynchronous == newAsynchronous)
        return;
    asynchronous = newAsynchronous;
    emit isAsynchronousChanged();
}
