// Connect4-AI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Board.h"

int main()
{
    Board board;
    board.makeMove(Move(0, RED));
    board.printBoard();
}