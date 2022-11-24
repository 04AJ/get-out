#ifndef MONSTER_H
#define MONSTER_H

#include <string>
using namespace std;

class Monster
{
public:
    virtual void getsHit(string weapon);
    int getLvl();
    float getHealth();
    virtual string setName() = 0;
    virtual string getName() = 0;
    void updateState();

protected:
    float health;
    int level;
};

#endif