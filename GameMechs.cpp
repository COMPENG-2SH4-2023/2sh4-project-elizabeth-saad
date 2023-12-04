#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs() // DEFAULT INITIALIZER
{
    input = 0; // NO INPUT
    exitFlag = false; // DO NOT EXIT
    loseFlag = false; // HAS NOT LOST
    boardSizeX = 30; // BOARDER WIDTH OF 30
    boardSizeY = 15; // BOARDER LENGTH OF 15
    score = 0; // SCORE IS RESET
}

GameMechs::GameMechs(int boardX, int boardY) // SIMILAR TO DEFAULT CONSTRUCTOR BUT ALLOWS BOARDER SIZE TO BE CUSTOMIZED BY PLAYER / IN MAIN
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    score = 0;
}

// NO DECONSTRUCTOR NEEDED AS NOTHING IS CREATED ON THE HEAP

bool GameMechs::getExitFlagStatus() // RETURNS EXITFLAG STATUS AS TRUE OR FALSE
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() // RETURNS LOSEFLAG AS TRUE OR FALSE
{
    return loseFlag;
}

char GameMechs::getInput() // GETS PLAYER INPUT AND RETURNS IT
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

    return (input);
}

int GameMechs::getBoardSizeX() // RETURNS BOARDER WIDTH
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() // RETURNS BOARDER LENGTH
{
    return boardSizeY;
}

int GameMechs::getScore() // RETURNS PLAYER SCORE
{
    return score;
}

void GameMechs::setExitTrue() // SETS EXIT FLAG AS TRUE - ACTIVATED WHEN ESC BUTTON IS PRESSED
{
    exitFlag = true;
}

void GameMechs::setLoseFlag() // SETS LOSE FLAGE AS TRUE WHEN SNAKE EATS ITSELF
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input) // SETS THE PLAYER INPUT
{

    if (MacUILib_hasChar() == 1)
    {
        input = this_input;
    }
}

void GameMechs::clearInput() // CLEARS INPUT TO PREP FOR THE NEXT ONE
{
    input = 0;
}

void GameMechs::incrementScore(int num) // INCREASES SCORE BY SET AMOUNT DEPENDING ON FOOD TYPE
{
    score += num;
}

void GameMechs::printMessage() // END OF GAME MESSAGES DEPENDING ON HOW THE GAME IS EXITED
{
    if (loseFlag == false && exitFlag== true)
    {
        MacUILib_printf("You have terminated the game. Game Over!");
    }
    else if (loseFlag == true && exitFlag== true)
    {
        MacUILib_printf("You have lost the game. Game Over!");
    }
}