#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "Food.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* thisFood);
        ~Player();

        objPosArrayList* getPlayerPos(); // Upgrade this in iteration 3.
        // void getPlayerPos(objPos &returnPos);        
        void updatePlayerDir();
        void movePlayer();

        bool checkSelfCollision();

        bool checkNormalFood(objPos currHead);
        bool checkSpecialFood(objPos currHead);

    private:
        objPosArrayList *playerPosList; // Upgrade this in iteration 3.       
        // objPos playerPos;
        enum Dir myDir;

        Food* myFood;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif