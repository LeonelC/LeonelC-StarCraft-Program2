#include <iostream>
#include <cstdlib>
using namespace std;

#include "medic.h"

medic::medic()
		:infantry("Unknown","medic") //call infantry's constructor with these inputs
{
	setBoosterShot(100);
}

medic::medic(string tempName, string tempType)
        : infantry(tempName, tempType) //call infantry's constructor with user defined inputs
{
    setBoosterShot(100);
}

        
void medic::setBoosterShot(int shots)
{
    this->boosterShot = shots;
}


int medic::getBoosterShot() const
{
    return this->boosterShot;
}

        
void medic::die()
{
    infantry::die();    //calls infantry's method for death
    this->setBoosterShot(0);
    cout << this->getName() << ": Medic!" << endl;
}
    

void medic::getAttacked(int damage) 
{
    this->setHealth(this->getHealth() - damage);
}

void medic::attack(infantry* beingAttacked)
{
	if (this->getPistol() > 0){
		beingAttacked->getAttacked(5);                      //attacking an infantry unit for 5 damage
		this->setPistol(this->getPistol() - 10); //reduce ammo by 10
	}
	
	if (beingAttacked->getHealth() <= 0)                      //kill the unit if their hp is < 0
		beingAttacked->die();
	
}
void medic::receiveAid(int healthBoost)
{
    this->setHealth(this->getHealth() + healthBoost);
}

void medic::renderAid(infantry* beingHelped)
{
   	int friendlyHP = beingHelped->getHealth();
	beingHelped->receiveAid(30);
	
    if (friendlyHP >= 75)
    	cout << this->getName() << ": Here's some lotion, a comb, and a blowtorch. Good luck! (no heal)" << endl;
    	
    else if (friendlyHP > 0 and friendlyHP < 75){
        cout << this->getName() << ": I'll get you fixed right up!" << endl;
    	beingHelped->receiveAid(30);
    	this->setBoosterShot(this->getBoosterShot() - 1);
    }
    else cout << this->getName() << ": I can't fix dead..." << endl;
    	
    
 //reduce ammo by 1
}


void medic::speak() const
{
    cout << this->getName() << ": Prepped and ready." << endl;
}    

void medic::display() const
{
    infantry::display();
	cout << "Unit boosters:     " <<  this->boosterShot << endl;
	cout << "Unit ammo:         " <<  this->getPistol() << endl << endl;
     
} 
