#include "Civilization.h"
#include <iostream>
std::string getUnitType(const Unit& unit) {
    // We can identify the unit type by checking its transformation cost
    // since each unit type has a unique transformation cost
    if (unit.getTransformCost() == 30) {
        return "Pikemen";
    } else if (unit.getTransformCost() == 40) {
        return "Archer";
    } else {
        return "Cavalry";
    }
}

void testUnitTransformation(){
    std::cout << "--- UNIT TRANSFORMATION TEST ---" << std::endl;
    Chinese c1("Test Unit");
    // Get a unit from the Army
    Unit u = c1.getUnits()[0];

    std::string unitType = getUnitType(u);
    std::cout << "Unit before transformation: " << unitType << std::endl;
    u.transformUnit();
    unitType = getUnitType(u);
    std::cout << "Unit after transformation: " << unitType << std::endl;
}

void testUnitTraining() {
    std::cout << "--- UNIT TRAINING EXAMPLE ---" << std::endl;
    Chinese c1("Test Unit");
    // Get a unit from the Army
    Unit u = c1.getUnits()[27];

    std::string unitType = getUnitType(u);
    std::cout << "Unit type: " << unitType << std::endl;
    std::cout << "Unit strength before training: " << u.getStrength() << std::endl;
    u.trainUnit();
    std::cout << "Unit strength after training: " << u.getStrength() << std::endl;
}

void testArmyBattle() {
    std::cout << "--- ARMY BATTLE TEST ---" << std::endl;

    // Create two armies
    Chinese chineseArmy("Dragon Dynasty");
    Byzantine byzantineArmy("Eastern Empire");

    // Display initial army compositions
    std::cout << "\nInitial Army Compositions:" << std::endl;

    std::cout << "\nChinese Army (" << chineseArmy.getName() << "):" << std::endl;
    std::cout << "Total Strength: " << chineseArmy.getArmyStrength() << std::endl;
    std::cout << "Unit Composition:" << std::endl;

    int chinesePikemen = 0, chineseArchers = 0, chineseCavalry = 0;
    for (const Unit& unit : chineseArmy.getUnits()) {
        std::string type = getUnitType(unit);
        if (type == "Pikemen") chinesePikemen++;
        else if (type == "Archer") chineseArchers++;
        else chineseCavalry++;
    }

    std::cout << "Pikemen: " << chinesePikemen << std::endl;
    std::cout << "Archers: " << chineseArchers << std::endl;
    std::cout << "Cavalry: " << chineseCavalry << std::endl;

    std::cout << "\nByzantine Army (" << byzantineArmy.getName() << "):" << std::endl;
    std::cout << "Total Strength: " << byzantineArmy.getArmyStrength() << std::endl;
    std::cout << "Unit Composition:" << std::endl;

    int byzantinePikemen = 0, byzantineArchers = 0, byzantineCavalry = 0;
    for (const Unit& unit : byzantineArmy.getUnits()) {
        std::string type = getUnitType(unit);
        if (type == "Pikemen") byzantinePikemen++;
        else if (type == "Archer") byzantineArchers++;
        else byzantineCavalry++;
    }

    std::cout << "Pikemen: " << byzantinePikemen << std::endl;
    std::cout << "Archers: " << byzantineArchers << std::endl;
    std::cout << "Cavalry: " << byzantineCavalry << std::endl;

    // Initiate battle
    std::cout << "\nInitiating Battle..." << std::endl;
    chineseArmy.attack(byzantineArmy);

    // Display post-battle results
    std::cout << "\nPost-Battle Results:" << std::endl;

    std::cout << "\nChinese Army Remaining Strength: " << chineseArmy.getArmyStrength() << std::endl;
    std::cout << "Byzantine Army Remaining Strength: " << byzantineArmy.getArmyStrength() << std::endl;

    // Display remaining units
    int remainingChineseUnits = 0, remainingByzantineUnits = 0;
    for (const Unit& unit : chineseArmy.getUnits()) remainingChineseUnits++;
    for (const Unit& unit : byzantineArmy.getUnits()) remainingByzantineUnits++;

    std::cout << "\nRemaining Units:" << std::endl;
    std::cout << "Chinese Army: " << remainingChineseUnits << " units" << std::endl;
    std::cout << "Byzantine Army: " << remainingByzantineUnits << " units" << std::endl;
}

int main() {
    // We can test code here.
    testUnitTransformation();
    testUnitTraining();
    testArmyBattle();
    return 0;
}
