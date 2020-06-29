#ifndef __SHARK_H__
#define __SHARK_H__
#include <iostream>
#include "fish.h"

class Shark:public Fish
{
public:
    Shark(std::string&);
    virtual ~Shark(){};
    /*virtual*/ unsigned int get_life_ex() const {return m_life_expectancy;}
    /*virtual*/ const std::string& get_species()const{return m_species;}
    /*virtual*/ const std::vector<e_continent>& get_cont()const{return m_continent;}
    /*virtual*/ const std::vector<e_food> &get_foods()const{ return m_foods;}
    /*virtual*/ const unsigned int get_speed() const {return m_speed;}
    /*virtual*/ const unsigned int get_lowest_depth()const{return m_lowest_depth;}
private:
    void print_data(std::ostream &os)const;
    static const int m_life_expectancy=9;
    static const std::string m_species;
    static const std::vector<e_continent> m_continent;
    static const std::vector<e_food> m_foods;
    static const int m_speed=6;
    static const int m_lowest_depth=19;
};

inline Shark::Shark(std::string &name):
        Fish(name) {}

inline void Shark::print_data(std::ostream &os)const
{
    Fish::print_data(os);
}



#endif