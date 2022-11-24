#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
using namespace std;

class Character
{

public:
    virtual void getsHit(string monster);
    int getLvl();
    float getHealth();
    virtual string getName() = 0;
    void saveData();
    void loadData();
    void updateState();
    virtual void addXp(int xp);
    vector<string> getBag();
    void openChest();
    float eatCandy();
    float useHealthKit();
    virtual int attack();
    virtual void special() = 0;

protected:
    string name;
    float health;
    int level;
    vector<string> bag;
};

#endif