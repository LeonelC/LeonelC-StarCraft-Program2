///////////////////////////////////////////////////////////////////////////////
//
//    battleship.cpp  Class Functions for the battleship Class (derived Class)
//
//    Created by Will McWhorter, Ph.D.
//
///////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "marine.h"

marine::marine()
		:infantry("Unknown","marine") //call infantry's constructor with these inputs
{
	setAssaultRifle(100);
}

marine::marine(string tempName, string tempType)
        : infantry(tempName, tempType) //call infantry's constructor with user defined inputs
{
    setAssaultRifle(100);
}

        
void marine::setAssaultRifle(int ammo)
{
    this->assaultRifle = ammo;
}


int marine::getAssaultRifle() const
{
    return this->assaultRifle;
}

        
void marine::die()
{
    infantry::die();    //calls infantry's method for death
    this->setAssaultRifle(0);
    cout << this->getName() << " has gone to hell to regroup." << endl;
}
    

void marine::getAttacked(int damage) 
{
    this->setHealth(this->getHealth() - damage);
}

void marine::attack(infantry* beingAttacked)
{
	if (this->assaultRifle > 0){
		beingAttacked->getAttacked(10);                      //attacking an infantry unit for 10 damage
		this->setAssaultRifle(this->getAssaultRifle() - 10); //reduce ammo by 10
	}
	
	if (beingAttacked->getHealth() <= 0)                      //kill the unit if their hp is < 0
		beingAttacked->die();
	
}
void marine::receiveAid(int healthBoost)
{
    this->setHealth(this->getHealth() + healthBoost);
}

void marine::renderAid(infantry* beingHelped)
{
   int friendlyHP = beingHelped->getHealth();
	int survival;
	string name = this->getName();
	srand (time(0));
	survival = rand() % 10 + 1;
    
    if (friendlyHP > 75)
    	cout << name << ": You ain't hurt, boy! Now get up and fight!" << endl;
    	
    else if (friendlyHP > 25 and friendlyHP < 75){
        cout << name << ": Let me patch you up, boy!." << endl;
    	beingHelped->receiveAid(10);
    }
    
    else {
    	cout << name << ": Sorry, bro...You ain't gonna make it." << endl;
    	if (survival <= 5)
    		beingHelped->die();
	}
}


void marine::speak() const
{
    cout << this->getName() << ": You wanna piece of me, boy?" << endl;
}    

void marine::display() const
{
    infantry::display();
	cout << "Unit ammo: " <<  this->assaultRifle << endl;
     
} 
