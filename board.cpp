#include "board.h"

Board::Board() {
    for(int i=0; i<16; i++) {
        boardRows.push_back(BoardRow());
    }
}

CellCondition &Board::getCondition(int col, int row) {
    return this -> boardRows.at(row).getCellConditions().at(col);
}

vector<BoardRow> Board::getBoardRows() {
    return this -> boardRows;
}

ostream & operator<<(ostream &os, Board &board) {
    for(int i=0; i<16; i++) {
        os << board.getBoardRows().at(i);
    }
    return os;
}

BoardRow::BoardRow() {
    for(int i=0; i<16; i++) {
        cellConditions.push_back(DeathCell(0));
    }
}

vector<CellCondition> &BoardRow::getCellConditions() {
    return this -> cellConditions;
}

ostream & operator<<(ostream &os, BoardRow &boardRow) {
   for(int i=0; i<16; i++) {
        os << boardRow.getCellConditions().at(i);
   }
   os << endl;
   return os;
}

CellCondition::CellCondition(int condition): valueCondition(condition){
}

void CellCondition::setCondition(CellCondition condition) {
    (*this) = condition;
}

int CellCondition::getValueCondition() {
    return this -> valueCondition;
}

ostream & operator<<(ostream& os, CellCondition &cellCondition) {
   os << cellCondition.getValueCondition();
   return os;
}

DeathCell::DeathCell(int death): CellCondition(death){
}

LifeCell::LifeCell(int life): CellCondition(life) {
}