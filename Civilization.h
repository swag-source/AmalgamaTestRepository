//
// Created by str8cho on 08/12/24.
//

#ifndef AMALGAMATEST_CIVILIZATION_H
#define AMALGAMATEST_CIVILIZATION_H

#include "Army.h"


// Civilization-specific armies
class Chinese : public Army {
public:
    Chinese() : Army(2, 25, 2) {}
};

class Byzantine : public Army {
public:
    Byzantine() : Army(10, 10, 10) {}
};

class English : public Army {
public:
    English() : Army(10, 10, 10) {}
};


#endif //AMALGAMATEST_CIVILIZATION_H
