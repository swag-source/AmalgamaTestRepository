#include "Unit.h"

Unit::Unit(int strength, int trainingCost, int transformCost, int trainingStrength) {
    this->strength = strength;
    this->trainingCost = trainingCost;
    this->transformCost = transformCost;
    this->trainingStrength = trainingStrength;
}

int Unit::getStrength() const {
    return strength;
}

int Unit::getTransformCost() const {
    return transformCost;
}

int Unit::getTrainingCost() const {
    return trainingCost;
}

void Unit::trainUnit(){
    strength += trainingStrength;
}

// Performs an in-place unit transformation.
void Unit::transformUnit() {
    // Case Pikemen
    if(this->transformCost == 30){
        *this = Archer();
    } else if (this->transformCost == 40) {
        // Case Archer
        *this = Cavalry();
    }
    // We don't have a case for Cavalry
}