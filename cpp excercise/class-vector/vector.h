#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <cstdio>
#include <stdint.h>
#include <iostream>

template <typename T>
class Vector
{
public:
	Vector();
	explicit Vector(size_t capacity, T value=T(0));
	Vector(const Vector& other);
	~Vector();
	Vector <T>& operator=(const Vector <T>& other);

	size_t size() const;
	size_t max_size() const;
    void resize(size_t num, T val=T(0));
    size_t capacity()const;
	bool empty() const;
	void reserve(size_t n);

	T& operator[](size_t index);
	const T& operator[](size_t index)const;
    T& at(size_t index);//TODO add consts
    T& front();
    T& back();
    T* data();

    void assign(size_t n, const T& val);
    void push_back(const T&);
    void pop_back();
    void insert(size_t index, T val, size_t amount=1);
    void erase(size_t index, size_t num=T(1));//TODO add default parameter of range
    void swap(Vector& other);
    void clear();

    Vector<T>& operator+=(Vector& other);
private:
	T* m_arr;
	size_t m_size;
	size_t m_capacity;
};

template <typename T>
Vector<T>::Vector():m_arr(NULL),m_size(0),m_capacity(0){}

template <typename T>
Vector<T>::Vector(size_t capacity, T value):m_arr(new T[capacity]), m_size(capacity), m_capacity(capacity)
{
	for(size_t i=0; i<capacity; i++)
	{
		m_arr[i] = value;
	}	
}

template <typename T>
Vector<T>::Vector(const Vector& other):m_arr(new T[other.m_capacity]), m_size(other.m_size), m_capacity(other.m_capacity)
{
	for(size_t i=0; i<other.m_size; i++)
	{
		m_arr[i] = (other.m_arr)[i];
	}
}
template <typename T>
Vector<T>::~Vector()
{
	delete [] m_arr;
	m_arr = NULL;
}

template <typename T>
Vector <T>& Vector<T>::operator=(const Vector <T>& other)
{
    if(m_capacity==0)
        m_capacity=1;
    if(m_capacity<other.m_size)
    {
        m_capacity*=2;
        this->operator=(other);
    }
    T* tmp=new T[m_capacity];
    if(tmp)
    {
        for (size_t i = 0; i < other.m_size; ++i) {
            tmp[i]=other.m_arr[i];
        }
        delete[] m_arr;
        m_arr=tmp;
        m_size=other.m_size;
    }
    return *this;
}

template <typename T>
inline size_t Vector<T>::size() const
{
	return m_size;
}

template <typename T>
inline size_t Vector<T>::max_size() const
{
	return SIZE_MAX;
}

template<typename T>
void Vector<T>::resize(size_t num, T val){
    if(num<m_size)
    {
        for(size_t i=num;i<m_size;++i)
            m_arr[i].~T();
        m_size=num;
        return;
    }
    T* tmp=new T[num];
    if(tmp)
    {
        for (size_t i = 0; i<m_size; ++i) {
            tmp[i]=m_arr[i];
        }
        for (size_t j = m_size; j <num ; ++j) {
            tmp[j]=val;
        }
        delete[]m_arr;
        m_arr=tmp;
        m_size=num;
    }
}

template<typename T>
size_t Vector<T>::capacity()const{
    return m_capacity;
}
	
template <typename T>
inline bool Vector<T>::empty() const
{
    return m_size==0;
}	
	
template <typename T>
inline void Vector<T>::reserve(size_t n)
{
    size_t i=0;
	if(n>m_capacity)
	{
		T* new_arr = new T[n];
		if(new_arr)
        {
            for (; i <m_size ; ++i) {
                new_arr[i]=m_arr[i];
            }
            for(;i<n;i++)
            {
                new_arr[i]=T(0);
            }
            delete m_arr;
            m_arr = new_arr;
            m_capacity=n;
        }
	}
}

template <typename T>
inline T& Vector<T>::operator[](size_t index)
{
    return m_arr[index];
}

template <typename T>
inline const T& Vector<T>::operator[](size_t index)const
{
    return m_arr[index];
}

template<typename T>
T& Vector<T>::at(size_t index){
    if(index>m_size)
    {
        throw std::out_of_range("index out of range!");
    }
    return m_arr[index];
}

