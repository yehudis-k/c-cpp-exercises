//
// Created by student on 18/06/2020.
//

#include "c2c_polymorphism_def.h"
#include <malloc.h>


int next_id=0;
const char DEFAULT_SYMBOL_DOLLAR='$';
const char DEFAULT_SYMBOL_HASH='#';
const char DEFAULT_SYMBOL_FLOAT_DOLLAR='@';



//-------------------------------------------------------------------------------Text Formatter:---

funcptr text_formatter_table[]={(funcptr )text_formatter_dtor,
                                NULL};

void text_formatter_dtor(TextFormatter* const this){}

//-------------------------------------------------------------------------------Default text formatter:---

funcptr default_text_formatter_table[]={(funcptr )DefaultTextFormatter_dtor,
                                        (funcptr )DefaultTextFormatter_print};

void DefaultTextFormatter_ctor(DefaultTextFormatter* const this)
{
    this->text_formatter_base.vptr=default_text_formatter_table;
    this->id=next_id++;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);
}
void DefaultTextFormatter_copy_ctor(DefaultTextFormatter* const this,const DefaultTextFormatter* const other)
{
    this->id=next_id++;
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, this->id);

}
DefaultTextFormatter* DefaultTextFormatter_operator_eq(DefaultTextFormatter* const this,const DefaultTextFormatter* const other)
{
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, this->id);
    return this;
}
void DefaultTextFormatter_dtor(DefaultTextFormatter* const this)
{
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
}
void DefaultTextFormatter_print(const DefaultTextFormatter* const this,const char* text)
{
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);
}

DefaultTextFormatter* generateFormatterArray()
{
    DefaultTextFormatter* tmp=(DefaultTextFormatter*)malloc(3*sizeof(DefaultTextFormatter));
    DefaultTextFormatter_ctor(&tmp[0]);
    DefaultTextFormatter_ctor(&tmp[1]);
    DefaultTextFormatter_ctor(&tmp[2]);
    return tmp;
}


//-------------------------------------------------------------------------------Pre post fixer:---
funcptr pre_post_fixer_table[]={(funcptr )PrePostFixer_dtor,
                                (funcptr )PrePostFixer_print_char,
                                (funcptr )PrePostFixer_getDefaultSymbol,
                                (funcptr )PrePostFixer_print_long_char};

void PrePostFixer_ctor(PrePostFixer* const this ,const char* prefix, const char* postfix)
{
    DefaultTextFormatter_ctor((DefaultTextFormatter*)this);
    this->def_text_fomatter_base.text_formatter_base.vptr=pre_post_fixer_table;
    this->pre=prefix;
    this->post=postfix;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}

void PrePostFixer_dtor(PrePostFixer* const this)
{
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
    this->def_text_fomatter_base.text_formatter_base.vptr=default_text_formatter_table;
    DefaultTextFormatter_dtor((DefaultTextFormatter*)this);
}

void PrePostFixer_print_char(const PrePostFixer* const this, const char* text)
{
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", this->pre, text, this->post);
}

void PrePostFixer_print_long_char(const PrePostFixer* const this,long num, const char symbol)
{
    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");
    if (symbol)
    {
        printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", this->pre, symbol, num, this->post);
    }
    else
    {
        printf("%-60s | ", "[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", this->pre, num, this->post);
    }
}

char PrePostFixer_getDefaultSymbol(PrePostFixer* const this)
{
    return '\0';
}

//-------------------------------------------------------------------------------Pre post dollar fixer:---

funcptr pre_post_dollar_table[]={(funcptr )PrePostDollarFixer_dtor,
                                 (funcptr )PrePostFixer_print_char,
                                 (funcptr )PrePostDollarFixer_getDefaultSymbol,
                                 (funcptr )PrePostDollarFixer_print_long_char};

void PrePostDollarFixer_ctor(PrePostDollarFixer* const this,const char* prefix, const char* postfix)
{
    PrePostFixer_ctor((PrePostFixer*)this, prefix,postfix);
    this->pre_post_fixer_base.def_text_fomatter_base.text_formatter_base.vptr=pre_post_dollar_table;
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", this->pre_post_fixer_base.pre, this->pre_post_fixer_base.post);
}

void PrePostDollarFixer_copy_ctor(PrePostDollarFixer* const this,const PrePostDollarFixer* const other)
{
    DefaultTextFormatter_copy_ctor((DefaultTextFormatter*)this,(DefaultTextFormatter*)other);
    this->pre_post_fixer_base.pre=other->pre_post_fixer_base.pre;
    this->pre_post_fixer_base.post=other->pre_post_fixer_base.post;
    this->pre_post_fixer_base.def_text_fomatter_base.text_formatter_base.vptr=pre_post_dollar_table;
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", this->pre_post_fixer_base.pre, this->pre_post_fixer_base.post);
}

