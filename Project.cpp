#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000

// bool exitFlag;

GameMechs* myGM; // REFERENCE TO GAME MECHS CLASS
Player* myPlayer; // REFERENCE TO PLAYER CLASS
Food* myFood; // REFERENCE TO FOOD CLASS

// FUNCTION PROTOTYPES
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void)
{
    Initialize();

    while(myGM->getExitFlagStatus() == false) // CHECKS IF GAME IS STILL ON VIA GAME MECHS REFERENCE
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
}

void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(30, 15); // SETS GAME BOARDER
    myFood = new Food(myGM); // CREATES NEW INSTANCE OF FOOD WITH REFERENCE TO GAME MECHS
    myPlayer = new Player(myGM, myFood); // CREATES NEW INSTANCE OF PLAYER WITH REFERENCE TO GAME MECHS AND FOOD

    objPosArrayList* tempPos = myPlayer->getPlayerPos();

    myFood->generateFood(myPlayer->getPlayerPos());

}

void GetInput(void)
{
    myGM->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    myGM->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    bool drawn;

    // PLAYER / SNAKE POSITIONS
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    // FOOD POSITIONS
    objPosArrayList* playerFood = myFood->getFoodPos();
    objPos tempFoodPos;

    for (int i = 0; i < myGM->getBoardSizeY(); i++) // DRAWS EACH CORRESPONDING Y
    {
        for (int j = 0; j < myGM->getBoardSizeX(); j++) // DRAWS EACH CORRESPONDING X
        {
            drawn = false;
            
            for (int k = 0; k < playerBody->getSize(); k++) // DRAWS EACH CORRESPONDING PLAYER SEGMENT
            {
                playerBody->getElement(tempBody, k);
                if (tempBody.x == j && tempBody.y == i && i < (myGM->getBoardSizeY() - 1) && j != 0 && j < (myGM->getBoardSizeX() - 1)) // PRINTS PLAYER CONSIDERING WRAP AROUND
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            for (int m = 0; m < playerFood->getSize(); m++) // PRINTS FOODS
            {
                playerFood->getElement(tempFoodPos, m);

                if (tempFoodPos.x == j && tempFoodPos.y == i && i < (myGM->getBoardSizeY() - 1) && j != 0 && j < (myGM->getBoardSizeX() - 1)) // ENSURES PRINTED IN BOARDER 
                {
                    MacUILib_printf("%c", tempFoodPos.symbol);
                    drawn = true;
                    break;
                }
            }

            if (drawn)
            {
               continue;
            }

            if (i == 0 || i == myGM->getBoardSizeY() - 1 || j == 0 || j == myGM->getBoardSizeX() - 1)
            {
                MacUILib_printf("%c", '#');
            }
            else if (j == tempFoodPos.x && i == tempFoodPos.y) 
            {
                MacUILib_printf("%c", tempFoodPos.symbol);
            }
            else if (j == tempFoodPos.x && i == tempFoodPos.y)
            {
                MacUILib_printf("%c", tempFoodPos.symbol);
            }
            else
            {
                MacUILib_printf("%c", 32); // PRINTS BLANK SPACE
            }
        }
        MacUILib_printf("\n");   
    }

    MacUILib_printf("Score: %d\n", myGM->getScore()); // PRINTS SCORE
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void)
{        
    MacUILib_clearScreen();   

    myGM->printMessage();
    
    MacUILib_uninit();

    // DELETES PRE-MADE REFERENCES TO OTHER CLASSES
    // STOPS MEMORY LEAK
    delete myGM;
    delete myFood;
    delete myPlayer;
}
