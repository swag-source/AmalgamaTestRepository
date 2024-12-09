#ifndef AMALGAMATEST_ARMY_H
#define AMALGAMATEST_ARMY_H

#include "Unit.h"
#include <vector>
#include <tuple>

typedef enum {
    Winner,
    Loser,
    Draw
} result_t;

class Army {
public:
    // Constructors
    Army(int pikemen, int archery, int cavalry);

    // Battle operations
    void attack(Army &t);

    // Economy operations
    void addCoins(int n);
    void removeCoins(int n);
    bool trainUnit(Unit &u);
    bool transformUnit(Unit &u);

    // Getters (mark as const since they don't modify state)
    int getArmyStrength() const;
    int getCoins() const;
    Unit getStrongestUnit() const;
    const std::vector<Unit> &getUnits() const;


private:
    // Core data
    std::vector<Unit> units;
    std::vector<std::pair<Army, result_t>> history;
    int coins = 1000;

    // Helper methods for battle logic
    bool canAffordPayment(int cost) const;
    void addUnit(const Unit& unit);
    int getTotalArmyStrength() const;
    static void handleBattleWinner(Army& winner, Army& loser);
    static void removeStrongestUnits(Army& army, int count);
    void recordBattleResult(Army& enemy, result_t result);
};



#endif //AMALGAMATEST_ARMY_H