//g++ -pedantic -Wall -Wconversion  test.cpp dnaSeq.cpp except.cpp main.cpp -lgtest -lgtest_main -pthread -o test
// Created by student on 07/06/2020.
//
#include "test.h"
/*int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/

TEST(DnaBasicTests, CreateDna)
{
    const char* good="CTGA";
    const char* bad="XXX";
    std::string str="AAAAA";
    DnaSequence d1(good);
    DnaSequence d2("");
    DnaSequence d3(str);
    DnaSequence d4=d1;
    ASSERT_EQ("CTGA",d1.getSeq());
    ASSERT_THROW(d2=bad, ValidError);
    ASSERT_EQ("AAAAA",d3.getSeq());
    ASSERT_EQ(d1.getSeq(),d4.getSeq());
}


TEST(DnaBasicTests,assignmentOp)
{
    DnaSequence d1("AAAA");
    DnaSequence d2("CCGTAAA");
    d1=d2;
    ASSERT_EQ(d1.getSeq(),d2.getSeq());
}

TEST(DnaBasicTests, getLength)
{
    DnaSequence d("AAAAA");
    ASSERT_EQ(d.getLen(),5);
}

TEST(DnaBasicTests, arrayIndexOp)
{
    DnaSequence d1("ACGT");
    char c=d1[2];
    ASSERT_EQ(c,'G');
    d1[0]='T';
    ASSERT_EQ((char)d1[0],'T');
    ASSERT_THROW(d1[0]='P', ValidError);
}

TEST(DnaBasicTests, EqualOp)
{
    DnaSequence d1("ACGT");
    DnaSequence d2("ACGT");
    DnaSequence d3("AAAA");
    ASSERT_TRUE(d1==d2);
    ASSERT_FALSE(d1==d3);
}

TEST(DnaBasicTests, NotEqualOp)
{
    DnaSequence d1("ACGT");
    DnaSequence d2("ACGT");
    DnaSequence d3("AAAA");
    ASSERT_TRUE(d1!=d3);
    ASSERT_FALSE(d1!=d2);
}

TEST(DnaBasicTests, cout)
{
    DnaSequence d1("ACGT");
    ASSERT_TRUE(std::cout<<d1);
}

TEST(DnaSecondPhase, slice)
{
    DnaSequence d1("AAATTCGT");
    ASSERT_EQ(d1.mySlice(1,3),"AA");
}

TEST(DnaSecondPhase, pair)
{
    DnaSequence d1("AAATTCGTAA");
    std::cout<<d1.pair();
    ASSERT_EQ(d1.pair(),"TTTAAGCATT");
}

TEST(DnaSecondPhase, find)
{
    DnaSequence d1("AAATTCGT");
    ASSERT_EQ(d1.find("AT"),2);
}

TEST(DnaSecondPhase, count)
{
    DnaSequence d1("AAATTCGAT");
    ASSERT_EQ(d1.find("AT"),2);
}

TEST(DnaSecondPhase, findAll)
{
    DnaSequence d1("AAATTCGAT");
    std::vector<size_t> vec;
    vec.push_back(2);
    vec.push_back(7);
    ASSERT_EQ(d1.findAll("AT"),vec);
}


TEST(DnaSecondPhase, findConsensusSeq)
{
    DnaSequence d1("ATGGGGATGTAA");
    std::vector<DnaSequence> vec;
    vec.push_back("ATGGGGATGTAA");
    vec.push_back("ATGTAA");
    ASSERT_EQ(d1.findConsensusSeq(),vec);
}

TEST(DnaSecondPhase, readFromFile)
{
    DnaSequence d2("AAAAACGCGCGCTCGCT");
    writeToFile(d2,"file.txt");
    DnaSequence d1=readFromFile("file.txt");
    ASSERT_EQ(d1.getSeq(),"AAAAACGCGCGCTCGCT");
}

TEST(DnaSecondPhase, writeToFile)
{
    DnaSequence d1("ATGGGGATG");
    writeToFile(d1,"file.txt");
    DnaSequence d2=readFromFile("file.txt");
    ASSERT_EQ(d2.getSeq(),"ATGGGGATG");
}
