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

protected:
    string name;
    int level;
};

#endif
