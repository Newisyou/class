#include <iostream>
#include <string>

using namespace std;

class Field {
public:
    Cell field[10][10];

    void attack(Cell cell) {
    }
};

class Cell {
public:
    int x;
    int y;
    string type; // занята ли клетка каким-либо кораблём
};

class ships{
    public:
    Cell ship1[1];
    Cell ship2[2];
    Cell ship3[3];
    cell ship4[4];
    void die(){

    }
}

class Player{
    public:
    void ship(){
        ships ships[10];
    };
}

class Game {
    void Shoot(Cell c) { ///функция, обрабатывающая выстрел
    }
};

