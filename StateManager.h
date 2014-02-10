#pragma once
#include "StateMachine.h"

class StateManager
{
public:
	StateManager();

	enum states {STATE_NONE, STATE_PLAY, STATE_PLAY_GENERATE, STATE_PLAY_PRECALCULATED, STATE_EXIT};

	StateMachine *oldState;
	StateMachine *currentState;

	void ChangeState( StateMachine *newState );

	~StateManager();
};

