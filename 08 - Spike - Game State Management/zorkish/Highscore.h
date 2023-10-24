#pragma once
#include "GameManager.h"
#include "State.h"
#include "Exit.h"
#include "Highscore.h"
#include <iostream>

class Highscore : public State
{
private:
	string _command;

	void processInput();
public:
	Highscore(GameManager*);
	~Highscore();
	void update();
	void render();
};