//
// Created by student on 06/08/2020.
//

#ifndef INC_19_SINGLETON_SINGLETON_H
#define INC_19_SINGLETON_SINGLETON_H

#include <iostream>

template <typename T>
class Singleton
{
public:
    static T* get(int);
private:
    static T* m_singleton;
    Singleton() {std::cout<<"ctor"<<std::endl;}
    Singleton(const Singleton&){}
    Singleton& operator=(const Singleton&){}
    Singleton& operator=(Singleton&){}
};

template <typename T>
T* Singleton<T>::m_singleton = NULL;

class Logger
{
public:
    Logger(int num):m_id(num){std::cout<<"logger ctor"<<std::endl;}

private:
    int m_id;
};

template <typename T>
inline T* Singleton<T>::get(int n)
{
    if (!m_singleton)
        m_singleton = new T(n);
    return m_singleton;
}


#endif //INC_19_SINGLETON_SINGLETON_H
