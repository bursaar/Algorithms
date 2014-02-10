#pragma once
class StateMachine
{
public:
	StateMachine();
	void Update();
	void EnterState();
	void ExitState();
	~StateMachine();
};

