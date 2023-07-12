#include "Board.h"

Board::Board()
{
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            _board[i][j] = '-';
        }
    }
}

// function to check if the move is legal
bool Board::isMoveLegal(Move* move)
{
    if (move->_turn != _turn) 
    {
        return false;
    }
    if (_board[0][move->_x])
    {
        return false;
    }
    if (0 > move->_x || move->_x >= BOARD_WIDTH)
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
bool Board::makeMove(Move* move)
{
    if (!isMoveLegal(move))
    {
        return false;
    }
    _first.push_back(move);
    switchTurn();
    return false;
}

list<Move*> Board::getList()
{
    return _first;
}