void PrePostDollarFixer_dtor(PrePostDollarFixer* const this)
{
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", this->pre_post_fixer_base.pre, this->pre_post_fixer_base.post);
    this->pre_post_fixer_base.def_text_fomatter_base.text_formatter_base.vptr=pre_post_fixer_table;
    PrePostFixer_dtor((PrePostFixer*)this);
}

void PrePostDollarFixer_print_int_char(const PrePostDollarFixer* const this,int num, char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");

    this->pre_post_fixer_base.def_text_fomatter_base.text_formatter_base.vptr[3]((PrePostDollarFixer*)this,(long)num, symbol);
}


void PrePostDollarFixer_print_long_char(const PrePostDollarFixer* const this,long num, char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");
    PrePostFixer_print_long_char((PrePostFixer*)this,num,symbol);
}


void PrePostDollarFixer_print_double_char(const PrePostDollarFixer* const this,double num, char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", this->pre_post_fixer_base.pre, symbol, num, this->pre_post_fixer_base.post);
}

char PrePostDollarFixer_getDefaultSymbol(const PrePostDollarFixer* const this)
{
    return DEFAULT_SYMBOL_DOLLAR;
}

//-------------------------------------------------------------------------------Pre post hash fixer:---

funcptr pre_post_hash_table[]={(funcptr )PrePostHashFixer_dtor,
                               (funcptr )PrePostFixer_print_char,
                               (funcptr )PrePostHashFixer_getDefaultSymbol,
                               (funcptr )PrePostHashFixer_print_long_char};

void PrePostHashFixer_ctor_int(PrePostHashFixer* const this,int prc)
{
    PrePostDollarFixer_ctor((PrePostDollarFixer*)this,"===> ", " <===");
    this->pre_post_dollar_base.pre_post_fixer_base.def_text_fomatter_base.text_formatter_base.vptr=pre_post_hash_table;
    this->precision=prc;
    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", this->pre_post_dollar_base.pre_post_fixer_base.pre,
            this->pre_post_dollar_base.pre_post_fixer_base.post, this->precision);

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", this->pre_post_dollar_base.pre_post_fixer_base.pre, DEFAULT_SYMBOL_HASH, this->precision,
            9999.9999, this->pre_post_dollar_base.pre_post_fixer_base.post);
}


void PrePostHashFixer_dtor(PrePostHashFixer* const this)
{
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", this->pre_post_dollar_base.pre_post_fixer_base.pre,
           this->pre_post_dollar_base.pre_post_fixer_base.post);
    this->pre_post_dollar_base.pre_post_fixer_base.def_text_fomatter_base.text_formatter_base.vptr=pre_post_dollar_table;
    PrePostDollarFixer_dtor((PrePostDollarFixer*)this);
}

void PrePostHashFixer_print_int_char(const PrePostHashFixer* const this,int num, char symbol)
{
    printf("%-60s | ", "[PrePostHashFixer::print(int, char)]");
    printf("-->\n");

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", this->pre_post_dollar_base.pre_post_fixer_base.pre, symbol, this->precision,
           (double)num, this->pre_post_dollar_base.pre_post_fixer_base.post);

}

void PrePostHashFixer_print_long_char(const PrePostHashFixer* const this,long num, char symbol)
{
    printf("%-60s | ", "[PrePostHashFixer::print(long, char)]");
    printf("-->\n");

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", this->pre_post_dollar_base.pre_post_fixer_base.pre, symbol, this->precision,
           (float)num, this->pre_post_dollar_base.pre_post_fixer_base.post);

}


char PrePostHashFixer_getDefaultSymbol(PrePostHashFixer* const this)
{
    return DEFAULT_SYMBOL_HASH;
}

//-------------------------------------------------------------------------------Pre post float dollar fixer:---

funcptr pre_post_float_dollar_table[]={(funcptr )PrePostFloatDollarFixer_dtor,
                                       (funcptr )PrePostFixer_print_char,
                                       (funcptr )PrePostFloatDollarFixer_getDefaultSymbol,
                                       (funcptr )PrePostDollarFixer_print_long_char};

void PrePostFloatDollarFixer_ctor(PrePostFloatDollarFixer* const this,const char* prefix, const char* postfix)
{
    PrePostDollarFixer_ctor((PrePostDollarFixer*)this, prefix,postfix);
    this->pre_post_dollar_base.pre_post_fixer_base.def_text_fomatter_base.text_formatter_base.vptr=pre_post_float_dollar_table;
    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", this->pre_post_dollar_base.pre_post_fixer_base.pre,
            this->pre_post_dollar_base.pre_post_fixer_base.post);
}

void PrePostFloatDollarFixer_dtor(PrePostFloatDollarFixer* const this)
{
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", this->pre_post_dollar_base.pre_post_fixer_base.pre,
           this->pre_post_dollar_base.pre_post_fixer_base.post);
    this->pre_post_dollar_base.pre_post_fixer_base.def_text_fomatter_base.text_formatter_base.vptr=pre_post_dollar_table;
    PrePostDollarFixer_dtor((PrePostDollarFixer*)this);
}

