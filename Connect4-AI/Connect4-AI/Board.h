#pragma once
#include <list>

using std::list;

#define BOARD_HEIGHT 6
#define BOARD_WIDTH 7

#define YELLOW 'Y'
#define RED 'R'
#define NO_MOVE '-'


struct Move
{
	Move(int x, char turn) : _x(x), _turn(turn) {};
	Move(int x) : _x(x), _turn('0') {};
	int _x;
	char _turn;
};


class Board
{
public:

	Board();

	bool isMoveLegal(const Move& move);
	char getCurrentTurn();
	void switchTurn();
	bool makeMove(const Move& move);
	list<Move> getList();
	bool isGameOver();

	char* getBoard();
	void printBoard();

private:
	char _turn;
	char _board[BOARD_HEIGHT][BOARD_WIDTH];
	list<Move> _first;
	
};

