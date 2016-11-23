/////////////////////////////////////////////////////////////////////////////
//
//    ghost.cpp  Class Functions for the ghost Class (derived Class)
//
//    Created by Will McWhorter, Ph.D.
//
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

#include "ghost.h"


ghost::ghost()
	  : infantry("unknown", "ghost")
{
    this->setCloak(false);
    this->setSniperRifle(20);
    //cout << "I'm a ghost"<<endl;
}
ghost::ghost(string tempName, string tempType)
      : infantry(tempName, tempType)
{
    this->setCloak(false);
    this->setSniperRifle(20);
    //cout << "I'm a ghost"<<endl;
}
        
void ghost::setSniperRifle(int ammo)
{
    this->sniperRifle = ammo;
}

int ghost::getSniperRifle() const
{
    return this->sniperRifle; // ammunition left
}
    
void ghost::setCloak(bool status)
{
    
    this->cloak = status;
}   

bool ghost::getCloak() const
{
	return this->cloak;
}

void ghost::die() 
{
	infantry::die();
	this->setSniperRifle(0);
	cout << this->getName() << ": Never say die..." << endl;
}

 

void ghost::display() const
{

    infantry::display();
    cout << "Unit Sniper:       " <<  this->sniperRifle << endl;
    cout << "Invisible:         " <<  ((this->getCloak() )? "cloaked" : "uncloaked");
	cout << endl << endl;
     
} 

void ghost::getAttacked(int damage) 
{
    if ( !getCloak() )										  //if not cloaked
		this->setHealth(this->getHealth() - damage);          //take damage
}

void ghost::attack(infantry* beingAttacked)
{
	int currentAmmo = this->getSniperRifle();
	this->setCloak(false);									  //if attacking, cloaking is off, I think?
	if (currentAmmo > 0){
		beingAttacked->getAttacked(20);                       //attacking an infantry unit for 20 damage
		this->setSniperRifle(currentAmmo - 1);                //reduce ammo by 1
	}
	
	if (beingAttacked->getHealth() <= 0)                      //kill the unit if their hp is < 0
		beingAttacked->die();
	
}
void ghost::receiveAid(int healthBoost)
{
    this->setHealth(this->getHealth() + healthBoost);
}

void ghost::renderAid(infantry* beingHelped)
{
	int friendlyHP = beingHelped->getHealth();
	int survival;
	string name = this->getName();
	srand (time(0));
	survival = rand() % 10 + 1;
    
    if (friendlyHP > 75)
    	cout << name << ": Suck it up, buttercup." << endl;
    	
    else if (friendlyHP > 25 and friendlyHP < 75){
        cout << name << ": You don't see me... I was never here." << endl;
    	beingHelped->receiveAid(5);
    }
    
    else {
    	cout << name << ": You don't look so hot." << endl;
    	if (survival <= 5)
    		beingHelped->die();
	}
	
}


void ghost::speak() const
{
    cout << this->getName() << ": Somebody call for an exterminator?" << endl;
}  