void PrePostFloatDollarFixer_print_float(PrePostFloatDollarFixer* const this,float num)
{
    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");

    PrePostFloatDollarFixer_print_float_char((PrePostFloatDollarFixer*)this,num,DEFAULT_SYMBOL_FLOAT_DOLLAR);

}

void PrePostFloatDollarFixer_print_float_char(PrePostFloatDollarFixer* const this,float num, char symbol)
{
    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float, char)]");
    printf("%s%c%.2f%s\n", this->pre_post_dollar_base.pre_post_fixer_base.pre, symbol, num,
            this->pre_post_dollar_base.pre_post_fixer_base.post);
}

char PrePostFloatDollarFixer_getDefaultSymbol(PrePostFloatDollarFixer* const this)
{
    return DEFAULT_SYMBOL_FLOAT_DOLLAR;
}

//-------------------------------------------------------------------------------Pre post checker:---
funcptr pre_post_checker_table[]={(funcptr )PrePostChecker_dtor,
                                  (funcptr )PrePostFixer_print_char,
                                  (funcptr )PrePostFloatDollarFixer_getDefaultSymbol,
                                  (funcptr )PrePostDollarFixer_print_long_char};

void PrePostChecker_ctor(PrePostChecker* const this)
{
    PrePostFloatDollarFixer_ctor((PrePostFloatDollarFixer*)this, "[[[[ ", " ]]]]");
    this->pre_post_float_dollar_base.pre_post_dollar_base.pre_post_fixer_base.def_text_fomatter_base.text_formatter_base.vptr=pre_post_checker_table;
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n",
            this->pre_post_float_dollar_base.pre_post_dollar_base.pre_post_fixer_base.pre,
            this->pre_post_float_dollar_base.pre_post_dollar_base.pre_post_fixer_base.post);
}

void PrePostChecker_dtor(PrePostChecker* const this)
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", this->pre_post_float_dollar_base.pre_post_dollar_base.pre_post_fixer_base.pre,
           this->pre_post_float_dollar_base.pre_post_dollar_base.pre_post_fixer_base.post);
    this->pre_post_float_dollar_base.pre_post_dollar_base.pre_post_fixer_base.def_text_fomatter_base.text_formatter_base.vptr=pre_post_float_dollar_table;
    PrePostFloatDollarFixer_dtor((PrePostFloatDollarFixer*)this);
}

void printThisSymbolUsingFunc(const PrePostChecker* const this)
{
    printf("%-60s | ", "[PrePostChecker::printThisSymbolUsingFunc()]");
    char(*tmpfunc)(const void* const);
    tmpfunc=(char(*)(const void* const))this->pre_post_float_dollar_base.pre_post_dollar_base.pre_post_fixer_base.
            def_text_fomatter_base.text_formatter_base.vptr[2];
    printf("Default symbol is %c\n",
           tmpfunc(this));
}

void printThisSymbolDirectly(const PrePostChecker* const this)
{
    printf("%-60s | ", "[PrePostChecker::printThisSymbolDirectly()]");
    printf("Default symbol is %c\n", DEFAULT_SYMBOL_FLOAT_DOLLAR);
}

void printDollarSymbolByCastUsingFunc(const PrePostChecker* const this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastUsingFunc()]");
    char(*tmpfunc)(const void* const);
    tmpfunc=(char(*)(const void* const))this->pre_post_float_dollar_base.pre_post_dollar_base.pre_post_fixer_base.
            def_text_fomatter_base.text_formatter_base.vptr[2];
    printf("Default symbol is %c\n",
           tmpfunc(this));
}

void printDollarSymbolByScopeUsingFunc(const PrePostChecker* const this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");
    printf("Default symbol is %c\n", PrePostDollarFixer_getDefaultSymbol((PrePostDollarFixer*)this));
}
void printDollarSymbolByCastDirectly(const PrePostChecker* const this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastDirectly()]");
    printf("Default symbol is %c\n", DEFAULT_SYMBOL_DOLLAR);
}
void printDollarSymbolByScopeDirectly(const PrePostChecker* const this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeDirectly()]");
    printf("Default symbol is %c\n", DEFAULT_SYMBOL_DOLLAR);
}

//-------------------------------------------------------------------------------Multiplier:---
funcptr multiplier_table[]={(funcptr )Multiplier_dtor,
                            (funcptr )Multiplier_print};

void Multiplier_dtor(Multiplier* const this)
{
    printf("--- Multiplier DTOR: times = %d\n", this->times);
    this->def_text_formatter_base.text_formatter_base.vptr=default_text_formatter_table;
    DefaultTextFormatter_dtor((DefaultTextFormatter*)this);
}

void Multiplier_print(const Multiplier* const this,const char* text)
{
    printf("%-60s | ", "[Multiplier::print(const char*)]");
    for (int i = 0; i < this->times; ++i)
        printf("%s", text);
    printf("\n");
}