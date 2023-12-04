#include "Player.h"

Player::Player(GameMechs* thisGMRef, Food* thisFood) // DEFAULT CONSTRUCTOR TAKING REFERENCES TO THE GAME MECHS AND FOOD CLASSES
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP; // KEEPS PLAYER STILL UNITL DIRECTION INPUT IS RECIEVED
    myFood = thisFood;

    // more actions to be included

    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '@'); // SETS PLAYER TO START IN THE CENTER OF THE GAME BOARDER

    playerPosList = new objPosArrayList(); // CREATES INSTANCE ON THE HEAP
    playerPosList->insertHead(tempPos); // PLACES PLAYER
}

Player::~Player() // DESTRUCTOR FOR THE MEMBER CREATED ON THE HEAP IN THE CONSTRUCTOR
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() // GETS THE PLAYER POSITION
{
    // return the reference to the playerPos arrray list
    
    return playerPosList;
}

void Player::updatePlayerDir() // UPDATES THE DIRECTION OF THE PLAYER BASED ON INPUT
{
    // PPA3 input processing logic
    char input = mainGameMechsRef->getInput();

    switch (input)
    {
        case 27: // EXIT KEY IS ESC
            mainGameMechsRef->setExitTrue();
            break;
        // UP
        case 'W':
        case 'w':
            if (myDir != UP && myDir != DOWN)
            {
                myDir = UP;
            }
            break;
        // DOWN
        case 'S':
        case 's':
            if (myDir != UP && myDir != DOWN)
            {
                myDir = DOWN;
            }
            break;
        // LEFT
        case 'A':
        case 'a':
            if (myDir != LEFT && myDir != RIGHT)
            {
                myDir = LEFT;
            }
            break;
        // RIGHT
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

bool Player::checkSelfCollision() // CHECKS IF SNAKE HAS EATEN ITSELF
{
    objPos currHead;
    playerPosList->getHeadElement(currHead); // GETS POSITION OF THE SNAKE HEAD
    objPos tempPos;

    // CHECKS IF SNAKE HEAD IS THE SAME POSITION OF OTHER PARTS OF BODY
    for (int i = 1; i < playerPosList->getSize(); i++)
    {
        playerPosList->getElement(tempPos, i);
        
        if (currHead.isPosEqual(&tempPos)) // IF THE SNAKES HEAD COLLIDES WITH BODY RETURNS TRUE
        {
            return true;
        }
    }

    return false; // IF THE SNKAE HEAD HASNT COLLIDED WITH BODY CONTINUE GAME / RETURN FALSE
}

bool Player::checkSpecialFood(objPos currHead) // CHECKS IF SNAKE HAS EATEN SPECIAL FOOD
{
    objPosArrayList* foodBucket = myFood->getFoodPos();
    objPos specialFoodPos;

    for (int i = 0; i < foodBucket->getSize(); i++)
    {
        foodBucket->getElement(specialFoodPos, i);
        
        if (specialFoodPos.isPosEqual(&currHead) && specialFoodPos.symbol == '%') // IF THE FOOD IS SPECIAL RETURN TRUE
        {
            return true;
        }
    }

    return false; // RETURNS FALSE IF NOT
}

bool Player::checkNormalFood(objPos currHead) // CHECKS IF SNAKE HAS EATEN NORMAL FOOD
{
    objPosArrayList* foodBucket = myFood->getFoodPos();
    objPos specialFoodPos;

    for (int i = 0; i < foodBucket->getSize(); i++)
    {
        foodBucket->getElement(specialFoodPos, i);
        
        if (specialFoodPos.isPosEqual(&currHead) && specialFoodPos.symbol == 'F') // IF THE FOOD IS NORMAL RETURN TRUE
        {
            return true;
        }
    }

    return false; // IF NOT NORMAL FOOD RETURN FLASE
}

void Player::movePlayer() // MOVES SNAKE
{
    // PPA3 Finite State Machine logic
    objPos currHead;
    playerPosList->getHeadElement(currHead);
    
    int boardSizeX = mainGameMechsRef->getBoardSizeX();
    int boardSizeY = mainGameMechsRef->getBoardSizeY();

    // CHECKS NEXT HEAD POSITION
    switch (myDir)
    {
        case UP:
            currHead.y--;
            if (currHead.y <= 0)
            {
                currHead.y = boardSizeY - 2;
            }
            break;
        case DOWN:
            currHead.y++;
            if (currHead.y >= boardSizeY)
            {
                currHead.y = 1;
            }
            break;
        case LEFT:
            currHead.x--;
            if (currHead.x <= 0)
            {
                currHead.x = boardSizeX - 2;
            }
            break;
        case RIGHT:
            currHead.x++;
            if (currHead.x >= boardSizeX)
            {
                currHead.x = 1;
            }
            break;
        case STOP:
        default:
            break;        
    }

    if (checkNormalFood(currHead)) // INCREASES SNAKE LENGTH BY ONE AND INCREMEMENTS SCORE BY ONE IF SNAKE EATS REGULAR FOOD
    {
        playerPosList->insertHead(currHead);
        mainGameMechsRef->incrementScore(1);
        myFood->generateFood(playerPosList);
    }
    else if (checkSpecialFood(currHead)) // INCREASES SNAKE LENGTH BY ONE AND INCREMEMENTS SCORE BY THREE IF SNAKE EATS REGULAR FOOD
    {
        playerPosList->insertHead(currHead);

        mainGameMechsRef->incrementScore(3);

        myFood->generateFood(playerPosList);
    }
    else // REMOVES TAIL AND ADDS HEAD LIKE NORMAL IF NO FOOD IS EATEN
    {
        playerPosList->insertHead(currHead);
        playerPosList->removeTail();
    }

    if (checkSelfCollision()) // CHECKS IF THE SNAKE HAS EATEN ITSELF AND SETS FLAGS ACCORDINGLY
    {
        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();
    }
}