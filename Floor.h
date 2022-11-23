#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Floor
{
public:
    char *create2DArray(ifstream &fin)
    {
        const int ROW = 11;
        const int COL = 31;
        char *floor = new char[ROW][COL];
        int row = 0;
        int col = 0;
        string temp;
        while (getline(fin, temp))
        {

            for (int i = 0; i < 31; i++)
            {
                floor[row][i] = temp.at(i);
            }
            row++;
        }
        fin.close();

        return floor;
    }
};

#endif