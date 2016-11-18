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

class carrier: virtual public vessel
{
    public:
        carrier(string vname="Unknown", string vteam="Unknown", string vtype="Carrier", 
                int fighter=30, int cruise=50);
        
        void set_fighter_plane(int);
        int get_fighter_plane() const;
        
        void set_cruise_missile(int);
        int get_cruise_missile() const;

        void launch_fighter_plane(vessel*);
        void launch_cruise_missile(vessel*);
        
        virtual void light_attack(vessel*);
        virtual void heavy_attack(vessel*);
        virtual void sink();

        virtual void print() const;
        virtual void display() const;
                
    private:
        int fighter_plane;
        int cruise_missile;
    
};    

#endif
