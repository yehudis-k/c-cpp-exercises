#ifndef __LION_H__
#define __LION_H__
#include <iostream>
#include "mammal.h"

class Lion:public Mammals
{
public:
    Lion(std::string&);
    /*virtual*/ unsigned int get_life_ex() const {return m_life_expectancy;}
    /*virtual*/ const std::string& get_species()const{return m_species;}
    /*virtual*/ const std::vector<e_continent>& get_cont()const{return m_continent;}
    /*virtual*/ const std::vector<e_food> &get_foods()const{ return m_foods;}
    /*virtual*/ const unsigned int get_speed() const{return m_speed;}
    /*virtual*/ const unsigned int get_dur_preg()const{return m_dur_preg;}
    /*virtual*/ const unsigned int get_num_born()const{ return m_num_born;}

private:
    void print_data(std::ostream &os)const;
    static const int m_life_expectancy=5;
    static const std::string m_species;
    static const std::vector<e_continent> m_continent;
    static const std::vector<e_food> m_foods;
    static const int m_speed=8;
    static const int m_dur_preg=5;
    static const int m_num_born=1;
};

inline Lion::Lion(std::string &name):Mammals(name) {}

inline void Lion::print_data(std::ostream &os)const
{
    Mammals::print_data(os);
}


#endif