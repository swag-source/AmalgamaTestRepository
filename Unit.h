//
// Created by str8cho on 01/12/24.
//
#ifndef AMALGAMATEST_UNIT_H
#define AMALGAMATEST_UNIT_H
#include <string>

class Unit {
public:
    Unit(int strength, int trainingCost, int transformCost, int trainingStrength);

    int getStrength() const;

    int getTransformCost() const;

    int getTrainingCost() const;

    void trainUnit();

    void transformUnit();


private:
    int trainingCost;
    int transformCost;
    int trainingStrength;
    int strength;
};

class Pikemen : public Unit {
public:
    Pikemen() : Unit(5, 10, 30, 3) {}
};

class Cavalry : public Unit {
public:
    Cavalry() : Unit(20, 30, 1e9, 10) {}
};

class Archer : public Unit {
public:
    Archer() : Unit(10,20,40, 7) {}
};

#endif //AMALGAMATEST_UNIT_H
