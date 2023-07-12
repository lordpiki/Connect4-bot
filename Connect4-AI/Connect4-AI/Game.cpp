#include "Game.h"
#include <iostream>
#include <string>


Game::Game()
{
}

void Game::runGame()
{
	while (!_board.isGameOver())
	{
		_connector.sendBoardToClient(_board.makeMove(Move(_connector.getCol(), _board.getCurrentTurn())));
		_board.printBoard();
	}
}
