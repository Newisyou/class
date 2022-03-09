#include <iostream>

using namespace std;

class Domino
{
public:
    int half1;
    int half2;
};

class Bank
{
    int used[28] = {0};
public:
    Domino bank[28];

    void CreateBank() {
        int i = 0;
        for(int h = 0; h < 7; h++)
            for(int l = h; l < 7; l++, i++)
            {
                bank[i].half1 = h;
                bank[i].half2 = l;
            }
    }

    Domino TakeDomino() {
        int n = rand() % 28;
        while(used[n] == 1)
            n = rand() % 28;
        used[n] = 1;
        return bank[n];
    }
};

class Player
{
    int i = 0;
public:
    Domino hand[21];
    void FirstHand(Bank bank)
    {
        for(i = 0; i < 8; i++)
            hand[i] = bank.TakeDomino();
    }

    void Collect(Bank bank)
    {
        hand[i++] = bank.TakeDomino();
    }
};

class Field
{
public:
    int end1;
    int end2;

    void MakeFirstMove(Domino domino)
    {
        end1 = domino.half1;
        end2 = domino.half2;
    }

    void MakeMove(Domino domino)
    {
        if(end1 == domino.half1)
            end1 = domino.half2;
        else if(end1 == domino.half2)
            end1 = domino.half1;
        else if(end2 == domino.half1)
            end2 = domino.half2;
        else if(end2 == domino.half2)
            end2 = domino.half1;
        else
            cout << "You can't move!" << endl;
    }

};
