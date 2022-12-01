#ifndef GHOST_H
#define GHOST_H

#include "Monster.h"

class Ghost : public Monster
{
public:
    Ghost(float h, int l)
    {
        health = h;
        level = l;
        cout << "Created Ghost obj" << endl;
    }

    void getsHit(Object *user)
    {
        health -= (20 * user->getLvl());
        cout << user->getName() << " attacked " << name << endl;
        cout << name << " Health:" << health << endl;
    }

    string getName()
    {
        return name;
    }
    ~Ghost();

private:
    string name = "Ghost";
};

#endif