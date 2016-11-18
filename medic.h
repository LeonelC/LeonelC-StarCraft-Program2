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

class submarine: virtual public vessel
{
    public:
        submarine(string vname="Unknown", string vteam="Unknown", string vtype="Submarine", 
                   int torpedo=20, int nuclear_missile=16);
                   
       
        void set_torpedo(int);
        int get_torpedo() const;
        
        void set_nuclear_missile(int);
        int get_nuclear_missile() const;

        void fire_torpedo(vessel*);
        void launch_nuclear_missile(vessel*);
        
        virtual void light_attack(vessel*);
        virtual void heavy_attack(vessel*);
        virtual void sink();
        
        // overloaded hit methods so that subs can't be dammaged by 
        // weapons other than torpedos and nuclear missiles
        virtual void main_gun_hit();
        virtual void battery_gun_hit();
        virtual void fighter_plane_hit();
        virtual void cruise_missile_hit();
        

        virtual void print() const;
        virtual void display() const;
                
    private:
        int torpedo;
        int nuclear_missile;
            
};   


#endif
