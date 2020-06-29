#ifndef __ANIMAL_H__
#define __ANIMAL_H__
#include <iostream>
#include <vector>


enum e_continent { America, Africa,Europe, Asia, Australia, Antarctica};
enum e_food {meat, vegetable, worms};

static const std::string continent_arr[6]={"America", "Africa", "Europe", "Asia", "Australia", "Antarctica"};
static const std::string food_tipes_arr[3]={"meat", "vegetable", "worms"};

class Animal
{
public:
    Animal(std::string&);
    virtual ~Animal(){};
    const std::string get_name()const{return m_name;}
    virtual unsigned int get_life_ex()const = 0 ;
    virtual const std::string& get_species() const = 0;
    virtual const std::vector<e_continent> &get_cont()const = 0 ;
    virtual const std::vector<e_food>& get_foods() const = 0;
    virtual const unsigned int get_speed()const = 0;
    friend std::ostream& operator<<(std::ostream& cout, const Animal& an);
    friend std::ostream& operator<<(std::ostream& cout, const Animal* an);
    virtual void print_data(std::ostream &os)const;
private:
    std::string m_name;

};


inline Animal::Animal(std::string &name):
        m_name(name){}


inline std::ostream& operator<<(std::ostream& os, const Animal& an)
{
    an.print_data(os);
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const Animal* const an)
{
    an->print_data(os);
    return os;
}

inline void Animal::print_data(std::ostream &os)const
{
    os<<"name: "<<get_name()<<std::endl;
    os<<"life: "<<get_life_ex()<<std::endl;
    os<<"species: "<<get_species()<<std::endl;
    os<<"continents: ";
    std::vector<e_continent> tmp=get_cont();
    std::vector<e_continent>::const_iterator ptr=tmp.begin();
    for(;ptr!=tmp.end();++ptr)
    {
        os << continent_arr[*ptr] << " ";
    }os<<std::endl;

    std::cout<<"food: ";
    std::vector<e_food> tmp2=get_foods();
    std::vector<e_food>::const_iterator ptr2=tmp2.begin();
    for(;ptr2!=tmp2.end();++ptr2)
    {
        os << food_tipes_arr[*ptr2] << " ";
    }os<<std::endl;
    os<<"speed: "<<get_speed()<<std::endl;
}

#endif
