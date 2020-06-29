


#include "c2c_inheritance_defs.h"

void doMaterials()
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    Materials mat;
    Material_t mat1;
    Material_t mat2;

    printf("\n--- Start doMaterials() ---\n\n");


    printf("Size of Materials: %lu\n", sizeof(Materials));
    printf("Size of mat: %lu\n", sizeof(mat));
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));

    struct MatTest { Materials mat; Material_t mat_t; }MatTest;
    printf("Size of Materials + Material_t: %lu\n", sizeof(MatTest.mat_t)+sizeof(MatTest.mat_t));


    mat1.material=OTHER;
    printf("Material created, set to %s\n", names[mat1.material]);


    mat2.material=METAL;
    printf("Material created, set to %s\n", names[mat2.material]);

    printf("\n--- End doMaterials() ---\n\n");
}

void doPhysicalBox()
{
    PhysicalBox pb1;
    PhysicalBox pb2;
    PhysicalBox pb3;
    PhysicalBox pb4;
    printf("\n--- Start doPhysicalBox() ---\n\n");

    PhysicalBox_new_dddt(&pb1,8,6,4,PLASTIC);
    PhysicalBox_new_t(&pb2,WOOD);
    PhysicalBox_new_ddd(&pb3,7,7,7);

    printf("\npb4 is copy-constructed from pb1\n");
    pb4=pb1;
    print_physicalBox(&pb4);
    print_physicalBox(&pb1);
    printf("pb4 %s pb1\n", ((pb4.Base_box.length==pb1.Base_box.length)&&(pb4.Base_box.height==pb1.Base_box.height)
    &&(pb4.Base_box.width==pb1.Base_box.width)&&(pb4.material.material==pb1.material.material))? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    pb4 = pb3;
    print_physicalBox(&pb4);
    print_physicalBox(&pb3);
    printf("pb4 %s pb3\n", ((pb4.Base_box.length==pb3.Base_box.length)&&(pb4.Base_box.height==pb3.Base_box.height)
                            &&(pb4.Base_box.width==pb3.Base_box.width)&&(pb4.material.material==pb3.material.material)) ? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");
    PhysicalBox_destruct(&pb4);
    PhysicalBox_destruct(&pb3);
    PhysicalBox_destruct(&pb2);
    PhysicalBox_destruct(&pb1);
}

void doWeightBox()
{
    WeightBox pw1;
    WeightBox pw2;
    WeightBox pw3;
    WeightBox pw4;
    printf("\n--- Start doWeightBox() ---\n\n");

    WeightBox_new_ddd_w(&pw1,8,6,4,25);
    WeightBox_new_ddd(&pw2,1,2,3);
    WeightBox_new_ddd_w(&pw3,10, 20, 30, 15);

    printf("\npw4 is copy-constructed from pw1\n");
    WeightBox_copy_ctor(&pw4,&pw1);
    print_weightBox(&pw4);
    print_weightBox(&pw1);
    printf("pw4 %s pw1\n", ((pw4.Base_box.width==pw1.Base_box.width)&&(pw4.Base_box.height==pw1.Base_box.height)
    &&(pw4.Base_box.length==pw1.Base_box.length)&&(pw4.weight==pw1.weight)) ? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    WeightBox_operator_eq(&pw4, &pw3);
    print_weightBox(&pw4);
    print_weightBox(&pw3);
    printf("pw4 %s pw3\n", ((pw4.Base_box.width==pw3.Base_box.width)&&(pw4.Base_box.height==pw3.Base_box.height)
                            &&(pw4.Base_box.length==pw3.Base_box.length)&&(pw4.weight==pw3.weight)) ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");
    WeightBox_destruct(&pw4);
    WeightBox_destruct(&pw3);
    WeightBox_destruct(&pw2);
    WeightBox_destruct(&pw1);
}

int main() {
    printf("\n--- Start main() ---\n\n");

    doMaterials();

    doPhysicalBox();

    doWeightBox();

    printf("\n--- End main() ---\n\n");
    return 0;
}


