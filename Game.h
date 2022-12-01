#ifndef GAME_H
#define GAME_H
#include <iostream>

#include "Characters/Character.h"
// #include "Characters/GBuster.h"
#include "Characters/Detective.h"
#include "Monsters/Monster.h"
#include "Monsters/Ghost.h"

#include "Floor.h"
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
      cout << "[" << user->getName() << "(You) | Level: " << user->getLvl() << " | Health: " << user->getHealth() << "] VS [" << enemy->getName() << "(You) | Level: " << enemy->getLvl() << " | Health: " << enemy->getHealth() << "]" << endl;
      cout << "1. Attack monster    2. Use Special Attack    3. Use Health Kit    4. Eat Candy" << endl;
      int choice = 0;
      cin >> choice;
      if (choice == 1)
      {
        // enemy->getsHit(user);
        user->getsHit(enemy);
      }

      if (user->getHealth() == 0.0)
      {
        endDuel = true;
        return true;
      }
      else if (enemy->getHealth() == 0.0)
      {
        endDuel = true;
        return false;
      }
    }

    return false;
  }
  static bool floor3(vector<vector<char>> map, char symbol, Character *user, int _x, int _y)
  {
    // creating Ghost monster
    Monster *ghost = new Ghost(100.0, 1);

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
            cout << "CONGRADULATIONS! You have defeated the monster. You have gained ___ xp" << endl;
          }
        }
        else if (d == 2)
        {
          user->skipDuel();
        }
      }
      cin >> input;
    }

    // deleting ghost
    delete ghost;

    if ((_x == 10) || (_y == 29))
    {
      return true;
    }
    else
    {
      return false;
    }
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