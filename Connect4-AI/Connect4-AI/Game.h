#pragma once
#include "Board.h"
#include "Connector.h"


class Game
{
public:
	Game();
	void runGame();

private:
	Connector _connector;
	Board _board;

};

