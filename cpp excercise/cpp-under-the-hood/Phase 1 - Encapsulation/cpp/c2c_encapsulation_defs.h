
#ifndef INC_06_UTH_C2C_ENCAPSULATION_DEFS_H
#define INC_06_UTH_C2C_ENCAPSULATION_DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NUM_BOXES 3



typedef struct Box {
    double length;
    double width;
    double height;
}Box;
void Box_new_default(Box* const this );
void Box_new_dim(Box* const this , double dim);
void Box_new(Box* const this , double l, double w, double h);
void Box_destruct(const Box* const this);
void operator_mult_eq(Box* const this, double mult);
void print_box(const Box* const this);


typedef struct Shelf {
    Box boxes[NUM_BOXES];
}Shelf;

void set_box(Shelf* const shelf,int index, const Box* const dims);
double get_volume(const Shelf* const shelf);
void print_shelf(const Shelf* const shelf);
void Shelf_destruct(const Shelf* const this);










/*double get_length(const Box* const this)
{
    return this->length;
}
double get_width(const Box* const this)
{
    return this->width;
}

double get_height(const Box* const this)
{
    return this->height;
}

double get_valume(const Box* const this)
{
    return (this->height*this->width*this->length);
}





Box operator_mult(const Box* const box, double mult)
{
    Box res;
    //Box_new(&res, get_length(&box), get_width(&box), get_height(&box));
    operator_eq(&res, box);
    operator_mult_eq(&res,mult);
    return res;
}

Box operator_mult_rev(double mult, const Box* const box)
{
    return operator_mult(box,mult);
}

bool operator_eq_eq(const Box* const b1, const Box* const b2)
{
    return ((get_height(b1)==get_height(b2))&&(get_width(b1)==get_width(b2))&&(get_length(b1)==get_length(b2)));
}

bool operator_not_eq(const Box* const b1, const Box* const b2)
{
    return !(operator_eq_eq(b1, b2));
}

void operator_eq(Box* const this, const Box* const box)
{
    this->length=get_length(box);
    this->width=get_width(box);
    this->height=get_height(box);
}*/

#endif
