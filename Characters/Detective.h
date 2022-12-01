#ifndef DETECTIVE_H
#define DETECTIVE_H

#include <iostream>
#include "Character.h"

using namespace std;

class Detective : public Character
{
public:
    Detective(string n)

    {

        name = n;
        health = 100.0;
        xp = 0.0;
        cout << "Created new Detective Character: " << name << " with health: " << health << " and weapon: " << weapon << endl;
    }
    void levelUp()
    {
        level++;
    }
    string getWeapon()
    {
        return weapon;
    }
    void getsHit(Monster *enemy)
    {
        health -= (10 * enemy->getLvl());
        cout << enemy->getName() << " attacked " << name << endl;
        cout << name << " Health:" << health << endl;
    }
    void special()
    {
        cout << "using special" << endl;
    }
    // void addXp(int xp)
    // {
    //     this->xp += (xp + 10);
    // }
    ~Detective()
    {
        cout << "removed Detective obj" << endl;
    }

private:
    string weapons[6] = {"Pistol", "Grenade", "Bayonets", "Machine Gun", "Tank", "Nuke"};
    string weapon = weapons[level - 1];
};

#endif