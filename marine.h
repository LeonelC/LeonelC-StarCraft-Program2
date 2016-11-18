///////////////////////////////////////////////////////////////////
//
//    battleship.h   Class Definition for battleship (derived class)
//
//    Created by Will McWhorter, Ph.D.
//
///////////////////////////////////////////////////////////////////

#ifndef MARINE_H
#define MARINE_H

#include "infantry.h"


class battleship: virtual public vessel
{
    public:
        battleship(string vname="Unknown", string vteam="Unknown", string vtype="Battle Ship", 
                       int main=200, int cruise=35, int battery=5000);
        
        void set_main_gun(int);
        int get_main_gun() const;
        
        void set_cruise_missile(int);
        int get_cruise_missile() const;
        
        void set_battery_gun(int);
        int get_battery_gun() const;
        
        void fire_main_gun(vessel*);
        void launch_cruise_missile(vessel*);
        void fire_battery_gun(vessel*);
        
        virtual void light_attack(vessel*);
        virtual void heavy_attack(vessel*);
        virtual void sink();

        void print() const;
        void display() const;
                
    private:
        int main_gun;
        int cruise_missile;
        int battery_gun;
        
};


#endif
