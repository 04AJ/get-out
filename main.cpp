
#include "Floor.h"
#include "Object.h"
// NEEDS TO BE ON TOP OTHERWISE PROGRAM WILL CRASH

#include "Characters/Detective.h"
#include "Characters/GBuster.h"
#include "Characters/VampireSlayer.h"
#include "Characters/Character.h"
#include "Monsters/Monster.h"
#include "Monsters/Ghost.h"

#include "Game.h"

#include <iostream>
#include <memory>
#include <vector>
#include <fstream>

using namespace std;

int main()
{

  vector<vector<char>> maze3 = Floor::create2DArray("mazes/maze3.txt");
  vector<vector<char>> maze2 = Floor::create2DArray("mazes/maze2.txt");
  vector<vector<char>> maze1 = Floor::create2DArray("mazes/maze1.txt");

  // NEW CHARACTER POINTERS

  Character *detective = nullptr;
  Character *ghostbuster = nullptr;
  Character *vslayer = nullptr;

  // LOADING FROM FILE POINTERS
  Character *file_detective = nullptr;
  Character *file_ghostbuster = nullptr;
  Character *file_vslayer = nullptr;

  bool gameLoop = true;
  while (gameLoop)
  {

    // OPENING PAGE
    int load = Game::openingMenu();

    // Creating new character
    if (load == 1)
    {
      // OUTPUTTING CHARACTER ASCII
      int charType = Game::characterOptions();

      char myChar;

      int cX = 0;
      int cY = 2;

      cout
          << "Name your character (one word, all lowercase): " << endl;
      string charName;
      cin >> charName;

      bool moveDown = false;

      if (charType == 1)
      {
        myChar = 'G';
        ghostbuster = new GBuster(charName);
        moveDown = Game::floor3(maze3, myChar, ghostbuster, cX, cY);
        if (moveDown)
        {
          cout << "You survived Floor 3." << endl;
          cout << "1. To move down to Floor 2               2. To save your progress and close game" << endl;
        }
        else
        {
          return 0;
        }
      }
      else if (charType == 2)
      {

        myChar = 'D';
        detective = new Detective(charName);

        moveDown = Game::floor3(maze3, myChar, detective, cX, cY);
        if (moveDown)
        {
          cout << "You survived Floor 3." << endl;
          cout << "1. To move down to Floor 2               2. To save your progress and close game" << endl;
        }
        else
        {
          return 0;
        }
      }
      else if (charType == 3)
      {
        myChar = 'V';
        vslayer = new VampireSlayer(charName);
        moveDown = Game::floor3(maze3, myChar, vslayer, cX, cY);
        if (moveDown)
        {
          cout << "You survived Floor 3." << endl;
          cout << "1. To move down to Floor 2               2. To save your progress and close game" << endl;
        }
        else
        {
          return 0;
        }
      }
    }

    // Loading from file
    else if (load == 2)
    {
      string charName;
      cout << "Enter the name of your character (one word, all lowercase)" << endl;
      cin >> charName;

      string charType;
      float health;
      float xp;
      int level;
      int x;
      int y;
      int floor;

      string fileName = "users/" + charName + ".txt";
      ifstream user(fileName);
      if (!user.is_open())
      {
        cout << "User not found. Returning to menu." << endl;
        cout << endl;
        cout << endl;
        continue;
      }

      user >> charType >> health >> xp >> level >> x >> y >> floor;
      bool moveDown = false;
      char myChar;
      if (charType == "Detective")
      {
        myChar = 'D';
        file_detective = new Detective(charName, health, xp, level);
        moveDown = Game::floor3(maze3, myChar, file_detective, x, y);
        if (moveDown)
        {
        }
        else
        {
          return 0;
        }
      }
      else if (charType == "GhostBuster")
      {
        myChar = 'G';
        file_ghostbuster = new GBuster(charName, health, xp, level);
        moveDown = Game::floor3(maze3, myChar, file_ghostbuster, x, y);
        if (moveDown)
        {
        }
        else
        {
          return 0;
        }
      }
      else if (charType == "VampireSlayer")
      {
        myChar = 'V';
        file_vslayer = new VampireSlayer(charName, health, xp, level);
        moveDown = Game::floor3(maze3, myChar, file_vslayer, x, y);
        if (moveDown)
        {
        }
        else
        {
          return 0;
        }
      }
    }
  }

  delete detective;
  delete ghostbuster;
  delete vslayer;
  delete file_detective;
  delete file_ghostbuster;
  delete file_vslayer;

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