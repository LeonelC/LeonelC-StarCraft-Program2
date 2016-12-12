//////////////////////////////////////////////////////////////////////////////////////
//
//    super_ship.cpp (Derived Class - Multiple Inheritance)
//                                                                                   
//    NOTE: This class is derived from multiple base classes which are derived 
//          from the same base class (diamond inheritance)
//
//    Created by Will McWhorter, Ph.D.
//
//////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <cstdlib>
#include <ctime>

#include "super_soldier.h"

using namespace std;

superSoldier::superSoldier(string tempName, string tempType)
    :infantry(tempName, tempType), marine(tempName, tempType),
     firebat(tempName, tempType),
     ghost(tempName, tempType),
     medic(tempName, tempType)
{
     setRocketLauncher(10); 
     setStickyGrenade(4);
     this->setHealth(150);
     //cout << "I'm a super soldier" << endl;
}


void superSoldier::setRocketLauncher(int rockets)
{
    this->rocketLauncher = rockets;
}
    

int superSoldier::getRocketLauncher() const
{
    return this->rocketLauncher;
}

void superSoldier::setStickyGrenade(int nades)
{
    this->stickyGrenade = nades;
}
    

int superSoldier::getStickyGrenade() const
{
    return this->stickyGrenade;
}

void superSoldier::die()
{
	// this guy dies all over the place
    this->setAssaultRifle(0);
    this->setSniperRifle(0);
    this->setFlamethrower(0);
    this->setPistol(0);
    this->setBoosterShot(0);
    this->setStickyGrenade(0);
    this->setRocketLauncher(0);
    this->setHealth(0);
    cout << this->getName() << ": What is dead, may never die..." << endl;
}
    

void superSoldier::getAttacked(int damage) 
{
	if ( !getCloak() )
    	this->setHealth(this->getHealth() - damage);
}

void superSoldier::attack(infantry* beingAttacked)
{
	int luck, damage;
	
	string name = this->getName();
	srand (time(0));
	luck = rand() % 10 + 1;
	
	switch(luck) {                                            //supersoldier is pretty particular about weapons used for a situation
	case 1: if (this->getPistol() > 0){                       //critical miss
			this->setPistol(getPistol() - 1);
			damage = 5;
			} break;
			
	case 2:
	case 3:
	case 4: if (this->getAssaultRifle() > 0){
			this->setAssaultRifle(getAssaultRifle() - 1);
			damage = 10;
			} break;
			
	case 5: 
	case 6: if (this->getFlamethrower() > 0){
			this->setFlamethrower(getFlamethrower() - 1);
			damage = 20;
			} break;
	
	case 7: 
	case 8: if (this->getSniperRifle() > 0){
			this->setSniperRifle(getSniperRifle() - 1);
			damage = 20;
			} break;
		
	case 9: if (this->getStickyGrenade() > 0){
			this->setStickyGrenade(getStickyGrenade() - 1);
			damage = 30;
			} break;
	case 10:if (this->getRocketLauncher() > 0){               //critical hit
			this->setRocketLauncher(getRocketLauncher() - 1);
			damage = 40;
			} break;
	}  // end switch
	
	if (damage == 0 and this->getPistol() > 0) {             //in case he didn't have ammo pulls out pistol
			this->setPistol(getPistol() - 1);
			damage = 5;
	}
	beingAttacked->getAttacked(damage);                      //attacking an infantry unit for random damage

	
	if (beingAttacked->getHealth() <= 0)                      //kill the unit if their hp is < 0
		beingAttacked->die();
	
}
void superSoldier::receiveAid(int healthBoost)
{
    this->setHealth(this->getHealth() + healthBoost);
}

void superSoldier::renderAid(infantry* beingHelped)
{
   	int friendlyHP = beingHelped->getHealth();
	beingHelped->receiveAid(30);
	this->setBoosterShot(this->getBoosterShot() - 1); //reduce ammo by 1
}


void superSoldier::speak() const
{
    cout << this->getName() << ": Y'all are about to get some good ol' fashioned discipline." << endl;
}    

void superSoldier::display() const
{
    infantry::display();
    cout << "Unit boosters:     " <<  this->getBoosterShot() << endl;
	cout << "Unit Pistol:       " <<  this->getPistol() << endl;
    cout << "Unit Rifle:        " <<  this->getAssaultRifle() << endl;
    cout << "Unit Sniper:       " <<  this->getSniperRifle() << endl;
    cout << "Invisible:         " <<  this->getCloak() ? "cloaked" : "uncloaked";
    cout << endl;
	cout << "Unit flamethrower: " <<  this->getFlamethrower() << endl;
	cout << "Unit Stickies:     " <<  this->getStickyGrenade() << endl;
	cout << "Unit Rockets:      " <<  this->getRocketLauncher() << endl << endl;
     
} 