template<typename T>
T& Vector<T>::front() {
    return m_arr[0];
}

template<typename T>
T& Vector<T>::back() {
    return m_arr[m_size-1];
}

template<typename T>
T* Vector<T>::data()
{
    return m_arr;
}

template<typename T>
void Vector<T>::assign(size_t n, const T& val){

    if(n<m_capacity)
    {
        for (size_t i = 0; i<n; ++i) {
            m_arr[i]=val;
        }
        for (size_t i = n; i<m_size; ++i)
            m_arr[i].~T();
        m_size=n;
        return;
    }
    T* tmp=new T[n];
    if(tmp)
    {
        for (size_t i = 0; i<n; ++i) {
            tmp[i]=val;
        }
        delete[]m_arr;
        m_arr=tmp;
        m_size=n;
        m_capacity=n;
    }
}

template<typename T>
void Vector<T>::push_back(const T& val){
    if(m_size==m_capacity)
    {
        T* tmp=new T[m_capacity*2];
        if(!tmp)
            return;
        for (size_t i = 0; i < m_capacity; ++i) {
            tmp[i]=m_arr[i];
        }
        delete[]m_arr;
        m_arr=tmp;
        m_capacity*=2;
    }
    m_arr[m_size]=val;
    ++m_size;
}

template<typename T>
void Vector<T>::pop_back(){
    if(m_size>0)
    {
        m_arr[m_size].~T();
        m_size--;
    }
}

template<typename T>
void Vector<T>::insert(size_t index, T val, size_t amount) {
    size_t i;
    if(m_size+amount>m_capacity)
    {
        T* tmp=new T[m_capacity*2];
        if(tmp)
        {
            for (i = m_size; i > index; --i) {
                tmp[i+amount-1]=m_arr[i];
            }
            for (size_t j=amount; j>0; j--) {
                tmp[i+j-1]=val;
            }
            for(;i>0;i--)
            {
                tmp[i-1]=m_arr[i-1];
            }
            delete[]m_arr;
            m_arr=tmp;
            m_capacity*=2;
            m_size+=amount;
        }
    }
    else{
        for(i=m_size;i>index;i--)
            m_arr[i+amount-1]=m_arr[i];
        for (size_t j=amount; j>0; j--) {
            m_arr[i+j-1]=val;
        }
        m_size+=amount;
    }
}

template<typename T>
void Vector<T>::erase(size_t index, size_t num)
{
    for(size_t i=index;i<m_size;i++)
    {
        m_arr[i]=m_arr[i+num];
    }
    for(size_t i=m_size-num;i<m_size;i++)
        m_arr[i].~T();
    m_size-=num;
}

template<typename T>
void Vector<T>::swap(Vector& other)
{
    Vector<T> tmp=*this;
    *this=other;
    other=tmp;
}

template<typename T>
void Vector<T>::clear()
{
    for(size_t i=0;i<m_size;++i)
        m_arr[i].~T();
    m_size=0;
}

template<typename T>
Vector<T> operator+(Vector<T>& v1,Vector<T>& v2)
{
    size_t size_v1=v1.size();
    size_t size_v2=v2.size();
   T* tmp=new T[v1.size()+v2.size()];
    if(tmp)
    {
        for(size_t i=0;i<size_v1;i++)
            tmp[i]=v1[i];

        for(size_t i=0;i<size_v2;i++)
            tmp[v1.size()+i]=v2[i];
    }
    Vector<T> new_vec;
    new_vec.reserve(size_v1+size_v2);
    new_vec.resize(size_v1+size_v2);
    for(size_t i=0;i<size_v1+size_v2;i++)
        new_vec[i]=tmp[i];
    return new_vec;
}

template<typename T>
Vector<T>& Vector<T>::operator+=(Vector& other)
{
    size_t capacity=m_capacity;
    while(m_capacity>capacity)
    {
        capacity*=2;
    }
    reserve(capacity);
    *this=*this+other;
    return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Vector<T>& v) {
    os<<"size: "<<v.size();
    os<<" capacity: "<<v.capacity()<<" vector: ";
    for(size_t i=0;i<v.size();++i)
    {
        os<<v[i]<<" ";
    }
    return os;
}




#endif
