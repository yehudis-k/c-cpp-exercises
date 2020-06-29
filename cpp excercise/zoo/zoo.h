//
// Created by student on 26/05/2020.
//

#ifndef ZOO_ZOO_H
#define ZOO_ZOO_H

#include <iostream>
#include <vector>
#include "animal.h"

class Zoo
{
public:
    Zoo(std::vector<Animal*> animals):m_zoo(animals){}
    void print_all()const;
private:
    std::vector<Animal*> m_zoo;
};


inline void Zoo::print_all()const {
    std::vector<Animal*>::const_iterator iter=m_zoo.begin();
    for (;iter!=m_zoo.end();++iter)
    {
        std::cout<<"-------------------------------------"<<std::endl;
        //(*iter)->print_data();
        std::cout<<*iter<<std::endl;
    }
}

#endif //ZOO_ZOO_H
