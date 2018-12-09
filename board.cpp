#include "board.h"

Board::Board()
{
    this->board = new int *[16];
    for (int i = 0; i < 16; i++)
        this->board[i] = new int[16];

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
            this->board[i][j] = 0;
    }
}

void Board::print()
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
            cout << this->board[i][j];
        cout << endl;
    }
}

int **Board::getBoard()
{
    return this->board;
}
