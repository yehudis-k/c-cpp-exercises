#ifndef __FISH_H__
#define __FISH_H__
#include <iostream>
#include "animal.h"
#include "Ifish.h"

class Fish: public Animal, public Ifish
{
public:
    Fish(std::string&);
    virtual ~ Fish(){};
protected:
    virtual void print_data(std::ostream &os)const;
private:

};

inline Fish::Fish(std::string& name) :
        Animal(name){}


inline void Fish::print_data(std::ostream &os)const  {
    os<<"i'm a fish: "<<std::endl;
    Animal::print_data(os);
    os<<"lowest depth: "<<get_lowest_depth()<<std::endl;
}

#endif
