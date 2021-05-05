#pragma once
#include <stdlib.h>
#include <map>
using namespace std;

#include "City.hpp"
#include "Color.hpp"
using namespace pandemic;

namespace pandemic{
    class Board
    {
        std::map<City, int> world;

    public:
        Board(){};
        int& operator[](City city);
        static bool is_clean();
        void remove_cures();
        friend std::ostream& operator<<(std::ostream& os,Board board){return os;}

    };

}