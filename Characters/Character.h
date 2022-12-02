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
        candyCount = 5;
        kitCount = 3;
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
    virtual void updateState(float mXP) = 0;

    vector<string> getBag()
    {
        return bag;
    }
    void eatCandy()
    {
        health += 50;
        candyCount--;
        cout << "Ate candy... Health raised by 50!" << endl;
        cout << cCount() << "/5 Candies left" << endl;
        cout << endl;
        cout << endl;
    }
    void useHealthKit()
    {
        health += 100;
        kitCount--;
        cout << "Used Health Kit... Health raised by 100!" << endl;
        cout << kCount() << "/3 Health Kits left" << endl;
        cout << endl;
        cout << endl;
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