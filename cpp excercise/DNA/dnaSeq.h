//
// Created by student on 01/06/2020.
//
#include <iostream>
#include <cstring>
#include <fstream>
#include "except.h"
#include <vector>
#ifndef DNA_DNASEQ_H
#define DNA_DNASEQ_H

static const char validChar[4]={'A', 'C', 'T', 'G'};



class DnaSequence
{
private:
    class DnaChar {
    public:
        DnaChar(){}
        DnaChar(char);
        DnaChar(const DnaChar&);
        operator char(){return letter;}
        DnaChar&operator=(const DnaChar&);
        const char& getChar() const {return letter;}
    private:
        char letter;
    };
    static DnaChar* convert(const char*);
    static DnaChar* convert(const std::string);
    DnaChar * m_seq;
    size_t length;
public:
    DnaSequence(const char*);
    DnaSequence(const std::string&);
    DnaSequence(const DnaSequence&);
    ~DnaSequence();
    DnaSequence& operator=(const DnaSequence&);
    const size_t getLen()const {return length;}
    std::string getSeq()const;
    DnaChar& operator[](size_t index);
    const DnaChar& operator[](size_t index)const;
    DnaSequence mySlice(size_t start, size_t end);
    DnaSequence pair();
    size_t find(DnaSequence);
    size_t count(DnaSequence);
    std::vector<size_t> findAll(DnaSequence);
    std::vector<DnaSequence> findConsensusSeq();

friend std::ostream& operator << (std::ostream& cout,const DnaSequence::DnaChar& dna);    
};

void writeToFile(DnaSequence, const char*);
DnaSequence readFromFile(const char*);

inline DnaSequence::DnaSequence(const char* str):m_seq(convert(str)), length(strlen(str)){}

inline DnaSequence::DnaSequence(const std::string& str):m_seq(convert(str.c_str())),length(str.length()) {}

inline DnaSequence::DnaSequence(const DnaSequence & seq):m_seq(new DnaChar[seq.getLen()+1]), length(seq.getLen())
{
    m_seq=convert(seq.getSeq());
}

inline DnaSequence::~DnaSequence()
{
    delete[] m_seq;
}

inline DnaSequence& DnaSequence::operator=(const DnaSequence& second)
{
    if (this != &second)
    {
        length=second.getLen();
        DnaChar* tmp=m_seq;
        m_seq=new DnaChar [second.getLen()+1];
        delete tmp;
        m_seq=convert(second.getSeq());

    }
    return *this;
}


inline std::string DnaSequence::getSeq() const {
    std::string tmp;
    for (size_t i = 0; i < length; i++) {
        tmp.push_back(m_seq[i].getChar());
    }
    return tmp;
}

inline const DnaSequence::DnaChar& DnaSequence::operator[](size_t index)const
{
    if(index>length)
        throw IndexError();
    return m_seq[index];
}

inline DnaSequence::DnaChar& DnaSequence::operator[](size_t index)
{
    if(index>length)
        throw IndexError();
    return m_seq[index];
}

inline std::ostream& operator<<(std::ostream& cout, const DnaSequence& dna) {
    cout<<dna.getSeq()<<std::endl;
    return cout;
}

inline std::ostream& operator<<(std::ostream& cout, const DnaSequence::DnaChar& dna)
{
    cout<<dna.getChar()<<std::endl;
    return cout;
}


inline bool operator==(const DnaSequence & d1, const DnaSequence & d2) {
    if (d2.getSeq()==d1.getSeq())
        return true;
    return false;
}
inline bool operator!=(const DnaSequence & d1, const DnaSequence & d2) {
    if (d2.getSeq()!=d1.getSeq())
        return true;
    return false;
}

inline DnaSequence::DnaChar::DnaChar(char c) : letter('\0')
{
    bool flag=false;
    for (size_t i = 0; i < sizeof(validChar); i++) {
        if (c==validChar[i])
        {
            flag=true;
        }
    }
    if (flag==false)
    {
        throw ValidError();
    }
    letter=c;
}

inline DnaSequence::DnaChar& DnaSequence::DnaChar::operator=(const DnaChar & dna)
{
    letter=dna.letter;
    return *this;
}


#endif //DNA_DNASEQ_H
