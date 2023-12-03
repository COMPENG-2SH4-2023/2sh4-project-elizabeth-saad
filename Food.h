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

    public:
        Food(GameMechs* thisGMRef);
        ~Food();

        void generateFood(objPosArrayList* blockOff);
        void getFoodPos(objPos &returnPos);
};

#endif