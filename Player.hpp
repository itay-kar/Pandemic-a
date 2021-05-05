#pragma once
#include "City.hpp"
#include "Board.hpp"
using namespace pandemic;

    
namespace pandemic{
    class Player
    {
        
    protected:
        Board& world;
        std::string curr_role;
        City curr_city;

    public:
        Player(Board& board ,City city):world(board),curr_city(city){}
        Player& take_card(City city);
        virtual Player& build();
        Player& fly_direct(City city);
        Player& drive(City city);
        virtual Player& treat(City city);
        virtual Player& discover_cure(Color color);
        Player& fly_charter(City city);
        Player& fly_shuttle(City city);
        std::string role() { return this->curr_role;}
    };
}