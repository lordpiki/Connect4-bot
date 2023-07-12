#pragma once
#include <list>
#include <string>

using std::list;
using std::string;

#define BOARD_HEIGHT 6
#define BOARD_WIDTH 7

#define VALID_MOVE 1
#define ILLEGAL_MOVE 2
#define RED_WIN 3
#define YELLOW_WIN 4
#define TIE 5


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
	string makeMove(const Move& move);
	list<Move> getList();
	bool isGameOver();

	string returnResult(int code);

	char* getBoard();
	void printBoard();

private:
	char _turn;
	char _board[BOARD_HEIGHT][BOARD_WIDTH];
	list<Move> _first;
	
};

