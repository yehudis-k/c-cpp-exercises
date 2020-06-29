

#ifndef INC_06_UTH_C2C_INHERITANCE_DEFS_H
#define INC_06_UTH_C2C_INHERITANCE_DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include "c2c_encapsulation_defs.h"

typedef enum Types
{
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
}Types;

typedef struct Materials
{
    char a;

}Materials;


typedef struct Material_t
{
    Types material;
    Materials Base_materials;

}Material_t;


typedef struct PhysicalBox
{
    Box Base_box;
    Material_t material;

}PhysicalBox;

void PhysicalBox_new_ddd(PhysicalBox* const this, double l, double w, double h);
void PhysicalBox_new_dddt(PhysicalBox* const this,double l, double w, double h, Types t);
void PhysicalBox_new_t(PhysicalBox* const this,Types t);
void PhysicalBox_destruct(PhysicalBox* const this);
void print_physicalBox(const PhysicalBox* const this);

typedef struct WeightBox
{
    Box Base_box;
    double weight;

}WeightBox;

void WeightBox_new_ddd_w(WeightBox* const this,double l, double w, double h, double wgt);
void WeightBox_new_ddd(WeightBox* const this,double l, double w, double h);
void WeightBox_copy_ctor(WeightBox* const this,const WeightBox* other);
void WeightBox_destruct(WeightBox* const this);
void WeightBox_operator_eq(WeightBox* const this,const WeightBox* other);
void print_weightBox(WeightBox* const this);


#endif
