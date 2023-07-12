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
		_board.makeMove(Move(_connector.getCol(), RED));
		_connector.sendBoardToClient(_board.getBoard());
		_board.printBoard();
	}
}
