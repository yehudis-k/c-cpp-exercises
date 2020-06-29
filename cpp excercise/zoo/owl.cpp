#include "owl.h"

const std::string Owl:: m_species="owl";
e_continent temp_cont1[] = {Antarctica,Australia, Asia,};
const std::vector<e_continent>Owl:: m_continent(temp_cont1, temp_cont1 + sizeof(temp_cont1)/sizeof(temp_cont1[0]));

e_food temp_food1[] = {vegetable,worms};
const std::vector<e_food>Owl:: m_foods(temp_food1, temp_food1+ sizeof(temp_food1)/sizeof(temp_food1[0]));