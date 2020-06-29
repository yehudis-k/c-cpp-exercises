
#include "c2c_encapsulation_defs.h"
const char* DEF_MSG= "The total volume held on the shelf is";
const char* message="The total volume held on the shelf is";

void Box_new_default(Box* const this )
{
    this->length=1;
    this->width=1;
    this->height=1;
    print_box(this);
}

void Box_new_dim(Box* const this , double dim)
{
    this->length=dim;
    this->width=dim;
    this->height=dim;
    print_box(this);
}

void Box_new(Box* const this , double l, double w, double h)
{
    this->length=l;
    this->width=w;
    this->height=h;
    print_box(this);
}

void Box_destruct(const Box* const this)
{
    printf("Box destructor, %f x %f x %f\n", this->width, this->height, this->length);
}

void operator_mult_eq(Box* const this, double mult)
{
    this->length*=mult;
    this->width*=mult;
    this->height*=mult;
}

void print_box(const Box* const this)
{
    printf("Box: %f x %f x %f\n", this->length, this->width, this->height);
}


void set_box(Shelf* const shelf,int index, const Box* const dims)
{
    Box tmp=*dims;
    shelf->boxes[index]=tmp;
}

double get_volume(const Shelf* const shelf)
{
    size_t i;
    double vol=0;
    for(i=0;i<NUM_BOXES;i++)
        vol+=(shelf->boxes[i].width*shelf->boxes[i].height*shelf->boxes[i].length);
    return vol;
}

void print_shelf(const Shelf* const shelf)
{
    printf("%s %f\n", message, get_volume(shelf));
}

void Shelf_destruct(const Shelf* const this)
{
    int i;
    for(i=NUM_BOXES-1;i>=0;i--)
        Box_destruct(&this->boxes[i]);
}