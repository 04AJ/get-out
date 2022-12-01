#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const int ROW = 11;
const int COL = 31;

class Floor
{
public:
    static vector<vector<char>> create2DArray(string name)
    {

        ifstream fin;
        fin.open(name);

        vector<vector<char>> floor(ROW);
        for (int i = 0; i < ROW; i++)
        {
            floor[i] = vector<char>(COL);
        }

        int row = 0;
        int col = 0;
        string temp;
        while (getline(fin, temp))
        {

            for (col = 0; col < 31; col++)
            {
                floor[row][col] = temp.at(col);
            }
            row++;
        }
        fin.close();

        return floor;
    }

    static void printMap(vector<vector<char>> &map)
    {
        for (int i = 0; i < 11; i++)
        {

            for (int j = 0; j < 31; j++)
            {
                cout << map[i][j];
            }
            cout << endl;
        };
    }

    static bool checkCollision(vector<vector<char>> &map, int xTest, int yTest)
    {
        // out of map
        if (xTest < 0 || xTest >= ROW)
        {
            return false;
        }
        else if (yTest < 0 || yTest >= COL)
        {
            return false;
        }
        else if (map[xTest][yTest] == '#')
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    // char **map
    static void userInput(char input, vector<vector<char>> &map, char ch, int &x, int &y)
    {
        switch (input)
        {
        case 'w':
            if (checkCollision(map, (x - 1), y))
            {
                map[x][y] = ' ';
                map[--x][y] = ch;
            }
            break;
        case 'a':
            if (checkCollision(map, x, (y - 1)))
            {
                map[x][y] = ' ';
                map[x][--y] = ch;
            }
            break;
        case 's':
            if (checkCollision(map, (x + 1), y))
            {
                map[x][y] = ' ';
                map[++x][y] = ch;
            }
            break;
        case 'd':
            if (checkCollision(map, x, (y + 1)))
            {
                map[x][y] = ' ';
                map[x][++y] = ch;
            }
            break;
        default:
            cout << "Enter valid key" << endl;
        }
    }
};

#endif