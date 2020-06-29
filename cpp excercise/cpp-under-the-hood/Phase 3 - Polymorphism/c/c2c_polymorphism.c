//
// Created by student on 18/06/2020.
//

//gcc c2c_polymorphism.c c2c_polymorphism_def.c
#include "c2c_polymorphism_def.h"
#include <malloc.h>
extern funcptr multiplier_table[];
void do_pre_post_fixer()
{
    PrePostFixer angleBrackets;

    printf("\n--- start doPrePostFixer() ---\n\n");

    PrePostFixer_ctor(&angleBrackets,"<<< ", " >>>");
    PrePostFixer_print_char(&angleBrackets,"Hello World!");
    PrePostFixer_print_long_char(&angleBrackets,-777,'\0');
    PrePostFixer_print_long_char(&angleBrackets,350,'#');
    PrePostFixer_print_long_char(&angleBrackets,(long)3.14,'\0');

    printf("\n--- end doPrePostFixer() ---\n\n");

    PrePostFixer_dtor(&angleBrackets);
}

void doPrePostDollarFixer()
{
    PrePostDollarFixer asterisks;

    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    PrePostDollarFixer_ctor(&asterisks,"***** ", " *****");
    PrePostDollarFixer_print_int_char(&asterisks,-777,'$');
    PrePostDollarFixer_print_int_char(&asterisks,350,'#');
    PrePostDollarFixer_print_double_char(&asterisks,3.14,'$');


    printf("\n--- end doPrePostDollarFixer() ---\n\n");

    PrePostDollarFixer_dtor(&asterisks);
}

void doPrePostFloatDollarFixer()
{
    PrePostFloatDollarFixer hashes;
    PrePostDollarFixer hashes2;

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");


    PrePostFloatDollarFixer_ctor(&hashes,"### ", " ###");

    PrePostFloatDollarFixer_print_float(&hashes, -777);
    PrePostFloatDollarFixer_print_float_char(&hashes, 350,'#');
    PrePostFloatDollarFixer_print_float(&hashes, 3.14f);

    PrePostDollarFixer_copy_ctor(&hashes2,(PrePostDollarFixer*)&hashes);
    PrePostDollarFixer_print_double_char(&hashes2,7.5,'$');
    PrePostDollarFixer_print_int_char(&hashes2,100,'$');

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostDollarFixer_dtor(&hashes2);
    PrePostFloatDollarFixer_dtor(&hashes);
}

void doPrePostChecker()
{
    PrePostChecker check;

    printf("\n--- start doPrePostChecker() ---\n\n");

    PrePostChecker_ctor(&check);
    printThisSymbolUsingFunc(&check);
    printThisSymbolDirectly(&check);
    printDollarSymbolByCastDirectly(&check);
    printDollarSymbolByScopeDirectly(&check);
    printDollarSymbolByCastUsingFunc(&check);
    printDollarSymbolByScopeUsingFunc(&check);

    printf("\n--- end doPrePostChecker() ---\n\n");

    PrePostChecker_dtor(&check);
}

