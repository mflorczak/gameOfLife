#include "board.h"

Board::Board() {
    for(int i=0; i<16; i++) {
        BoardRow *boardRow = new BoardRow();
        this -> boardRows.push_back(boardRow);
    }
}

int *Board::getCondition(int col, int row) {
    return this -> boardRows.at(row)->getCellConditions().at(col);
}

vector<BoardRow *> Board::getBoardRows() {
    return this -> boardRows;
}

ostream & operator<<(ostream &os, Board *board) {
    for(int i=0; i<16; i++) {
        os << board->getBoardRows().at(i);
    }
    return os;
}

BoardRow::BoardRow() {
    for(int i=0; i<16; i++) {
        this -> cellConditions.push_back(new int);
        this -> cellConditions.at(i) = 0;
    }
}

vector<int *> BoardRow::getCellConditions() {
    return this -> cellConditions;
}

ostream & operator<<(ostream &os, BoardRow *boardRow) {
   for(int i=0; i<16; i++) {
        os << boardRow -> getCellConditions().at(i);
   }
   os << endl;
   return os;
}

