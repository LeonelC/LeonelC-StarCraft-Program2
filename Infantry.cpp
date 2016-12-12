///////////////////////////////////////////////////////////////////////
//
//      vessel.cpp   Class Functions for the vessel Class (Base Class)
//
//      Created by Will McWhorter, Ph.D.
// 
///////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#include "infantry.h"



// constructors

infantry::infantry() 
{
    setName("Unknown");
    setType("Unknown"); 
    setPistol(100);
    setHealth(100);

}


infantry::infantry(string tempName, string tempType)
{
    setName(tempName);
    setType(tempType);
    setPistol(100);
	setHealth(100);
}       


// set and get functions

void infantry::setName(string tempName)
{
    this->name = tempName;
}
        
        
string infantry::getName() const
{
    return this->name;
}
        
void infantry::setType(string tempType)
{
    this->type  = tempType;
}


string infantry::getType() const
{
    return this->type;
}        
    

void infantry::setPistol(int ammo)
{
    this->pistol = ammo;
}
        
        
int infantry::getPistol() const
{
    return this->pistol;
}

void infantry::setHealth(int hp)
{
	this->health = hp;
}

int infantry::getHealth() const
{
	return this->health;
}


// sets a infantry's base class values to 0
void infantry::die()
{
	setHealth(0);
	setPistol(0);
}
                                     



// display is an output function that is used to output attributes in the game display table
void infantry::display() const
{
	cout << "Unit Name:         " <<  this->name << endl;
	cout << "Unit Type:         " <<  this->type << endl;
	cout << "Unit Health:       " <<  this->health << endl;
	
}

