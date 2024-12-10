#include "Army.h"
#include <numeric>

// Constructor
Army::Army(const std::string& name, int pikemen, int archery, int cavalry){  // Initialize name using member initializer list
    this->armyID = name;
    for (int i = 0; i < pikemen; ++i) {
        addUnit(Pikemen());
    }

    for (int i = 0; i < archery; ++i) {
        addUnit(Archer());
    }

    for (int i = 0; i < cavalry; ++i) {
        addUnit(Cavalry());
    }
}

// Helper methods
bool Army::canAffordPayment(int cost) const {
    return coins >= cost;
}

void Army::addUnit(const Unit& unit) {
    units.push_back(unit);
}

int Army::getTotalArmyStrength() const {
    int res = 0;
    for (auto unit: units) {
        res += unit.getStrength();
    }
    return res;
}

void Army::handleBattleWinner(Army& winner, Army& loser) {
    winner.addCoins(100);
    removeStrongestUnits(loser, 2);
}

void Army::removeStrongestUnits(Army& army, int count) {
    for(int i = 0; i < count && !army.units.empty(); ++i) {
        auto strongestIt = std::max_element(army.units.begin(), army.units.end(),
                                            [](const Unit& a, const Unit& b) {
                                                return a.getStrength() < b.getStrength();
                                            });

        if (strongestIt != army.units.end()) {
            army.units.erase(strongestIt);
        }
    }
}

void Army::recordBattleResult(Army& enemy, result_t result) {
    this->history.emplace_back(enemy.getName(), result);
    enemy.history.emplace_back(this->getName(),
                               result == Winner ? Loser : result == Loser ? Winner : Draw);
}

// Methods
void Army::attack(Army &t) {
    int battleResult = this->getTotalArmyStrength() - t.getTotalArmyStrength();

    if(battleResult > 0) {
        handleBattleWinner(*this, t);
        recordBattleResult(t, Winner);
    }
    else if(battleResult < 0) {
        handleBattleWinner(t, *this);
        recordBattleResult(t, Loser);
    }
    else {
        removeStrongestUnits(*this, 1);
        removeStrongestUnits(t, 1);
        recordBattleResult(t, Draw);
    }
}

void Army::addCoins(int n) {
    coins += n;
}

void Army::removeCoins(int n) {
    coins -= n;
}

bool Army::trainUnit(Unit &u) {
    int trainingCost = u.getTrainingCost();
    if(!canAffordPayment(trainingCost))
        return false;

    removeCoins(trainingCost);
    u.trainUnit();
    return true;
}

bool Army::transformUnit(Unit &u) {
    if(!canAffordPayment(u.getTransformCost()))
        return false;

    removeCoins(u.getTransformCost());
    u.transformUnit();
    return true;
}

// Getters
int Army::getArmyStrength() const {
    return getTotalArmyStrength();
}

Unit Army::getStrongestUnit() const {
    if (units.empty()) {
        return {0, 0, 0, 0};
    }

    return *std::max_element(units.begin(), units.end(),
                             [](const Unit& a, const Unit& b) {
                                 return a.getStrength() < b.getStrength();
                             });
}

int Army::getCoins() const {
    return coins;
}

const std::vector<Unit> &Army::getUnits() const {
    return units;
}

std::string Army::getName() const {
    return armyID;
}

const std::vector<std::pair<std::string, result_t>> &Army::getHistory() const {
    return history;
}



