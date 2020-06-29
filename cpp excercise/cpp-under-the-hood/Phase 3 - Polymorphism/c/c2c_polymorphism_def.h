//
// Created by student on 18/06/2020.
//

#ifndef INC_08_UTH3_POLYMORPHISM_C2C_POLYMORPHISM_DEF_H
#define INC_08_UTH3_POLYMORPHISM_C2C_POLYMORPHISM_DEF_H

#include <stdio.h>

typedef void (*funcptr)(void*,...);
//-------------------------------------------------------------------------------Text Formatter:---
typedef struct TextFormatter
{
    funcptr * vptr;
}TextFormatter;

void text_formatter_dtor(TextFormatter* const this);
void text_formatter_print(TextFormatter* const this, const char* c);

//-------------------------------------------------------------------------------Default text formatter:---

typedef struct DefaultTextFormatter
{
    TextFormatter text_formatter_base;
    int id;

}DefaultTextFormatter;

void DefaultTextFormatter_ctor(DefaultTextFormatter* const this);
void DefaultTextFormatter_copy_ctor(DefaultTextFormatter* const this,const DefaultTextFormatter* const other);
DefaultTextFormatter* DefaultTextFormatter_operator_eq(DefaultTextFormatter* const this,const DefaultTextFormatter* const other);
void DefaultTextFormatter_dtor(DefaultTextFormatter* const this);
void DefaultTextFormatter_print(const DefaultTextFormatter* const this,const char* text);

DefaultTextFormatter* generateFormatterArray();

//-------------------------------------------------------------------------------Pre post fixer:---

typedef struct PrePostFixer
{
    DefaultTextFormatter def_text_fomatter_base;
    const char* pre;
    const char* post;
}PrePostFixer;

void PrePostFixer_ctor(PrePostFixer* const this ,const char* prefix, const char* postfix);
void PrePostFixer_dtor(PrePostFixer* const this);
void PrePostFixer_print_char(const PrePostFixer* const this, const char* text);
void PrePostFixer_print_long_char(const PrePostFixer* const this,long num, const char symbol);
char PrePostFixer_getDefaultSymbol(PrePostFixer* const this);

//-------------------------------------------------------------------------------Pre post dollar fixer:---

typedef struct PrePostDollarFixer
{
    PrePostFixer pre_post_fixer_base;

}PrePostDollarFixer;

void PrePostDollarFixer_ctor(PrePostDollarFixer* const this,const char* prefix, const char* postfix);
void PrePostDollarFixer_copy_ctor(PrePostDollarFixer* const this,const PrePostDollarFixer* const other);
void PrePostDollarFixer_dtor(PrePostDollarFixer* const this);

void PrePostDollarFixer_print_int_char(const PrePostDollarFixer* const this,int num, char symbol);
void PrePostDollarFixer_print_long_char(const PrePostDollarFixer* const this,long num, char symbol);
void PrePostDollarFixer_print_double_char(const PrePostDollarFixer* const this,double num, char symbol);

char PrePostDollarFixer_getDefaultSymbol(const PrePostDollarFixer* const this);

//-------------------------------------------------------------------------------Pre post hash fixer:---

typedef struct PrePostHashFixer
{
    PrePostDollarFixer pre_post_dollar_base;
    int precision;
}PrePostHashFixer;

void PrePostHashFixer_ctor_int(PrePostHashFixer* const this,int prc);
void PrePostHashFixer_dtor(PrePostHashFixer* const this);

void PrePostHashFixer_print_int_char(const PrePostHashFixer* const this,int num, char symbol);
void PrePostHashFixer_print_long_char(const PrePostHashFixer* const this,long num, char symbol);


char PrePostHashFixer_getDefaultSymbol(PrePostHashFixer* const this);

//-------------------------------------------------------------------------------Pre post float dollar fixer:---

typedef struct PrePostFloatDollarFixer
{
    PrePostDollarFixer pre_post_dollar_base;
}PrePostFloatDollarFixer;

void PrePostFloatDollarFixer_ctor(PrePostFloatDollarFixer* const this,const char* prefix, const char* postfix);
void PrePostFloatDollarFixer_dtor(PrePostFloatDollarFixer* const this);

void PrePostFloatDollarFixer_print_float(PrePostFloatDollarFixer* const this,float num);
void PrePostFloatDollarFixer_print_float_char(PrePostFloatDollarFixer* const this,float num, char symbol);

char PrePostFloatDollarFixer_getDefaultSymbol(PrePostFloatDollarFixer* const this);

//-------------------------------------------------------------------------------Pre post checker:---

typedef struct PrePostChecker
{
    PrePostFloatDollarFixer pre_post_float_dollar_base;
}PrePostChecker;

void PrePostChecker_ctor(PrePostChecker* const this);
void PrePostChecker_dtor(PrePostChecker* const this);

void printThisSymbolUsingFunc(const PrePostChecker* const this);
void printThisSymbolDirectly(const PrePostChecker* const this);
void printDollarSymbolByCastUsingFunc(const PrePostChecker* const this);
void printDollarSymbolByScopeUsingFunc(const PrePostChecker* const this);
void printDollarSymbolByCastDirectly(const PrePostChecker* const this);
void printDollarSymbolByScopeDirectly(const PrePostChecker* const this);

//-------------------------------------------------------------------------------Multiplier:---

typedef struct Multiplier
{
    DefaultTextFormatter def_text_formatter_base;
    int times;
}Multiplier;

void Multiplier_dtor(Multiplier* const this);
void Multiplier_print(const Multiplier* const this,const char* text);



#endif //INC_08_UTH3_POLYMORPHISM_C2C_POLYMORPHISM_DEF_H
