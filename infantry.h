 
 ///////////////////////////////////////////////////////////////////
//
//       vessel.h  Class Definition for vessel (base class)
//
//       Created by Will McWhorter, Ph.D.
//  
///////////////////////////////////////////////////////////////////

#ifndef INFANTRY_H
#define INFANTRY_H


#include <string>
#include <iomanip>

using namespace std;

class infantry
{
    public:
        infantry();
        infantry(string, string);
        
        void  setName(string);
        string getName() const;
        
        void  setType(string);
        string getType() const;
        
        void setHealth(int);
        int  getHealth() const;
        
        void setPistol(int);
        int  getPistol() const;
        
    	//This set of abstract functions must be defined for each inheriting class
        virtual void attack(infantry*) = 0;
        virtual void renderAid(infantry*) = 0;
        virtual void getAttacked(int) = 0;
        virtual void receiveAid(int) = 0;
        virtual void die() = 0;
        virtual void speak() const = 0;
        
        void display() const;
              
    private:
        string name;
        string type;
        int health;
        int pistol;

};    


#endif

