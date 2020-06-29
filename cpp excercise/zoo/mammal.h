#ifndef __MAMMAL_H__
#define __MAMMAL_H__
#include <iostream>
#include "animal.h"
#include "Imammal.h"

class Mammals:public Animal, public Imammal
{
public:
    Mammals(std::string&);
    virtual ~ Mammals(){};
protected:
    virtual void print_data(std::ostream &os)const;
private:

};

inline Mammals::Mammals(std::string &name) :
        Animal(name){}


inline void Mammals::print_data(std::ostream &os) const {
    os<<"i'm a mammal: "<<std::endl;
    Animal::print_data(os);
    os<<"dur preg: "<<get_dur_preg()<<std::endl;
    os<<"num born: "<<get_num_born()<<std::endl;
}

#endif
