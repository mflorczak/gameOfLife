#pragma once
#include <iostream>
#include <vector>
using namespace std;

class BoardRow {
    private:
        vector<int*> cellConditions;
    public:
        BoardRow();
        vector<int*> getCellConditions();
        friend ostream& operator<<(ostream &, BoardRow *);
};

class Board {
    private:
        vector<BoardRow*> boardRows;
    public: 
        Board();
        int *getCondition(int, int);
        vector<BoardRow*> getBoardRows();
        friend ostream&::operator<<(ostream&, Board *);
};
