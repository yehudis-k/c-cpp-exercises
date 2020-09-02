//
// Created by student on 07/07/2020.
//
#include <gtest/gtest.h>
#include "SharedPtr.h"
int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*int main()
{
    SharedPtr<Person> sp(new Person);
    SharedPtr<Person> sp2(sp);
    sp->speak();
    sp2->speak();
    std::cout<<"is sp equal to sp2 ? "<<(sp==sp2)<<std::endl;
    std::cout<<"is sp not equal to sp2 ? "<<(sp!=sp2)<<std::endl;
    return 0;
}*/

TEST(Ptr, SharedPtr)
{
    SharedPtr<Person> sp1(new Person(123));
    SharedPtr<Person> sp2(sp1);
    ASSERT_TRUE(sp1 == sp2);
    ASSERT_FALSE(sp1 != sp2);

    sp1->speak();
    sp2->speak();

    SharedPtr<Person> sp3(NULL);
    ASSERT_TRUE(!sp3);
    ASSERT_FALSE(sp3);
    ASSERT_TRUE(sp2);

    SharedPtr<Student> s1(new Student);
    ASSERT_FALSE(s1==sp3);
    sp3 = s1;
    ASSERT_TRUE(s1==sp3);

    SharedPtr<Person> base(new Person);
    SharedPtr<Person> s2=s1;
    base=s1;
    ASSERT_TRUE(base==s1);

}

TEST(Ptr, UniquePtr)
{
    UniquePtr<Person> sp(new Person);
    sp->speak();
//doesn't work because the pointer is unique
//    UniquePtr<Person> sp2(sp);
}

TEST(Ptr, SmartPtr)
{
    SmartPtr<Person> sp1(new Person);
    SmartPtr<Person> sp2(new Person);
    //SharedPtr<Person> sp2(sp);
    sp1->speak();

    //ASSERT_EQ(sp1<Person> == sp2<Person>, 1);
}

