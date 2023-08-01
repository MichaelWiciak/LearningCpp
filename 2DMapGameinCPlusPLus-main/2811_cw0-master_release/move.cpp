#include "move.h"

void Move::fire(Cave& c, string userCommand)
{
    string s = tail(userCommand);

    int newTomX = c.getTom()->getX(),  newTomY = c.getTom()->getY();

    // Changed the checking for direction, because it will accept input such as 'wqqq' as 'west'
    if (s.compare("west")==0)
        newTomX--;
    else if  (s.compare("north")==0)
        newTomY--;
    // Now performs move when the command indicates south or east direction
    else if  (s.compare("south")==0)
        newTomY++;
    else if  (s.compare("east")==0)
        newTomX++;
    else
    {
        cerr << "tom can't \"" << s << "\"" << endl;
        return;
    }


    if (newTomX < 0 || newTomY < 0 || newTomX >= c.getWidth() || newTomY >= c.getHeight())
    {
        cerr << "can't walk into the void" << endl;
        return;
    }
    else if (c.getMap()[newTomX][newTomY]->isBlocking()!=0)
    {
        cerr << "something is blocking the way" << endl;
        return;
    }
    else if (newTomX != c.getTom()->getX() || newTomY != c.getTom()->getY())
    {
        c.getTom() -> setLocation (&c, newTomX, newTomY);
        cerr << "tom shuffles through the dank cave" << endl;
        return;
    }
}
