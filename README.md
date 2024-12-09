# AmalgamaTestRepository

## Ejércitos
Los ejércitos poseen una cantidad inicial de piqueros, arqueros y caballeros
dependiendo
de la civilización. Pueden coexistir muchos ejércitos de la misma civilización.
También poseen 1000 monedas de oro al momento de la creación.
Cada ejército posee un historial de todas las batallas en las que participó.

## Unidades
A cada unidad le puedo pedir los años de vida de la misma.
Hay tres tipos de unidades:
* **Piquero**
* **Arquero**
* **Caballero**

Cada unidad posee puntos de fuerza, según la siguiente tabla:
| Unidad    | Puntos aportados |
| --------- | ---------------- |
| Piquero   | 5                |
| Arquero   | 10               |
| Caballero | 20               |

La cantidad inicial de unidades es determinada por la siguiente tabla:
| Civilizacion | Piqueros | Arqueros | Caballeros |
| ------------ | -------- | -------- | ---------- |
| Chinos       | 2        | 25       | 2          |
| Ingleses     | 10       | 10       | 10         |
| Bizantinos   | 5        | 8        | 15         |


## Entrenamiento
Cada unidad se puede entrenar, esto tiene un costo en monedas de oro y un
beneficio en puntos
de fuerza que se le suman a la unidad, según la siguiente tabla:

| Unidad    | Puntos obtenidos | Costo del entrenamiento |
| --------- | ---------------- | ----------------------- |
| Piquero   | 3                | 10                      |
| Arquero   | 7                | 20                      |
| Caballero | 10               | 30                      |


## Transformación
Cada unidad puede entrenar, a un costo, para convertirse en otra, según la
siguiente tabla:

| Unidad original | Unidad a la que se convierte | Costo de la transformación |
| --------------- | ---------------------------- | ----------------------- |
| Piquero         | Arquero                      | 30                      |
| Arquero         | Caballero                    | 40                      |
| Caballero       | No se puede transformar      | -                       |


## Batallas
Batallas
Un ejército puede atacar a otro en cualquier momento, incluso si son de la misma
civilización. Al hacerlo el ganador de la batalla es simplemente el ejército que tiene más puntos.
Las consecuencias de la batalla son las siguientes:
* **Ejército perdedor**: Pierde las dos unidades con mayor puntaje.
* **Ejército ganador**: Obtiene 100 unidades de oro.
* **En caso de empate**: Ambos jugadores pierden alguna unidad (queda a criterio del programador)

## UML Class Diagram

```mermaid
%%{init: {'theme': 'light', 'themeVariables': { 'lineColor': '#000000' }}}%%
classDiagram
    direction LR
    Army <|-- Chinese
    Army <|-- Byzantine
    Army <|-- English
    Army "1" *-- "*" Unit
    Army o-- result_t
    Unit <|-- Pikemen
    Unit <|-- Cavalry
    Unit <|-- Archer

    class Army {
        -string armyID
        -vector~Unit~ units
        -vector~pair~string,result_t~~ history
        -int coins
        +Army(string id, int pikemen, int archery, int cavalry)
        +attack(Army& target) void
        +trainUnit(Unit& unit) bool
        +transformUnit(Unit& unit) bool
        +getArmyStrength() int
        +getCoins() int
        +getStrongestUnit() Unit
        +getUnits() vector~Unit~
        +getName() string
        +getHistory() vector~pair~string,result_t~~
        -canAffordPayment(int cost) bool
        -addUnit(Unit& unit) void
        -getTotalArmyStrength() int
        -handleBattleWinner(Army& winner, Army& loser) void
        -removeStrongestUnits(Army& army, int count) void
        -recordBattleResult(Army& enemy, result_t result) void
        -addCoins(int amount) void
        -removeCoins(int amount) void
    }

    class Unit {
        -int trainingCost
        -int transformCost
        -int trainingStrength
        -int strength
        +Unit(int strength, int trainingCost, int transformCost, int trainingStrength)
        +getStrength() int
        +getTransformCost() int
        +getTrainingCost() int
        +trainUnit() void
        +transformUnit() void
    }

    class Pikemen {
        +Pikemen()
    }

    class Cavalry {
        +Cavalry()
    }

    class Archer {
        +Archer()
    }

    class Chinese {
        +Chinese(string Name)
    }

    class Byzantine {
        +Byzantine(string Name)
    }

    class English {
        +English(string Name)
    }

    class result_t {
        <<enumeration>>
        Winner
        Loser
        Draw
    }