void runAsPrePostFixerRef(const PrePostFixer* pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    (pp->def_text_fomatter_base.text_formatter_base.vptr[3])((PrePostFixer*)pp,123,'\0');

    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(const PrePostDollarFixer* pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

    PrePostDollarFixer_print_int_char((PrePostDollarFixer*)pp,123,'$');

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerObj(const PrePostDollarFixer pp)
{
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    PrePostDollarFixer_print_int_char(&pp,123,'$');

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}

void runAsPrePostHashFixerRef(const PrePostHashFixer* pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    PrePostHashFixer_print_int_char(pp,123,'#');

    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void doMultiplier()
{
    Multiplier m1,m2,m3,m4;
    printf("\n--- start doMultiplier() ---\n\n");

    DefaultTextFormatter_ctor((DefaultTextFormatter*)&m1);
    m1.def_text_formatter_base.text_formatter_base.vptr=multiplier_table;
    m1.times=3;
    printf("--- Multiplier CTOR: times = %d\n", m1.times);

    DefaultTextFormatter_ctor((DefaultTextFormatter*)&m2);
    m2.def_text_formatter_base.text_formatter_base.vptr=multiplier_table;
    m2.times=5;
    printf("--- Multiplier CTOR: times = %d\n", m2.times);

    DefaultTextFormatter_copy_ctor((DefaultTextFormatter*)&m3,(DefaultTextFormatter*)&m1);
    m3=m1;

    DefaultTextFormatter_copy_ctor((DefaultTextFormatter*)&m4,(DefaultTextFormatter*)&m2);
    m4.def_text_formatter_base.text_formatter_base.vptr=m2.def_text_formatter_base.text_formatter_base.vptr;
    m4.times=m2.times;

    m1.def_text_formatter_base.text_formatter_base.vptr[1](&m1,"abc ");
    m1.def_text_formatter_base.text_formatter_base.vptr[1](&m2,"abc ");
    m1.def_text_formatter_base.text_formatter_base.vptr[1](&m3,"abc ");
    m1.def_text_formatter_base.text_formatter_base.vptr[1](&m4,"abc ");


    printf("\n--- start doMultiplier() ---\n\n");
    Multiplier_dtor(&m4);
    Multiplier_dtor(&m3);
    Multiplier_dtor(&m2);
    Multiplier_dtor(&m1);
}

void doFormatterArray()
{
    PrePostDollarFixer d1;
    Multiplier m1;
    PrePostChecker c1;
    DefaultTextFormatter formatters[3];
    printf("\n--- start doFormatterArray() ---\n\n");

    PrePostDollarFixer_ctor(&d1,"!!! ", " !!!");
    DefaultTextFormatter_copy_ctor(&formatters[0],(DefaultTextFormatter*)&d1);
    PrePostDollarFixer_dtor(&d1);

    DefaultTextFormatter_ctor((DefaultTextFormatter*)&m1);
    m1.def_text_formatter_base.text_formatter_base.vptr=multiplier_table;
    m1.times=4;
    printf("--- Multiplier CTOR: times = %d\n", m1.times);
    DefaultTextFormatter_copy_ctor(&formatters[1],(DefaultTextFormatter*)&m1);
    Multiplier_dtor(&m1);

    PrePostChecker_ctor(&c1);
    DefaultTextFormatter_copy_ctor(&formatters[2],(DefaultTextFormatter*)&c1);
    PrePostChecker_dtor(&c1);

    for (int i = 0; i < 3; ++i)
    {
        DefaultTextFormatter_print(&formatters[i],"Hello World!");
    }

    printf("\n--- end doFormatterArray() ---\n\n");
    for (int j = 2; j >=0; j--) {
        DefaultTextFormatter_dtor(&formatters[j]);
    }
}

void doFormatterPtrs()
{
    DefaultTextFormatter* pfmt[3];
    printf("\n--- start doFormatterPtrs() ---\n\n");

    pfmt[0]=malloc(sizeof(PrePostDollarFixer));
    PrePostDollarFixer_ctor((PrePostDollarFixer*)pfmt[0],"!!! ", " !!!");

    pfmt[1]=malloc(sizeof(Multiplier));
    DefaultTextFormatter_ctor((DefaultTextFormatter*)pfmt[1]);
    ((Multiplier*)pfmt[1])->def_text_formatter_base.text_formatter_base.vptr=multiplier_table;
    ((Multiplier*)pfmt[1])->times=4;
    printf("--- Multiplier CTOR: times = %d\n", ((Multiplier*)pfmt[1])->times);

    pfmt[2]=malloc(sizeof(PrePostChecker));
    PrePostChecker_ctor((PrePostChecker*)pfmt[2]);

    for (int i = 0; i < 3; ++i)
    {
        pfmt[i]->text_formatter_base.vptr[1](pfmt[i],"Hello World!");
    }

    for (int i = 2; i >= 0; --i)
    {
        pfmt[i]->text_formatter_base.vptr[0](pfmt[i]);
        free(pfmt[i]);
    }

    printf("\n--- end doFormatterPtrs() ---\n\n");
}


void doFormatterDynamicArray()
{
    DefaultTextFormatter* formatters;
    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    formatters=generateFormatterArray();

    for (int i = 0; i < 3; ++i)
    {
        formatters[i].text_formatter_base.vptr[1](&formatters[i],"Hello World!");
    }

    for (int i = 2; i >=0; i--)
        formatters[i].text_formatter_base.vptr[0](&formatters[i]);

    free(formatters);

    printf("\n--- start doFormatterDynamicArray() ---\n\n");
}

int main()
{
    PrePostHashFixer hfix;
    PrePostDollarFixer hfix_copy;
    printf("\n--- Start main() ---\n\n");

    do_pre_post_fixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();

    PrePostHashFixer_ctor_int(&hfix,4);
    runAsPrePostFixerRef((PrePostFixer*)&hfix);
    runAsPrePostDollarFixerRef((PrePostDollarFixer*)&hfix);
    PrePostDollarFixer_copy_ctor(&hfix_copy,(PrePostDollarFixer*)&hfix);
    runAsPrePostDollarFixerObj(hfix_copy);
    PrePostDollarFixer_dtor(&hfix_copy);
    runAsPrePostHashFixerRef(&hfix);

    doMultiplier();

    doFormatterArray();

    doFormatterPtrs();

    doFormatterDynamicArray();


    printf("\n--- End main() ---\n\n");
    PrePostHashFixer_dtor(&hfix);

    return 0;
}

