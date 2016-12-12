#ifndef MARINE_H
#define MARINE_H

#include "infantry.h"


class marine: virtual public infantry
{
    public:
        marine();
        marine (string tempName = "unknown", string tempType = "marine");
        
        void setAssaultRifle(int);
        int  getAssaultRifle() const;
        virtual void speak() const;
        virtual void display() const;
        virtual void attack(infantry*);
        virtual void renderAid(infantry*);
        virtual void getAttacked(int);
        virtual void receiveAid(int);
        virtual void die();
        
                 
    private:
        int assaultRifle;
    
};    

#endif
