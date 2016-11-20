//////////////////////////////////////////////////////////////////////////
//
//    carrier.cpp  Class Functions for the carrier Class (derived Class)
//
//    Created by Will McWhorter, Ph.D.
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "firebat.h"
#include "infantry.h"

firebat::firebat()
		:infantry("Unknown","firebat") //call infantry's constructor with these inputs
{
	setFlamethrower(100);
}

firebat::firebat(string tempName, string tempType)
        : infantry(tempName, tempType) //call infantry's constructor with user defined inputs
{
    setFlamethrower(100);
}

        
void firebat::setFlamethrower(int ammo)
{
    this->flamethrower = ammo;
}


int firebat::getFlamethrower() const
{
    return this->flamethrower;
}

        
void firebat::die()
{
    infantry::die();    //calls infantry's method for death
    this->setFlamethrower(0);
    cout << this->getName() << "'s flame has been extinguished" << endl;
}
    

void firebat::getAttacked(int damage) 
{
    this->setHealth(this->getHealth() - damage);
}

void firebat::attack(infantry* beingAttacked)
{
	if (this->flamethrower > 0){
		beingAttacked->getAttacked(20);                      //attacking an infantry unit for 20 damage
		this->setFlamethrower(this->getFlamethrower() - 10); //reduce ammo by 10
	}
	
	if (beingAttacked->getHealth() <= 0)                      //kill the unit if their hp is < 0
		beingAttacked->die();
	
}
void firebat::receiveAid(int healthBoost)
{
    this->setHealth(this->getHealth() + healthBoost);
}

void firebat::renderAid(infantry* beingHelped)
{
    cout << this->getName() <<": Sorry " << beingHelped->getName() 
		 << ", I've got no first aid supplies. Keep thinking positive thoughts!" << endl;
}


void firebat::speak() const
{
    cout << this->getName() << ": Need a light?" << endl;
}    

void firebat::display() const
{
    infantry::display();
	cout << "Unit ammo: " <<  this->flamethrower << endl;
     
} 
