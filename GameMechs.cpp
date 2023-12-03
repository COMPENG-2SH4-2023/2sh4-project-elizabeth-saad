#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 30;
    boardSizeY = 15;
    score = 0;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    score = 0;
}

// do you need a destructor?

bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    return (input);
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    // input = this_input;

    if (MacUILib_hasChar() == 1)
    {
        input = this_input;
    }
}

void GameMechs::clearInput()
{
    input = 0;
}

void GameMechs::incrementScore()
{
    score += 1;
}

void GameMechs::printMessage()
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

// void GameMechs::generateFood(objPosArrayList* blockOff)
// {
//     int x_rand;
//     int y_rand;
//     bool same = false;

//     int length = blockOff->getSize();
//     int count = 0;

//     objPos snake;

//     /*
//     while (count < length) {
//         blockOff->getElement(snake, i);
//         x_rand = (rand() % (boardSizeX - 2)) + 1; 
//         y_rand = (rand() % (boardSizeY - 2)) + 1;
//         if (snake.x == x_rand && snake.y == y_rand) {
//             same = true;
//         }
//         else {
            
//         }
//     }
//     */

//     for (int i = 0; i < length; i ++)
//     {
//         blockOff->getElement(snake, i);

//         do { // GENERATE NEW FOOD POSITION UNTIL NOT SAME AS PLAYER POSITION

//             x_rand = (rand() % (boardSizeX - 2)) + 1; 
//             y_rand = (rand() % (boardSizeY - 2)) + 1;

//         } while ((x_rand == snake.x) && (y_rand == snake.y));

//         break;
//     }

//     foodPos.x = x_rand;
//     foodPos.y = y_rand;
// }

// void GameMechs::getFoodPos(objPos &returnPos)
// {
//     returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
// }