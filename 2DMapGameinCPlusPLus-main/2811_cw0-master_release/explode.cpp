#include "explode.h"
#include "blocks.h"
#include "location.h"
#include "tom.h"
#include "thing.h"

void Explode::fire(Cave& c, string userCommand)
{
    // Get current location of Tom
    Location* loc = c.getMap()[c.getTom()->getX()][c.getTom()->getY()];
    // Check if there is a bomb on the tile Tom is on
    //if (bombCheck(*loc)==0){
    //    cerr << "There is no bomb here so I don't know how to " << userCommand << endl;
    //}
    //else{
        // Get's Tom's current coordinates in a 'x,y' format where x and y are coordinates of Tom
        string format = to_string(c.getTom()->getX()) + "," + to_string(c.getTom()->getY());
        // Initialises a set of strings
        std::set<string> a;
        // Put the first location to get into 'a'
        a.insert(format);
        // Continue this loop recursively until 'a' is empty, meaning there is nothing left to explode
        while (a.empty()==false){
            a = recursiveChecker(c, a);
            }
    //}
}

set<string> Explode::recursiveChecker(Cave& c, set<string> &aList){
    // Will hold the output of 'destroyThings()'
    int valueHolder=-1;
    // will hold the values of x,y
    int x=-1;
    int y=-1;
    // Take a value from the set
    auto someElementIterator = aList.begin();
    string coordinates = *someElementIterator;
    // Convert the value in the set into an integer
    x = stoi(coordinates.substr(0, coordinates.find(',')));
    y = stoi(coordinates.substr(coordinates.find(',')+1, coordinates.length()-1));
    if (x >= 0 && y >= 0 && x<c.getWidth() && y<c.getHeight()){
        // Explode self location
        Location* loc = c.getMap()[x][y];
        destroyThings(*loc);
        // Remove that coordinate from the set
        aList.erase(someElementIterator);
        // Check if the north value is in the right range
        // If so, do the same as above
        if (x >= 0 && y-1 >= 0 && x<c.getWidth() && y-1<c.getHeight()){
            loc = c.getMap()[x][y-1];
            valueHolder = destroyThings(*loc);
            if (valueHolder==1){
                // add this location to the set
                string nextValue = to_string(x) + "," + to_string(y-1);
                aList.insert(nextValue);
            }
        }
        // Check if the south value is in the right range
        if (x >= 0 && y+1 >= 0 && x<c.getWidth() && y+1<c.getHeight()){
            loc = c.getMap()[x][y+1];
            valueHolder = destroyThings(*loc);
            if (valueHolder==1){
                string nextValue = to_string(x) + "," + to_string(y+1);
                aList.insert(nextValue);
            }
        }
        // Check if the east value is in the right range
        if (x+1 >= 0 && y >= 0 && x+1<c.getWidth() && y<c.getHeight()){
        loc = c.getMap()[x+1][y];
        valueHolder = destroyThings(*loc);
        if (valueHolder==1){
            string nextValue = to_string(x+1) + "," + to_string(y);
            aList.insert(nextValue);
        }
        }
        // Check if the west value is in the right range
        if (x-1 >= 0 && y >= 0 && x-1<c.getWidth() && y<c.getHeight()){
            loc = c.getMap()[x-1][y];
            valueHolder = destroyThings(*loc);
            if (valueHolder==1){
                string nextValue = to_string(x-1) + "," + to_string(y);
                aList.insert(nextValue);
            }
        }
    }
    else{
        // If the current location is in an invalid range, delete it from the set
        aList.erase(someElementIterator);
    }
    // return the set
    return aList;
}

int Explode::bombCheck(Location& location){
    // This function checks whether a bomb exists at a given location
    // Take all 'things' at current location
    for (Thing * t : *location.getThings()){
        // If they are an subclass of bomb
        if (dynamic_cast<Bomb*>(t)){
            // Return 1 for true
            return 1;
        }
    }
    // Return 0 for false
    return 0;
}

int Explode::destroyThings(Location& location){
    // This function destroys all 'things' at current location
    // It return 0 or 1 depending on whether there was a bomb at current location
    int thereIsABomb=0;
    if (bombCheck(location)==1){
        // We will store the 'Things' we want to remove because if remove them straight away
        // the for loop will not delete every item
        std::set<Thing*> toRemove;
        for (Thing * t : *location.getThings())
        {
            if ( dynamic_cast<Blocks*>(t) )
            {
                toRemove.insert(t);
            }
            else if (dynamic_cast<Coin*>(t)){
                toRemove.insert(t);
            }
            else if (dynamic_cast<Mushroom*>(t)){
                toRemove.insert(t);
            }
            else if (dynamic_cast<Bomb*>(t)){
                toRemove.insert(t);
                thereIsABomb=1;
            }
        }
        // Deletes all the Things we marked to be deleted
        for (Thing* t: toRemove){
           location.remove(t);
        }
    }
    return thereIsABomb;
}

