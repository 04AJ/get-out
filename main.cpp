#include <iostream>
#include <memory>
#include <vector>
#include <fstream>

// NEEDS TO BE ON TOP OTHERWISE PROGRAM WILL CRASH
#include "Characters/Detective.h"
#include "Characters/Character.h"
#include "Monsters/Ghost.h"
#include "Monsters/Monster.h"

// #include "Characters/GBuster.h"

#include "Floor.h"
#include "Game.h"

using namespace std;

int main()
{

  vector<vector<char>> maze3 = Floor::create2DArray("mazes/maze3.txt");
  vector<vector<char>> maze2 = Floor::create2DArray("mazes/maze2.txt");
  vector<vector<char>> maze1 = Floor::create2DArray("mazes/maze1.txt");

  // CHARACTER POINTER

  Character *detective = nullptr;

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
    }
    else if (charType == 2)
    {

      myChar = 'D';
      detective = new Detective(charName);

      moveDown = Game::floor3(maze3, myChar, detective, cX, cY);
    }
    else if (charType == 3)
    {
    }
  }

  // Loading from file
  else if (load == 2)
  {
    string charName;
    cout << "Enter the name of your character (one word, all lowercase)" << endl;
    cin >> charName;
    string testName;
    ifstream fin;
    fin.open("users.txt");
    while (getline(fin, testName))
    {
      if (charName == testName)
      {
        string fileName = "users/" + charName + ".txt";
        ifstream user(fileName);
        if (user.is_open())
        {
        }
      }
    }

    fin.close();
  }

  delete detective;

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