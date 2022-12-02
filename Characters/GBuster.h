#ifndef GBUSTER_H
#define GBUSTER_H

#include <iostream>

#include "Character.h"
#include <fstream>
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
        weapon = weapons[level - 1];
        cout << "Created new GhostBuster Character " << name << " with health: " << health << " and weapon: " << weapon << endl;
    }
    GBuster(string n, float h, float x, int l)

    {
        type = "GhostBuster";
        name = n;
        health = h;
        xp = x;
        setLvl(l);
        specialCount = 3;
        weapon = weapons[level - 1];
        cout << "Loaded GhostBuster Character " << name << " with health: " << health << " and weapon: " << weapon << endl;
    }
    void levelUp()
    {
        level++;
        cout << "YOU LEVELD UP!" << endl;
        cout << "Level: " << level << "--->  New Weapon: " << weapon << endl;
        weapon = weapons[level - 1];
    }
    string getWeapon()
    {
        return weapon;
    }
    void getsHit(Monster *enemy)
    {
        string mName = enemy->getName();
        cout << enemy->getName() << " attacked " << name << endl;
        if (mName == "Ghost")
        {
            health -= (8 * enemy->getLvl());
            cout << "Ghost attack is weak against GhostBusters" << endl;
        }
        else
        {
            health -= (10 * enemy->getLvl());
        }

        cout << name << " Health:" << health << endl;
        cout << endl;
        cout << endl;
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
        cout << endl;
        cout << endl;
    }

    void saveData(int x, int y, int floor)
    {
        string fileName = "users/" + name + ".txt";
        ofstream fout;
        fout.open(fileName);
        fout << type << endl;
        fout << health << endl;
        fout << xp << endl;
        fout << level << endl;
        fout << x << endl;
        fout << y << endl;
        fout << floor << endl;

        fout.close();
    }
    ~GBuster()
    {
        cout << "removed Detective obj" << endl;
    }

private:
    string weapons[6] = {"Ghost Trap", "Slime Blower", "Ghost Grabber", "Ghost Vacuum", "Ghost Tank", "Proton Pack"};
    string weapon;
};

#endif