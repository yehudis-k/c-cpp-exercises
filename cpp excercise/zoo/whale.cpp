#include "whale.h"

const std::string Whale:: m_species="whale";
e_continent temp_cont3[] = {Antarctica,Europe};
const std::vector<e_continent>Whale:: m_continent(temp_cont3, temp_cont3 + sizeof(temp_cont3)/sizeof(temp_cont3[0]));

e_food temp_food3[] = {vegetable};
const std::vector<e_food>Whale:: m_foods(temp_food3, temp_food3 + sizeof(temp_food3)/sizeof(temp_food3[0]));