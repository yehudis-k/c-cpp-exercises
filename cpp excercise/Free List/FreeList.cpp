#include "FreeList.h"
#include <malloc.h>
#include <iostream>
static const size_t size_of_heap=20;

Person* initListOfFreeBlocks(Person* heap, Person* head)
{
    Person* ptr = heap;
    head = ptr;

    for (size_t i = 0; i < size_of_heap; ++i) {
        *(Person**)ptr = ptr + sizeof(Person);
        ptr += sizeof(Person);
    }

    *(Person**)ptr = NULL;

    return head;
}

Person* Person::s_pool = (Person*)malloc(sizeof(Person)*size_of_heap);
Person* Person::s_firstFree = initListOfFreeBlocks(s_pool, s_firstFree);

void Person::printHeap()
{
    Person* ptr = s_firstFree;
    while (*(Person**)ptr != NULL)
    {
        std::cout << "block number: " << (ptr - s_pool) / sizeof(Person) <<" is free "<< std::endl;
        ptr = *(Person**)ptr;
    }
}

