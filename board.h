#pragma once
#include <iostream>
#include <vector>
using namespace std;

class CellCondition {
    protected:
        int valueCondition;
    public:
        CellCondition(int);
        void setCondition(CellCondition);
        int getValueCondition();
        friend ostream& operator<<(std::ostream&, CellCondition&);
};

class BoardRow {
    private:
        vector<CellCondition> cellConditions;
    public:
        BoardRow();
        vector<CellCondition> &getCellConditions();
        friend ostream& operator<<(ostream &, BoardRow&);
};

class Board {
    private:
        vector<BoardRow> boardRows;
    public: 
        Board();
        CellCondition &getCondition(int, int);
        vector<BoardRow> getBoardRows();
        friend ostream&::operator<<(ostream&, Board&);
};

class DeathCell: public CellCondition {
    public: 
        DeathCell(int);
};

class LifeCell: public CellCondition {
    public:
        LifeCell(int);
};