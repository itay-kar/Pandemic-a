#include "doctest.h"
#include "Color.hpp"
#include "Board.hpp"
#include "Scientist.hpp"
#include "OperationsExpert.hpp"
#include "GeneSplicer.hpp"
#include "City.hpp"
#include "Researcher.hpp"
#include "Virologist.hpp"
#include "Medic.hpp"
#include "Dispatcher.hpp"
#include "FieldDoctor.hpp"
using namespace pandemic;


Board board;
Player First ={board , City::Atlanta};

    TEST_CASE("BuildTest"){
        //taking one card from the deck
     CHECK_NOTHROW(First.take_card(City::Bangkok));
     //Taking more than 1 card in a row;
     CHECK_NOTHROW(First.take_card(MexicoCity).take_card(City::Madrid));
     
     //Build() Test
     // Building with no card in hand should raise error
     CHECK_THROWS(First.build());
     //Move City Then Build with card in hand should build.
     CHECK_NOTHROW(First.drive(Bangkok).build());
    }

     //Drive Tests
     TEST_CASE("Drive"){
     CHECK_NOTHROW(First.drive(Bangkok));
     CHECK_THROWS_AS_MESSAGE(First.drive(City::Madrid),exception,"Cannot Drive to non close city");
     }

    TEST_CASE("Flights"){
     CHECK_NOTHROW(First.fly_charter(City::Bangkok));
     CHECK_NOTHROW(First.fly_direct(Bangkok));
     
     CHECK_NOTHROW(First.fly_shuttle(City::Madrid));
     CHECK_THROWS(First.fly_direct(MexicoCity));
    
    First.take_card(Bangkok).take_card(Madrid);
     CHECK_NOTHROW(First.fly_shuttle(City::Bangkok));
     CHECK_NOTHROW(First.fly_charter(MexicoCity));
    } 

    TEST_CASE("Treating pandemic"){
     CHECK_NOTHROW(First.treat(City::Bangkok));
     CHECK_THROWS(First.treat(MexicoCity));
     
     First.drive(Chicago);
     // Not in the city that needs treating raise error
     CHECK_THROWS(First.treat(City::Bangkok));
     board[Chicago] = 4;
     CHECK_NOTHROW(First.treat(Chicago));
     CHECK_LT(board[Chicago],4);
     
    }

    TEST_CASE("Board Check"){
     CHECK(board.is_clean() == false);
     board.remove_cures();
    CHECK(board.is_clean()== true);
    board[Newyork]=1;
    CHECK(board.is_clean() == false);
    
    }
     
