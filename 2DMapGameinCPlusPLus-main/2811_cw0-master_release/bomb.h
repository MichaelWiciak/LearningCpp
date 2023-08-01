#ifndef BOMB_H
#define BOMB_H


#include "thing.h"

// This class can be placed and can be used by the explode
class Bomb : public Thing
{
    string getName()
    {
        return "bomb";
    }
    Thing* clone()
    {
        return new Bomb(); // this could be overridden by subclasses.
    }
};

#endif // BOMB_H
