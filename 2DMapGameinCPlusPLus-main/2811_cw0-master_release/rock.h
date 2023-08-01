#ifndef ROCK_H
#define ROCK_H

#include "blocks.h"
#include "thing.h"
#include <string>

// a giant bolder that stops tom from walking through this location
class Rock: public Thing, public Blocks
{
public:
    Rock(){};
    ~Rock(){};
    string getName()
    {
        return "rock";
    }
    Thing* clone()
    {
        return new Rock(); // this could be overridden by subclasses.
    }
};

#endif // ROCK_H
