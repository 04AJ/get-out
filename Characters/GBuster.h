#ifndef GBUSTER_H
#define GBUSTER_H

#include <iostream>
#include "Character.h"

using namespace std;

class GBuster : public Character
{
public:
    GBuster(string n)

    {

        name = n;
        health = 100.0;
        xp = 0.0;
        cout << "Created new GhostBuster Character: " << name << " with health: " << health << " and weapon: " << weapon << endl;
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
    ~GBuster()
    {
        cout << "removed Detective obj" << endl;
    }

private:
    string weapons[6] = {"Ghost Trap", "Slime Blower", "Ghost Grabber", "Ghost Vacuum", "Ghost Tank", "Proton Pack"};
    string weapon = weapons[level - 1];
};

#endif