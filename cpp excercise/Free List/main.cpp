#include "FreeList.h"

int main()
{
    //Person person;
    //person.printHeap();
    Person* p0 = new Person("aaa", 2222, 20);
    p0->printPerson();
    Person* p1 = new Person;
    p1->printPerson();
    Person* p2 = new Person("bbb", 3333, 30);
    Person* p3 = new Person;
    delete (p2);
    delete (p1);
    Person* p4 = new Person;
    char* c = new char[3];
    p0->printHeap();
    return 0;
}