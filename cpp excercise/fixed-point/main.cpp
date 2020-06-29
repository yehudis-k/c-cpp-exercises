//g++ -pedantic -Wall -Wconversion  test.cpp price.cpp main.cpp -lgtest -lgtest_main -pthread -o test

#include <iostream>
#include "test.h"
int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
