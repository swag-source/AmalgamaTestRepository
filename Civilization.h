#ifndef AMALGAMATEST_CIVILIZATION_H
#define AMALGAMATEST_CIVILIZATION_H

#include "Army.h"


// Civilization-specific armies
class Chinese : public Army {
public:
    explicit Chinese(const std::string& Name) : Army(Name,2, 25, 2) {}
};

class Byzantine : public Army {
public:
    explicit Byzantine(const std::string& Name) : Army(Name, 10, 10, 10) {}
};

class English : public Army {
public:
    explicit English(const std::string& Name) : Army(Name, 10, 10, 10) {}
};


#endif //AMALGAMATEST_CIVILIZATION_H
