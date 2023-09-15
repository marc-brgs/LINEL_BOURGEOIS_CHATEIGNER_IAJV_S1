#pragma once

#include <string>
#include <vector>
#include "Action.h"

class ActionManager
{
public:
	ActionManager() {};

	std::vector<Action*> InitActions();
	void DestroyActions(std::vector<Action*>& actions);
};

