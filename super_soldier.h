//////////////////////////////////////////////////////////////////////////////////////
//
//    super_ship.h (Derived Class - Multiple Inheritance)
//                                                                                   
//    NOTE: This class is derived from multiple base classes which are derived 
//          from the same base class (diamond inheritance)
//
//    Created by Will McWhorter, Ph.D.
//
//////////////////////////////////////////////////////////////////////////////////////

#ifndef SUPER_SOLDIER_H
#define SUPER_SOLDIER_H

//#include <iostream>

#include "marine.h"
#include "firebat.h"
#include "ghost.h"
#include "medic.h"

class super_ship: public destroyer, public battleship, public submarine, public carrier
{
   public:
    super_ship(string vname="Unknown",string vteam="Unknown", string vtype="Super Ship", 
        int dbgun=4000, int bbgun=4000, int mgun=50, int bcruise=10, int fighter=20, int ccruise=10,
        int torp=30, int nuke=12);  
    
    void set_laser(int);
    int get_laser() const;

    void set_plasma_cluster_nuke(int);
    int get_plasma_cluster_nuke() const;        

    void fire_laser(vessel*);
    void fire_plasma_cluster_nuke(vessel*);

    virtual void light_attack(vessel*);
    virtual void heavy_attack(vessel*);
    virtual void sink();  
    
    virtual void print() const;
    virtual void display() const; 
     
      
   private:
      int laser;
      int plasma_cluster_nuke;      
      
};


#endif
