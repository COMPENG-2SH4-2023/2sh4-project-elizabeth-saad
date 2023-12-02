#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000

// bool exitFlag;

GameMechs* myGM;
Player* myPlayer;
GameMechs* game;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void)
{
    Initialize();

    while(myGM->getExitFlagStatus() == false)  
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

    myGM = new GameMechs(26, 13);
    myPlayer = new Player(myGM);

    // game = new GameMechs();

    // exitFlag = false;
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

    // objPos tempPos;
    // myPlayer->getPlayerPos(tempPos);

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;

    for (int i = 0; i < myGM->getBoardSizeY(); i++)
    {
        for (int j = 0; j < myGM->getBoardSizeX(); j++)
        {
            drawn = false;
            
            for (int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody, k);
                if (tempBody.x == j && tempBody.y == i)
                {
                    MacUILib_printf("%c", tempBody.symbol);
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
            // else if (j == tempPos.x && i == tempPos.y)
            // {
            //     MacUILib_printf("%c", tempPos.symbol);
            // }
            else
            {
                MacUILib_printf("%c", 32);   
            }
        }
        MacUILib_printf("\n");   
    }

    // MacUILib_printf("Score: %d\n Player Pos: <%d, %d>\n", myGM->getScore(), tempPos.x, tempPos.y);
    MacUILib_printf("Score: %d\n", myGM->getScore());

    // For debugging (delete later)
    MacUILib_printf("Player Positions:\n");
    for (int a = 0; a < playerBody->getSize(); a++)
    {
        playerBody->getElement(tempBody, a);
        MacUILib_printf("<%d, %d> ", tempBody.x, tempBody.y);
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void)
{    
    MacUILib_clearScreen();    
    MacUILib_uninit();

    // delete game;
    delete myGM;
    delete myPlayer;
}
