#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Monster.h"

class Vampire : public Monster
{
public:
    Vampire(float h, int l)
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
            cout << "Ghost Buster special attack on Vampire. 1.5x more damage" << endl;
            health -= ((20 * user->getLvl()) * 1.5);
            cout << user->getName() << " attacked " << name << endl;
            cout << name << " Health:" << health << endl;
        }
        if (user->getType() == "Detective")
        {
            cout << "Detective special attack on Vampire. 1.2x more damage" << endl;
            health -= ((20 * user->getLvl()) * 1.2);
            cout << user->getName() << " attacked " << name << endl;
            cout << name << " Health:" << health << endl;
        }
        if (user->getType() == "VampireSlayer")
        {
            cout << "Vampire Slayer special attack on Vampire. 2x more damage" << endl;
            health -= ((20 * user->getLvl()) * 2);
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
               __.......__
            .-:::::::::::::-.
          .:::''':::::::''':::.
        .:::'     `:::'     `:::. 
   .'\  ::'   ^^^  `:'  ^^^   '::  /`.
  :   \ ::   _.__       __._   :: /   ;
 :     \`: .' ___\     /___ `. :'/     ; 
:       /\   (_|_)\   /(_|_)   /\       ;
:      / .\   __.' ) ( `.__   /. \      ;
:      \ (        {   }        ) /      ; 
 :      `-(     .  ^"^  .     )-'      ;
  `.       \  .'<`-._.-'>'.  /       .'
    `.      \    \;`.';/    /      .'
      `._    `-._       _.-'    _.'
       .'`-.__ .'`-._.-'`. __.-'`.
     .'       `.         .'       `.
   .'           `-.   .-'           `.
        )" << endl;
    }
    ~Vampire();

private:
    string name = "Vampire";
};

#endif