

#include "c2c_inheritance_defs.h"

void PhysicalBox_new_ddd(PhysicalBox* const this, double l, double w, double h)
{
    Box_new((Box*)this, l,w,h);
    this->material.material=OTHER;
    printf("Material created, set to %s\n", "Other");
    print_physicalBox(this);
}

void PhysicalBox_new_dddt(PhysicalBox* const this,double l, double w, double h, Types t)
{
    Box_new((Box*)this, l,w,h);
    this->material.material=t;
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("Material created, set to %s\n", names[this->material.material]);
    print_physicalBox(this);
}

void PhysicalBox_new_t(PhysicalBox* const this,Types t)
{
    Box_new_default((Box*)this);
    this->material.material=t;
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("Material created, set to %s\n", names[this->material.material]);
    print_physicalBox(this);
}

void PhysicalBox_destruct(PhysicalBox* const this)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("PhysicalBox dtor, %f x %f x %f, %s; ", this->Base_box.length, this->Base_box.width, this->Base_box.height, names[this->material.material]);
    Box_destruct((Box*)this);
}

void print_physicalBox(const PhysicalBox* const this)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("PhysicalBox, made of %s; ", names[this->material.material]);
    print_box((Box*)this);
}

void WeightBox_new_ddd_w(WeightBox* const this,double l, double w, double h, double wgt)
{
    Box_new((Box*)this,l,w,h);
    this->weight=wgt;
    print_weightBox(this);
}

void WeightBox_new_ddd(WeightBox* const this,double l, double w, double h)
{
    Box_new((Box*)this,l,w,h);
    this->weight=0.0;
    print_weightBox(this);
}
void WeightBox_copy_ctor(WeightBox* const this,const WeightBox* other)
{
    this->weight=other->weight;
    Box_new_default((Box*)this);
    print_weightBox(this);
}
void WeightBox_destruct(WeightBox* const this)
{
    printf("Destructing WeightBox; ");
    print_weightBox(this);
    Box_destruct((Box*)this);
}
void WeightBox_operator_eq(WeightBox* const this,const WeightBox* other)
{
    this->weight=other->weight;
}
void print_weightBox(WeightBox* const this)
{
    printf("WeightBox, weight: %f; ", this->weight);
    print_box((Box*)this);
}
