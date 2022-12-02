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
        type = "GhostBuster";
        name = n;
        health = 100.0;
        xp = 0.0;
        specialCount = 3;
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
        cout << endl;
        cout << endl;
    }
    void special()
    {
        cout << "using special" << endl;
    }
    void updateState(float mXP)
    {
        xp += mXP;
        if (xp >= 300 && xp < 400)
            levelUp();
        else if (xp >= 600 && xp < 700)
            levelUp();
        else if (xp >= 900 && xp < 1000)
            levelUp();
        else if (xp >= 1200 && xp < 1300)
            levelUp();
        else if (xp >= 1500 && xp < 1600)
            levelUp();
        else if (xp >= 1800 && xp < 1900)
            levelUp();

        cout << "Total XP: " << xp << endl;
    }
    ~GBuster()
    {
        cout << "removed Detective obj" << endl;
    }

private:
    string weapons[6] = {"Ghost Trap", "Slime Blower", "Ghost Grabber", "Ghost Vacuum", "Ghost Tank", "Proton Pack"};
    string weapon = weapons[level - 1];
};

#endif