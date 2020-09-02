//
// Created by student on 06/08/2020.
//
#include "singleton.h"

int main()
{
    int* a = Singleton<int>::get(1);
    int* b = Singleton<int>::get(2);
    int* c = Singleton<int>::get(3);
    //Logger* a = Singleton<Logger>::get(1);
    //Logger* b = Singleton<Logger>::get(2);
    //Logger* c = Singleton<Logger>::get(3);
    std::cout<<*a<<std::endl;
    std::cout<<*b<<std::endl;
    std::cout<<*c<<std::endl;

    return 0;
}

