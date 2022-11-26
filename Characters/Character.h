#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "../Monsters/Monster.h"
#include "../Monsters/Ghost.h"
using namespace std;

class Character
{

public:
    virtual void getsHit(Monster *enemy) = 0;
    int getLvl()
    {
        return level;
    };
    float getHealth()
    {
        return health;
    };
    string getName()
    {
        return name;
    }
    virtual string getWeapon() = 0;
    void saveData();
    void loadData();
    void updateState();
    virtual void addXp(int xp)
    {
        this->xp += xp;
    }
    vector<string> getBag()
    {
        return bag;
    }
    void openChest();
    void eatCandy()
    {
        health += 5;
    }
    void useHealthKit()
    {
        health += 10;
    }
    void skipDuel()
    {
        health /= 2.0;
        cout << "Skipped Duel" << endl;
        cout << "Health: " << health << endl;
    }
    // virtual int attack(Monster *enemy)
    // {
    //     cout << name << " attacked!" << endl;
    // }
    virtual void special() = 0;

protected:
    string name;
    float health;
    float xp;
    int level;
    vector<string> bag;
};

#endif