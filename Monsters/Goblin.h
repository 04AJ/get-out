#ifndef GOBLIN_H
#define GOBLIN_H

#include "Monster.h"

class Goblin : public Monster
{
public:
    Goblin(float h, int l)
    {
        health = h;
        level = l;
    }

    void getsHit(Object *user)
    {
        health -= (10 * user->getLvl());
        cout << user->getName() << " attacked " << name << endl;
        cout << name << " Health:" << health << endl;
        cout << endl;
        cout << endl;
    }
    void getsSpecial(Object *user)
    {
        if (user->getType() == "GhostBuster")
        {
            cout << "Ghost Buster special attack on Goblin. 1.2x more damage" << endl;
            health -= ((20 * user->getLvl()) * 1.2);
            cout << user->getName() << " attacked " << name << endl;
            cout << name << " Health:" << health << endl;
        }
        if (user->getType() == "Detective")
        {
            cout << "Detective special attack on Goblin. 2x more damage" << endl;
            health -= ((20 * user->getLvl()) * 2);
            cout << user->getName() << " attacked " << name << endl;
            cout << name << " Health:" << health << endl;
        }
        if (user->getType() == "VampireSlayer")
        {
            cout << "Vampire Slayer special attack on Goblin. 1.5x more damage" << endl;
            health -= ((20 * user->getLvl()) * 1.5);
            cout << user->getName() << " attacked " << name << endl;
            cout << name << " Health:" << health << endl;
        }
        cout << endl;
        cout << endl;
    }

    string getName()
    {
        return name;
    }
    void print()
    {
        cout << R"(
             ,      ,
            /(.-""-.)\
        |\  \/      \/  /|
        | \ / =.  .= \ / |
        \( \   o\/o   / )/
         \_, '-/  \-' ,_/
           /   \__/   \
           \ \__/\__/ /
         ___\ \|--|/ /___
       /`    \      /    `\
      /       '----'       \
        )" << endl;
    }
    ~Goblin();

private:
    string name = "Goblin";
};

#endif