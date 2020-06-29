//
// Created by student on 09/06/2020.
//

#ifndef INC_05_FIXED_POINT_FixedPoint_H
#define INC_05_FIXED_POINT_FixedPoint_H
#include <iostream>
#include <math.h>


template <unsigned int SIZE,typename T=int>
class FixedPoint
{
public:
    T a;
    using theType=decltype(a);
    FixedPoint();
    explicit FixedPoint(T dollars, int cents=0);
    T getDollars()const{return m_dollars;}
    T getCents()const{return m_cents;}
    bool isPositive()const{return m_positive;}
    unsigned int getAfterPoint()const{return m_after_point;}
    unsigned int getPrecision()const;
    operator double();
    FixedPoint<SIZE,T>& operator=(T);
    FixedPoint<SIZE,T>& operator=(const FixedPoint<SIZE,T>&);
    FixedPoint<SIZE,T>& operator+=(const FixedPoint<SIZE,T>&);
    FixedPoint<SIZE,T>& operator+=(T);
    FixedPoint<SIZE,T>& operator-=(FixedPoint<SIZE,T>);
    FixedPoint<SIZE,T>& operator-=(T);
    FixedPoint<SIZE,T>& operator*=(FixedPoint<SIZE,T>);
    FixedPoint<SIZE,T>& operator*=(T);
    FixedPoint<SIZE,T>& operator/=(FixedPoint<SIZE,T>);
    FixedPoint<SIZE,T>& operator/=(T);
    FixedPoint<SIZE,T>& operator%=(FixedPoint<SIZE,T>);
    FixedPoint<SIZE,T>& operator%=(T);
    FixedPoint<SIZE,T>& operator--();
    FixedPoint<SIZE,T>& operator++();
    FixedPoint<SIZE,T> operator--(int);
    FixedPoint<SIZE,T> operator++(int);
private:
    T m_dollars=0;
    unsigned int m_cents=0;
    bool m_positive;
    unsigned int m_after_point=pow(10, SIZE);
//friend std::ostream& operator << (std::ostream& cout,const FixedPoint<SIZE,T>& p);
};


//member Functions-----------------------------------------------------------------------------------------member Functions:
//member Functions-----------------------------------------------------------------------------------------member Functions:
//member Functions-----------------------------------------------------------------------------------------member Functions:
template <unsigned int SIZE,typename T>
inline FixedPoint<SIZE,T>::FixedPoint():m_dollars(0),m_cents(0),m_positive(true) {}

template <unsigned int SIZE,typename T>
inline FixedPoint<SIZE,T>::FixedPoint(T dollars, int cents):m_dollars(0),m_cents(0),m_positive(true) {
    if((dollars<0)||(cents<0))
        m_positive=false;
    if(dollars<0)
        dollars=(T)-dollars;
    if(cents<0)
        cents=-cents;
    m_dollars=dollars;
    m_cents=cents;
    while(m_cents>getAfterPoint())
        m_cents/=10;
    //change();
}

template <unsigned int SIZE,typename T>
inline unsigned int FixedPoint<SIZE,T>::getPrecision() const {
    unsigned int fraction=getCents();
    unsigned int num_digits=SIZE;
    while (fraction%10==0)
    {
        fraction/=10;
        num_digits--;
    }
    return num_digits;
}

template <unsigned int SIZE,typename T>
inline FixedPoint<SIZE,T>::operator double(){
    if(!isPositive())
        return -(double(m_dollars)+double(m_cents)/getAfterPoint());
    return double(m_dollars)+double(m_cents)/getAfterPoint();
}

template <unsigned int SIZE,typename T>
inline FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator=(T num) {
    *this=FixedPoint<SIZE,T>(num);
    return *this;
}

template <unsigned int SIZE,typename T>
inline FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator=(const FixedPoint<SIZE,T>& p)
{
    if(this!=&p)
    {
        m_dollars=p.getDollars();
        m_cents=p.getCents();
        m_positive=p.isPositive();
    }
    return *this;
}

template <unsigned int SIZE,typename T>
FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator+=(const FixedPoint<SIZE,T>& p)
{
    *this=*this+p;
    return *this;
}

template <unsigned int SIZE,typename T>
FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator+=(T num)
{
    FixedPoint<SIZE,T> tmp(num);
    *this=*this+tmp;
    return *this;
}

template <unsigned int SIZE,typename T>
FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator-=(FixedPoint<SIZE,T> p)
{
    *this=*this-p;
    return *this;
}

template <unsigned int SIZE,typename T>
FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator-=(T num)
{
    FixedPoint<SIZE,T> tmp(num);
    *this=*this-tmp;
    return *this;
}

