#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include <string>

#include "cave.h"
#include "rock.h"
#include "thing.h"
#include "location.h"
#include "move.h"
#include "place.h"
#include "throw.h"
#include "explode.h"

using namespace std;

Cave::Cave(int w, int h) : width(w), height(h) // width and height of the cave
{
    // if either of the parameters for width/height is lower than 5, return error since the cave is too small
    if ( width < 5 || height < 5)
        throw new logic_error("cave too small for tom.");

    map = new Location**[width];

    // Initialises the map
    for (int x = 0; x < width; x++)
    {
        Location** column = new Location*[height];
        map[x] = column;
        for (int y = 0; y < height; y++)
            column[y] = new Location();
    }

    // Creates rocks on the boundaries of the map
    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
            if ( x == 0 || y == 0 || x == width-1 || y == height-1 )
                 map[x][y] -> add( new Rock() );

    tom = new Tom();
    // add tom to the middle of the map
    tom -> setLocation( this, width/2,height/2);
}

Cave::~Cave()
{
    // Destructor for Cave, which gets rid of the dynimically allocated 'map'
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // delete stored pointer
            delete map[i][j];
        }
        // delete sub array
        delete[] map[i];
    }
    delete [] map; //delete outer array
    map = NULL;
}
Cave& Cave::operator=(const Cave &otherCave)
{
    return *new Cave(otherCave);
}

Cave::Cave(const Cave& otherCave)
    {
    // Creates a copy of Cave object, while being a deep copy
    this->width = otherCave.width;
    this->height = otherCave.height;

    this->map = new Location**[width];

    for (int x = 0; x < width; x++)
    {
        Location** column = new Location*[height];
        this->map[x] = column;
        for (int y = 0; y < height; y++){
            column[y] = new Location();
        }
    }

    // Copies each thing at each index in the other cave into the new cave using 'clone()'
    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++){
            for (unsigned long index=0; index < otherCave.map[x][y]->getThings()->size(); index++){
                if (dynamic_cast<Tom*> (otherCave.map[x][y]->getThings()->at(index)) == NULL){
                    map[x][y]->add(otherCave.map[x][y]->getThings()->at(index)->clone());
                }

            }
        }
    // Initialises the new tom at appropriate location
    this->tom = new Tom();
    this->tom -> setLocation(this, otherCave.tom->getX(), otherCave.tom->getY());

}


void Cave::command (string userCommand)
{
    if (Move().triggersOn(userCommand))
        Move().fire(*this, userCommand);
    else if (Place().triggersOn(userCommand))
        Place().fire(*this, userCommand);
    // Checks if an throw command was requested by user
    else if (Throw().triggersOn(userCommand))
        Throw().fire(*this, userCommand);
    // Checks if an explode command was requested by user
    else if (Explode().triggersOn(userCommand))
        Explode().fire(*this, userCommand);
    else
        cerr << "tom doesn't know how to "+userCommand << endl;;
}

void Cave::show()
{
    vector<Thing*>* thingsWithTom = map[tom -> getX()][tom -> getY()] -> getThings();

    for (int y = 0; y < height; y++)
    { // for all rows
        for (int x = 0; x < width; x++) // for all columns
            cout << map[x][y] -> show(); // output whatever we find there

        cout << "  "; // list the things at this location
        if (y <  (int) thingsWithTom -> size())
            cout << (*thingsWithTom)[y] -> getName();

        cout << endl;
    }

    cout << endl;
}
