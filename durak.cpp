#include <iostream>


using namespace std;

//TODO  trump;

class Card
{
public:
    bool trump;
    string suit;
    string num;
};

class Bank {
    int used[36] = {0};
public:
    Card bank[36];

    void CreateBank() {
        int i = 0;
        string numbers[9] = {"6", "7", "8", "9", "10", "J", "Q", "K", "A"};
        string suits[4] = {"a", "b", "c", "d"};
        for (int n = 0; n < 9; i++)
            for (int s = 0; s < 4; s++) {
                bank[i].suit = suits[s];
                bank[i].num = numbers[n];
            }
    }

    Card TakeCard() {
        int n = rand() % 36;
        while (used[n] == 1)
            n = rand() % 36;
        used[n] = 1;
        return bank[n];
    }
};

class Player
{
    int i = 0;
public:
    Card hand[36];
    void FirstHand(Bank bank)
    {
        for(i = 0; i < 6; i++)
            hand[i] = bank.TakeCard();
    }

    void Collect(Bank bank)
    {
        hand[i++] = bank.TakeCard();
    }
};


class Desk {
    int newCard = 0; // первая свободная
public:
    Card desk[36];


public:
    void Go(Card card) {
        desk[newCard++] = card;
    }

    void Answer() {										//покрытие
        for (int i = 0; i < (desk.size()) / 2; ++i) {
            if ((suit == desk[2 * i] and num > desk[2 * i + 1]) or (suit == trump and desk[2 * i] != trump) or (suit == desk[2 * i] and suit == trump and num > desk[2 * i + 1])) {
                desk.push_back(card.suit);
                desk.push_back(card.num);
            }
            else {
                cout << "you can't move this card" << endl;
            }
        }
    }

};