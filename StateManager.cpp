#include "StateManager.h"


StateManager::StateManager()
{
}

void StateManager::ChangeState(StateMachine *newState)
{
	oldState = currentState;
	oldState->ExitState;
	newState->EnterState;
	currentState = newState;
}

StateManager::~StateManager()
{
}
