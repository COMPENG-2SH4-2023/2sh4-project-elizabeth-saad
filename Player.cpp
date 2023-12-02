#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    // playerPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '@');

    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '@');
    
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

    // For debugging (delete later)
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
}

Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

// void Player::getPlayerPos(objPos &returnPos)
objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    // returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    char input = mainGameMechsRef->getInput();

    switch (input)
    {
        case 27:
            mainGameMechsRef->setExitTrue();
            break;
        case 'W':
        case 'w':
            if (myDir != UP && myDir != DOWN)
            {
                myDir = UP;
            }
            break;
        case 'S':
        case 's':
            if (myDir != UP && myDir != DOWN)
            {
                myDir = DOWN;
            }
            break;
        case 'A':
        case 'a':
            if (myDir != LEFT && myDir != RIGHT)
            {
                myDir = LEFT;
            }
            break;
        case 'D':
        case 'd':
            if (myDir != LEFT && myDir != RIGHT)
            {
                myDir = RIGHT;
            }
            break;
        default:
            break;
    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    objPos currHead;
    playerPosList->getHeadElement(currHead);
    
    int boardSizeX = mainGameMechsRef->getBoardSizeX();
    int boardSizeY = mainGameMechsRef->getBoardSizeY();

    switch (myDir)
    {
        case UP:
            currHead.y--;
            // playerPos.y--;
            if (currHead.y <= 0)
            // if (playerPos.y <= 0)
            {
                currHead.y = boardSizeY - 2;
                // playerPos.y = boardSizeY - 2;
            }
            break;
        case DOWN:
            currHead.y++;
            // playerPos.y++;
            if (currHead.y >= boardSizeY)
            // if (playerPos.y >= boardSizeY)
            {
                currHead.y = 1;
                // playerPos.y = 1;
            }
            break;
        case LEFT:
            currHead.x--;
            // playerPos.x--;
            if (currHead.x <= 0)
            // if (playerPos.x <= 0)
            {
                currHead.x = boardSizeX - 2;
                // playerPos.x = boardSizeX - 2;
            }
            break;
        case RIGHT:
            currHead.x++;
            // playerPos.x++;
            if (currHead.x >= boardSizeX)
            // if (playerPos.x >= boardSizeX)
            {
                currHead.x = 1;
                // playerPos.x = 1;
            }
            break;
        case STOP:
        default:
            break;        
    }

    playerPosList->insertHead(currHead);
    playerPosList->removeTail();
}
