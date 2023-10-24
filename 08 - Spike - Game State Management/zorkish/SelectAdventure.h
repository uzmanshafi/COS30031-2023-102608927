#pragma once
#include "GameManager.h"
#include "State.h"
#include "Gameplay.h"
#include <iostream>

class SelectAdventure : public State
{
public:
	SelectAdventure(GameManager*);
	~SelectAdventure();

	void update();
	void render();
};