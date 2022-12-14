#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
    Object()
    {
        name = "Unknown";
        level = 1;
    }
    string getName()
    {
        return name;
    }
    int getLvl()
    {
        return level;
    }
    int sCount()
    {
        return specialCount;
    }
    void reset()
    {
        specialCount = 3;
        candyCount = 5;
        kitCount = 3;
    }
    void dropSpecial()
    {
        if (specialCount > 0)
        {
            specialCount--;
            cout << specialCount << "/3 Special Remaining" << endl;
        }
        else
        {
            cout << "0/3 Specials Remaining" << endl;
        }
    }
    string getType()
    {
        return type;
    }
    int cCount()
    {
        return candyCount;
    }
    int kCount()
    {
        return kitCount;
    }
    void setLvl(int lvl)
    {
        level = lvl;
    }

protected:
    string name;
    string type;
    int level;
    int specialCount;
    int candyCount;
    int kitCount;
};

#endif
