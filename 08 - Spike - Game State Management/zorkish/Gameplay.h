#pragma once
#include "GameManager.h"
#include "State.h"
#include "Exit.h"
#include "Highscore.h"
#include <iostream>

class Gameplay : public State
{
private:
	string _command;

	void processInput();
public:
	Gameplay(GameManager*);
	~Gameplay();
	void update();
	void render();
};