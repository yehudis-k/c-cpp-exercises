//
// Created by student on 26/05/2020.
//
#include "zoo.h"
#include "lion.h"
#include "shark.h"
#include "owl.h"
#include "whale.h"

int main()
{
    std::vector<Animal*> my_animals;
    std::string name1="Simba";
    std::string name2="Mufasa";
    std::string name3="Jaws";
    std::string name4="Hedwig";
    std::string name5="Whale";
    Lion lion1(name1);
    Lion lion2(name2);
    Shark shark(name3);
    Owl owl(name4);
    Whale whale(name5);
   std::cout<<lion1<<std::endl;
    std::cout<<lion2<<std::endl;
    std::cout<<shark<<std::endl;
    std::cout<<whale<<std::endl;
    std::cout<<&owl<<std::endl;
    my_animals.push_back(&lion1);
    my_animals.push_back(&lion2);
    my_animals.push_back(&shark);
    my_animals.push_back(&owl);
    my_animals.push_back(&whale);
    Zoo my_zoo(my_animals);
    std::cout<<"*************************************\nmy zoo:"<<std::endl;
    my_zoo.print_all();
    return 0;
}

