#include <iostream>
#include "Floor.h"
#include "Characters/Ghostbuster.h"
#include "Characters/Character.h"
#include "Monsters/Monster.h"
#include "Monsters/Ghost.h"
using namespace std;

// creates new menu for fighting and increases or decreases user character xp/level
bool duel(Character *user, Monster *enemy)
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
  return false;
}

bool floor3(char **map, char symbol, Character *user, int _x, int _y)
{
  // creating Ghost monster
  Monster *ghost = new Ghost(100.0, 1);

  map[_x][_y] = symbol;
  Floor::printMap(map);
  cout << "Type w a s d and click enter to move your character, type 'q' and click enter to quit" << endl;
  char input;
  cin >> input;

  while ((input != 'q' || input != 'Q') && ((_x != 10) && (_y != 29)))
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

bool floor2();

bool floor1();

int main()
{

  // creating all floors
  char **maze3 = Floor::create2DArray("mazes/maze3.txt");
  char **maze2 = Floor::create2DArray("mazes/maze2.txt");
  char **maze1 = Floor::create2DArray("mazes/maze1.txt");

  // creating all character pointers
  Character *gbuster = nullptr;
  Character *detective = nullptr;
  Character *vslayer = nullptr;

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

  if (load == 1)
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
    // symbol on maze
    char myChar;
    // char position in maze
    int cX = 0;
    int cY = 2;
    cin >> charType;

    cout << "Name your character (one word): " << endl;
    string charName = "";
    cin >> charName;

    bool moveDown = false;
    if (charType == 1)
    {
      myChar = 'G';
      gbuster = new Ghostbuster(charName);
      moveDown = floor3(maze3, myChar, gbuster, cX, cY);
    }

    if (moveDown == true)
    {
      cout << "End of floor 3 reached!" << endl;
      cout << "1. Move down to next floor   2. Pause the game" << endl;
    }
  }

  delete gbuster;
  delete detective;
  delete vslayer;
  delete[] maze3;
  return 0;
}

/*
Sources:
https://www.google.com/url?q=https://www.dcode.fr/maze-generator&sa=D&source=docs&ust=1669275854077728&usg=AOvVaw31qhAtfq_0OdMb2YnPPFJB
https://www.asciiart.eu/movies/ghostbusters
https://patorjk.com/software/taag/#p=display&h=0&v=0&f=Ghost&t=Get%20Out
https://www.asciiart.eu/people/occupations/knights
https://ascii.co.uk/art/detective


*/