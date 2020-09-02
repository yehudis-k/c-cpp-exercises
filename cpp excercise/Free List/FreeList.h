#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>
#include <cstdio>
#include <exception>
#include <cstring>
class Base
{
public:
    Base(){}
private:
    Base(Base&){}
    Base operator=(Base&){}
    void* operator new[](size_t size){}
    void operator delete[](void* ptr){}
};

class Person : private Base//person allocator and separate Person to a different class
{
public:
    Person();
    Person(char*, unsigned int, unsigned char);

    void*           operator new(size_t size);
    void            operator delete(void* ptr);
    static void     printHeap();
    void            printPerson();

private:
    static Person*  s_pool;
    static Person*  s_firstFree;
    char            m_fullname[32];
    unsigned int    m_id;
    unsigned char   m_age;

};

inline Person::Person():m_fullname("anonymous"), m_id(1111), m_age(0){}

inline Person::Person(char* name, unsigned int id, unsigned char age):m_fullname(""), m_id(id), m_age(age)
{
    strcpy(m_fullname, name);
}

inline void* Person::operator new(size_t size)
{
    if (*(Person**)s_firstFree == NULL)
    {
        throw (std::bad_alloc());
    }
    void* tmp = s_firstFree;
    s_firstFree += sizeof(Person);
    return tmp;
}

inline void Person::operator delete(void* ptr)
{
    Person* tmp = s_firstFree;
    s_firstFree = (Person*)ptr;
    *(Person**)ptr = tmp;
}

inline void Person::printPerson()
{
    std::cout << "name: " << m_fullname << " id: " << m_id << " age: " << m_age << std::endl;
}





#endif //__PERSON_H__