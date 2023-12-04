#include "Food.h"
#include "MacUILib.h"

Food::Food(GameMechs* thisGMRef)
{
    srand(time(NULL));
    foodPos.setObjPos(-1, -1, 'X');
    thisGM = thisGMRef;

    foodBucket = new objPosArrayList();

    foodBucket->insertHead(foodPos);
    foodBucket->insertHead(foodPos);
    foodBucket->insertHead(foodPos);
}

Food::~Food()
{
    delete foodBucket;
}

void Food::generateFood(objPosArrayList* blockOff)
{
   
    bool same;
    int length = blockOff->getSize();
    int bucketLength = foodBucket->getSize();
    objPos snake;
    objPos tempFood;

    for (int i = 0; i < 3; i++)
    {
        int random = rand() % 2;

        if (i < random)
        {
            foodPos.symbol = 'S';
        }
        else
        {
            foodPos.symbol = 'X';
        }
        
        do
        {
            same = false;

            foodPos.x = (rand() % (thisGM->getBoardSizeX() - 2)) + 1; 
            foodPos.y = (rand() % (thisGM->getBoardSizeY() - 2)) + 1;

            for (int i = 0; i < length; i++)
            {
                blockOff->getElement(snake, i);

                if (foodPos.isPosEqual(&tempPos))
                {
                    same = true;
                    break;
                }
            }

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

        foodBucket->insertHead(foodPos);
        foodBucket->removeTail();
    }
}

objPosArrayList* Food::getFoodPos()
{
    // returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);

    return foodBucket;
}