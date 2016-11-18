//////////////////////////////////////////////////////////////////////////
//
//    carrier.cpp  Class Functions for the carrier Class (derived Class)
//
//    Created by Will McWhorter, Ph.D.
//
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "firebat.h"


carrier::carrier(string vname, string vteam, string vtype, int fighter, int cruise)
                       : vessel(vname, vteam, vtype)
{
    set_fighter_plane(fighter);
    set_cruise_missile(cruise);
    set_health(6000);
    srand(time(NULL));
    //cout << "Carrier Constructor" << endl;
}

        
void carrier::set_fighter_plane(int fighter)
{
    fighter_plane = fighter;
}


int carrier::get_fighter_plane() const
{
    return fighter_plane;
}

        
void carrier::set_cruise_missile(int cruise)
{
    cruise_missile = cruise;
}
    

int carrier::get_cruise_missile() const
{
    return cruise_missile;
}


void carrier::launch_fighter_plane(vessel* attacked_vessel)
{
    if(fighter_plane!=0 && this->get_health()!=0 && attacked_vessel->get_health()!=0)
    {
        if(1+rand()%5 == 1)        
                fighter_plane--;  
                
        attacked_vessel->fighter_plane_hit();
        
    }        
}

void carrier::launch_cruise_missile(vessel* attacked_vessel)
{
    if(cruise_missile!=0 && this->get_health()!=0 && attacked_vessel->get_health()!=0)
    {
        cruise_missile--;
        attacked_vessel->cruise_missile_hit();
    }    
}


void carrier::light_attack(vessel* attacked_vessel)
{
    int x;
    
  
    for(x=1;x<=2;x++)
       launch_fighter_plane(attacked_vessel);
           
    launch_cruise_missile(attacked_vessel);
    
    if (attacked_vessel->get_health() == 0)
        attacked_vessel->sink();
     
}    

void carrier::heavy_attack(vessel* attacked_vessel)
{
    int x;

    for(x=1;x<=6;x++)
       launch_fighter_plane(attacked_vessel);
            
    for(x=1;x<=3;x++)    
       launch_cruise_missile(attacked_vessel);
       
    if (attacked_vessel->get_health() == 0)
        attacked_vessel->sink();

}    


void carrier::sink()
{
   set_fighter_plane(0);
   set_cruise_missile(0);
}


void carrier::print() const
{
    cout << endl;
    vessel::print();
    cout << "Fighter Planes: " << get_fighter_plane() << endl;
    cout << "Cruise Missiles: " << get_cruise_missile() << endl;
        
}  


void carrier::display() const
{
    vessel::display();
    cout << right << setw(5) << " "
         << right << setw(5) << " "
         << right << setw(4) << get_cruise_missile()
         << right << setw(4) << get_fighter_plane()
         << endl;
     
} 
