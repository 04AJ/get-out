#ifndef CHARACTER_H
#define CHARACTER_H

#include "../Object.h"
#include "../Monsters/Monster.h"
#include <string>
#include <vector>

using namespace std;

class Character : public Object
{

public:
    virtual void getsHit(Monster *enemy) = 0;
    Character()
    {
        name = "Unknown";
        health = 0.0;
        xp = 0.0;
        level = 1;
    }
    int getLvl()
    {
        return level;
    }
    float getHealth()
    {
        return health;
    }

    string getName()
    {
        return name;
    }
    void setName(string str)
    {
        name = str;
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

    virtual void special() = 0;

protected:
    float health;
    float xp;

    vector<string> bag;
};

#endif