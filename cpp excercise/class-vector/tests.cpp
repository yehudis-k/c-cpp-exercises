
#include "tests.h"
#include "vector.h"

TEST(VectorBasics, CreateVector)
{
    Vector<int> v1;
    Vector<int> v2(2,5);
    Vector<int> v3(v2);
    Vector<int> v4(5);

    ASSERT_EQ(v1.size(),0);
    ASSERT_EQ(v1.capacity(),0);

    ASSERT_EQ(v2.size(),2);
    ASSERT_EQ(v2.front(),5);

    ASSERT_EQ(v3.size(),v2.size());
    ASSERT_EQ(v3.front(),v2.front());

    ASSERT_EQ(v4.size(),5);
    ASSERT_EQ(v4.front(),0);
}

TEST(VectorBasics, OperatorEq)
{
    Vector<int> v1(2,5);
    Vector<int> v2(3,4);
    v1=v2;

    ASSERT_EQ(v2.size(),v1.size());
    ASSERT_EQ(v1.capacity(),4);
    ASSERT_EQ(v2.front(),v1.front());
}

TEST(VectorCapacity, size)
{
    Vector<int> v1(2,5);
    ASSERT_EQ(v1.size(),2);
}

TEST(VectorCapacity, maxSize)
{
    Vector<int> v1(2,5);
    ASSERT_EQ(v1.max_size(),(size_t)-1);
}

TEST(VectorCapacity, resize)
{
    Vector<int> v1(2,5);
    Vector<int> v2(4,5);
    Vector<int> v3(4,5);

    v1.resize(4);
    ASSERT_EQ(v1.back(),0);

    v2.resize(3);
    ASSERT_EQ(v2.size(),3);

    v1.resize(5,8);
    ASSERT_EQ(v1.back(),8);
}

TEST(VectorCapacity, capacity)
{
    Vector<int> v1(2,5);
    ASSERT_EQ(v1.capacity(),2);
}

TEST(VectorCapacity, empty)
{
    Vector<int> v1;
    ASSERT_TRUE(v1.empty());

    v1.push_back(5);
    ASSERT_FALSE(v1.empty());
}

TEST(VectorCapacity, reserve)
{
    Vector<int> v1(2,5);
    v1.reserve(4);
    ASSERT_EQ(v1.capacity(),4);
    ASSERT_EQ(v1.size(),2);
}

TEST(VectorElementAccess, operatorParentheses)
{
    Vector<int> v1(2,5);
    ASSERT_EQ(v1[0],5);
    ASSERT_EQ(v1[3],0);
    v1[1]=100;
    ASSERT_EQ(v1[1],100);
}

TEST(VectorElementAccess, operatorAt)
{
    Vector<float> v1(2,5.5);
    ASSERT_FLOAT_EQ(v1.at(0),5.5);
    ASSERT_THROW(v1.at(3),std::out_of_range);
    v1.at(1)=100.25;
    ASSERT_FLOAT_EQ(v1.at(1),100.25);
}

TEST(VectorElementAccess, frontBack)
{
    Vector<double> v1(1,5.5);
    v1.push_back(7.5);
    ASSERT_DOUBLE_EQ(v1.front(),5.5);
    ASSERT_DOUBLE_EQ(v1.back(),7.5);
}

TEST(VectorElementAccess, data)
{
    Vector<int> v1(3,5);
    int* p=v1.data();
    ASSERT_EQ(p,&(v1.front()));
    *p=7;
    p++;
    *p=10;
    ASSERT_DOUBLE_EQ(v1.front(),7);
    ASSERT_DOUBLE_EQ(v1[1],10);
    ASSERT_DOUBLE_EQ(v1.back(),5);
}

TEST(VectorModefiers, assign)
{
    Vector<int> v1(3,5);
    v1.assign(8,100);

    ASSERT_EQ(v1[6],100);
    ASSERT_EQ(v1.capacity(),8);
    ASSERT_EQ(v1.size(),8);

    v1.assign(5,99);
    ASSERT_THROW(v1.at(6),std::out_of_range);
    ASSERT_EQ(v1.capacity(),8);
    ASSERT_EQ(v1.size(),5);
}

TEST(VectorModefiers, pushBack)
{
    Vector<short> v1(3,5);
    ASSERT_EQ(v1.back(),5);
    v1.push_back(10);
    ASSERT_EQ(v1.back(),10);
}

TEST(VectorModefiers, popBack)
{
    Vector<short> v1(3,5);
    v1.push_back(10);
    ASSERT_EQ(v1.back(),10);
    v1.pop_back();
    ASSERT_EQ(v1.back(),5);
}

TEST(VectorModefiers, insert)
{
    Vector<short> v1(4,5);
    v1.insert(2,100,3);
    ASSERT_EQ(v1[2],100);
    ASSERT_EQ(v1.capacity(),8);
    ASSERT_EQ(v1.size(),7);
}

TEST(VectorModefiers, erase)
{
    Vector<short> v1(1,5);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.erase(2);
    ASSERT_EQ(v1[2],8);
    ASSERT_EQ(v1.size(),3);
    v1.push_back(9);
    v1.push_back(10);
    v1.erase(1,2);
    ASSERT_EQ(v1[1],9);
    ASSERT_EQ(v1[2],10);
    ASSERT_EQ(v1.size(),3);
}

TEST(VectorModefiers, swap)
{
    Vector<int> v1(2,5);
    Vector<int> v2(3,100);
    v1.swap(v2);
    ASSERT_EQ(v1.front(),100);
    ASSERT_EQ(v2.front(),5);
    ASSERT_EQ(v1.size(),3);
    ASSERT_EQ(v2.size(),2);
    ASSERT_EQ(v1.capacity(),4);
    ASSERT_EQ(v2.capacity(),3);
    v2.~Vector();
    ASSERT_EQ(v1.front(),100);
}

TEST(VectorModefiers, clear)
{
    Vector<int> v1(2,5);
    ASSERT_EQ(v1.size(),2);
    ASSERT_EQ(v1.capacity(),2);
    v1.clear();
    ASSERT_EQ(v1.size(),0);
    ASSERT_EQ(v1.capacity(),2);
}

TEST(VectorAdvanced, operatorPlus)
{
    Vector<int> v1(2,5);
    Vector<int> v2(3,8);
    Vector<int> v3;
    v3=v1+v2;
    ASSERT_EQ(v3.size(),5);
    ASSERT_EQ(v3.capacity(),8);
    ASSERT_EQ(v3[3],8);
    ASSERT_EQ(v3.front(),5);
}

TEST(VectorAdvanced, operatorPlusEq)
{
    Vector<int> v1(2,5);
    Vector<int> v2(5,8);
    v1+=v2;
    ASSERT_EQ(v1.size(),7);
    ASSERT_EQ(v1.capacity(),8);
    ASSERT_EQ(v1[3],8);
    ASSERT_EQ(v1.front(),5);
}

TEST(VectorAdvanced, cout)
{
    Vector<short> v1(1,5);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    //std::cout<<v1<<std::endl;
    ASSERT_TRUE(std::cout<<v1);
}
