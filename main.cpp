
#include "Floor.h"
#include "Object.h"

#include "Characters/Detective.h"
#include "Characters/GBuster.h"
#include "Characters/VampireSlayer.h"
#include "Characters/Character.h"

#include "Game.h"

#include <iostream>
#include <memory>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<char>> maze3 = Floor::create2DArray("mazes/maze3.txt");
vector<vector<char>> maze2 = Floor::create2DArray("mazes/maze2.txt");
vector<vector<char>> maze1 = Floor::create2DArray("mazes/maze1.txt");

void selectFloor(int _floor, char _myChar, Character *user, int _x, int _y);

int main()
{

  // New Character pointers
  Character *detective = nullptr;
  Character *ghostbuster = nullptr;
  Character *vslayer = nullptr;

  // Loading from file Character pointers
  Character *file_detective = nullptr;
  Character *file_ghostbuster = nullptr;
  Character *file_vslayer = nullptr;

  bool gameLoop = true;
  while (gameLoop)
  {

    // Opening game menu
    int load = Game::openingMenu();

    // If user decides to create new character
    if (load == 1)
    {
      // Character ASCII and Character type choice
      int charType = Game::characterOptions();
      if (charType > 3 || charType < 0)
      {

        cout << "Invalid input. Try again" << endl;
        continue;
      }

      char myChar;

      int cX = 0;
      int cY = 2;

      cout
          << "Name your character (one word, all lowercase): " << endl;
      string charName;
      cin >> charName;

      bool moveDown3 = false;
      bool moveDown2 = false;
      bool moveDown1 = false;

      if (charType == 1)
      {
        myChar = 'G';
        ghostbuster = new GBuster(charName);

        // puts user in the third floor
        selectFloor(3, myChar, ghostbuster, cX, cY);
      }
      else if (charType == 2)
      {

        myChar = 'D';
        detective = new Detective(charName);
        selectFloor(3, myChar, detective, cX, cY);
      }
      else if (charType == 3)
      {
        myChar = 'V';
        vslayer = new VampireSlayer(charName);
        selectFloor(3, myChar, vslayer, cX, cY);
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
      bool moveDown3 = false;
      bool moveDown2 = false;
      bool moveDown1 = false;
      char myChar;
      if (charType == "Detective")
      {
        myChar = 'D';
        file_detective = new Detective(charName, health, xp, level);
        // puts user in the floor they left off
        selectFloor(floor, myChar, file_detective, x, y);
      }
      else if (charType == "GhostBuster")
      {
        myChar = 'G';
        file_ghostbuster = new GBuster(charName, health, xp, level);
        selectFloor(floor, myChar, file_ghostbuster, x, y);
      }
      else if (charType == "VampireSlayer")
      {
        myChar = 'V';
        file_vslayer = new VampireSlayer(charName, health, xp, level);
        selectFloor(floor, myChar, file_vslayer, x, y);
      }
    }
    else
    {
      cout << "Invalid input. Try again" << endl;
      continue;
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
void selectFloor(int _floor, char _myChar, Character *user, int _x, int _y)
{
  bool moveDown3 = false;
  bool moveDown2 = false;
  bool moveDown1 = false;
  if (_floor == 3)
  {
    moveDown3 = Game::floor3(maze3, _myChar, user, _x, _y);
    if (moveDown3)
    {
      moveDown2 = Game::floor2(maze2, _myChar, user, 0, 2);
      if (moveDown2)
      {
        moveDown1 = Game::floor1(maze1, _myChar, user, 0, 2);
        if (moveDown1)
        {
          exit(1);
        }
        else
        {
          exit(1);
        }
      }
      else
      {
        exit(1);
      }
    }
    else
    {
      exit(1);
    }
  }
  if (_floor == 2)
  {
    moveDown2 = Game::floor2(maze2, _myChar, user, _x, _y);
    if (moveDown2)
    {
      moveDown1 = Game::floor1(maze1, _myChar, user, 0, 2);
      if (moveDown1)
      {
        exit(1);
      }
      else
      {
        exit(1);
      }
    }
    else
    {
      exit(1);
    }
  }
  if (_floor == 1)
  {
    moveDown1 = Game::floor1(maze1, _myChar, user, _x, _y);
    if (moveDown1)
    {
      exit(1);
    }
    else
    {
      exit(1);
    }
  }
}

/*
Sources:
https://www.google.com/url?q=https://www.dcode.fr/maze-generator&sa=D&source=docs&ust=1669275854077728&usg=AOvVaw31qhAtfq_0OdMb2YnPPFJB
https://www.asciiart.eu/movies/ghostbusters
https://patorjk.com/software/taag/#p=display&h=0&v=0&f=Ghost&t=Get%20Out
https://www.asciiart.eu/people/occupations/knights
https://ascii.co.uk/art/detective
https://patorjk.com/software/taag/#p=display&f=3D-ASCII&t=Floor%201
https://patorjk.com/software/taag/#p=display&f=Slant&t=Great%20Job%2C%20You%20Survived!
https://www.asciiart.eu/mythology/ghosts
https://ascii.co.uk/art/goblin
https://www.asciiart.eu/mythology/monsters


*/