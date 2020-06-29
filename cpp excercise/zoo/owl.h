#ifndef __OWL_H__
#define __OWL_H__
#include <iostream>
#include "bird.h"

class Owl:public Bird
{
public:
    Owl(std::string&);
    /*virtual*/ unsigned int get_life_ex() const {return m_life_expectancy;}
    /*virtual*/ const std::string& get_species()const{return m_species;}
    /*virtual*/ const std::vector<e_continent> &get_cont()const{return m_continent;}
    /*virtual*/ const std::vector<e_food>& get_foods()const{ return m_foods;}
    /*virtual*/ const unsigned int get_speed() const{return m_speed;}
    /*virtual*/ const unsigned int get_height()const{return m_height;}
    /*virtual*/ const unsigned int get_wing_span()const{ return m_wing_span;}
private:
    virtual void print_data(std::ostream &os)const;
    static const int m_life_expectancy=2;
    static const std::string m_species;
    static const std::vector<e_continent> m_continent;
    static const std::vector<e_food> m_foods;
    static const int m_speed=7;
    static const int m_height=8;
    static const int m_wing_span=9;
};

inline Owl::Owl(std::string &name):
       Bird(name) {}

inline void Owl::print_data(std::ostream &os)const
{
    Bird::print_data(os);
}


#endif