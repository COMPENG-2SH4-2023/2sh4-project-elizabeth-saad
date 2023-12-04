#include "Food.h"
#include "MacUILib.h"

Food::Food(GameMechs* thisGMRef)  // DEFAULT FOOD CONSTRUCTOR
{
    srand(time(NULL)); // SEEDS THE RANDOM FUNCTION WITH CURRENT TIME
    foodPos.setObjPos(-1, -1, 'F'); // SETS INITIAL FOOD OFF THE BORDER
    thisGM = thisGMRef; // SETS PRIVATE VARIABLE TO REFERENCES GAME MECHS

    foodBucket = new objPosArrayList(); // CREATES A NEW FOODBUCKET OBJECT ON THE HEAP

    foodBucket->insertHead(foodPos);
    foodBucket->insertHead(foodPos);
    foodBucket->insertHead(foodPos);
}

Food::~Food() // DESTRUCTOR FOR FOODBUCKET MADE ON THE HEAP IN INITIALIZATION
{
    delete foodBucket;
}

void Food::generateFood(objPosArrayList* blockOff)
{
   
    bool same; // BOOLEAN FLAG REPRESENTING IF THE FOOD IS GENERATED ON THE SNAKE
    int length = blockOff->getSize(); 
    int bucketLength = foodBucket->getSize(); 
    objPos snake;
    objPos tempFood;

    for (int i = 0; i < 3; i++) // ITERATES 3 TIMES FOR THE 3 ITEMS IN FOOD BUCKET
    {
        int random = rand() % 2; // GENERATES RANDOM INTEGER BETWEEN 0 AND 1

        if (i < random) // IF THE ITERATION IS LESS THAN RANDOM INTEGER, SET FOOD AS SPECIAL
        {
            foodPos.symbol = '%';
        }
        else // IF THE ITERATION IS EQUAL TO GREATER THAN THE RANDOM INTEGER, GENERATE NORMAL FOOD
        {
            foodPos.symbol = 'F';
        }
        
        // GENERATES RANDOM POSITION FOR FOOD UNTIL SAME IS SET FLASE
        // SET SAME AS TRUE IF THE FOOD IS PLACED ON TOP OF THE SNAKE
        // GENERATES NEW POSITION UNTIL FOOD IS NO LONGER ON THE SNAKE
        // SO SAME IS SET TO FALSE AND THE LOOP IS ENDED

        do
        {
            same = false;

            foodPos.x = (rand() % (thisGM->getBoardSizeX() - 2)) + 1; 
            foodPos.y = (rand() % (thisGM->getBoardSizeY() - 2)) + 1;

            // FOR THE TOTAL LENGTH / POSITIONS OF THE SNAKE
            for (int i = 0; i < length; i++)
            {
                blockOff->getElement(snake, i);

                if (foodPos.isPosEqual(&tempPos))
                {
                    same = true;
                    break;
                }
            }

            // FOR THE TOTAL FOOD IN THE BUCKET
            for (int i = 0; i < bucketLength; i++)
            {
                foodBucket->getElement(tempFood, i);

                if (foodPos.isPosEqual(&tempFood))
                {
                    same = true;
                    break;
                }
            }

        } while (same);

        // INSERT FOOD
        foodBucket->insertHead(foodPos);
        foodBucket->removeTail();
    }
}

objPosArrayList* Food::getFoodPos()
{
    return foodBucket; // RETURNS FOOD POSITION AND SYMBOL FROM ARRAYLIST/FOODBUCKET
}