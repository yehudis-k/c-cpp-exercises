//
// Created by student on 09/06/2020.
//

#include "test.h"

TEST(CtorTest, CreateFixedPoint)
{    FixedPoint<2> p1(5,25);
    ASSERT_FLOAT_EQ(float(p1), 5.25);
    FixedPoint<3> p2(5,2532);
    std::cout<<p2<<std::endl;
    ASSERT_DOUBLE_EQ(double(p2), 2.253);
    //FixedPoint<char,2> p2(5,-25);
    //ASSERT_FLOAT_EQ(float(p2), -5.25);
    //std::cout<<p2<<std::endl;
    FixedPoint<2,short> p3;
    ASSERT_FLOAT_EQ(float(p3), 0);
    FixedPoint<2,size_t> p4(999999999,99);
    ASSERT_EQ(p4.getDollars(), 999999999);
    ASSERT_EQ(p4.getCents(), 99);
}

TEST(ArithmeticOperatorTest, PlusOp)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(2,78);
    FixedPoint<2> p3(-1);
    FixedPoint<2> p4=p3+p1;
    ASSERT_DOUBLE_EQ(p1+p2, 8.03);
    ASSERT_DOUBLE_EQ(p1+5, 10.25);
    ASSERT_DOUBLE_EQ(float(p4), 4.25);
    FixedPoint<2> p5(3, -70);
    FixedPoint<2> p6(-5, 40);
    FixedPoint<2> p7(p5 + p6);
    FixedPoint<2> p8(p6 + p5);
    FixedPoint<2> p9(p6 + p6);
    FixedPoint<2> p10(p5 + p5);
    ASSERT_DOUBLE_EQ(p7, -9.1);
    ASSERT_DOUBLE_EQ(p8, -9.1);
    ASSERT_DOUBLE_EQ(p9, -10.8);
    ASSERT_DOUBLE_EQ(p10, -7.4);
}

TEST(ArithmeticOperatorTest, MinusOp)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(2,50);
    ASSERT_DOUBLE_EQ(float(p1-p2), 2.75);
    ASSERT_DOUBLE_EQ(float(p2-p1), -2.75);
    ASSERT_DOUBLE_EQ(p1-5, 0.25);
    FixedPoint<2> p3(3, -70);
    FixedPoint<2> p4(5, 40);
    FixedPoint<2> p5(p3 - p4);
    FixedPoint<2> p6(p4 - p3);
    FixedPoint<2> p7(p4 - p4);
    FixedPoint<2> p8(p3 - p3);
    ASSERT_DOUBLE_EQ(p5, -9.1);
    ASSERT_DOUBLE_EQ(p6, 9.1);
    ASSERT_DOUBLE_EQ(p7, 0);
    ASSERT_DOUBLE_EQ(p8, 0);

}

TEST(ArithmeticOperatorTest, MultiplicationOp)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(2);
    FixedPoint<4> p5(2,1234);
    FixedPoint<2> p3(-1,50);
    FixedPoint<2> p4(2,50);
    FixedPoint<2> p6(10,1);
    FixedPoint<2> p7(5,23);
    ASSERT_DOUBLE_EQ(double(p1*p2), 10.5);
    ASSERT_DOUBLE_EQ(double(p5*5), 10.617);
    std::cout<<p5<<std::endl;
    ASSERT_DOUBLE_EQ(double(p2*-5), -10);
    ASSERT_DOUBLE_EQ(double(p3*p4), -3.75);
    ASSERT_DOUBLE_EQ(double(p6*p7), 52.35);
}

TEST(ArithmeticOperatorTest, DivideOp)
{
    FixedPoint<2> p1(6,25);
    FixedPoint<2> p2(2,50);
    FixedPoint<2> p3(-2,50);
    ASSERT_DOUBLE_EQ(double(p1/p2), 2);
    ASSERT_DOUBLE_EQ(p1/4, 1.5625);
    ASSERT_DOUBLE_EQ(p2/p3, -1);
}

TEST(ArithmeticOperatorTest, ModuloOp)
{
    FixedPoint<2> p1(5,30);
    FixedPoint<2> p2(2);
    ASSERT_DOUBLE_EQ(double(p1%p2), 1.30);
}


TEST(ArithmeticOperatorTest, PlusEqOp)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(2,5);
    FixedPoint<2> p3(-2,5);
    p1+=p2;
    p2+=2;
    p3+=1;
    ASSERT_DOUBLE_EQ(double(p1), 7.30);
    ASSERT_DOUBLE_EQ(double(p2), 4.05);
    ASSERT_DOUBLE_EQ(double(p3), -1.05);
}

TEST(ArithmeticOperatorTest, MinusEqOp) {
    FixedPoint<2> p1(5, 25);
    FixedPoint<2> p2(2, 5);
    p1 -= p2;
    p2 -= 3;
    ASSERT_DOUBLE_EQ(double(p1), 3.20);
    ASSERT_DOUBLE_EQ(double(p2), -0.95);
}

TEST(ArithmeticOperatorTest, MultEqOp)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(2,5);
    FixedPoint<2> p3(-2,5);
    p1*=p2;
    p2*=1;
    p3*=1;
    ASSERT_DOUBLE_EQ(p1, 10.76);
    ASSERT_DOUBLE_EQ(p2, 2.05);
    ASSERT_DOUBLE_EQ(p3, -2.05);
}

