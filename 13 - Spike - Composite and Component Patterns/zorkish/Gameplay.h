#pragma once
#include "GameManager.h"
#include "GameWorld.h"
#include "State.h"
#include "Exit.h"
#include "Highscore.h"
#include <iostream>
#include <fstream>

using namespace std;
using json = nlohmann::json;

class Gameplay : public State
{
private:
	string _command;

	GameManager* _Manager;
	GameWorld* _gameWorld;

	void processInput();
public:
	Gameplay(GameManager*, string);
	~Gameplay();
	void update();
	void render();
};