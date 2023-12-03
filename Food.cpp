#include "Food.h"
#include "MacUILib.h"

Food::Food(GameMechs* thisGMRef)
{
    srand(time(NULL));
    foodPos.setObjPos(-1, -1, 'X');
    thisGM = thisGMRef;
}

Food::~Food()
{

}

void Food::generateFood(objPosArrayList* blockOff)
{
    bool same;
    int length = blockOff->getSize();
    objPos snake;

    do
    {
        same = false;

        foodPos.x = (rand() % (thisGM->getBoardSizeX() - 2)) + 1; 
        foodPos.y = (rand() % (thisGM->getBoardSizeY() - 2)) + 1;

        for (int i = 0; i < length; i ++)
        {
            blockOff->getElement(snake, i);

            if (foodPos.isPosEqual(&tempPos))
            {
                same = true;
                break;
            }
        }
    } while (same);
}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}