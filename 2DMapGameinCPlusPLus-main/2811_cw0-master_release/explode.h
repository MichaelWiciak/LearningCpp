#ifndef EXPLODE_H
#define EXPLODE_H

#include <set>
#include "coin.h"
#include "command.h"
#include "mushroom.h"
#include "bomb.h"
#include "rock.h"
#include <iostream>

using namespace std;


// A command which will destroy things in adjacent locations and continue doing so if it finds bombs
// on adjacent tiles
class Explode : public Command
{
public:
    Explode() : Command("explode") {};
    void fire(Cave& c, string userCommand);
    int destroyThings(Location& location);
    set<string> recursiveChecker(Cave& c, set<string> &aList);
    int bombCheck(Location& location);
};

#endif // EXPLODE_H
