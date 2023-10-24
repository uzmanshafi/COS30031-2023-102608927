#pragma once
#include "GameManager.h"
#include "State.h"
#include "About.h"
#include "HallOfFame.h"
#include "Help.h"
#include "SelectAdventure.h"
#include "Exit.h"
#include <iostream>

class MainMenu : public State
{
public:
	MainMenu(GameManager*);
	~MainMenu();

	void update();
	void render();
};