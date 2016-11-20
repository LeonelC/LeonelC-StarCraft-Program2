///////////////////////////////////////////////////////////////////
//
//    carrier.h   Class Definition for carrier (derived class)
//
//    Created by Will McWhorter, Ph.D.
//
///////////////////////////////////////////////////////////////////

#ifndef FIREBAT_H
#define FIREBAT_H

#include "infantry.h"

class firebat: virtual public infantry
{
    public:
        firebat();
        firebat (string, string);
        
        void setFlamethrower(int);
        int  getFlamethrower() const;
        
        virtual void attack(infantry*);
        virtual void renderAid(infantry*);
        virtual void getAttacked(int);
        virtual void receiveAid(int);
        virtual void die();
        virtual void speak() const;
        
        virtual void display() const;
                
    private:
        int flamethrower;
    
};    

#endif
