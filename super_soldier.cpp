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
	ghost::getAttacked(damage);
}

void superSoldier::attack(infantry* beingAttacked)
{
	int luck, damage;
	
	string name = this->getName();
	srand (time(0));
	luck = rand() % 10 + 1;
	
	this->setCloak(false);
	switch(luck) {                                            //supersoldier is pretty particular about weapons used for a situation
	case 1: medic::attack(beingAttacked);
			 break;
			
	case 2:
	case 3:
	case 4: marine::attack(beingAttacked);
			 break;
			
	case 5: 
	case 6: firebat::attack(beingAttacked);
			 break;
	
	case 7: 
	case 8: ghost::attack(beingAttacked);
			 break;
		
	case 9: if (this->getStickyGrenade() > 0){
			this->setStickyGrenade(getStickyGrenade() - 1);
			damage = 30;
			} break;
	case 10:if (this->getRocketLauncher() > 0){               //critical hit
			this->setRocketLauncher(getRocketLauncher() - 1);
			damage = 40;
			} break;
	}  // end switch
	if (luck >= 9)
	{
		beingAttacked->getAttacked(damage);                      //attacking an infantry unit for random damage
	
	if (beingAttacked->getHealth() <= 0)                      //kill the unit if their hp is < 0
		beingAttacked->die();
	}
}
void superSoldier::receiveAid(int healthBoost)
{
    ghost::receiveAid(healthBoost);
}

void superSoldier::renderAid(infantry* beingHelped)
{
   	medic::renderAid(beingHelped);
}


void superSoldier::speak() const
{
    cout << this->getName() << ": Y'all are about to get some good ol' fashioned discipline." << endl;
}    

void superSoldier::display() const
{
    infantry::display();
	cout << setw(8) << this->getAssaultRifle() << setw(8) << this->getFlamethrower() << setw(8) << this->getSniperRifle() << setw(7) << ((this->getCloak() )? "Yes" : "No") << setw(7) << this->getBoosterShot() << setw(10)<< this->getStickyGrenade() << setw(8) << this->getRocketLauncher() << endl;
     
} 
