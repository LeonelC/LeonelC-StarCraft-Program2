#ifndef SUPER_SOLDIER_H
#define SUPER_SOLDIER_H

//#include <iostream>

#include "marine.h"
#include "firebat.h"
#include "ghost.h"
#include "medic.h"

class superSoldier: public marine, public firebat, public ghost, public medic
{
   public:
   	superSoldier();
    superSoldier(string tempName="Unknown", string tempType="Super Soldier");  
    
    void setStickyGrenade(int);
    int getStickyGrenade() const;

    void setRocketLauncher(int);
    int getRocketLauncher() const;        

    virtual void attack(infantry*);
    virtual void renderAid(infantry*);
    virtual void getAttacked(int);
    virtual void receiveAid(int);
    virtual void speak() const;
    
    virtual void die();
    virtual void display() const;
      
   private:
      int stickyGrenade;
      int rocketLauncher;      
      
};


#endif
