#pragma once
#include "GameManager.h"
#include "State.h"

class Exit : public State
{
private:

public:
	Exit(GameManager*);
	~Exit();

	void update();
	void render();
};