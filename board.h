#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Board
{
  private:
    int **board;

  public:
    Board();
    int **getBoard();
    void print();
};
