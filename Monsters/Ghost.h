#ifndef GHOST_H
#define GHOST_H
#include "Monster.h"
#include "../Characters/Character.h"
#include "../Characters/Detective.h"

class Ghost : public Monster
{
public:
    Ghost(float h, int l)
    {
        health = h;
        level = l;
        cout << "Created Ghost obj" << endl;
    }

    // void getsHit(Character *user)
    // {
    //     health -= (10 * user->getLvl());
    //     cout << user->getName() << " attacked " << name << " with the " << user->getWeapon() << endl;
    //     cout << name << " Health:" << health << endl;
    // }

    // void test(Character *user)
    // {
    //     cout << user->getName() << endl;
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