template <unsigned int SIZE,typename T>
FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator*=(FixedPoint<SIZE,T> p)
{
    *this=*this*p;
    return *this;
}

template <unsigned int SIZE,typename T>
FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator*=(T num)
{
    FixedPoint<SIZE,T> tmp(num);
    *this=*this*tmp;
    return *this;
}

template <unsigned int SIZE,typename T>
FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator/=(FixedPoint<SIZE,T> p)
{
    *this=*this/p;
    return *this;
}

template <unsigned int SIZE,typename T>
FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator/=(T num)
{
    FixedPoint<SIZE,T> tmp(num);
    *this=*this/tmp;
    return *this;
}

template <unsigned int SIZE,typename T>
FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator%=(FixedPoint<SIZE,T> p)
{
    *this=*this%p;
    return *this;
}

template <unsigned int SIZE,typename T>
FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator%=(T num)
{
    FixedPoint<SIZE,T> tmp(num);
    *this=*this%tmp;
    return *this;
}

template <unsigned int SIZE,typename T>
inline FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator++() {
    *this+=FixedPoint<SIZE,T>(1);
    return *this;
}

template <unsigned int SIZE,typename T>
inline FixedPoint<SIZE,T>& FixedPoint<SIZE,T>::operator--() {
    *this-=FixedPoint<SIZE,T>(1);
    return *this;
}

template <unsigned int SIZE,typename T>
inline FixedPoint<SIZE,T> FixedPoint<SIZE,T>::operator++(int) {
    FixedPoint<SIZE,T> res=*this;
    *this+=FixedPoint<SIZE,T>(1);
    return res;
}

template <unsigned int SIZE,typename T>
inline FixedPoint<SIZE,T> FixedPoint<SIZE,T>::operator--(int) {
    FixedPoint<SIZE,T> res=*this;
    *this-=FixedPoint<SIZE,T>(1);
    return res;
}

template <unsigned int SIZE,typename T>
inline FixedPoint<SIZE,T> change(T dollars, unsigned int cents) {
    unsigned int after_point=pow(10,SIZE);
    if(cents>=after_point)
    {
        dollars+=cents/after_point;
        cents%=after_point;
    }
    return FixedPoint<SIZE, T>(dollars,cents);
    /*if(m_cents>=getAfterPoint())
    {
        m_dollars+=m_cents/getAfterPoint();
        m_cents%=getAfterPoint();
    }*/
}

template <unsigned int SIZE,typename T>
inline std::ostream& operator<<(std::ostream& cout, const FixedPoint<SIZE,T>& p) {
    std::string sign="";
    if(!p.isPositive())
        sign="-";
    cout<<sign<<p.getDollars()<<"."<<p.getCents()<<std::endl;
    return cout;
}

//arithmetic Operators-----------------------------------------------------------------------------------------arithmetic Operators:
//arithmetic Operators-----------------------------------------------------------------------------------------arithmetic Operators:
//arithmetic Operators-----------------------------------------------------------------------------------------arithmetic Operators:
template <unsigned int SIZE,typename T>
inline FixedPoint<SIZE,T> operator-(const FixedPoint<SIZE,T>& p) {
    if(p.isPositive())
        return FixedPoint<SIZE,T>(p.getDollars()*-1, p.getCents()*-1);
    FixedPoint<SIZE,T> res(p.getDollars(), p.getCents());
    return res;
}

template <unsigned int SIZE,typename T>
inline FixedPoint<SIZE,T> operator+(const FixedPoint<SIZE,T> &p1, const FixedPoint<SIZE,T> &p2)
{
    if(p1.isPositive()==p2.isPositive())
    {
        FixedPoint<SIZE,T> res=change<SIZE,T>(p1.getDollars()+p2.getDollars(), p1.getCents()+p2.getCents());
        return res;
    }
    else{
        if(!p1.isPositive())
        {
            return p2-(-p1);
        }
    }
    return p1-(-p2);
}

template <unsigned int SIZE,typename T>
inline FixedPoint<SIZE,T> operator-(const FixedPoint<SIZE,T> &p1, const FixedPoint<SIZE,T> &p2)
{
    if(p1==p2)
        return FixedPoint<SIZE,T>(0);
    if(!p2.isPositive())
    {
        return p1+(-p2);
    }
    if(!p1.isPositive())
    {
        return(-((-p1)+p2));
    }
    if(p1<p2)
        return -(p2-p1);
    T dollar=p1.getDollars()-p2.getDollars();
    int cent=p1.getCents()-p2.getCents();
    if(cent<0)
    {
        dollar-=1;
        cent+=p1.getAfterPoint();
    }
    FixedPoint<SIZE,T> res=change<SIZE,T>(dollar,(unsigned int)cent);
    return res;
}


