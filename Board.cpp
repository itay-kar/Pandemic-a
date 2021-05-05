#include "Board.hpp"
using namespace pandemic;

    int& Board::operator[](City city){return world[city];}
    bool Board::is_clean(){return true;}
    void Board::remove_cures(){}
