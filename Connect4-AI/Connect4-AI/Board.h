#pragma once
#include <list>

using std::list;

#define BOARD_HEIGHT 6
#define BOARD_WIDTH 7

#define YELLOW 'Y'
#define RED 'R'

struct Move
{
	Move(int x, int y, char turn) : _x(x), _turn(turn) {};
	Move(int x, int y) : _x(x), _turn('0') {};
	int _x;
	char _turn;
};


class Board
{
public:

	Board();

	bool isMoveLegal(Move* move);
	char getCurrentTurn();
	void switchTurn();
	bool makeMove(Move* move);
	list<Move*> getList();

private:
	char _turn;
	char _board[BOARD_HEIGHT][BOARD_WIDTH];
	list<Move*> _first;
	
};

