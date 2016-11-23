#ifndef FIREBAT_H
#define FIREBAT_H

#include "infantry.h"

class firebat: virtual public infantry
{
    public:
        firebat();
        firebat (string tempName = "unknown", string tempType = "firebat");
        
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
