#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 256 // SETS MAX CAPACITY OF THE LIST TO 256 ELEMENTS

#include "objPos.h"

class objPosArrayList
{
    private:
        objPos* aList;
        int listSize;
        int arrayCapacity;

    public:
        objPosArrayList(); // DEFAULT CONSTRUCTOR 
        ~objPosArrayList(); // DESTRUCTOR FOR ELEMENTS MADE ON THE HEAP IN CONSTRUCTOR

        int getSize();
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        
        void getHeadElement(objPos &returnPos);
        void getTailElement(objPos &returnPos);
        void getElement(objPos &returnPos, int index);
};

#endif