#include "Imammal.h"
#include "fish.h"


class Whale:public Imammal, public Fish
{
public:
    Whale(std::string&);
    /*virtual*/ unsigned int get_life_ex() const {return m_life_expectancy;}
    /*virtual*/ const std::string& get_species()const{return m_species;}
    /*virtual*/ const std::vector<e_continent>& get_cont()const{return m_continent;}
    /*virtual*/ const std::vector<e_food> &get_foods()const{ return m_foods;}
    /*virtual*/ const unsigned int get_speed() const{return m_speed;}
    /*virtual*/ const unsigned int get_dur_preg()const{return m_dur_preg;}
    /*virtual*/ const unsigned int get_num_born()const{ return m_num_born;}
    /*virtual*/ const unsigned int get_lowest_depth()const{return m_lowest_depth;}

protected:
    void print_data(std::ostream &os)const;

private:
    static const int m_life_expectancy=7;
    static const std::string m_species;
    static const std::vector<e_continent> m_continent;
    static const std::vector<e_food> m_foods;
    static const int m_speed=20;
    static const int m_dur_preg=5;
    static const int m_num_born=1;
    static const int m_lowest_depth=50;
};

inline Whale::Whale(std::string &name):
        Fish(name) {}


inline void Whale::print_data(std::ostream &os)const
{
    Fish::print_data(os);
    os<<"dur preg: "<<get_dur_preg()<<std::endl;
    os<<"num born: "<<get_num_born()<<std::endl;
}
