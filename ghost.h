#ifndef GHOST_H
#define GHOST_H

#include "infantry.h"


class ghost: virtual public infantry
{
    public:
        ghost();
        ghost(string tempName = "unknown", string tempType = "ghost");  
		           
        void setSniperRifle(int);
        int getSniperRifle() const;
		
		void setCloak(bool);
		bool getCloak() const;
        
        virtual void attack(infantry*);
        virtual void renderAid(infantry*);
        virtual void getAttacked(int);
        virtual void receiveAid(int);
        virtual void speak() const;
        
        virtual void die();
        virtual void display() const;
                
    private:
        int  sniperRifle;
        bool cloak;
        
};


#endif
