#include "Player.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '@');
}

Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    char input = mainGameMechsRef->getInput();

    switch (input)
    {
        case 'w':
            if (myDir != UP && myDir != DOWN)
            {
                myDir = UP;
            }
            break;
        case 's':
            if (myDir != UP && myDir != DOWN)
            {
                myDir = DOWN;
            }
            break;
        case 'a':
            if (myDir != LEFT && myDir != RIGHT)
            {
                myDir = LEFT;
            }
            break;
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
    int boardSizeX = mainGameMechsRef->getBoardSizeX();
    int boardSizeY = mainGameMechsRef->getBoardSizeY();

    switch (myDir)
    {
        case UP:
            playerPos.y--;
            if (playerPos.y <= 0)
            {
                playerPos.y = boardSizeY - 2;
            }
            break;
        case DOWN:
            playerPos.y++;
            if (playerPos.y >= boardSizeY)
            {
                playerPos.y = 1;
            }
            break;
        case LEFT:
            playerPos.x--;
            if (playerPos.x <= 0)
            {
                playerPos.x = boardSizeX - 2;
            }
            break;
        case RIGHT:
            playerPos.x++;
            if (playerPos.x >= boardSizeX)
            {
                playerPos.x = 1;
            }
            break;
        default:
            break;        
    }
}
