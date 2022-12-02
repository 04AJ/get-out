#ifndef GAME_H
#define GAME_H

#include "Object.h"
#include "Characters/Character.h"

#include "Monsters/Monster.h"
#include "Monsters/Ghost.h"
#include "Monsters/Goblin.h"
#include "Monsters/Vampire.h"

#include "Floor.h"
#include <iostream>
#include <fstream>
using namespace std;

class Game
{
public:
  static int openingMenu()
  {
    // opening menu
    cout << R"(
                ('-.    .-') _                                     .-') _    
              _(  OO)  (  OO) )                                   (  OO) )   
  ,----.     (,------. /     '._         .-'),-----.  ,--. ,--.   /     '._  
 '  .-./-')   |  .---' |'--...__)       ( OO'  .-.  ' |  | |  |   |'--...__) 
 |  |_( O- )  |  |     '--.  .--'       /   |  | |  | |  | | .-') '--.  .--' 
 |  | .--, \ (|  '--.     |  |          \_) |  |\|  | |  |_|( OO )   |  |    
(|  | '. (_/  |  .--'     |  |            \ |  | |  | |  | | `-' /   |  |    
 |  '--'  |   |  `---.    |  |             `'  '-'  '('  '-'(_.-'    |  |    
  `------'    `------'    `--'               `-----'   `-----'       `--'    
)" << endl;
    cout << "1: Create new character    2: Load character from file" << endl;
    int load = 0;
    cin >> load;

    return load;
  }

  static int characterOptions()
  {

    cout << "Option 1: Ghostbuster" << endl;
    cout << R"(                       ---                                     
                    -        --                             
                --( /     \ )XXXXXXXXXXXXX                   
            --XXX(   O   O  )XXXXXXXXXXXXXXX-              
           /XXX(       U     )        XXXXXXX\               
         /XXXXX(              )--   XXXXXXXXXXX\            
        /XXXXX/ (      O     )   XXXXXX   \XXXXX\
        XXXXX/   /            XXXXXX   \   \XXXXX----        
        XXXXXX  /          XXXXXX         \  ----  -         
---     XXX  /          XXXXXX      \           ---        
  --  --  /      /\  XXXXXX            /     ---=         
    -        /    XXXXXX              '--- XXXXXX         
      --\/XXX\ XXXXXX                      /XXXXX         
        \XXXXXXXXX                        /XXXXX/
         \XXXXXX                         /XXXXX/         
           \XXXXX--  /                -- XXXX/       
            --XXXXXXX---------------  XXXXX--         
               \XXXXXXXXXXXXXXXXXXXXXXXX-            
                 --XXXXXXXXXXXXXXXXXX-)"
         << endl;
    cout << "Option 2: Detective" << endl;
    cout << R"(
                             /^\/^\
                             \----|
                         _---'---~~~~-_
                          ~~~|~~L~|~~~~
                             (/_  /~~--
                           \~ \  /  /~
                         __~\  ~ /   ~~----,
                         \    | |       /  \
                         /|   |/       |    |
                         | | | o  o     /~   |
                       _-~_  |        ||  \  /
                      (// )) | o  o    \\---'
                      //_- |  |          \
                     //   |____|\______\__\
                     ~      |   / |    |
                             |_ /   \ _|
                           /~___|  /____\           )"
         << endl;
    cout << "Option 3: Vampire Slayer" << endl;
    cout << R"( 
                         /\
                         || 
                         ||
                         ||
                         ||           {}
                         ||          .--.
                         ||         /.--.\
                         ||         |====|
                         ||         |`::`|
                        _||_    .-;`\..../`;_.-^-._
                         /\\   /  |...::..|`   :   `|
                         |:'\ |   /'''::''|   .:.   |
                          \ /\;-,/\   ::  |..:::::..|
                           \ <` >  >._::_.| ':::::' |
                            `""`  /   ^^  |   ':'   |
                                  |       \    :    /
                                  |        \   :   /
                                  |___/\___|`-.:.-`
                                   \_ || _/    `
                                   <_ >< _>
                                   |  ||  |
                                   |  ||  |
                                  _\.:||:./_
                                 /____/\____\
         )"
         << endl;
    cout << "Enter 1,2, or 3 to select your character type:" << endl;
    int charType = 0;
    cin >> charType;

    return charType;
  }

  // creates new menu for fighting and increases or decreases user character xp/level
  static bool duel(Character *user, Monster *enemy)
  {
    bool endDuel = false;
    while (!endDuel)
    {
      cout << "[" << user->getName() << "(You) | Level: " << user->getLvl() << " | Health: " << user->getHealth() << " | Weapon: " << user->getWeapon() << "] VS [" << enemy->getName() << " | Level: " << enemy->getLvl() << " | Health: " << enemy->getHealth() << "]" << endl;
      cout << "1. Attack monster    2. Use Special Attack    3. Use Health Kit    4. Eat Candy" << endl;
      int choice = 0;
      cin >> choice;

      if (choice == 1)
      {
        cout << R"(      
  _    _                       _   _             _              
 | |  | |                     | | | |           | |             
 | |  | |___  ___ _ __    __ _| |_| |_ __ _  ___| | _____       
 | |  | / __|/ _ \ '__|  / _` | __| __/ _` |/ __| |/ / __|      
 | |__| \__ \  __/ |    | (_| | |_| || (_| | (__|   <\__ \_ _ _ 
  \____/|___/\___|_|     \__,_|\__|\__\__,_|\___|_|\_\___(_|_|_)
        )" << endl;
        enemy->getsHit(user);

        cout << "[" << user->getName() << "(You) | Level: " << user->getLvl() << " | Health: " << user->getHealth() << "] VS [" << enemy->getName() << " | Level: " << enemy->getLvl() << " | Health: " << enemy->getHealth() << "]" << endl;
      }
      else if (choice == 2)
      {
        if (user->sCount() == 0)
        {
          cout << "No more special attacks available" << endl;
          cout << endl;
          cout << endl;
          continue;
        }
        else
        {
          cout << R"(      
   _____                 _       _         _   _             _          
  / ____|               (_)     | |       | | | |           | |         
 | (___  _ __   ___  ___ _  __ _| |   __ _| |_| |_ __ _  ___| | __      
  \___ \| '_ \ / _ \/ __| |/ _` | |  / _` | __| __/ _` |/ __| |/ /      
  ____) | |_) |  __/ (__| | (_| | | | (_| | |_| || (_| | (__|   < _ _ _ 
 |_____/| .__/ \___|\___|_|\__,_|_|  \__,_|\__|\__\__,_|\___|_|\_(_|_|_)
        | |                                                             
        |_|                                                             
          )" << endl;
          enemy->getsSpecial(user);
          user->dropSpecial();
        }
      }

      else if (choice == 3)
      {
        if (user->kCount() > 0)
        {
          user->useHealthKit();
          cout << "[" << user->getName() << "(You) | Level: " << user->getLvl() << " | Health: " << user->getHealth() << " | Weapon: " << user->getWeapon() << "] VS [" << enemy->getName() << " | Level: " << enemy->getLvl() << " | Health: " << enemy->getHealth() << "]" << endl;
        }
        else
        {
          cout << "No more Health Kits available" << endl;
          cout << endl;
          cout << endl;
          continue;
        }
      }
      else if (choice == 4)
      {
        if (user->cCount() > 0)
        {
          user->eatCandy();
          cout << "[" << user->getName() << "(You) | Level: " << user->getLvl() << " | Health: " << user->getHealth() << " | Weapon: " << user->getWeapon() << "] VS [" << enemy->getName() << " | Level: " << enemy->getLvl() << " | Health: " << enemy->getHealth() << "]" << endl;
        }
        else
        {
          cout << "No more Candy available" << endl;
          cout << endl;
          cout << endl;

          continue;
        }
      }

      if (enemy->getHealth() <= 0.0)
      {
        endDuel = true;
        return false;
      }

      char enter;
      cout << "Enter 'm' to for the monster's attack" << endl;
      cin >> enter;
      if (enter == 'm')
      {

        // Monster attacks
        cout << R"(
  __  __                 _                    _   _             _              
 |  \/  |               | |                  | | | |           | |             
 | \  / | ___  _ __  ___| |_ ___ _ __    __ _| |_| |_ __ _  ___| | _____       
 | |\/| |/ _ \| '_ \/ __| __/ _ \ '__|  / _` | __| __/ _` |/ __| |/ / __|      
 | |  | | (_) | | | \__ \ ||  __/ |    | (_| | |_| || (_| | (__|   <\__ \_ _ _ 
 |_|  |_|\___/|_| |_|___/\__\___|_|     \__,_|\__|\__\__,_|\___|_|\_\___(_|_|_)
        )" << endl;
        user->getsHit(enemy);
      }

      if (user->getHealth() <= 0.0)
      {
        endDuel = true;
        return true;
      }
    }

    return false;
  }
  static bool floor3(vector<vector<char>> map, char symbol, Character *user, int _x, int _y)
  {
    // Monster pointers
    Monster *ghost = new Ghost(100.0, 1);
    Monster *goblin = new Goblin(150.0, 2);

    map[_x][_y] = symbol;
    Floor::printMap(map);
    cout << "Type w a s d and click enter to move your character, type 'q' and click enter to quit" << endl;
    char input;
    cin >> input;

    while ((input != 'q' && input != 'Q') && ((_x != 10) && (_y != 29)))
    {
      Floor::userInput(input, map, symbol, _x, _y);
      cout << "x:" << _x << " y:" << _y << endl;
      Floor::printMap(map);

      if ((_x == 2) && (_y == 7))
      {
        int d = 0;
        cout << "Ghost encountered! Level:" << ghost->getLvl() << endl;
        cout << "1. Duel Monster for the chance to earn xp!        2. No Duel (loose half your health)" << endl;
        cin >> d;
        if (d == 1)
        {
          if (duel(user, ghost))
          {
            cout << "You have died. GAME OVER" << endl;
            return false;
          }
          else
          {
            float gXP = (ghost->getLvl()) * 100;
            cout << endl;
            cout << endl;
            cout << "CONGRATULATIONS! You defeated the monster. You gained " << gXP << " xp" << endl;
            user->updateState(gXP);
            Floor::printMap(map);
            cout << "Type w a s d and click enter to move your character, type 'q' and click enter to quit" << endl;
          }
        }
        else if (d == 2)
        {
          user->skipDuel();
          Floor::printMap(map);
          cout << "Type w a s d and click enter to move your character, type 'q' and click enter to quit" << endl;
        }
      }
      if ((_x == 5) && (_y == 16))
      {
        int d = 0;
        cout << "Goblin encountered! Level:" << goblin->getLvl() << endl;
        cout << "1. Duel Monster for the chance to earn xp!        2. No Duel (loose half your health)" << endl;
        cin >> d;
        if (d == 1)
        {
          if (duel(user, goblin))
          {
            cout << "You have died. GAME OVER" << endl;
            return false;
          }
          else
          {
            float gXP = (goblin->getLvl()) * 300;
            cout << endl;
            cout << endl;
            cout << "CONGRATULATIONS! You defeated the monster. You gained " << gXP << " xp" << endl;
            user->updateState(gXP);
            Floor::printMap(map);
            cout << "Type w a s d and click enter to move your character, type 'q' and click enter to quit" << endl;
          }
        }
        else if (d == 2)
        {
          user->skipDuel();
          Floor::printMap(map);
          cout << "Type w a s d and click enter to move your character, type 'q' and click enter to quit" << endl;
        }
      }

      cin >> input;
    }

    // deleting pointers
    delete ghost;
    delete goblin;

    if ((_x == 10) || (_y == 29))
    {
      cout << "You survived Floor 3." << endl;
      cout << "1. Move down to Floor 2               2. Save your progress and close game" << endl;
      int save;
      cin >> save;
      if (save == 1)
      {
        return true;
      }
      else if (save == 2)
      {
        cout << "Saving user data for " << user->getName() << endl;
        user->saveData(_x, _y, 3);
        exit(1);
      }
    }
    else if (input == 'q' || input == 'Q')
    {
      cout << "1. Save user data                      2. Don't save data" << endl;
      int save;
      cin >> save;
      if (save == 1)
      {
        cout << "Saving user data for " << user->getName() << endl;
        user->saveData(_x, _y, 3);
        exit(1);
      }
      else if (save == 2)
      {
        exit(1);
      }
    }
    else
    {
      return false;
    }
    return false;
  }

  static void test(char symbol, int _x, int _y, vector<vector<char>> map)
  {
    map[_x][_y] = symbol;
    Floor::printMap(map);
    cout << "Type w a s d and click enter to move your character, type 'q' and click enter to quit" << endl;
    char input;
    cin >> input;
    while ((input != 'q' && input != 'Q') && ((_x != 10) && (_y != 29)))
    {
      Floor::userInput(input, map, symbol, _x, _y);
      cout << "x:" << _x << " y:" << _y << endl;
      Floor::printMap(map);

      cin >> input;
    }
  }
};

#endif