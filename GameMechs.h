#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;

        objPos foodPos;

        bool loseFlag;
        int score;
        
        int boardSizeX;
        int boardSizeY;

    public:
        GameMechs(); // DEFAULT CONSTRUCTOR
        GameMechs(int boardX, int boardY); // CONSTRUCTOR WITH CUSTOMIZABLE BOARDER
        
        bool getExitFlagStatus();
        void setExitTrue();

        bool getLoseFlagStatus();
        void setLoseFlag();

        char getInput();
        void setInput(char this_input);
        void clearInput();

        void incrementScore(int num); // TAKES IN AMOUNT OF POINTS TO BE ADDED DEPENDING ON THE FOOD EATEN

        int getBoardSizeX();
        int getBoardSizeY();

        int getScore();

        void printMessage(); // PRINTS END OF GAME MESSAGES
};

#endif