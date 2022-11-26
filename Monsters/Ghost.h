#ifndef GHOST_H
#define GHOST_H
#include "Monster.h"
#include "../Characters/Character.h"
#include "../Characters/Ghostbuster.h"

class Ghost : public Monster
{
public:
    Ghost(float h, int l)
    {
        health = h;
        level = l;
    }

    // void getsHit(Character *user)
    // {
    //     health -= (10 * user->getLvl());
    //     cout << user->getName() << " attacked " << name << " with the " << user->getWeapon() << endl;
    //     cout << name << " Health:" << health << endl;
    // }
    string getName()
    {
        return name;
    }
    ~Ghost();

private:
    string name = "Ghost";
};

#endif