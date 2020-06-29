#include "lion.h"

const std::string Lion:: m_species="lion";
e_continent temp_cont2[] = {Antarctica,Europe, Asia,};
const std::vector<e_continent>Lion:: m_continent(temp_cont2, temp_cont2 + sizeof(temp_cont2)/sizeof(temp_cont2[0]));

e_food temp_food2[] = {meat, vegetable};
const std::vector<e_food>Lion:: m_foods(temp_food2, temp_food2 + sizeof(temp_food2)/sizeof(temp_food2[0]));
