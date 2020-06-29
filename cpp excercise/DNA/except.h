//
// Created by student on 01/06/2020.
//

#ifndef DNA_EXCEPT_H
#define DNA_EXCEPT_H

#include <iostream>
#include <exception>

class ValidError:public std::exception
{
public:
    /*virtual*/ const char* what() const throw(){return "Invalid DNA char";}
};

class OpenFileError:public std::exception
{
public:
    /*virtual*/ const char* what() const throw(){return "Error openinf file";}
};

class IndexError:public std::exception
{
public:
    /*virtual*/ const char* what() const throw(){return "Invalid index";}
};

#endif //DNA_EXCEPT_H
