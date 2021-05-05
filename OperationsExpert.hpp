#pragma once
#include "Player.hpp"
#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"

class OperationsExpert:public Player{

public:
OperationsExpert(Board board , City city): Player(board,city){
    this->curr_role = "OperationsExpert";
    }
    Player& build() override;
};
