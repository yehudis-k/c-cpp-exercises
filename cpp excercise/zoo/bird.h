#ifndef __BIRD_H__
#define __BIRD_H__
#include <iostream>
#include "animal.h"
#include "Ibird.h"

class Bird:public Animal, public Ibird
{
public:
    Bird(std::string&);
    virtual ~ Bird(){};
protected:
    virtual void print_data(std::ostream &os)const;
private:

};

inline Bird::Bird(std::string& name) :
        Animal(name){}

inline void Bird::print_data(std::ostream &os)const  {
    os<<"i'm a bird: "<<std::endl;
    Animal::print_data(os);
    os<<"hieght: "<<get_height()<<std::endl;
    os<<"wing span: "<<get_wing_span()<<std::endl;
}

#endif
