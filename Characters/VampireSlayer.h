#ifndef VAMPIRESLAYER_H
#define VAMPIRESLAYER_H

#include <iostream>
#include <fstream>
#include "Character.h"

using namespace std;

class VampireSlayer : public Character
{

public:
    VampireSlayer(string n)

    {
        type = "VampireSlayer";
        name = n;
        health = 100.0;
        xp = 0.0;
        specialCount = 3;
        weapon = weapons[level - 1];
        cout << "Created new VampireSlayer Character " << name << " with health: " << health << " and weapon: " << weapon << endl;
    }

    VampireSlayer(string n, float h, float x, int l)

    {
        type = "VampireSlayer";
        name = n;
        health = h;
        xp = x;
        setLvl(l);
        specialCount = 3;
        weapon = weapons[level - 1];
        cout << "Loaded VampireSlayer Character " << name << " with health: " << health << " and weapon: " << weapon << endl;
    }

    void levelUp()
    {
        level++;
        cout << "YOU LEVELD UP!" << endl;
        weapon = weapons[level - 1];
        cout << "Level: " << level << "--->  New Weapon: " << weapon << endl;
    }
    string getWeapon()
    {
        return weapon;
    }
    void getsHit(Monster *enemy)
    {
        string mName = enemy->getName();
        cout << enemy->getName() << " attacked " << name << endl;
        if (mName == "Vampire")
        {
            health -= (8 * enemy->getLvl());
            cout << "Vampire attack is weak against VampireSlayers" << endl;
        }
        else
        {
            health -= (10 * enemy->getLvl());
        }

        cout << name << " Health:" << health << endl;
        cout << endl;
        cout << endl;
    }
    // updates users xp and determines if they can level up
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
    void print()
    {
        cout << R"( 
                         /\
                         || 
                         ||
                         ||
                         ||           {}
                         ||          .--.
                         ||         /.--.\
                         ||         |====|
                         ||         |`::`|
                        _||_    .-;`\..../`;_.-^-._
                         /\\   /  |...::..|`   :   `|
                         |:'\ |   /'''::''|   .:.   |
                          \ /\;-,/\   ::  |..:::::..|
                           \ <` >  >._::_.| ':::::' |
                            `""`  /   ^^  |   ':'   |
                                  |       \    :    /
                                  |        \   :   /
                                  |___/\___|`-.:.-`
                                   \_ || _/    `
                                   <_ >< _>
                                   |  ||  |
                                   |  ||  |
                                  _\.:||:./_
                                 /____/\____\
         )"
             << endl;
    }
    ~VampireSlayer()
    {
        cout << "removed VampireSlayer obj" << endl;
    }

private:
    string weapons[6] = {"Mirror", "Garlic", "Brick", "Sunlight Blaster", "Flamethrower", "Silver Knife"};
    string weapon;
};

#endif