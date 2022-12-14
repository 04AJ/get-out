#ifndef MONSTER_H
#define MONSTER_H

#include "../Object.h"
#include "../Characters/Character.h"
#include "../Characters/Detective.h"

#include <string>
#include <iostream>

using namespace std;

class Monster : public Object
{
public:
    virtual void getsHit(Object *user) = 0;
    // if the Monster gets hit with special attack
    virtual void getsSpecial(Object *user) = 0;

    Monster()
    {
        health = 0.0;
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
    virtual string getName() = 0;
    void updateState();
    virtual void print() = 0;

protected:
    float health;
    int level;
};

#endif