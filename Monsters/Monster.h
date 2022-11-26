#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <iostream>
#include "../Characters/Character.h"
#include "../Characters/Ghostbuster.h"
using namespace std;

class Monster
{
public:
    // virtual void getsHit(Character *user) = 0;
    int getLvl()
    {
        return level;
    }
    float getHealth()
    {
        return health;
    }
    virtual string getName() = 0;
    void updateState();

protected:
    float health;
    int level;
};

#endif