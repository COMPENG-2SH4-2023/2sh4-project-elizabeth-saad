#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "GameMechs.h"

using namespace std;

class Food
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        bool posTaken;

        objPos tempPos;
        objPos foodPos;

        GameMechs* thisGM;

        objPosArrayList* foodBucket;

    public:
        Food(GameMechs* thisGMRef); // DEFAULT CONSTRUCTOR TAKES IN REFERENCE TO GAME MECHS
        ~Food(); // DESTRUCTOR FOR THE FOOD MADE ON THE HEAP

        void generateFood(objPosArrayList* blockOff); // GENERATES FOOD AND TAKES IN REFERENCE TO SNAKE ARRAYLIST
        objPosArrayList* getFoodPos(); // RETURNS THE POSITION AND SYMBOL OF EACH FOOD INSTANCE

        // void generateSpecialFood(objPosArrayList* playerPosList);
        // objPosArrayList *getFoodBucket();
};

#endif