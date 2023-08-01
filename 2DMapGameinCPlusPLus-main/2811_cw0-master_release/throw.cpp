#include "throw.h"
#include "thing.h"

void Throw::fire(Cave& c, string userCommand)
{
    // This functions allows to throw an 'thing' into either north, south, east, west direction
    string s = tail(userCommand);
    // Gets the location of the throw
    string location = tail(s);
    int index = s.find(location);
    // Gets the name of the object to be thrown
    string what = s.substr(0, index-1);
    // Checks if it is a coin
    if (what.compare("coin")==0 && location.compare("north")==0 && c.getTom()->getY()-1 >= 0){
        // Checks what direction it should be thrown
            // Gets the location of where the object should be thrown
            Location* loc = c.getMap()[c.getTom()->getX()][c.getTom()->getY()-1];
            // Checks if it can be thrown into that block
            if (loc->isBlocking()==0)
            {
                // Add this object to that throw location
                loc ->add(new Coin());
            }
            else
            {
                // The object cannot be thrown here
                cerr << "Can't throw it there" << endl;
            }
        }
        // Does the same as above but for south
    else if (what.compare("coin")==0 && location.compare("south")==0 && c.getTom()->getY()+1 < c.getHeight())
    {
        Location* loc = c.getMap()[c.getTom()->getX()][c.getTom()->getY()+1];
        if (loc->isBlocking()==0)
        {
            loc ->add(new Coin());
        }
        else
        {
            cerr << "Can't throw it there" << endl;
        }
    }
         // Does the same as above but for south
    else if (what.compare("coin")==0 && location.compare("east")==0 && c.getTom()->getX()+1 < c.getWidth())
    {
        Location* loc = c.getMap()[c.getTom()->getX()+1][c.getTom()->getY()];
        if (loc->isBlocking()==0)
        {
            loc ->add(new Coin());
        }
        else
        {
            cerr << "Can't throw it there" << endl;
        }
    }
     // Does the same as above but for south
    else if (what.compare("coin")==0 && location.compare("west")==0 && c.getTom()->getX()-1 >= 0)
    {
        Location* loc = c.getMap()[c.getTom()->getX()-1][c.getTom()->getY()];
        if (loc->isBlocking()==0)
        {
            loc ->add(new Coin());
        }
        else
        {
            cerr << "Can't throw it there" << endl;
        }
    }
    // Does the same as above but for a mushroom object
    else if (what.compare("mushroom")==0 && location.compare("north")==0 && c.getTom()->getY()-1 >= 0)
    {
            Location* loc = c.getMap()[c.getTom()->getX()][c.getTom()->getY()-1];
            if (loc->isBlocking()==0)
            {
                loc ->add(new Mushroom());
            }
            else
            {
                cerr << "Can't throw it there" << endl;
            }
    }
    else if (what.compare("mushroom")==0 && location.compare("south")==0 && c.getTom()->getY()+1 < c.getHeight())
    {
        Location* loc = c.getMap()[c.getTom()->getX()][c.getTom()->getY()+1];
        if (loc->isBlocking()==0)
        {
            loc ->add(new Mushroom());
        }
        else
        {
            cerr << "Can't throw it there" << endl;
        }
    }
    else if (what.compare("mushroom")==0 && location.compare("east")==0 && c.getTom()->getX()+1 < c.getWidth())
    {
        Location* loc = c.getMap()[c.getTom()->getX()+1][c.getTom()->getY()];
        if (loc->isBlocking()==0)
        {
            loc ->add(new Mushroom());
        }
        else
        {
            cerr << "Can't throw it there" << endl;
        }
    }
    else if (what.compare("mushroom")==0 && location.compare("west")==0 && c.getTom()->getX()-1 >= 0)
    {
        Location* loc = c.getMap()[c.getTom()->getX()-1][c.getTom()->getY()];
        if (loc->isBlocking()==0)
        {
            loc ->add(new Mushroom());
        }
        else
        {
            cerr << "Can't throw it there" << endl;
        }
    }
    else
        cerr << "I don't know how to throw a " << userCommand << endl;
}
