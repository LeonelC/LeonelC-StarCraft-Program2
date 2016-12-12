///////////////////////////////////////////////////////////////////
//
//     submarine.h  Class Definition for submarine (derived class)
//
//     Created by Will McWhorter, Ph.D.
//
///////////////////////////////////////////////////////////////////

#ifndef MEDIC_H
#define MEDIC_H

#include "infantry.h"

class medic: virtual public infantry
{
    public:
        medic();
        medic (string tempName = "unknown", string tempType = "medic");
        
        void setBoosterShot(int);
        int  getBoosterShot() const;
        virtual void speak() const;
        virtual void display() const;
        virtual void attack(infantry*);
        virtual void renderAid(infantry*);
        virtual void getAttacked(int);
        virtual void receiveAid(int);
        virtual void die();
        
                 
    private:
        int boosterShot;
    
};    

#endif
