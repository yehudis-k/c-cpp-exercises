//
// Created by student on 14/06/2020.
//
#include "c2c_encapsulation_defs.h"
static Box largeBox;
static Box box99;
static Box box88;
extern char* DEF_MSG;
extern char* message;

void this_func()
{
    printf("\n--- thisFunc() ---\n\n");
    if(box99.width==0)
        Box_new(&box99,99,99,99);
    operator_mult_eq(&box99, 10);
}

void that_func()
{
    printf("\n--- thatFunc() ---\n\n");
    if(box88.width==0)
        Box_new(&box88,88, 88, 88);
    operator_mult_eq(&box88, 10);
}

void doBoxes()
{
    printf("\n--- Start doBoxes() ---\n\n");
    Box b1;
    Box_new_dim(&b1, 3);
    Box b2;//TODO put in beginning
    Box_new(&b2, 4, 5, 6);

    printf("b1 volume: %f\n", b1.height*b1.width*b1.length);
    printf("b2 volume: %f\n", b2.height*b2.width*b2.length);

    operator_mult_eq(&b1, 1.5);
    operator_mult_eq(&b2, 0.5);

    printf("b1 volume: %f\n", b1.height*b1.width*b1.length);
    printf("b2 volume: %f\n", b2.height*b2.width*b2.length);

    Box b3=b2;
    Box b4=b2;
    operator_mult_eq(&b4,3);
    printf("b3 %s b4\n", ((b3.height==b4.height)&&(b3.width==b4.width)&&(b3.length==b4.length)) ? "equals" : "does not equal");

    operator_mult_eq(&b3, 1.5);
    operator_mult_eq(&b4, 0.5);

    printf("Now, b3 %s b4\n", ((b3.height==b4.height)&&(b3.width==b4.width)&&(b3.length==b4.length)) ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");

    Box_destruct(&b4);
    Box_destruct(&b3);
    Box_destruct(&b2);
    Box_destruct(&b1);
}

void doShelves()
{
    printf("\n--- start doShelves() ---\n\n");

    Box aBox;
    Box_new_dim(&aBox,5);

    Shelf aShelf;
    Box b1,b2, b3;
    Box_new_default(&b1);
    Box_new_default(&b2);
    Box_new_default(&b3);
    aShelf.boxes[0]=b1;
    aShelf.boxes[1]=b2;
    aShelf.boxes[2]=b3;

    print_shelf(&aShelf);
    set_box(&aShelf,1,&largeBox);
    set_box(&aShelf,0,&aBox);

    print_shelf(&aShelf);
    message="This is the total volume on the shelf:";//doesn't change!!!
    print_shelf(&aShelf);
    message="Shelf's volume:";//same
    print_shelf(&aShelf);

    Box tmp;
    Box_new(&tmp, 2,4,6);
    set_box(&aShelf,1,&tmp);
    Box_destruct(&tmp);
    Box tmp2;
    Box_new_dim(&tmp2, 2);
    set_box(&aShelf,2,&tmp2);
    Box_destruct(&tmp2);
    print_shelf(&aShelf);

    printf("\n--- end doShelves() ---\n\n");
    Shelf_destruct(&aShelf);
    Box_destruct(&aBox);
}

int main()
{
    Box_new(&largeBox,10,20,30);
    printf("\n--- Start main() ---\n\n");

    doBoxes();

    this_func();
    this_func();
    this_func();
    that_func();
    that_func();

    doShelves();

    printf("\n--- End main() ---\n\n");
    Box_destruct(&box88);
    Box_destruct(&box99);
    Box_destruct(&largeBox);
    return 0;
}

//gcc c2c_encapsulation.c c2c_encapsulation_defs.c
