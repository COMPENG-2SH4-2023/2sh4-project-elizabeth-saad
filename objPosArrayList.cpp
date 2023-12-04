#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList() // DEFAULT CONSTRUCTOR
{
    aList = new objPos[ARRAY_MAX_CAP]; // CREATES LIST OF OBJPOS INSTANCENS ON THE HEAP
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
}

objPosArrayList::~objPosArrayList() // DESTRUCTOR FOR ALIST MADE ON THE HEAP
{
    delete[] aList;
}

int objPosArrayList::getSize() // RETURNS SIZE OF THE ARRAYLIST
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos) // INSERTS HEAD AT BEGINNING OF ARRAYLIST AND SHIFTS ALL PRE-EXISTING ELEMENTS DOWN BY ONE
{
    // BREAK OUT OF FUNCTION IF THE ARRAYLIST IS AT MAX CAPACITY
    if (listSize == arrayCapacity)
    {
        return;
    }

    // SHIFTS ALL PRE-EXISTING ELEMENTS DOWN BY ONE
    for (int i = listSize; i > 0; i--)
    {
        aList[i].setObjPos(aList[i-1]);
    }

    aList[0].setObjPos(thisPos); // INSERTS HEAD AT THE BEGINNING OF THE ARRAYLIST

    listSize++; // INCREASES LISTSIZE BY ONE
}

void objPosArrayList::insertTail(objPos thisPos)
{
    // BREAK OUT OF FUNCTION IF THE ARRAYLIST IS AT MAX CAPACITY
    if (listSize == arrayCapacity)
    {
        return;
    }
        
    aList[listSize++].setObjPos(thisPos); // ADDS ELEMENT TO THE END OF THE ARRAYLIST
}

void objPosArrayList::removeHead()
{
    // BREAK OUT OF FUNCTION IF THE ARRAYLIST HAS NO ELEMENTS
    if (listSize <= 0)
    {
        return;
    }
    
    //MOVES EACH ELEMENT UP BY ONE
    for (int i = 0; i < listSize - 1; i++)
    {
        aList[i] = aList[i+1];
    }

    listSize--; // DECREASES LISTSIZE BY ONE
}

void objPosArrayList::removeTail()
{
    // BREAK OUT OF FUNCTION IF THE ARRAYLIST IS EMPTY
    if (listSize <= 0)
    {
        return;
    }
    
    listSize--; // DECREASES LIST SIZE BY ONE
}

void objPosArrayList::getHeadElement(objPos &returnPos) // GETS POSITION OF THE HEAD OF THE LIST
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos) // GOTS POSITION OF THE TAIL OF THE LIST
{
    returnPos.setObjPos(aList[listSize - 1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index) // GETS THE POSITION OF ANY ELEMENT IN THE LIST BASED ON INDEX
{
    if (index < 0 || index >= listSize)
    {
        returnPos.setObjPos(0, 0, ' ');
        return;
    }

    returnPos.setObjPos(aList[index]);
}