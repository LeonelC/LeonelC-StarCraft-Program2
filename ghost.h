///////////////////////////////////////////////////////////////////
//
//    destroyer.h   Class Definition for destroyer (derived class)
//
//    Created by Will McWhorter, Ph.D.
//
///////////////////////////////////////////////////////////////////


#ifndef GHOST_H
#define GHOST_H

#include "infantry.h"


class destroyer: virtual public vessel
{
    public:
        destroyer(string vname="Unknown", string vteam="Unknown", string vtype="Destroyer", 
                   int battery_gun=3000);
                      
        void set_battery_gun(int);
        int get_battery_gun() const;

        void fire_battery_gun(vessel*);
        
        virtual void light_attack(vessel*);
        virtual void heavy_attack(vessel*);
        virtual void sink();

        virtual void print() const;
        virtual void display() const;
                
    private:
        int battery_gun;
        
};


#endif
