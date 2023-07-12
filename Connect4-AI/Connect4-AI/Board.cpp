#include "Board.h"
#include <iostream>

using std::cout;
using std::endl;

Board::Board()
{
    _turn = RED;
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            _board[i][j] = NO_MOVE;
        }
    }
}

// function to check if the move is legal
bool Board::isMoveLegal(const Move& move)
{
    if (move._turn != _turn) 
    {
        return false;
    }
    if (_board[0][move._x] != NO_MOVE)
    {
        return false;
    }
    if (0 > move._x || move._x >= BOARD_WIDTH)
    {
        return false;
    }
    return true;
}

// returning current turn
char Board::getCurrentTurn()
{
    return _turn;
}

// switches turn for board
void Board::switchTurn()
{
    _turn = (_turn == YELLOW ? RED : YELLOW);
}

// function makes the move in the board and adds it the list
string Board::makeMove(const Move& move)
{
    if (!isMoveLegal(move))
    {
        return returnResult(ILLEGAL_MOVE);
    }
    for (int i = 6 - 1; i >= 0; i--)
    {
        if (_board[i][move._x] == NO_MOVE)
        {
            _board[i][move._x] = move._turn;
            break;
        }
    }
    _first.push_back(move);
    switchTurn();
    return returnResult(VALID_MOVE);
}

list<Move> Board::getList()
{
    return _first;
}

bool Board::isGameOver()
{
    return false;
}

string Board::returnResult(int code)
{
    string message = std::to_string(code) + getBoard();
    return message.c_str();
}

char* Board::getBoard()
{
    return *_board;
}

void Board::printBoard()
{
    cout << "  1 2 3 4 5 6 7" << endl;

    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        cout << "| ";
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            cout << _board[i][j] << " ";
        }
        cout << "|" << endl;
    }
}

