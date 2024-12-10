#ifndef AMALGAMATEST_ARMY_H
#define AMALGAMATEST_ARMY_H

#include "Unit.h"
#include <vector>
#include <string>

/**
 * Represents the possible outcomes of a battle
 */
enum result_t {
    Winner,
    Loser,
    Draw
};

/**
 * Represents an army that can engage in battles and manage units
 */
class Army {
public:
    Army(const std::string& id, int pikemen, int archery, int cavalry);

    // Battle operations
    void attack(Army& target);

    // Economy operations
    bool trainUnit(Unit& unit);
    bool transformUnit(Unit& unit);

    // Getters
    int getArmyStrength() const;
    int getCoins() const;
    Unit getStrongestUnit() const;
    const std::vector<Unit>& getUnits() const;
    std::string getName() const;
    const std::vector<std::pair<std::string, result_t>>& getHistory() const;

private:
    // Core data members
    std::string armyID;
    std::vector<Unit> units;
    std::vector<std::pair<std::string, result_t>> history;
    int coins{1000};

    // Helper methods for battle logic
    bool canAffordPayment(int cost) const;
    void addUnit(const Unit& unit);
    int getTotalArmyStrength() const;
    static void handleBattleWinner(Army& winner, Army& loser);
    static void removeStrongestUnits(Army& army, int count);
    void recordBattleResult(Army& enemy, result_t result);
    void addCoins(int amount);
    void removeCoins(int amount);
};

#endif //AMALGAMATEST_ARMY_H