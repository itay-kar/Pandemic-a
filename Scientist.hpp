#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"


namespace pandemic{
class Scientist:public Player
{

private:
    int n;

public:
    Scientist(Board board, enum City city, int number):Player(board,city){this->n = number;};
};
}