TEST(ArithmeticOperatorTest, DevEqOp)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(2,5);
    FixedPoint<2> p3(-10,5);
    p1/=p2;
    p2/=2;
    p3/=3;
    ASSERT_DOUBLE_EQ(p1, 2);
    ASSERT_DOUBLE_EQ(p2, 1);
    ASSERT_DOUBLE_EQ(p3, -3);
}

TEST(ArithmeticOperatorTest, ModEqOp)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(2,5);
    FixedPoint<2> p3(-2,50);
    p1%=p2;
    p2%=2;
    p3%=-2;
    ASSERT_DOUBLE_EQ(p1, 1.15);
    ASSERT_DOUBLE_EQ(p2, 0.05);
    ASSERT_DOUBLE_EQ(p3, 0.5);
}

TEST(ArithmeticOperatorTest, Unary)
{
    FixedPoint<2> p1(5,25);
    ASSERT_DOUBLE_EQ(float(-p1), -5.25);
}

TEST(ArithmeticOperatorTest, PreIncreaseOp)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(-1);
    FixedPoint<2> p3(0,-25);
    ++p1;
    ++p2;
    ++p3;
    ASSERT_DOUBLE_EQ(float(p1), 6.25);
    ASSERT_DOUBLE_EQ(float(p2), 0);
    ASSERT_DOUBLE_EQ(float(p3), 0.75);
}

TEST(ArithmeticOperatorTest, PreDecreaseOp)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(0,25);
    --p1;
    --p2;
    ASSERT_DOUBLE_EQ(float(p1), 4.25);
    ASSERT_DOUBLE_EQ(float(p2), -0.75);
}

TEST(ArithmeticOperatorTest, PostIncreaseOp)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(-1);
    FixedPoint<2> p3(0,-25);
    p1++;
    p2++;
    p3++;
    ASSERT_DOUBLE_EQ(float(p1), 6.25);
    ASSERT_DOUBLE_EQ(float(p2), 0);
    ASSERT_DOUBLE_EQ(float(p3), 0.75);
}

TEST(ArithmeticOperatorTest, PostDecreaseOp)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(0,25);
    p1--;
    p2--;
    ASSERT_DOUBLE_EQ(float(p1), 4.25);
    ASSERT_DOUBLE_EQ(float(p2), -0.75);
}

TEST(ComparisonOperatorTest, Equal)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(5,25);
    FixedPoint<2> p3(-2,5);
    FixedPoint<2> p4=p3;
    ASSERT_TRUE(p1==p2);
    ASSERT_FALSE(p1==p3);
    ASSERT_TRUE(p4==p3);
}


TEST(ComparisonOperatorTest, NotEqual)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(5,25);
    FixedPoint<2> p3(2,5);
    ASSERT_TRUE(p1!=p3);
    ASSERT_FALSE(p1!=p2);
}


TEST(ComparisonOperatorTest, Smaller)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(2,5);
    ASSERT_FALSE(p1<p2);
    ASSERT_TRUE(p2<p1);
}

TEST(ComparisonOperatorTest, Larger)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(2,5);
    ASSERT_TRUE(p1>p2);
    ASSERT_FALSE(p2>p1);
}

TEST(ComparisonOperatorTest, SmallerEqual)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(2,5);
    FixedPoint<2> p3(2,5);
    ASSERT_FALSE(p1<=p2);
    ASSERT_TRUE(p2<=p3);
}

TEST(ComparisonOperatorTest, LargerEqual)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(2,5);
    FixedPoint<2> p3(2,5);
    ASSERT_FALSE(p2>=p1);
    ASSERT_TRUE(p2>=p3);
}

TEST(BasicTest,AssignmentOp)
{
    FixedPoint<2> p1;
    p1=7;
    FixedPoint<2> p2;
    p2=-7;
    ASSERT_DOUBLE_EQ(float(p1),7.00);
    ASSERT_DOUBLE_EQ(float(p2),-7.00);
}

TEST(BasicTest, Print)
{
    FixedPoint<2> p1(5,25);
    FixedPoint<2> p2(1,-30);
    ASSERT_TRUE(std::cout<<p1);
    ASSERT_TRUE(std::cout<<p2);
}

TEST(BasicTest, CastToDouble)
{
    FixedPoint<2> p1(5,25);
    ASSERT_DOUBLE_EQ(double(p1), 5.25);
}

TEST(FunctionTest, Precision)
{
    FixedPoint<3> p1(5,2525);
    FixedPoint<4> p2(5,2500);
    FixedPoint<4> p3(5,0025);
    ASSERT_EQ(p1.getPrecision(),3);
    ASSERT_EQ(p2.getPrecision(),2);
    ASSERT_EQ(p3.getPrecision(),4);
}

TEST(FunctionTest, TheType)
{
    FixedPoint<3, short> p2(5,2525);
    FixedPoint<3, short>::theType p1;
    FixedPoint<3>::theType p3;
    ASSERT_EQ(typeid(p1),typeid(p2.getDollars()));
    ASSERT_EQ(typeid(p3),typeid(int));
}