template <unsigned int SIZE,typename T>
inline FixedPoint<SIZE,T> operator*(const FixedPoint<SIZE,T> &p1, const FixedPoint<SIZE,T> &p2)
{
    int flag=1;
    T p1_in_cents=p1.getDollars()*p1.getAfterPoint()+p1.getCents();
    T p2_in_cents=p2.getDollars()*p2.getAfterPoint()+p2.getCents();
    T tmp=p1_in_cents*p2_in_cents;
    if(p1.isPositive()!=p2.isPositive())
        flag=-1;
    std::cout<<"checking:::tmp: "<<tmp<<" dollars: "<<(T)(tmp/pow(p1.getAfterPoint(),2))<<" cents: "<<tmp%(T)pow(p1.getAfterPoint(),2)/p1.getAfterPoint()<<std::endl;
    FixedPoint<SIZE,T> res((T)(tmp/pow(p1.getAfterPoint(),2))*flag,tmp%(T)pow(p1.getAfterPoint(),2)/p1.getAfterPoint());
    return res;
}

template <unsigned int SIZE,typename T>
inline FixedPoint<SIZE,T> operator/(const FixedPoint<SIZE,T> &p1, const FixedPoint<SIZE,T> &p2)
{
    int flag=1;
    T p1_in_cents=p1.getDollars()*p1.getAfterPoint()+p1.getCents();
    T p2_in_cents=p2.getDollars()*p2.getAfterPoint()+p2.getCents();
    T tmp=p1_in_cents/p2_in_cents;
    std::cout<<tmp<<std::endl;
    if(p1.isPositive()!=p2.isPositive())
        flag=-1;
    FixedPoint<SIZE,T> res(tmp*flag);
    return res;
}

template <unsigned int SIZE,typename T>
inline FixedPoint<SIZE,T> operator%(const FixedPoint<SIZE,T> &p1, const FixedPoint<SIZE,T> &p2)
{
    int flag=1;
    T p1_in_cents=p1.getDollars()*p1.getAfterPoint()+p1.getCents();
    T p2_in_cents=p2.getDollars()*p2.getAfterPoint()+p2.getCents();
    T tmp=p1_in_cents%p2_in_cents;
    std::cout<<tmp<<std::endl;
    if(p1.isPositive()!=p2.isPositive())
        flag=-1;
    FixedPoint<SIZE,T> res((T)(tmp/p1.getAfterPoint())*flag,tmp%p1.getAfterPoint());
    return res;
}

//comparison operators-------------------------------------------------------------------------------------comparison operators:
//comparison operators-------------------------------------------------------------------------------------comparison operators:
//comparison operators-------------------------------------------------------------------------------------comparison operators:
template <unsigned int SIZE,typename T>
inline bool operator>(const FixedPoint<SIZE,T> &p1, const FixedPoint<SIZE,T> &p2)
{
    if(p1.isPositive()!=p2.isPositive())
        return p1.isPositive();
    if(p1.getDollars()>p2.getDollars())
        return p1.isPositive();
    return ((p1.getDollars() == p2.getDollars()) && (p1.getCents() > p2.getCents())) == p1.isPositive();
}

template <unsigned int SIZE,typename T>
inline bool operator<(const FixedPoint<SIZE,T> &p1, const FixedPoint<SIZE,T> &p2)
{
    return p2>p1;
}

template <unsigned int SIZE,typename T>
inline bool operator==(const FixedPoint<SIZE,T> &p1, const FixedPoint<SIZE,T> &p2)
{
    return (p1.getCents() == p2.getCents()) && (p1.getDollars() == p2.getDollars()) &&
           (p1.isPositive() == p2.isPositive());
}

template <unsigned int SIZE,typename T>
inline bool operator!=(const FixedPoint<SIZE,T> &p1, const FixedPoint<SIZE,T> &p2)
{
    return (p1.getCents() != p2.getCents()) || (p1.getDollars() != p2.getDollars()) ||
           (p1.isPositive() != p2.isPositive());
}

template <unsigned int SIZE,typename T>
inline bool operator<=(const FixedPoint<SIZE,T>& p1, const FixedPoint<SIZE,T>& p2)
{
    return (p1 == p2) || (p1 < p2);
}

template <unsigned int SIZE,typename T>
inline bool operator>=(const FixedPoint<SIZE,T>& p1, const FixedPoint<SIZE,T>& p2)
{
    return (p1==p2)||(p1>p2);
}
#endif //INC_05_FIXED_POINT_FixedPoint_H
