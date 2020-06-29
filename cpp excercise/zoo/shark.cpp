#include "shark.h"

const std::string Shark:: m_species="Shark";
e_continent temp_cont[] = {Antarctica,Europe, Asia,};
const std::vector<e_continent>Shark:: m_continent(temp_cont, temp_cont + sizeof(temp_cont)/sizeof(temp_cont[0]));

e_food temp_food[] = {meat, vegetable};
const std::vector<e_food>Shark:: m_foods(temp_food, temp_food + sizeof(temp_food)/sizeof(temp_food[0]));


